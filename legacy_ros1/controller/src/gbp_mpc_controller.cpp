#include <ros/ros.h>
#include <trajectory_msgs/JointTrajectory.h>
#include <trajectory_msgs/JointTrajectoryPoint.h>
#include <sensor_msgs/JointState.h>
#include <std_msgs/Bool.h>
#include <std_msgs/String.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <memory>
#include <Eigen/Dense>
#include <sstream>
#include <iterator>
#include <visualization_msgs/MarkerArray.h>
#include <limits>
#include <ros/package.h>
#include <string>
#include <map>
#include "Robot_classes/RobotDescription.h"
#include "utilities_function/dist_arm_3D_sphere.h"
#include "Robot_classes/CollisionSphere.h"
#include "utilities_function/ObstacleSeq.hpp"
#include "utilities_function/dist_interarm_sphere.h"
#include <boost/bind.hpp>

// GBP classes from cplus_dev
#include "GBP_classes/graph_env_message/FactorGraphRobot.h"
#include "GBP_classes/value_node/VNode.h"
#include "GBP_classes/value_node/RemoteVNode.h"
#include "GBP_classes/factor_node/FNode.h"
#include "GBP_classes/factor_node/DynaFNode.h"
#include "GBP_classes/factor_node/BoxFNode.h"
#include "GBP_classes/factor_node/SSAObstacleFNode.h"
#include "GBP_classes/factor_node/SSADistFNode.h"
#include "GBP_classes/graph_env_message/ObstacleMap.h"
#include "GBP_classes/graph_env_message/Gaussian.h"

// 考虑到可能的头文件包含顺序或重复定义问题
// 下面的类都是基于已有的 Cpp+ 逻辑进行包装

static constexpr int N_JOINTS = 7;

class GBPMpcController
{
public:
    ros::Time start_time_;
    GBPMpcController(const std::string &robot_name, ros::NodeHandle &nh_pub)
        : robot_name_(robot_name), nh_(nh_pub)
    {

        if (!nh_pub.hasParam("robot_name"))
        {
            ROS_WARN("Parameter 'robot_name' not found. Using default value 'panda_1'.");
        }

        nh_pub.param("horizon_steps", horizon_steps_, 5); // 固定视野为5~10
        nh_pub.param("lock_horizon", lock_horizon_, 0.05);
        nh_pub.param("safe_margin", safe_margin_, 0.1);
        nh_pub.param("buffer_rate", update_rate_, 1000); // 1KHz
        dt_ = 1.0 / update_rate_;                        // 确保dt和update_rate一致
        nh_pub.param("gbp_iters", iter_steps_, 1);       // 我们要在1KHz跑，迭代不宜太多
        nh_pub.param("damp_value", damp_value_, 0.0);

        // GBP Params
        nh_pub.param("obstacle_precision", obstacle_precision_, 10000.0);
        nh_pub.param("interarm_precision", interarm_precision_, 10000.0);
        nh_pub.param("start_position_precision", start_pos_precision_, 5000.0);
        nh_pub.param("start_velocity_precision", start_vel_precision_, 2000.0);
        nh_pub.param("target_position_precision", target_pos_precision_, 1000.0);
        nh_pub.param("target_velocity_precision", target_vel_precision_, 1000.0);
        nh_pub.param("state_precision", state_precision_, 500.0);
        nh_pub.param("state_safety", state_safety_, 1e-3);
        nh_pub.param("min_iter_relin", min_iter_relin_, 1);
        nh_pub.param("relin_thre", relin_thre_, 1e-5);

        nh_pub.param("is_ssa", is_ssa_, true);
        nh_pub.param("ssa_ks", ssa_ks_, 20.0);
        nh_pub.param("z_precision_vel", z_precision_vel_, 1000.0);
        nh_pub.param("smooth_alpha", smooth_alpha_, 20.0);

        nh_pub.param("vmax_coeff", vmax_coeff_, 0.3);
        nh_pub.param("amax_coeff", amax_coeff_, 0.3);
        state_max_ = Eigen::VectorXd(2 * N_JOINTS);
        state_min_ = Eigen::VectorXd(2 * N_JOINTS);

        std::string input_topic = "/" + robot_name_ + "/trajectory";
        std::string output_topic = "/" + robot_name_ + "/joint_impedance_tracking_controller_velocity/equilibrium_config";
        std::string self_js = "/" + robot_name_ + "/joint_states";
        std::string obstacle_topic = "/moving_obstacles";
        std::string neighbors_topic = "/" + robot_name_ + "/connected_agents";

        cmd_pub_ = nh_pub.advertise<trajectory_msgs::JointTrajectoryPoint>(output_topic, 1);
        traj_sub_ = nh_pub.subscribe(input_topic, 1, &GBPMpcController::trajCb, this);
        js_sub_ = nh_pub.subscribe(self_js, 1, &GBPMpcController::selfJsCb, this);
        // neighbors_sub_ = nh_pub.subscribe(neighbors_topic, 1, &GBPMpcController::neighborsCb, this);

        // 初始化机器人
        ROS_INFO_STREAM("[" << robot_name_ << "] Initializing Robot...");
        panda_ = std::make_shared<RobotDescription>("Panda", 1, safe_margin_);
        InitRobot(*panda_, robot_name_, nh_pub);
        ROS_INFO_STREAM("[" << robot_name_ << "] Robot Initialized, thetamax shape: " << panda_->thetamax.rows() << "x" << panda_->thetamax.cols());

        state_max_.head(N_JOINTS) = panda_->thetamax.col(0);
        state_max_.tail(N_JOINTS) = vmax_coeff_ * panda_->dthetamax.col(0);
        state_min_.head(N_JOINTS) = panda_->thetamax.col(1);
        state_min_.tail(N_JOINTS) = vmax_coeff_ * panda_->dthetamax.col(1);

        q_ = Eigen::VectorXd::Zero(N_JOINTS);
        qd_ = Eigen::VectorXd::Zero(N_JOINTS);
        last_point_.time_from_start = ros::Duration(0.0);
        start_time_ = ros::Time(0);

        omap_ = std::make_shared<ObstacleMap>(nh_pub);

        // 初始化固定GBP拓扑图
        ROS_INFO_STREAM("[" << robot_name_ << "] Start initGraph...");
        initGraph(is_ssa_, ssa_ks_, z_precision_vel_, smooth_alpha_);
        ROS_INFO_STREAM("[" << robot_name_ << "] GBPMpcController Init Complete!");
    }

