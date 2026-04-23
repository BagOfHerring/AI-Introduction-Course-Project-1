#!/usr/bin/env python3
"""
Part Spawner Node
=================
Periodically teleports existing objects in the MuJoCo scene to random positions
on the table surface, simulating "new parts appearing" for the vision pipeline.

Uses the /set_body_state service provided by mujoco_ros.
"""
import random
import rclpy
from rclpy.node import Node

from geometry_msgs.msg import PoseStamped, TwistStamped
from mujoco_ros_msgs.srv import SetBodyState
from mujoco_ros_msgs.msg import BodyState


# ── Table geometry (must match scene_with_workbench.xml) ────────────────
TABLE_CENTER_X = 0.5
TABLE_CENTER_Y = 0.0
TABLE_HALF_X   = 0.35   # slightly smaller than 0.4 to keep parts away from edge
TABLE_HALF_Y   = 0.50   # slightly smaller than 0.6
TABLE_Z        = 0.45   # just above table surface (0.4) so parts drop gently

# ── Bodies that can be randomized ───────────────────────────────────────
SPAWNABLE_BODIES = [
    'part_gear_1',
    'part_gear_2',
    'part_square_gear_1',
    'part_square_gear_2',
    'part_nut_1',
    'part_nut_2',
    'part_bearing_1',
    'part_bearing_2',
]


class PartSpawnerNode(Node):
    def __init__(self):
        super().__init__('part_spawner_node')

        self.client = self.create_client(SetBodyState, '/set_body_state')

        self.declare_parameter('spawn_interval', 8.0)
        self.spawn_interval = self.get_parameter('spawn_interval').value

        self.get_logger().info(f'Part Spawner started. Randomizing every {self.spawn_interval}s')
        self.get_logger().info(f'Bodies: {SPAWNABLE_BODIES}')

        # Wait for the service
        while not self.client.wait_for_service(timeout_sec=2.0):
            self.get_logger().info('Waiting for /set_body_state service...')

        # Do an initial randomization immediately
        self.randomize_all()

        # Then repeat on timer
        self.timer = self.create_timer(self.spawn_interval, self.randomize_all)

    def randomize_all(self):
        """Teleport every spawnable body to a random position on the table."""
        for body_name in SPAWNABLE_BODIES:
            x = TABLE_CENTER_X + random.uniform(-TABLE_HALF_X, TABLE_HALF_X)
            y = TABLE_CENTER_Y + random.uniform(-TABLE_HALF_Y, TABLE_HALF_Y)
            z = TABLE_Z

            self.set_body_pose(body_name, x, y, z)

        self.get_logger().info('Randomized all parts on table.')

    def set_body_pose(self, body_name, x, y, z):
        req = SetBodyState.Request()

        req.state = BodyState()
        req.state.name = body_name
        req.state.pose = PoseStamped()
        req.state.pose.header.frame_id = 'world'
        req.state.pose.header.stamp = self.get_clock().now().to_msg()
        req.state.pose.pose.position.x = x
        req.state.pose.pose.position.y = y
        req.state.pose.pose.position.z = z
        req.state.pose.pose.orientation.w = 1.0

        # Zero velocity so parts don't fly away
        req.state.twist = TwistStamped()
        req.state.twist.header.frame_id = 'world'

        req.set_pose = True
        req.set_twist = True
        req.set_mass = False
        req.reset_qpos = False
        req.admin_hash = ''

        future = self.client.call_async(req)
        future.add_done_callback(
            lambda f, name=body_name: self._on_response(f, name)
        )

    def _on_response(self, future, body_name):
        try:
            resp = future.result()
            if not resp.success:
                self.get_logger().warn(f'Failed to move {body_name}: {resp.status_message}')
        except Exception as e:
            self.get_logger().error(f'Service call failed for {body_name}: {e}')


def main(args=None):
    rclpy.init(args=args)
    node = PartSpawnerNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()
