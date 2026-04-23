import os

def fix_buffer_h():
    filepath = '/home/herring/桌面/SSRRTT/MRGBP-ROS2/MR-GBP/ros2_ws/src/controller/include/controller/buffer_controller.h'
    with open(filepath, 'r') as f:
        content = f.read()
    
    # Add node_ to class
    if 'rclcpp::Node::SharedPtr node_;' not in content:
        content = content.replace('rclcpp::Publisher<trajectory_msgs::msg::JointTrajectoryPoint>::SharedPtr cmd_pub_;', 
                                  'rclcpp::Node::SharedPtr node_;\n    rclcpp::Publisher<trajectory_msgs::msg::JointTrajectoryPoint>::SharedPtr cmd_pub_;')
    
    with open(filepath, 'w') as f:
        f.write(content)

def fix_buffer_cpp():
    filepath = '/home/herring/桌面/SSRRTT/MRGBP-ROS2/MR-GBP/ros2_ws/src/controller/src/buffer_controller.cpp'
    with open(filepath, 'r') as f:
        content = f.read()

    # Save node_
    content = content.replace(': robot_name_(robot_name)', ': robot_name_(robot_name), node_(node)')
    
    # Fix node->now() to node_->now()
    content = content.replace('node->now()', 'node_->now()')
    
    # Fix 运算符类型
    content = content.replace('traj.header.stamp.sec == 0  && traj.header.stamp.nanosec == 0 ? now : traj.header.stamp',
                              'traj.header.stamp.sec == 0 && traj.header.stamp.nanosec == 0 ? now : rclcpp::Time(traj.header.stamp)')
    content = content.replace('traj.header.stamp.sec == 0 && traj.header.stamp.nanosec == 0 ? now : traj.header.stamp',
                              'traj.header.stamp.sec == 0 && traj.header.stamp.nanosec == 0 ? now : rclcpp::Time(traj.header.stamp)')
    
    # Fix duration seconds error
    # "using trajectory_msgs::msg::JointTrajectoryPoint_... has no member named 'seconds'" 
    # This was `.time_from_start.seconds()` in traj_buffer_[i].time_from_start.seconds() > t
    content = content.replace('traj_buffer_[i].time_from_start.seconds()', 'rclcpp::Duration(traj_buffer_[i].time_from_start).seconds()')
    
    # cmd_pub_.publish -> cmd_pub_->publish
    content = content.replace('cmd_pub_.publish', 'cmd_pub_->publish')

    with open(filepath, 'w') as f:
        f.write(content)

def fix_node_cpp():
    filepath = '/home/herring/桌面/SSRRTT/MRGBP-ROS2/MR-GBP/ros2_ws/src/controller/src/controller_node.cpp'
    with open(filepath, 'r') as f:
        content = f.read()
    
    # Fix c_str() error
    content = content.replace('node->get_namespace().c_str()', 'node->get_namespace()')

    with open(filepath, 'w') as f:
        f.write(content)

def fix_dist_interarm():
    filepath = '/home/herring/桌面/SSRRTT/MRGBP-ROS2/MR-GBP/ros2_ws/src/cplus_dev/include/utilities_function/dist_interarm_sphere.h'
    with open(filepath, 'r') as f:
        content = f.read()
    content = content.replace('#include "RobotDescription.h"', '#include "GBP_classes/Robot_classes/RobotDescription.h"')
    with open(filepath, 'w') as f:
        f.write(content)

def fix_ssa_controller():
    # Fix RobotDescription.h and others in ssa_controller.cpp
    filepath = '/home/herring/桌面/SSRRTT/MRGBP-ROS2/MR-GBP/ros2_ws/src/controller/src/ssa_controller.cpp'
    with open(filepath, 'r') as f:
        content = f.read()
    content = content.replace('#include "Robot_classes/RobotDescription.h"', '#include "GBP_classes/Robot_classes/RobotDescription.h"')
    content = content.replace('#include "Robot_classes/CollisionSphere.h"', '#include "GBP_classes/Robot_classes/CollisionSphere.h"')
    with open(filepath, 'w') as f:
        f.write(content)
        
if __name__ == "__main__":
    fix_buffer_h()
    fix_buffer_cpp()
    fix_node_cpp()
    fix_dist_interarm()
    fix_ssa_controller()