    // 轨迹和时间相关的插值，同原来一样
    void setTrajectory(const trajectory_msgs::JointTrajectory &traj)
    {
        if (traj.points.empty())
            return;
        ros::Time now = ros::Time::now();
        ros::Time new_base = traj.header.stamp.isZero() ? now : traj.header.stamp;

        if (traj_buffer_.empty())
        {
            traj_buffer_ = traj.points;
            start_time_ = new_base;
            last_point_ = traj.points.front();
            last_point_.time_from_start = ros::Duration(0.0);
            return;
        }

        ros::Time cutoff_abs = std::max(now, start_time_ + ros::Duration(lock_horizon_));
        double t_cut_rel_old = (cutoff_abs - start_time_).toSec();
        auto absOld = [&](const trajectory_msgs::JointTrajectoryPoint &p)
        { return start_time_ + p.time_from_start; };
        auto absNew = [&](const trajectory_msgs::JointTrajectoryPoint &p)
        { return new_base + p.time_from_start; };

        std::vector<trajectory_msgs::JointTrajectoryPoint> merged;
        trajectory_msgs::JointTrajectoryPoint now_pt = last_point_;
        now_pt.time_from_start = ros::Duration(0.0);
        merged.push_back(now_pt);
        for (const auto &p : traj_buffer_)
        {
            ros::Time ta = absOld(p);
            if (ta < cutoff_abs && ta > now)
            {
                auto x = p;
                x.time_from_start = ta - now;
                merged.push_back(x);
            }
        }

        trajectory_msgs::JointTrajectoryPoint cut_pt;
        bool cut_ok = false;
        const double eps = 1e-9;
        for (const auto &p : traj_buffer_)
        {
            if (std::abs(p.time_from_start.toSec() - t_cut_rel_old) < eps)
            {
                cut_pt = p;
                cut_ok = true;
                break;
            }
        }
        if (!cut_ok && traj_buffer_.size() >= 2)
        {
            for (size_t i = 0; i + 1 < traj_buffer_.size(); ++i)
            {
                double t0 = traj_buffer_[i].time_from_start.toSec(), t1 = traj_buffer_[i + 1].time_from_start.toSec();
                if (t0 <= t_cut_rel_old && t_cut_rel_old <= t1 && t1 > t0)
                {
                    double tau = (t_cut_rel_old - t0) / (t1 - t0);
                    cut_pt = cubicHermiteInterp(traj_buffer_[i], traj_buffer_[i + 1], tau, t1 - t0);
                    cut_pt.time_from_start = ros::Duration(t_cut_rel_old);
                    cut_ok = true;
                    break;
                }
            }
        }
        if (!cut_ok && !traj_buffer_.empty())
        {
            const auto &f = traj_buffer_.front();
            const auto &l = traj_buffer_.back();
            cut_pt = (std::abs(f.time_from_start.toSec() - t_cut_rel_old) <= std::abs(l.time_from_start.toSec() - t_cut_rel_old)) ? f : l;
            cut_pt.time_from_start = ros::Duration(t_cut_rel_old);
            cut_ok = true;
        }
        if (cut_ok)
        {
            cut_pt.time_from_start -= (now - start_time_);
            merged.push_back(cut_pt);
        }

        for (const auto &p : traj.points)
        {
            ros::Time ta = absNew(p);
            if (ta > cutoff_abs && ta > now)
            {
                auto x = p;
                x.time_from_start = ta - now;
                merged.push_back(x);
            }
        }
        std::sort(merged.begin(), merged.end(), [](const auto &a, const auto &b)
                  { return a.time_from_start.toSec() < b.time_from_start.toSec(); });
        traj_buffer_.swap(merged);
        start_time_ = now;
    }

