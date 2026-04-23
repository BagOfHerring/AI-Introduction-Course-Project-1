#include "buffer_controller.h"
#include <ros/ros.h>
#include <trajectory_msgs/JointTrajectory.h>
#include <trajectory_msgs/JointTrajectoryPoint.h>

std::shared_ptr<BufferController> g_controller;

void trajCallback(const trajectory_msgs::JointTrajectory::ConstPtr &msg)
{
    if (g_controller)
    {
        g_controller->setTrajectory(*msg);
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "buffer_controller");
    ros::NodeHandle nh; // 默认绑定当前节点命名空间, 如/ns or /
    ROS_INFO("Node namespace: %s", nh.getNamespace().c_str());
    int buffer_rate = nh.param("buffer_rate", 100); // 默认100Hz
    // use ros parameters to get robot name and topics
    std::string robot_name;
    nh.param<std::string>("robot_name", robot_name, "panda_1");
    std::string input_topic = "trajectory"; // 都是相对于launch中的ns下的命名，在前面不能加"/"不然就是绝对命名空间
    // std::string output_topic =  robot_name + "_equilibrium_config";
    std::string output_topic = "joint_impedance_tracking_controller_velocity/equilibrium_config";

    g_controller = std::make_shared<BufferController>(robot_name, nh, output_topic);
    ros::Subscriber traj_sub = nh.subscribe(input_topic, 1, trajCallback);

    ros::Rate rate(buffer_rate); // 高频控制
    while (ros::ok())
    {
        double t = (ros::Time::now() - g_controller->getStartTime()).toSec();
        g_controller->update(t);
        ros::spinOnce();
        rate.sleep();
    }
    return 0;
}
