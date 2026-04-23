#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from std_msgs.msg import Float32

class MockVisionNode(Node):
    def __init__(self):
        super().__init__('mock_vision_node')
        self.pose_pub = self.create_publisher(PoseStamped, '/vision_detector/part_pose', 10)
        self.size_pub = self.create_publisher(Float32, '/vision_detector/part_size', 10)
        
        # Publish every 5 seconds for demonstration
        self.timer = self.create_timer(5.0, self.publish_part)
        self.get_logger().info("Mock Vision Node Started. Publishing dummy part periodically.")

    def publish_part(self):
        # Publish Pose
        pose_msg = PoseStamped()
        pose_msg.header.stamp = self.get_clock().now().to_msg()
        pose_msg.header.frame_id = "world"  
        
        # Mock Part Coordination
        pose_msg.pose.position.x = 0.5   # 50cm forward
        pose_msg.pose.position.y = 0.0   # Centered
        pose_msg.pose.position.z = 0.02  # On the workbench
        
        pose_msg.pose.orientation.w = 1.0
        pose_msg.pose.orientation.x = 0.0
        pose_msg.pose.orientation.y = 0.0
        pose_msg.pose.orientation.z = 0.0
        
        self.pose_pub.publish(pose_msg)
        
        # Publish Size
        size_msg = Float32()
        size_msg.data = 0.04 # 4cm size
        self.size_pub.publish(size_msg)

        self.get_logger().info(f"Published target part at x={pose_msg.pose.position.x}, y={pose_msg.pose.position.y}, z={pose_msg.pose.position.z}")

def main(args=None):
    rclpy.init(args=args)
    node = MockVisionNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