    void init_vnodes_fnodes(double t)
    {
        // 1. 获取MPC各个视野步长需要的参考目标状态序列 (t, t+dt_, t+2dt_ ... t+T*dt_)
        std::vector<Eigen::VectorXd> ref_states(horizon_steps_ + 1);
        std::vector<Eigen::VectorXd> ref_vels(horizon_steps_ + 1);
        for (int k = 0; k <= horizon_steps_; ++k)
        {
            double tk = t + k * dt_;
            getInterpPoint(tk, ref_states[k], ref_vels[k]);
        }
        // 2. 更新先验: v_0锁定当前真实观测，其他层引入先验TargetFactor
        Eigen::MatrixXd cov_s = Eigen::MatrixXd::Zero(2 * N_JOINTS, 2 * N_JOINTS);
        cov_s.diagonal().head(N_JOINTS).setConstant(1.0 / start_pos_precision_);
        cov_s.diagonal().tail(N_JOINTS).setConstant(1.0 / start_vel_precision_);
        Eigen::VectorXd x0 = Eigen::VectorXd::Zero(2 * N_JOINTS);
        x0 << q_, qd_;
        vnodes_[0]->belief = std::make_shared<Gaussian>(vnodes_[0]->dims, x0, cov_s); // 初始值
        Eigen::MatrixXd cov = Eigen::MatrixXd::Zero(2 * N_JOINTS, 2 * N_JOINTS);
        cov.diagonal().head(N_JOINTS).setConstant(1.0 / target_pos_precision_);
        cov.diagonal().tail(N_JOINTS).setConstant(1.0 / target_vel_precision_);
        for (int k = 1; k <= horizon_steps_; ++k)
        {
            Eigen::VectorXd ref_x = Eigen::VectorXd::Zero(2 * N_JOINTS);
            ref_x << ref_states[k], ref_vels[k];
            vnodes_[k]->belief = std::make_shared<Gaussian>(vnodes_[k]->dims, ref_x, cov);          // 初始值
            path_fnodes_[k - 1]->lin_point = ref_x;                                                 // 线性化点设置为参考状态
            path_fnodes_[k - 1]->factor = std::make_shared<Gaussian>(vnodes_[k]->dims, ref_x, cov); // 目标因子初始值
            // std::cout << "box_fnodes_.size() = " << box_fnodes_.size() << std::endl;
            box_fnodes_[k - 1]->update_factor();
            dyna_fnodes_[k - 1]->update_factor();
            obs_fnodes_[k - 1]->update_factor();
        }
    }
    void update(double t)
    {
        if (traj_buffer_.empty())
            return;

        init_vnodes_fnodes(t);
        graph_->loopy_propagate_extended(iter_steps_);

        // 5. 提取一步控制量 (比如 v_1 的位置和速度)
        Eigen::VectorXd next_x = vnodes_[1]->get_mean();

        trajectory_msgs::JointTrajectoryPoint cmd_pt;
        cmd_pt.positions.resize(N_JOINTS);
        cmd_pt.velocities.resize(N_JOINTS);
        for (int j = 0; j < N_JOINTS; ++j)
        {
            cmd_pt.positions[j] = next_x(j);
            cmd_pt.velocities[j] = limitVel(next_x.segment(N_JOINTS, N_JOINTS), state_max_.tail(N_JOINTS))(j);
        }
        cmd_pub_.publish(cmd_pt);
        last_point_ = cmd_pt;
        // ROS_INFO_STREAM_THROTTLE(1.0, "[" << robot_name_ << "] update t=" << t << " End");
    }

