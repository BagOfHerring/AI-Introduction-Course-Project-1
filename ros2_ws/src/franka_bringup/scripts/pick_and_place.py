#!/usr/bin/env python3
from collections import defaultdict
from copy import deepcopy
import math

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient

from action_msgs.msg import GoalStatus
from geometry_msgs.msg import Pose, PoseStamped
from sensor_msgs.msg import JointState
from std_msgs.msg import Float32, String
from control_msgs.action import FollowJointTrajectory, GripperCommand
import tf2_geometry_msgs  # noqa: F401
from tf2_ros import Buffer, TransformListener
from trajectory_msgs.msg import JointTrajectoryPoint

from rclpy.duration import Duration


TYPE_TO_QUADRANT = {
    'nut': 1,
    'gear': 2,
    'bearing': 3,
    'square_gear': 4,
}


QUADRANT_DROP_SLOTS = {
    1: [(0.66, 0.18), (0.73, 0.32)],
    2: [(0.34, 0.18), (0.27, 0.32)],
    3: [(0.34, -0.18), (0.27, -0.32)],
    4: [(0.66, -0.18), (0.73, -0.32)],
}


HOME_JOINTS = [0.0, -0.785, 0.0, -2.356, 0.0, 1.571, 0.785]
ARM_JOINT_NAMES = [
    'panda_joint1',
    'panda_joint2',
    'panda_joint3',
    'panda_joint4',
    'panda_joint5',
    'panda_joint6',
    'panda_joint7',
]
EE_ROTATION_IN_WORLD = (
    (1.0, 0.0, 0.0),
    (0.0, -1.0, 0.0),
    (0.0, 0.0, -1.0),
)

