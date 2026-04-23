#!/usr/bin/env python3

import re

import rclpy
from rclpy.node import Node
from rclpy.qos import DurabilityPolicy, QoSProfile, ReliabilityPolicy
from std_msgs.msg import String


ROS2_CONTROL_BLOCK = re.compile(r"<ros2_control\b.*?</ros2_control>", re.DOTALL)


class RobotDescriptionTopicPublisher(Node):
    def __init__(self) -> None:
        super().__init__("robot_description_topic_publisher")
        self.declare_parameter("robot_description", "")
        self.declare_parameter("topic_name", "/robot_description")
        self.declare_parameter("strip_ros2_control", True)

        robot_description = self.get_parameter("robot_description").get_parameter_value().string_value
        topic_name = self.get_parameter("topic_name").get_parameter_value().string_value
        strip_ros2_control = (
            self.get_parameter("strip_ros2_control").get_parameter_value().bool_value
        )

        if strip_ros2_control:
            robot_description = ROS2_CONTROL_BLOCK.sub("", robot_description)

        qos = QoSProfile(depth=1)
        qos.durability = DurabilityPolicy.TRANSIENT_LOCAL
        qos.reliability = ReliabilityPolicy.RELIABLE
        self.publisher_ = self.create_publisher(String, topic_name, qos)
        self.message_ = String(data=robot_description)
        self.publish_timer_ = self.create_timer(1.0, self.publish_description)
        self.publish_description()

    def publish_description(self) -> None:
        self.publisher_.publish(self.message_)


def main() -> None:
    rclpy.init()
    node = RobotDescriptionTopicPublisher()
    try:
        rclpy.spin(node)
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