    static Eigen::VectorXd limitVel(const Eigen::VectorXd &v, const Eigen::VectorXd &vmax)
    {
        // 绝对值限制，逐元素比较后裁剪到[-vmax, vmax]范围内
        Eigen::VectorXd out = v;
        for (int i = 0; i < N_JOINTS; ++i)
        {
            double lim = std::max(0.0, vmax(i));
            if (out(i) > lim)
                out(i) = lim;
            else if (out(i) < -lim)
                out(i) = -lim;
        }
        return out;
    }

private:
    void initGraph(bool is_ssa, double ssa_ks, double z_pv, double smooth_a)
    {
        ROS_INFO_STREAM("[" << robot_name_ << "] initGraph: Creating graph components...");
        graph_ = std::make_shared<FactorGraphRobot>();
        int dof = N_JOINTS * 2;
        vnodes_.resize(horizon_steps_ + 1);
        dyna_fnodes_.resize(horizon_steps_);
        obs_fnodes_.resize(horizon_steps_);
        path_fnodes_.resize(horizon_steps_);
        box_fnodes_.resize(horizon_steps_);

        // 1. 初始化变量节点 (VNode)，为每一步骤设置独立的维度名称
        ROS_INFO_STREAM("[" << robot_name_ << "] initGraph: Building VNodes...");
        for (int i = 0; i <= horizon_steps_; ++i)
        {
            std::string vName = "v" + std::to_string(i);
            std::vector<std::string> dims(dof);
            for (int j = 0; j < N_JOINTS; ++j)
            {
                dims[j] = vName + ".q" + std::to_string(j + 1);
                dims[j + N_JOINTS] = vName + ".qd" + std::to_string(j + 1);
            }
            // VNode(name, dims, robot, belief)
            // 机器人指针传 nullptr，belief 传 nullptr，等待后续设定因子或先验
            vnodes_[i] = std::make_shared<VNode>(vName, dims, panda_, nullptr);
            graph_->addNode(vnodes_[i]);
        }

        ROS_INFO_STREAM("[" << robot_name_ << "] initGraph: Building FNodes...");
        for (int i = 0; i < horizon_steps_; ++i)
        {
            std::vector<std::string> empty_dims = {}; // 因子层不显式传 dims，让其利用 VNode 的维度

            // 1. Dyna Factor
            std::vector<std::shared_ptr<VNode>> d_vnodes = {vnodes_[i], vnodes_[i + 1]};
            std::vector<std::string> dims;
            for (const auto &vnode : d_vnodes)
            {
                auto d = vnode->get_dims();
                dims.insert(dims.end(), d.begin(), d.end());
            }
            dyna_fnodes_[i] = std::make_shared<DynaFNode>(
                "fd" + std::to_string(i), d_vnodes, dt_, z_precision_vel_,
                nullptr, dims, min_iter_relin_, relin_thre_, true); // TODO: now is linear, can add some nonlinearity later
            graph_->addNode(dyna_fnodes_[i]);
            graph_->connect(vnodes_[i], dyna_fnodes_[i]);
            graph_->connect(vnodes_[i + 1], dyna_fnodes_[i]);

            // 2. Obstacle Factor (SSA)
            std::vector<std::shared_ptr<VNode>> o_vnodes = {vnodes_[i + 1]};
            obs_fnodes_[i] = std::make_shared<SSAObstacleFNode>(
                "fo" + std::to_string(i), o_vnodes, nullptr,
                omap_, safe_margin_, obstacle_precision_, ssa_ks,
                z_pv, smooth_a, dt_ * (i + 1), vnodes_[i + 1]->get_dims(),
                min_iter_relin_, relin_thre_, false, is_ssa);
            graph_->addNode(obs_fnodes_[i]);
            graph_->connect(vnodes_[i + 1], obs_fnodes_[i]);

            // 3. Task / Path Factor
            std::vector<std::shared_ptr<VNode>> t_vnodes = {vnodes_[i + 1]};
            Eigen::VectorXd init_x = Eigen::VectorXd::Zero(dof);
            path_fnodes_[i] = std::make_shared<FNode>(
                "ft" + std::to_string(i), t_vnodes, nullptr,
                vnodes_[i + 1]->get_dims());
            graph_->addNode(path_fnodes_[i]);
            graph_->connect(vnodes_[i + 1], path_fnodes_[i]);

            // 4. Box Factor
            std::vector<std::shared_ptr<VNode>> b_vnodes = {vnodes_[i + 1]};
            Eigen::VectorXd state_safety_vec = state_safety_ * Eigen::VectorXd::Ones(dof);
            box_fnodes_[i] = std::make_shared<BoxFNode>(
                "fb" + std::to_string(i),
                b_vnodes,
                nullptr,
                state_max_,
                state_min_,
                state_safety_vec,
                state_precision_,
                vnodes_[i + 1]->get_dims(),
                min_iter_relin_,
                relin_thre_,
                false);

            graph_->addNode(box_fnodes_[i]);
            graph_->connect(vnodes_[i + 1], box_fnodes_[i]);
        }
        ROS_INFO_STREAM("[" << robot_name_ << "] initGraph: Done.");
    }