class PickAndPlaceNode(Node):
    def __init__(self):
        super().__init__('pick_and_place_node')

        self.pose_sub = self.create_subscription(PoseStamped, '/vision_detector/part_pose', self.pose_callback, 10)
        self.type_sub = self.create_subscription(String, '/vision_detector/part_type', self.type_callback, 10)
        self.size_sub = self.create_subscription(Float32, '/vision_detector/part_size', self.size_callback, 10)
        self.joint_state_sub = self.create_subscription(JointState, '/joint_states', self.joint_state_callback, 10)

        # Action Clients
        self.arm_client = ActionClient(self, FollowJointTrajectory, '/panda_joint_trajectory_controller/follow_joint_trajectory')
        self.gripper_client = ActionClient(self, GripperCommand, '/panda_gripper_sim_node/gripper_action')

        self.expected_parts = int(self.declare_parameter('expected_parts', 8).value)
        self.snapshot_stability_sec = float(self.declare_parameter('snapshot_stability_sec', 1.5).value)
        self.snapshot_collection_timeout_sec = float(self.declare_parameter('snapshot_collection_timeout_sec', 4.0).value)
        self.snapshot_duplicate_distance = float(self.declare_parameter('snapshot_duplicate_distance', 0.05).value)
        self.table_surface_z = float(self.declare_parameter('table_surface_z', 0.4).value)
        self.table_center_x = float(self.declare_parameter('table_center_x', 0.5).value)
        self.table_center_y = float(self.declare_parameter('table_center_y', 0.0).value)
        self.approach_z = float(self.declare_parameter('approach_z', 0.55).value)
        self.pick_z = float(self.declare_parameter('pick_z', 0.30).value)
        self.place_z = float(self.declare_parameter('place_z', 0.43).value)
        self.open_width = float(self.declare_parameter('open_width', 0.04).value)
        self.close_width = float(self.declare_parameter('close_width', 0.0).value)
        self.world_frame = str(self.declare_parameter('world_frame', 'world').value)
        self.robot_base_frame = str(self.declare_parameter('robot_base_frame', 'panda_link0').value)
        self.trajectory_joint_step = float(self.declare_parameter('trajectory_joint_step', 0.04).value)
        self.trajectory_speed = float(self.declare_parameter('trajectory_speed', 0.35).value)
        self.min_trajectory_duration = float(self.declare_parameter('min_trajectory_duration', 1.8).value)
        self.max_trajectory_duration = float(self.declare_parameter('max_trajectory_duration', 6.0).value)

        self.partial_detection = {}
        self.snapshot_parts = []
        self.snapshot_cycle_start_time = self.get_clock().now()
        self.last_snapshot_update_time = None
        self.collecting_snapshot = True
        self.executing_sort_step = False
        self.move_attempts = defaultdict(int)
        self.drop_slot_indices = defaultdict(int)
        self.current_joint_positions = None
        self.last_commanded_joint_positions = list(HOME_JOINTS)
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        self.get_logger().info(
            'Pick and Place Node started. Before each grasp, capturing a fresh part snapshot '
            'and selecting one misplaced part to move.'
        )

    def pose_callback(self, msg):
        self._collect_detection_field('pose', deepcopy(msg.pose))

    def type_callback(self, msg):
        self._collect_detection_field('part_type', msg.data)

    def size_callback(self, msg):
        self._collect_detection_field('size_m', float(msg.data))

    def joint_state_callback(self, msg: JointState):
        if not msg.name or not msg.position:
            return

        name_to_position = dict(zip(msg.name, msg.position))
        if not all(joint_name in name_to_position for joint_name in ARM_JOINT_NAMES):
            return

        self.current_joint_positions = [name_to_position[joint_name] for joint_name in ARM_JOINT_NAMES]

    def _collect_detection_field(self, field_name, value):
        if not self.collecting_snapshot or self.executing_sort_step:
            return

        if field_name == 'pose':
            self.partial_detection = {'pose': value}
            return

        if 'pose' not in self.partial_detection:
            return

        self.partial_detection[field_name] = value
        if {'pose', 'part_type', 'size_m'} <= self.partial_detection.keys():
            detection = {
                'pose': self.partial_detection['pose'],
                'part_type': self.partial_detection['part_type'],
                'size_m': self.partial_detection['size_m'],
            }
            self.partial_detection = {}
            self._store_snapshot_detection(detection)

    def _store_snapshot_detection(self, detection):
        part_type = detection['part_type']
        if part_type not in TYPE_TO_QUADRANT:
            return

        position = detection['pose'].position
        for existing in self.snapshot_parts:
            if existing['part_type'] != part_type:
                continue

            dx = position.x - existing['pose'].position.x
            dy = position.y - existing['pose'].position.y
            if (dx * dx + dy * dy) ** 0.5 <= self.snapshot_duplicate_distance:
                existing['pose'] = detection['pose']
                existing['size_m'] = detection['size_m']
                self.last_snapshot_update_time = self.get_clock().now()
                return

        self.snapshot_parts.append(detection)
        self.last_snapshot_update_time = self.get_clock().now()
        self.get_logger().info(
            f"Snapshot capture: [{part_type}] x={position.x:.3f}, y={position.y:.3f}, size={detection['size_m']:.3f}m "
            f"({len(self.snapshot_parts)}/{self.expected_parts})"
        )

    def _reset_snapshot_cycle(self):
        self.partial_detection = {}
        self.snapshot_parts = []
        self.snapshot_cycle_start_time = self.get_clock().now()
        self.last_snapshot_update_time = None
        self.collecting_snapshot = True

    def _finish_snapshot_cycle(self) -> list:
        self.collecting_snapshot = False
        self.partial_detection = {}
        snapshot = [
            {
                'pose': deepcopy(part['pose']),
                'part_type': part['part_type'],
                'size_m': part['size_m'],
            }
            for part in self.snapshot_parts
        ]
        summary = ', '.join(
            f"{part['part_type']}@({part['pose'].position.x:.3f},{part['pose'].position.y:.3f})"
            for part in snapshot
        )
        if summary:
            self.get_logger().info(f'Current snapshot contains {len(snapshot)} parts: {summary}')
        return snapshot

    def _part_signature(self, part) -> str:
        pose = part['pose'].position
        return f"{part['part_type']}:{pose.x:.2f}:{pose.y:.2f}"

    def _quadrant_for_pose(self, pose: Pose) -> int:
        left_half = pose.position.x < self.table_center_x
        upper_half = pose.position.y >= self.table_center_y
        if not left_half and upper_half:
            return 1
        if left_half and upper_half:
            return 2
        if left_half and not upper_half:
            return 3
        return 4

    def _part_needs_move(self, part) -> bool:
        desired_quadrant = TYPE_TO_QUADRANT[part['part_type']]
        actual_quadrant = self._quadrant_for_pose(part['pose'])
        return actual_quadrant != desired_quadrant

    def _occupied_drop_slots(self, snapshot_parts: list, part_type: str) -> set[int]:
        occupied = set()
        slots = QUADRANT_DROP_SLOTS[TYPE_TO_QUADRANT[part_type]]
        threshold = self.snapshot_duplicate_distance * 1.5

        for part in snapshot_parts:
            if part['part_type'] != part_type or self._part_needs_move(part):
                continue

            px = part['pose'].position.x
            py = part['pose'].position.y
            for index, (slot_x, slot_y) in enumerate(slots):
                distance = ((px - slot_x) ** 2 + (py - slot_y) ** 2) ** 0.5
                if distance <= threshold:
                    occupied.add(index)
                    break

        return occupied

    def _build_pose(self, x: float, y: float, z: float) -> Pose:
        pose = Pose()
        pose.position.x = float(x)
        pose.position.y = float(y)
        pose.position.z = float(z)
        pose.orientation.w = 1.0
        return pose

    def _next_drop_pose(self, part_type: str, snapshot_parts: list) -> Pose:
        quadrant = TYPE_TO_QUADRANT[part_type]
        slots = QUADRANT_DROP_SLOTS[quadrant]
        occupied_slots = self._occupied_drop_slots(snapshot_parts, part_type)

        slot_index = None
        for index in range(len(slots)):
            if index not in occupied_slots:
                slot_index = index
                break

        if slot_index is None:
            slot_index = self.drop_slot_indices[quadrant] % len(slots)
        self.drop_slot_indices[quadrant] += 1
        x_target, y_target = slots[slot_index]
        return self._build_pose(x_target, y_target, self.place_z)

    def _select_part_to_move(self, snapshot_parts: list):
        candidates = [part for part in snapshot_parts if self._part_needs_move(part)]
        if not candidates:
            return None, None

        candidates.sort(
            key=lambda part: (
                self.move_attempts[self._part_signature(part)],
                TYPE_TO_QUADRANT[part['part_type']],
                part['pose'].position.y,
                part['pose'].position.x,
            )
        )
        chosen_part = candidates[0]
        target_pose = self._next_drop_pose(chosen_part['part_type'], snapshot_parts)
        return chosen_part, target_pose

    def maybe_execute_next_sort_step(self):
        if not self.collecting_snapshot or self.executing_sort_step:
            return

        if not self.snapshot_parts:
            return

        now = self.get_clock().now()
        snapshot_age = (now - self.snapshot_cycle_start_time).nanoseconds * 1e-9
        idle_time = 0.0
        if self.last_snapshot_update_time is not None:
            idle_time = (now - self.last_snapshot_update_time).nanoseconds * 1e-9

        snapshot_ready = len(self.snapshot_parts) >= self.expected_parts
        snapshot_ready = snapshot_ready or idle_time >= self.snapshot_stability_sec
        snapshot_ready = snapshot_ready or snapshot_age >= self.snapshot_collection_timeout_sec
        if not snapshot_ready:
            return

        snapshot_parts = self._finish_snapshot_cycle()
        chosen_part, target_pose = self._select_part_to_move(snapshot_parts)

        if chosen_part is None:
            self.get_logger().info('Current snapshot shows no misplaced parts. Starting a new scan cycle.')
            self._reset_snapshot_cycle()
            return

        self.executing_sort_step = True
        signature = self._part_signature(chosen_part)
        self.get_logger().info(
            f"Selected [{chosen_part['part_type']}] at ({chosen_part['pose'].position.x:.3f}, "
            f"{chosen_part['pose'].position.y:.3f}) for the next move."
        )
        success = self.execute_grasp_sequence(chosen_part, target_pose)
        if success:
            self.move_attempts.pop(signature, None)
        else:
            self.move_attempts[signature] += 1
            self.get_logger().warn(
                f"Move failed for [{chosen_part['part_type']}] at ({chosen_part['pose'].position.x:.3f}, "
                f"{chosen_part['pose'].position.y:.3f}); attempts={self.move_attempts[signature]}"
            )

        self.executing_sort_step = False
        self._reset_snapshot_cycle()

    def _compute_open_width(self, size_m: float) -> float:
        if size_m <= 0.0:
            return self.open_width
        return min(self.open_width, max(0.02, size_m * 0.6))

    def _move_pose(self, pose: Pose) -> bool:
        target_joints = self.calculate_ik(pose)
        if target_joints is None:
            return False
        return self.send_arm_trajectory(target_joints)

    def _quaternion_to_rotation_matrix(self, x: float, y: float, z: float, w: float):
        xx = x * x
        yy = y * y
        zz = z * z
        xy = x * y
        xz = x * z
        yz = y * z
        wx = w * x
        wy = w * y
        wz = w * z

        return (
            (1.0 - 2.0 * (yy + zz), 2.0 * (xy - wz), 2.0 * (xz + wy)),
            (2.0 * (xy + wz), 1.0 - 2.0 * (xx + zz), 2.0 * (yz - wx)),
            (2.0 * (xz - wy), 2.0 * (yz + wx), 1.0 - 2.0 * (xx + yy)),
        )

    def _transpose_matrix(self, matrix):
        return tuple(tuple(matrix[row][col] for row in range(3)) for col in range(3))

    def _matmul_3x3(self, left, right):
        return tuple(
            tuple(sum(left[row][idx] * right[idx][col] for idx in range(3)) for col in range(3))
            for row in range(3)
        )

    def _matvec_3x3(self, matrix, vector):
        return tuple(sum(matrix[row][idx] * vector[idx] for idx in range(3)) for row in range(3))

    def _world_pose_to_base_pose(self, pose: Pose):
        try:
            pose_stamped = PoseStamped()
            pose_stamped.header.frame_id = self.world_frame
            pose_stamped.header.stamp = self.get_clock().now().to_msg()
            pose_stamped.pose = deepcopy(pose)

            base_pose_stamped = self.tf_buffer.transform(
                pose_stamped,
                self.robot_base_frame,
                timeout=Duration(seconds=0.2),
            )
            transform = self.tf_buffer.lookup_transform(
                self.robot_base_frame,
                self.world_frame,
                rclpy.time.Time(),
            )
        except Exception as exc:
            self.get_logger().warn(
                f'Unable to transform from {self.world_frame} to {self.robot_base_frame}: {exc}'
            )
            return None, None

        rotation = transform.transform.rotation
        world_to_base = self._quaternion_to_rotation_matrix(
            rotation.x,
            rotation.y,
            rotation.z,
            rotation.w,
        )

        base_position = (
            base_pose_stamped.pose.position.x,
            base_pose_stamped.pose.position.y,
            base_pose_stamped.pose.position.z,
        )
        base_rotation = self._matmul_3x3(world_to_base, EE_ROTATION_IN_WORLD)

        self.get_logger().info(
            f'IK target world=({pose.position.x:.3f}, {pose.position.y:.3f}, {pose.position.z:.3f}) '
            f'-> base=({base_position[0]:.3f}, {base_position[1]:.3f}, {base_position[2]:.3f})'
        )
        return base_position, base_rotation

    def calculate_ik(self, pose):
        import franka_ik_py

        self.get_logger().info("Calculating analytical IK for target pose...")

        base_position, base_rotation = self._world_pose_to_base_pose(pose)
        if base_position is None or base_rotation is None:
            return None

        # T matrix as column-major 16-element array.
        # The analytical IK expects the target expressed in the robot base frame.
        O_T_EE_array = [
             base_rotation[0][0], base_rotation[1][0], base_rotation[2][0], 0.0,
             base_rotation[0][1], base_rotation[1][1], base_rotation[2][1], 0.0,
             base_rotation[0][2], base_rotation[1][2], base_rotation[2][2], 0.0,
             base_position[0], base_position[1], base_position[2], 1.0
        ]

        q7 = 0.785 # Default redundant parameter setup for Panda
        q_actual = self._get_reference_joint_positions()

        # Calculate multiple IK branches analytically
        solutions = franka_ik_py.franka_IK_EE(O_T_EE_array, q7, q_actual)

        valid_solutions = []
        for sol in solutions:
            if all(not math.isnan(joint_value) for joint_value in sol):
                valid_solutions.append(list(sol))
                continue

            self.get_logger().warn(f"Discarding incomplete IK solution: {sol}")

        if valid_solutions:
            best_solution = min(
                valid_solutions,
                key=lambda sol: sum((sol[idx] - q_actual[idx]) ** 2 for idx in range(len(ARM_JOINT_NAMES))),
            )
            self.get_logger().info(f"Analytical IK found valid solution: {best_solution}")
            return best_solution

        self.get_logger().error(
            f"IK failed for pose x={pose.position.x:.3f}, y={pose.position.y:.3f}, z={pose.position.z:.3f}."
        )
        return None

    def execute_grasp_sequence(self, part, target_pose):
        source_xy_pose = part['pose']
        source_pose = self._build_pose(source_xy_pose.position.x, source_xy_pose.position.y, self.pick_z)
        source_approach_pose = self._build_pose(source_pose.position.x, source_pose.position.y, self.approach_z)
        target_approach_pose = self._build_pose(target_pose.position.x, target_pose.position.y, self.approach_z)
        open_width = self._compute_open_width(part['size_m'])

        self.get_logger().info(
            f"Sorting [{part['part_type']}] from "
            f"({source_pose.position.x:.3f}, {source_pose.position.y:.3f}) to "
            f"quadrant {TYPE_TO_QUADRANT[part['part_type']]} at "
            f"({target_pose.position.x:.3f}, {target_pose.position.y:.3f}), size={part['size_m']:.3f}m"
        )

        if not self.send_gripper_command(width=open_width, max_effort=20.0):
            return False
        if not self._move_pose(source_approach_pose):
            return False
        if not self._move_pose(source_pose):
            return False
        if not self.send_gripper_command(width=self.close_width, max_effort=60.0):
            return False
        if not self._move_pose(source_approach_pose):
            return False
        if not self._move_pose(target_approach_pose):
            return False
        if not self._move_pose(target_pose):
            return False
        if not self.send_gripper_command(width=open_width, max_effort=20.0):
            return False
        if not self._move_pose(target_approach_pose):
            return False

        self.get_logger().info(f"Completed sorting [{part['part_type']}].")
        return True

    def send_arm_trajectory(self, joint_positions):
        self.get_logger().info("Sending arm motion command...")
        if not self.arm_client.wait_for_server(timeout_sec=5.0):
            self.get_logger().error("Arm action server not available!")
            return False

        goal_msg = FollowJointTrajectory.Goal()
        goal_msg.trajectory.joint_names = ARM_JOINT_NAMES
        reference_positions = self._get_reference_joint_positions()
        trajectory_points = self._build_interpolated_trajectory(reference_positions, joint_positions)
        goal_msg.trajectory.points.extend(trajectory_points)

        send_goal_future = self.arm_client.send_goal_async(goal_msg)
        rclpy.spin_until_future_complete(self, send_goal_future)
        goal_handle = send_goal_future.result()
        if not goal_handle.accepted:
            self.get_logger().error("Arm goal rejected.")
            return False

        result_future = goal_handle.get_result_async()
        rclpy.spin_until_future_complete(self, result_future)
        wrapped_result = result_future.result()
        if wrapped_result is None:
            self.get_logger().error("Arm action finished without a result payload.")
            return False

        if wrapped_result.status != GoalStatus.STATUS_SUCCEEDED:
            self.get_logger().error(
                f"Arm action did not succeed. Goal status={wrapped_result.status}."
            )
            return False

        follow_result = wrapped_result.result
        if follow_result is not None and getattr(follow_result, 'error_code', 0) != 0:
            self.get_logger().error(
                'Arm trajectory execution failed with error_code='
                f"{follow_result.error_code}, error_string='{getattr(follow_result, 'error_string', '')}'."
            )
            return False

        self.last_commanded_joint_positions = list(joint_positions)
        self.get_logger().info("Arm moved to target.")
        return True

    def _get_reference_joint_positions(self):
        if self.current_joint_positions is not None:
            return list(self.current_joint_positions)
        return list(self.last_commanded_joint_positions)

    def _build_interpolated_trajectory(self, start_positions, target_positions):
        max_joint_delta = max(abs(target - start) for start, target in zip(start_positions, target_positions))
        segment_count = max(1, int(math.ceil(max_joint_delta / max(1e-3, self.trajectory_joint_step))))
        unclamped_duration = max_joint_delta / max(1e-3, self.trajectory_speed)
        total_duration = min(
            self.max_trajectory_duration,
            max(self.min_trajectory_duration, unclamped_duration),
        )

        self.get_logger().info(
            f'Interpolating arm trajectory with {segment_count} segment(s), '
            f'max_delta={max_joint_delta:.3f} rad, total_duration={total_duration:.2f}s.'
        )

        points = []
        for segment_index in range(1, segment_count + 1):
            tau = segment_index / segment_count
            alpha = 10.0 * tau ** 3 - 15.0 * tau ** 4 + 6.0 * tau ** 5
            alpha_dot = (30.0 * tau ** 2 - 60.0 * tau ** 3 + 30.0 * tau ** 4) / total_duration
            point = JointTrajectoryPoint()
            point.positions = [
                start + alpha * (target - start)
                for start, target in zip(start_positions, target_positions)
            ]
            point.velocities = [
                (target - start) * alpha_dot
                for start, target in zip(start_positions, target_positions)
            ]
            point.time_from_start = Duration(seconds=total_duration * tau).to_msg()
            points.append(point)

        return points

    def send_gripper_command(self, width, max_effort):
        self.get_logger().info(f"Sending gripper command (width: {width})...")
        if not self.gripper_client.wait_for_server(timeout_sec=5.0):
            self.get_logger().error("Gripper action server not available!")
            return False

        goal_msg = GripperCommand.Goal()
        goal_msg.command.position = width
        goal_msg.command.max_effort = max_effort

        send_goal_future = self.gripper_client.send_goal_async(goal_msg)
        rclpy.spin_until_future_complete(self, send_goal_future)
        goal_handle = send_goal_future.result()
        if not goal_handle.accepted:
            self.get_logger().error("Gripper goal rejected.")
            return False

        result_future = goal_handle.get_result_async()
        rclpy.spin_until_future_complete(self, result_future)
        self.get_logger().info("Gripper action done.")
        return True

def main(args=None):
    rclpy.init(args=args)
    node = PickAndPlaceNode()

    try:
        while rclpy.ok():
            rclpy.spin_once(node, timeout_sec=0.1)
            node.maybe_execute_next_sort_step()
    except KeyboardInterrupt:
        pass
    finally:
        if rclpy.ok():
            node.destroy_node()
            rclpy.shutdown()

if __name__ == '__main__':
    main()
