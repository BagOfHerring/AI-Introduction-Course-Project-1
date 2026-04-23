#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient

from geometry_msgs.msg import PoseStamped
from control_msgs.action import FollowJointTrajectory, GripperCommand
from trajectory_msgs.msg import JointTrajectoryPoint

from rclpy.duration import Duration

class PickAndPlaceNode(Node):
    def __init__(self):
        super().__init__('pick_and_place_node')
        
        self.pose_sub = self.create_subscription(PoseStamped, '/vision_detector/part_pose', self.pose_callback, 10)
        
        # Action Clients
        self.arm_client = ActionClient(self, FollowJointTrajectory, '/panda_joint_trajectory_controller/follow_joint_trajectory')
        self.gripper_client = ActionClient(self, GripperCommand, '/panda_gripper_sim_node/gripper_action')
        
        self.pending_pose = None
        self.get_logger().info("Pick and Place Node Started. Waiting for part poses...")

    def pose_callback(self, msg):
        if self.pending_pose is None:
            self.pending_pose = msg.pose

    def calculate_ik(self, pose):
        import math
        import franka_ik_py
        
        self.get_logger().info("Calculating analytical IK for target pose...")
        
        # T matrix as column-major 16-element array.
        # R is chosen for EE pointing DOWN (-Z) and X-axis forward
        O_T_EE_array = [
             1.0,  0.0,  0.0, 0.0,
             0.0, -1.0,  0.0, 0.0,
             0.0,  0.0, -1.0, 0.0,
             pose.position.x, pose.position.y, pose.position.z, 1.0
        ]
        
        q7 = 0.785 # Default redundant parameter setup for Panda
        q_actual = [0.0, -0.785, 0.0, -2.356, 0.0, 1.571, 0.785] # Base initial conditions
        
        # Calculate multiple IK branches analytically
        solutions = franka_ik_py.franka_IK_EE(O_T_EE_array, q7, q_actual)
        
        for sol in solutions:
            if not math.isnan(sol[0]):
                self.get_logger().info(f"Analytical IK found valid solution: {sol}")
                return sol
                
        self.get_logger().error("IK Failed! Returning home posture fallback.")
        return q_actual

    def execute_grasp_sequence(self, pose):
        self.get_logger().info(f"Received new target at X:{pose.position.x:.3f}, Y:{pose.position.y:.3f}, Z:{pose.position.z:.3f}!")

        # 1. Open Gripper (Max single finger width logic: 0.04m)
        self.send_gripper_command(width=0.04, max_effort=20.0)
        
        # 2. Move to Target
        target_joints = self.calculate_ik(pose)
        self.send_arm_trajectory(target_joints)
        
        # 3. Close Gripper (grasp)
        self.send_gripper_command(width=0.0, max_effort=60.0)
        
        # 4. Move to Dropoff
        dropoff_joints = [0.5, 0.0, 0.0, -1.5, 0.0, 1.5, 0.785]
        self.send_arm_trajectory(dropoff_joints)
        
        # 5. Open Gripper (release)
        self.send_gripper_command(width=0.04, max_effort=20.0)
        
        self.get_logger().info("Grasp sequence completed. Waiting for next part...")

    def send_arm_trajectory(self, joint_positions):
        self.get_logger().info("Sending arm motion command...")
        if not self.arm_client.wait_for_server(timeout_sec=5.0):
            self.get_logger().error("Arm action server not available!")
            return

        goal_msg = FollowJointTrajectory.Goal()
        goal_msg.trajectory.joint_names = [
            'panda_joint1', 'panda_joint2', 'panda_joint3',
            'panda_joint4', 'panda_joint5', 'panda_joint6', 'panda_joint7'
        ]
        
        point = JointTrajectoryPoint()
        point.positions = joint_positions
        point.time_from_start = Duration(seconds=3).to_msg()
        goal_msg.trajectory.points.append(point)
        
        send_goal_future = self.arm_client.send_goal_async(goal_msg)
        rclpy.spin_until_future_complete(self, send_goal_future)
        goal_handle = send_goal_future.result()
        if not goal_handle.accepted:
            self.get_logger().error("Arm goal rejected.")
            return

        result_future = goal_handle.get_result_async()
        rclpy.spin_until_future_complete(self, result_future)
        self.get_logger().info("Arm moved to target.")

    def send_gripper_command(self, width, max_effort):
        self.get_logger().info(f"Sending gripper command (width: {width})...")
        if not self.gripper_client.wait_for_server(timeout_sec=5.0):
            self.get_logger().error("Gripper action server not available!")
            return

        goal_msg = GripperCommand.Goal()
        goal_msg.command.position = width
        goal_msg.command.max_effort = max_effort
        
        send_goal_future = self.gripper_client.send_goal_async(goal_msg)
        rclpy.spin_until_future_complete(self, send_goal_future)
        goal_handle = send_goal_future.result()
        if not goal_handle.accepted:
            self.get_logger().error("Gripper goal rejected.")
            return

        result_future = goal_handle.get_result_async()
        rclpy.spin_until_future_complete(self, result_future)
        self.get_logger().info("Gripper action done.")

def main(args=None):
    rclpy.init(args=args)
    node = PickAndPlaceNode()
    
    try:
        while rclpy.ok():
            rclpy.spin_once(node, timeout_sec=0.1)
            if node.pending_pose is not None:
                pose = node.pending_pose
                node.execute_grasp_sequence(pose)
                node.pending_pose = None
    except KeyboardInterrupt:
        pass
    finally:
        if rclpy.ok():
            node.destroy_node()
            rclpy.shutdown()

if __name__ == '__main__':
    main()