    void getInterpPoint(double tk, Eigen::VectorXd &pos, Eigen::VectorXd &vel)
    {
        if (traj_buffer_.empty())
        {
            pos = q_;
            vel = Eigen::VectorXd::Zero(N_JOINTS);
            return;
        }
        size_t idx = traj_buffer_.size();
        for (size_t i = 1; i < traj_buffer_.size(); ++i)
        {
            if (traj_buffer_[i].time_from_start.toSec() > tk)
            {
                idx = i - 1;
                break;
            }
        }
        if (idx >= traj_buffer_.size() - 1)
        {
            const auto &p = traj_buffer_.back();
            pos = Eigen::Map<const Eigen::VectorXd>(p.positions.data(), N_JOINTS);
            vel = Eigen::VectorXd::Zero(N_JOINTS);
            return;
        }
        const auto &p0 = traj_buffer_[idx];
        const auto &p1 = traj_buffer_[idx + 1];
        double t0 = p0.time_from_start.toSec();
        double t1 = p1.time_from_start.toSec();
        double tau = (tk - t0) / std::max(1e-9, t1 - t0);
        tau = std::max(0.0, std::min(1.0, tau));
        auto pnt = cubicHermiteInterp(p0, p1, tau, t1 - t0);
        pos = Eigen::Map<const Eigen::VectorXd>(pnt.positions.data(), N_JOINTS);
        vel = Eigen::Map<const Eigen::VectorXd>(pnt.velocities.data(), N_JOINTS);
    }

