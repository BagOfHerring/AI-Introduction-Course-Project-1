#pragma once
#include <string>
#include <vector>
#include <mutex>
#include <ros/ros.h>
#include <trajectory_msgs/JointTrajectory.h>
#include <trajectory_msgs/JointTrajectoryPoint.h>
#include <Eigen/Dense>
class BufferController
{
public:
    BufferController(const std::string &robot_name, ros::NodeHandle &nh, const std::string &output_topic);
    void setTrajectory(const trajectory_msgs::JointTrajectory &traj);
    void update(double current_time);
    ros::Time getStartTime() const { return start_time_; }

    std::string robot_name_;
    ros::Publisher cmd_pub_;
    std::vector<trajectory_msgs::JointTrajectoryPoint> traj_buffer_;
    trajectory_msgs::JointTrajectoryPoint last_point_;
    ros::Time start_time_;
    void publishCommand(const trajectory_msgs::JointTrajectoryPoint &pt);

    // interpolate
    trajectory_msgs::JointTrajectoryPoint linearInterp(const trajectory_msgs::JointTrajectoryPoint &pt0, const trajectory_msgs::JointTrajectoryPoint &pt1, double tau);
    trajectory_msgs::JointTrajectoryPoint cubicHermiteInterp(const trajectory_msgs::JointTrajectoryPoint &pt0, const trajectory_msgs::JointTrajectoryPoint &pt1, double tau, double dt);

    // 新增：初始位置相关
    void setInitialPosition(const std::vector<double> &pos);
    void reset();
    std::vector<double> initial_position_;
    std::vector<double> current_position_;

private:
    // 冻结窗口（秒），仅允许替换该窗口之后的轨迹点；默认0.1，可通过参数~lock_horizon覆盖
    double lock_horizon_ = 0.1;
    // 线程安全
    mutable std::mutex mtx_;
};
