#include "buffer_controller.h"
#include <rclcpp/rclcpp.hpp>
#include <trajectory_msgs/msg/joint_trajectory.hpp>
#include <trajectory_msgs/msg/joint_trajectory_point.hpp>

std::shared_ptr<BufferController> g_controller;

void trajCallback(const trajectory_msgs::msg::JointTrajectory::SharedPtr msg)
{
    if (g_controller)
    {
        g_controller->setTrajectory(*msg);
    }
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("buffer_controller");
    RCLCPP_INFO(node->get_logger(), "Node namespace: %s", node->get_namespace());
    int buffer_rate = node->declare_parameter<int>("buffer_rate", 100); // 默认100Hz
    // use ros parameters to get robot name and topics
    std::string robot_name;
    robot_name = node->declare_parameter<std::string>("robot_name", "panda01");
    std::string input_topic = "trajectory"; // 都是相对于launch中的ns下的命名，在前面不能加"/"不然就是绝对命名空间
    // std::string output_topic =  robot_name + "_equilibrium_config";
    std::string output_topic = "joint_impedance_tracking_controller_velocity/equilibrium_config";

    g_controller = std::make_shared<BufferController>(robot_name, node, output_topic);
    auto traj_sub = node->create_subscription<trajectory_msgs::msg::JointTrajectory>(input_topic, 1, trajCallback);

    rclcpp::Rate rate(buffer_rate); // 高频控制
    while (rclcpp::ok())
    {
        double t = (node->now() - g_controller->getStartTime()).seconds();
        g_controller->update(t);
        rclcpp::spin_some(node);
        rate.sleep();
    }
    return 0;
}