    trajectory_msgs::JointTrajectoryPoint cubicHermiteInterp(const trajectory_msgs::JointTrajectoryPoint &pt0, const trajectory_msgs::JointTrajectoryPoint &pt1, double tau, double dt)
    {
        trajectory_msgs::JointTrajectoryPoint pt = pt0;
        Eigen::VectorXd p0 = Eigen::Map<const Eigen::VectorXd>(pt0.positions.data(), pt0.positions.size());
        Eigen::VectorXd p1 = Eigen::Map<const Eigen::VectorXd>(pt1.positions.data(), pt1.positions.size());
        Eigen::VectorXd v0 = Eigen::VectorXd::Zero(p0.size());
        Eigen::VectorXd v1 = Eigen::VectorXd::Zero(p1.size());
        if (!pt0.velocities.empty())
            v0 = Eigen::Map<const Eigen::VectorXd>(pt0.velocities.data(), pt0.velocities.size());
        if (!pt1.velocities.empty())
            v1 = Eigen::Map<const Eigen::VectorXd>(pt1.velocities.data(), pt1.velocities.size());

        double h00 = 2 * pow(tau, 3) - 3 * pow(tau, 2) + 1;
        double h10 = pow(tau, 3) - 2 * pow(tau, 2) + tau;
        double h01 = -2 * pow(tau, 3) + 3 * pow(tau, 2);
        double h11 = pow(tau, 3) - pow(tau, 2);

        Eigen::VectorXd pos = h00 * p0 + h10 * v0 * dt + h01 * p1 + h11 * v1 * dt;
        Eigen::VectorXd vel = (6 * (p1 - p0) / dt - 4 * v0 - 2 * v1) * tau +
                              (6 * (p0 - p1) / dt + 3 * v0 + 3 * v1) * tau * tau + v0;

        pt.positions = std::vector<double>(pos.data(), pos.data() + pos.size());
        pt.velocities = std::vector<double>(vel.data(), vel.data() + vel.size());
        pt.time_from_start = ros::Duration(pt0.time_from_start.toSec() + tau * dt);
        return pt;
    }

    void trajCb(const trajectory_msgs::JointTrajectory::ConstPtr &msg) { setTrajectory(*msg); }
    void selfJsCb(const sensor_msgs::JointState::ConstPtr &msg)
    {
        Eigen::VectorXd curq = Eigen::VectorXd::Zero(N_JOINTS);
        Eigen::VectorXd curqd = Eigen::VectorXd::Zero(N_JOINTS);
        for (size_t i = 0; i < msg->name.size(); ++i)
        {
            std::string n = msg->name[i];
            int j = n.back() - '1'; // "panda_1_joint1" -> 0
            if (j >= 0 && j < N_JOINTS)
            {
                curq[j] = msg->position[i];
                if (msg->velocity.size() == msg->position.size())
                    curqd[j] = msg->velocity[i];
            }
        }
        q_ = curq;
        qd_ = curqd;
    }
    // void obstacleCb(const visualization_msgs::MarkerArray::ConstPtr &msg) {
    //     omap_->updateObstacles(*msg);
    // }

    struct OtherRobot
    {
        std::string name;
        // 仅订阅高频 joint_states
        ros::Subscriber sub_js_raw;
        Eigen::VectorXd q = Eigen::VectorXd::Zero(N_JOINTS);
        Eigen::VectorXd qd = Eigen::VectorXd::Zero(N_JOINTS);
        std::shared_ptr<RobotDescription> model;
        bool has_state = false;
        std::vector<std::shared_ptr<RemoteVNode>> remote_vnodes;
        std::vector<std::shared_ptr<SSADistFNode>> interarm_fnode;
    };

    // void neighborsCb(const std_msgs::String::ConstPtr &msg)
    // {
    //     if (!msg)
    //         return;
    //     std::vector<std::string> names;
    //     std::stringstream ss(msg->data);
    //     std::string item;
    //     while (std::getline(ss, item, ','))
    //     {
    //         if (!item.empty())
    //         {
    //             // 去空格
    //             item.erase(0, item.find_first_not_of(' '));
    //             item.erase(item.find_last_not_of(' ') + 1);
    //             if (!item.empty() && item != robot_name_)
    //                 names.push_back(item);
    //         }
    //     }
    //     updateNeighbors(names, nh_);
    // }

