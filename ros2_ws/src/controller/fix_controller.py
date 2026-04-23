import os
import re

def fix_buffer_controller_h():
    filepath = '/home/herring/桌面/SSRRTT/MRGBP-ROS2/MR-GBP/ros2_ws/src/controller/include/controller/buffer_controller.h'
    with open(filepath, 'r') as f:
        content = f.read()
    
    content = content.replace('ros::NodeHandle &nh', 'rclcpp::Node::SharedPtr node')
    content = content.replace('rclcpp::PublisherBase::SharedPtr cmd_pub_', 'rclcpp::Publisher<trajectory_msgs::msg::JointTrajectoryPoint>::SharedPtr cmd_pub_')
    
    with open(filepath, 'w') as f:
        f.write(content)

def fix_buffer_controller_cpp():
    filepath = '/home/herring/桌面/SSRRTT/MRGBP-ROS2/MR-GBP/ros2_ws/src/controller/src/buffer_controller.cpp'
    with open(filepath, 'r') as f:
        content = f.read()
    
    content = content.replace('ros::NodeHandle &nh', 'rclcpp::Node::SharedPtr node')
    content = content.replace('nh.advertise', 'node->create_publisher')
    content = content.replace('nh.getParam', 'node->get_parameter')
    content = content.replace('rclcpp::Time::now()', 'node->now()')
    content = content.replace('traj.header.stamp.isZero()', 'traj.header.stamp.sec == 0 && traj.header.stamp.nanosec == 0')
    content = content.replace('rclcpp::Duration(lock_horizon_)', 'rclcpp::Duration::from_seconds(lock_horizon_)')
    content = content.replace('rclcpp::Duration(0.0)', 'rclcpp::Duration::from_seconds(0.0)')
    content = content.replace('rclcpp::Duration(t_cut_rel)', 'rclcpp::Duration::from_seconds(t_cut_rel)')
    content = content.replace('rclcpp::Duration(t)', 'rclcpp::Duration::from_seconds(t)')
    content = content.replace('rclcpp::Duration(pt0.time_from_start.seconds()', 'rclcpp::Duration::from_seconds(rclcpp::Duration(pt0.time_from_start).seconds()')
    
    # regex for .seconds() on time_from_start -> rclcpp::Duration(..).seconds()
    content = re.sub(r'([a-zA-Z0-9_]+)\.time_from_start\.seconds\(\)', r'rclcpp::Duration(\1.time_from_start).seconds()', content)
    
    # replace the complex duration math in linearInterp
    content = content.replace(
        'rclcpp::Duration::from_seconds(rclcpp::Duration(pt0.time_from_start).seconds() + tau * (rclcpp::Duration(pt1.time_from_start).seconds() - rclcpp::Duration(pt0.time_from_start).seconds()))', 
        'rclcpp::Duration::from_seconds(rclcpp::Duration(pt0.time_from_start).seconds() + tau * (rclcpp::Duration(pt1.time_from_start).seconds() - rclcpp::Duration(pt0.time_from_start).seconds()))'
    )
    # same for hermite
    content = content.replace('rclcpp::Duration(pt0.time_from_start.toSec() + tau * dt)', 'rclcpp::Duration::from_seconds(rclcpp::Duration(pt0.time_from_start).seconds() + tau * dt)')

    with open(filepath, 'w') as f:
        f.write(content)

def fix_controller_node_cpp():
    filepath = '/home/herring/桌面/SSRRTT/MRGBP-ROS2/MR-GBP/ros2_ws/src/controller/src/controller_node.cpp'
    with open(filepath, 'r') as f:
        content = f.read()

    content = content.replace('const trajectory_msgs::msg::JointTrajectory::ConstPtr &msg', 'const trajectory_msgs::msg::JointTrajectory::SharedPtr msg')
    content = content.replace('ros::init(argc, argv, "buffer_controller");', 'rclcpp::init(argc, argv);')
    content = content.replace('ros::NodeHandle nh; // 默认绑定当前节点命名空间, 如/ns or /', 'auto node = std::make_shared<rclcpp::Node>("buffer_controller");')
    content = content.replace('nh.getNamespace()', 'node->get_namespace()')
    content = content.replace('int buffer_rate = nh.param("buffer_rate", 100);', 'int buffer_rate = node->declare_parameter<int>("buffer_rate", 100);')
    content = content.replace('nh.param<std::string>("robot_name", robot_name, "panda_1");', 'robot_name = node->declare_parameter<std::string>("robot_name", "panda01");')
    content = content.replace('g_controller = std::make_shared<BufferController>(robot_name, nh, output_topic);', 'g_controller = std::make_shared<BufferController>(robot_name, node, output_topic);')
    content = content.replace('rclcpp::SubscriptionBase::SharedPtr traj_sub = nh.subscribe(input_topic, 1, trajCallback);', 'auto traj_sub = node->create_subscription<trajectory_msgs::msg::JointTrajectory>(input_topic, 1, trajCallback);')
    content = content.replace('rclcpp::Time::now()', 'node->now()')

    with open(filepath, 'w') as f:
        f.write(content)

if __name__ == '__main__':
    fix_buffer_controller_h()
    fix_buffer_controller_cpp()
    fix_controller_node_cpp()
