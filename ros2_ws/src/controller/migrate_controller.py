import os
import glob

def replace_in_file(filepath):
    print(f"Processing {filepath}")
    with open(filepath, 'r') as f:
        content = f.read()

    # Headers
    content = content.replace('#include <ros/ros.h>', '#include <rclcpp/rclcpp.hpp>')
    content = content.replace('#include <ros/package.h>', '#include <ament_index_cpp/get_package_share_directory.hpp>')
    content = content.replace('#include <trajectory_msgs/JointTrajectory.h>', '#include <trajectory_msgs/msg/joint_trajectory.hpp>')
    content = content.replace('#include <trajectory_msgs/JointTrajectoryPoint.h>', '#include <trajectory_msgs/msg/joint_trajectory_point.hpp>')
    content = content.replace('#include <sensor_msgs/JointState.h>', '#include <sensor_msgs/msg/joint_state.hpp>')
    content = content.replace('#include <std_msgs/Bool.h>', '#include <std_msgs/msg/bool.hpp>')
    content = content.replace('#include <std_msgs/String.h>', '#include <std_msgs/msg/string.hpp>')
    content = content.replace('#include <visualization_msgs/MarkerArray.h>', '#include <visualization_msgs/msg/marker_array.hpp>')
    
    # Types
    content = content.replace('trajectory_msgs::JointTrajectoryPoint', 'trajectory_msgs::msg::JointTrajectoryPoint')
    content = content.replace('trajectory_msgs::JointTrajectory', 'trajectory_msgs::msg::JointTrajectory')
    content = content.replace('sensor_msgs::JointState', 'sensor_msgs::msg::JointState')
    content = content.replace('std_msgs::String', 'std_msgs::msg::String')
    content = content.replace('std_msgs::Bool', 'std_msgs::msg::Bool')
    content = content.replace('visualization_msgs::MarkerArray', 'visualization_msgs::msg::MarkerArray')
    
    # ROS 2 Time / Duration
    content = content.replace('ros::Time', 'rclcpp::Time')
    content = content.replace('ros::Duration', 'rclcpp::Duration')
    content = content.replace('.toSec()', '.seconds()')
    content = content.replace('ros::ok()', 'rclcpp::ok()')
    content = content.replace('ros::spinOnce()', 'rclcpp::spin_some(node)')
    content = content.replace('ros::spin()', 'rclcpp::spin(node)')
    content = content.replace('ros::Rate', 'rclcpp::Rate')
    content = content.replace('ros::Publisher', 'rclcpp::PublisherBase::SharedPtr')
    content = content.replace('ros::Subscriber', 'rclcpp::SubscriptionBase::SharedPtr')
    content = content.replace('ros::package::getPath("controller")', 'ament_index_cpp::get_package_share_directory("controller")')

    # Logging
    content = content.replace('ROS_INFO(', 'RCLCPP_INFO(node->get_logger(), ')
    content = content.replace('ROS_WARN(', 'RCLCPP_WARN(node->get_logger(), ')
    content = content.replace('ROS_ERROR(', 'RCLCPP_ERROR(node->get_logger(), ')
    content = content.replace('ROS_INFO_STREAM(', 'RCLCPP_INFO_STREAM(node->get_logger(), ')
    content = content.replace('ROS_WARN_STREAM(', 'RCLCPP_WARN_STREAM(node->get_logger(), ')
    content = content.replace('ROS_ERROR_STREAM(', 'RCLCPP_ERROR_STREAM(node->get_logger(), ')

    with open(filepath, 'w') as f:
        f.write(content)

base_dir = '/home/herring/桌面/SSRRTT/MRGBP-ROS2/MR-GBP/ros2_ws/src/controller'
for root, _, files in os.walk(base_dir):
    for f in files:
        if f.endswith('.cpp') or f.endswith('.h') or f.endswith('.hpp'):
            replace_in_file(os.path.join(root, f))