    // void updateNeighbors(const std::vector<std::string> &names, ros::NodeHandle nh)
    // {
    //     // 移除不存在的
    //     for (auto it = others_.begin(); it != others_.end();)
    //     {
    //         if (std::find(names.begin(), names.end(), it->first) == names.end())
    //         {
    //             // 移除remote_vnode和interarm_fnode等相关资源
    //             for (auto &rvn : it->second.remote_vnodes)
    //                 graph_->removeNode(rvn);
    //             for (auto &iaf : it->second.interarm_fnode)
    //                 graph_->removeNode(iaf);
    //             it = others_.erase(it);
    //         }
    //         else
    //         {
    //             ++it;
    //         }
    //     }
    //     // 新增或已存在的保持
    //     for (const auto &n : names)
    //     {
    //         if (n == robot_name_)
    //             continue;
    //         auto it = others_.find(n);
    //         if (it == others_.end())
    //         {
    //             ROS_INFO_STREAM("[" << robot_name_ << "] Adding neighbor: " << n);
    //             // 新增机器人，创建模型和订阅
    //             OtherRobot o;
    //             o.name = n;
    //             o.model = std::make_shared<RobotDescription>("Panda", 1, safe_margin_);
    //             InitRobot(*o.model, n, nh);

    //             ROS_INFO_STREAM("[" << robot_name_ << "] Subscribing to " << n << " joint_states");
    //             // 仅订阅 /name/joint_states
    //             std::string raw_topic = "/" + n + "/joint_states";
    //             o.sub_js_raw = nh.subscribe<sensor_msgs::JointState>(raw_topic, 1, boost::bind(&GBPMpcController::otherJsCb, this, _1, n));

    //             ROS_INFO_STREAM("[" << robot_name_ << "] Creating RemoteVNodes");
    //             // 初始化remote_vnode
    //             o.remote_vnodes.resize(horizon_steps_);
    //             for (int i = 1; i <= horizon_steps_; ++i)
    //             {
    //                 std::string vName = n + ".v" + std::to_string(i);
    //                 std::vector<std::string> dims(2 * N_JOINTS);
    //                 for (int j = 0; j < N_JOINTS; ++j)
    //                 {
    //                     dims[j] = n + ".v" + std::to_string(i) + ".q" + std::to_string(j + 1);
    //                     dims[j + N_JOINTS] = n + ".v" + std::to_string(i) + ".qd" + std::to_string(j + 1);
    //                 }

    //                 o.remote_vnodes[i - 1] = std::make_shared<RemoteVNode>(vName, dims, o.model);
    //                 graph_->addNode(o.remote_vnodes[i - 1]);
    //             }

    //             ROS_INFO_STREAM("[" << robot_name_ << "] Creating SSADistFNodes");
    //             // 初始化remote_vnode和interarm_fnode等相关资源
    //             o.interarm_fnode.resize(horizon_steps_);

    //             for (int i = 1; i <= horizon_steps_; ++i)
    //             {
    //                 std::string fName = n + ".f" + std::to_string(i);
    //                 std::vector<std::shared_ptr<VNode>> dist_vnodes = {o.remote_vnodes[i - 1], vnodes_[i]};
    //                 std::vector<std::string> dims;
    //                 for (const auto &vnode : dist_vnodes)
    //                 {
    //                     auto d = vnode->get_dims();
    //                     dims.insert(dims.end(), d.begin(), d.end());
    //                 }
    //                 // SSADistFNode 的实例化
    //                 o.interarm_fnode[i - 1] = std::make_shared<SSADistFNode>(
    //                     fName,
    //                     dist_vnodes,
    //                     nullptr,
    //                     safe_margin_,
    //                     interarm_precision_,
    //                     ssa_ks_,
    //                     z_precision_vel_,
    //                     dims,
    //                     min_iter_relin_,
    //                     relin_thre_,
    //                     false,
    //                     is_ssa_);

    //                 graph_->addNode(o.interarm_fnode[i - 1]);
    //                 // 分别跟两端的 VNode 创建边连接
    //                 graph_->connect(o.remote_vnodes[i - 1], o.interarm_fnode[i - 1]);
    //                 graph_->connect(vnodes_[i], o.interarm_fnode[i - 1]);
    //             }

    //             others_.emplace(n, std::move(o));
    //             ROS_INFO_STREAM("[" << robot_name_ << "] Done adding neighbor: " << n);
    //         }
    //     }
    // }

    // void otherJsCb(const sensor_msgs::JointState::ConstPtr &msg, const std::string &name)
    // {
    //     auto it = others_.find(name);
    //     if (it == others_.end())
    //         return;
    //     auto &o = it->second;
    //     // 简化：按顺序读取前 N_JOINTS 个关节
    //     if (!msg || msg->position.size() < static_cast<size_t>(N_JOINTS))
    //         return;
    //     o.q = Eigen::VectorXd::Zero(N_JOINTS);
    //     o.qd = Eigen::VectorXd::Zero(N_JOINTS);
    //     for (int j = 0; j < N_JOINTS; ++j)
    //     {
    //         o.q(j) = msg->position[j];
    //         o.qd(j) = msg->velocity[j];
    //     }
    //     o.has_state = true;
    // }

    static void InitRobot(RobotDescription &rb, const std::string &arm_id, ros::NodeHandle &nh)
    {
        std::vector<double> xyz, rpy;
        std::string p_xyz = std::string("/robots/") + arm_id + "/base_xyz";
        std::string p_rpy = std::string("/robots/") + arm_id + "/base_rpy";
        if (!nh.getParam(p_xyz, xyz) || xyz.size() != 3)
            xyz = {0.0, 0.0, 0.0};
        if (!nh.getParam(p_rpy, rpy) || rpy.size() != 3)
            rpy = {0.0, 0.0, 0.0};
        rb.set_base(Eigen::Vector3d(xyz[0], xyz[1], xyz[2]), Eigen::Vector3d(rpy[0], rpy[1], rpy[2]));
        std::string pkg_path = ros::package::getPath("controller");
        rb.loadCollisionSphere(pkg_path + "/config/franka_sphere.yaml");
    }

    std::string robot_name_;
    ros::NodeHandle nh_;
    ros::Publisher cmd_pub_;
    ros::Subscriber traj_sub_, js_sub_, obstacle_sub_, neighbors_sub_;

    std::shared_ptr<RobotDescription> panda_;
    std::shared_ptr<ObstacleMap> omap_;
    std::vector<trajectory_msgs::JointTrajectoryPoint> traj_buffer_;
    trajectory_msgs::JointTrajectoryPoint last_point_;

    double lock_horizon_;
    Eigen::VectorXd q_, qd_, state_max_, state_min_;
    int update_rate_;
    // MPC / GBP params
    bool is_ssa_;
    int horizon_steps_, iter_steps_, min_iter_relin_;
    double ssa_ks_, smooth_alpha_, vmax_coeff_, amax_coeff_;
    double dt_, relin_thre_, safe_margin_, damp_value_;
    double obstacle_precision_, interarm_precision_, z_precision_vel_, target_pos_precision_, target_vel_precision_, start_pos_precision_, start_vel_precision_, state_precision_, state_safety_;

    std::map<std::string, OtherRobot> others_;
    std::shared_ptr<FactorGraphRobot> graph_;
    std::vector<std::shared_ptr<VNode>> vnodes_;
    std::vector<std::shared_ptr<FNode>> path_fnodes_;
    std::vector<std::shared_ptr<DynaFNode>> dyna_fnodes_;
    std::vector<std::shared_ptr<SSAObstacleFNode>> obs_fnodes_;
    std::vector<std::shared_ptr<BoxFNode>> box_fnodes_;
    std::vector<std::shared_ptr<RemoteVNode>> remote_vnodes_;
};

int main(int argc, char **argv)
{
    ros::init(argc, argv, "gbp_mpc_controller");
    ros::NodeHandle nh;
    std::string robot_name;
    nh.param<std::string>("robot_name", robot_name, "panda_1");

    GBPMpcController ctrl(robot_name, nh);

    int rate = 1000;
    nh.param("buffer_rate", rate, 500);
    ros::Rate r(rate);
    std::cout << "GBPMpcController running with update rate: " << rate << " Hz" << std::endl;

    while (ros::ok())
    {
        ros::spinOnce();
        if (ctrl.start_time_.isZero())
        {
            r.sleep();
            continue;
        }
        ros::Time now = ros::Time::now();
        double t_rel = std::max(0.0, (now - ctrl.start_time_).toSec());
        auto time_1 = ros::Time::now();
        ctrl.update(t_rel);
        auto time_2 = ros::Time::now();
        double elapsed_ms = (time_2 - time_1).toSec() * 1000.0;
        ROS_INFO_STREAM_THROTTLE(1.0, "[" << robot_name << "] Update cycle time: " << elapsed_ms << " ms");
        r.sleep();
    }
    return 0;
}
