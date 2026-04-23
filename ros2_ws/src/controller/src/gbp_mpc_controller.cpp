#include <rclcpp/rclcpp.hpp>
#include <trajectory_msgs/msg/joint_trajectory.hpp>
#include <trajectory_msgs/msg/joint_trajectory_point.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <std_msgs/msg/bool.hpp>
#include <std_msgs/msg/string.hpp>
#include <algorithm>
#include <vector>
#include <cmath>
#include <memory>
#include <functional>
#include <Eigen/Dense>
#include <sstream>
#include <iterator>
#include <visualization_msgs/msg/marker_array.hpp>
#include <limits>
#include <ament_index_cpp/get_package_share_directory.hpp>
#include <string>
#include <map>
#include "Robot_classes/RobotDescription.h"
#include "utilities_function/dist_arm_3D_sphere.h"
#include "Robot_classes/CollisionSphere.h"
#include "utilities_function/ObstacleSeq.hpp"
#include "utilities_function/dist_interarm_sphere.h"
// #include <boost/bind.hpp>

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

// Helper: assign rclcpp::Duration to builtin_interfaces::msg::Duration
static inline void set_duration(builtin_interfaces::msg::Duration &d, double seconds) {
    int32_t sec = static_cast<int32_t>(seconds);
    uint32_t nsec = static_cast<uint32_t>((seconds - sec) * 1e9);
    d.sec = sec;
    d.nanosec = nsec;
}

// 考虑到可能的头文件包含顺序或重复定义问题
// 下面的类都是基于已有的 Cpp+ 逻辑进行包装

static constexpr int N_JOINTS = 7;

class GBPMpcController
{
public:
    rclcpp::Time start_time_;
    GBPMpcController(const std::string &robot_name, std::shared_ptr<rclcpp::Node> node)
        : robot_name_(robot_name), node_(node)
    {

        if (!node->has_parameter("robot_name"))
        {
            RCLCPP_WARN(node_->get_logger(), "Parameter 'robot_name' not found. Using default value 'panda01'.");
        }

        node->declare_parameter("horizon_steps", 5); node->get_parameter("horizon_steps", horizon_steps_); // 固定视野为5~10
        node->declare_parameter("lock_horizon", 0.05); node->get_parameter("lock_horizon", lock_horizon_);
        node->declare_parameter("safe_margin", 0.1); node->get_parameter("safe_margin", safe_margin_);
        node->declare_parameter("buffer_rate", 1000); node->get_parameter("buffer_rate", update_rate_); // 1KHz
        dt_ = 1.0 / update_rate_;                        // 确保dt和update_rate一致
        node->declare_parameter("gbp_iters", 1); node->get_parameter("gbp_iters", iter_steps_);       // 我们要在1KHz跑，迭代不宜太多
        node->declare_parameter("damp_value", 0.0); node->get_parameter("damp_value", damp_value_);

        // GBP Params
        node->declare_parameter("obstacle_precision", 10000.0); node->get_parameter("obstacle_precision", obstacle_precision_);
        node->declare_parameter("interarm_precision", 10000.0); node->get_parameter("interarm_precision", interarm_precision_);
        node->declare_parameter("start_position_precision", 5000.0); node->get_parameter("start_position_precision", start_pos_precision_);
        node->declare_parameter("start_velocity_precision", 2000.0); node->get_parameter("start_velocity_precision", start_vel_precision_);
        node->declare_parameter("target_position_precision", 1000.0); node->get_parameter("target_position_precision", target_pos_precision_);
        node->declare_parameter("target_velocity_precision", 1000.0); node->get_parameter("target_velocity_precision", target_vel_precision_);
        node->declare_parameter("state_precision", 500.0); node->get_parameter("state_precision", state_precision_);
        node->declare_parameter("state_safety", 1e-3); node->get_parameter("state_safety", state_safety_);
        node->declare_parameter("min_iter_relin", 1); node->get_parameter("min_iter_relin", min_iter_relin_);
        node->declare_parameter("relin_thre", 1e-5); node->get_parameter("relin_thre", relin_thre_);

        node->declare_parameter("is_ssa", true); node->get_parameter("is_ssa", is_ssa_);
        node->declare_parameter("ssa_ks", 20.0); node->get_parameter("ssa_ks", ssa_ks_);
        node->declare_parameter("z_precision_vel", 1000.0); node->get_parameter("z_precision_vel", z_precision_vel_);
        node->declare_parameter("smooth_alpha", 20.0); node->get_parameter("smooth_alpha", smooth_alpha_);

        node->declare_parameter("vmax_coeff", 0.3); node->get_parameter("vmax_coeff", vmax_coeff_);
        node->declare_parameter("amax_coeff", 0.3); node->get_parameter("amax_coeff", amax_coeff_);
        state_max_ = Eigen::VectorXd(2 * N_JOINTS);
        state_min_ = Eigen::VectorXd(2 * N_JOINTS);

        std::string input_topic = "/" + robot_name_ + "/trajectory";
        std::string output_topic = "/" + robot_name_ + "/joint_impedance_tracking_controller_velocity/equilibrium_config";
        std::string self_js = "/" + robot_name_ + "/joint_states";
        std::string obstacle_topic = "/moving_obstacles";
        std::string neighbors_topic = "/" + robot_name_ + "/connected_agents";

        cmd_pub_ = node->create_publisher<trajectory_msgs::msg::JointTrajectoryPoint>(output_topic, 1);
        traj_sub_ = node->create_subscription<trajectory_msgs::msg::JointTrajectory>(input_topic, 1, std::bind(&GBPMpcController::trajCb, this, std::placeholders::_1));
        js_sub_ = node->create_subscription<sensor_msgs::msg::JointState>(self_js, 1, std::bind(&GBPMpcController::selfJsCb, this, std::placeholders::_1));
        // neighbors_sub_ = nh_pub.subscribe(neighbors_topic, 1, &GBPMpcController::neighborsCb, this);

        // 初始化机器人
        RCLCPP_INFO_STREAM(node_->get_logger(), "[" << robot_name_ << "] Initializing Robot...");
        panda_ = std::make_shared<RobotDescription>("Panda", 1, safe_margin_);
        InitRobot(*panda_, robot_name_, node);
        RCLCPP_INFO_STREAM(node_->get_logger(), "[" << robot_name_ << "] Robot Initialized, thetamax shape: " << panda_->thetamax.rows() << "x" << panda_->thetamax.cols());

        state_max_.head(N_JOINTS) = panda_->thetamax.col(0);
        state_max_.tail(N_JOINTS) = vmax_coeff_ * panda_->dthetamax.col(0);
        state_min_.head(N_JOINTS) = panda_->thetamax.col(1);
        state_min_.tail(N_JOINTS) = vmax_coeff_ * panda_->dthetamax.col(1);

        q_ = Eigen::VectorXd::Zero(N_JOINTS);
        qd_ = Eigen::VectorXd::Zero(N_JOINTS);
        set_duration(last_point_.time_from_start, 0.0);
        start_time_ = rclcpp::Time(0, 0, node_->get_clock()->get_clock_type());

        omap_ = std::make_shared<ObstacleMap>(node);

        // 初始化固定GBP拓扑图
        RCLCPP_INFO_STREAM(node_->get_logger(), "[" << robot_name_ << "] Start initGraph...");
        initGraph(is_ssa_, ssa_ks_, z_precision_vel_, smooth_alpha_);
        RCLCPP_INFO_STREAM(node_->get_logger(), "[" << robot_name_ << "] GBPMpcController Init Complete!");
    }

    // 轨迹和时间相关的插值，同原来一样
    void setTrajectory(const trajectory_msgs::msg::JointTrajectory &traj)
    {
        if (traj.points.empty())
            return;
        rclcpp::Time now = node_->now();
        rclcpp::Time new_base = (traj.header.stamp.sec == 0 && traj.header.stamp.nanosec == 0) ? now : rclcpp::Time(traj.header.stamp);

        if (traj_buffer_.empty())
        {
            traj_buffer_ = traj.points;
            start_time_ = new_base;
            last_point_ = traj.points.front();
            set_duration(last_point_.time_from_start, 0.0);
            return;
        }

        rclcpp::Time cutoff_abs = std::max(now, start_time_ + rclcpp::Duration::from_seconds(lock_horizon_));
        double t_cut_rel_old = (cutoff_abs - start_time_).seconds();
        auto absOld = [&](const trajectory_msgs::msg::JointTrajectoryPoint &p)
        { return start_time_ + p.time_from_start; };
        auto absNew = [&](const trajectory_msgs::msg::JointTrajectoryPoint &p)
        { return new_base + p.time_from_start; };

        std::vector<trajectory_msgs::msg::JointTrajectoryPoint> merged;
        trajectory_msgs::msg::JointTrajectoryPoint now_pt = last_point_;
        set_duration(now_pt.time_from_start, 0.0);
        merged.push_back(now_pt);
        for (const auto &p : traj_buffer_)
        {
            rclcpp::Time ta = absOld(p);
            if (ta < cutoff_abs && ta > now)
            {
                auto x = p;
                { auto _dur = ta - now; set_duration(x.time_from_start, _dur.seconds()); }
                merged.push_back(x);
            }
        }

        trajectory_msgs::msg::JointTrajectoryPoint cut_pt;
        bool cut_ok = false;
        const double eps = 1e-9;
        for (const auto &p : traj_buffer_)
        {
            if (std::abs(rclcpp::Duration(p.time_from_start).seconds() - t_cut_rel_old) < eps)
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
                double t0 = rclcpp::Duration(traj_buffer_[i].time_from_start).seconds(), t1 = rclcpp::Duration(traj_buffer_[i + 1].time_from_start).seconds();
                if (t0 <= t_cut_rel_old && t_cut_rel_old <= t1 && t1 > t0)
                {
                    double tau = (t_cut_rel_old - t0) / (t1 - t0);
                    cut_pt = cubicHermiteInterp(traj_buffer_[i], traj_buffer_[i + 1], tau, t1 - t0);
                    set_duration(cut_pt.time_from_start, t_cut_rel_old);
                    cut_ok = true;
                    break;
                }
            }
        }
        if (!cut_ok && !traj_buffer_.empty())
        {
            const auto &f = traj_buffer_.front();
            const auto &l = traj_buffer_.back();
            cut_pt = (std::abs(rclcpp::Duration(f.time_from_start).seconds() - t_cut_rel_old) <= std::abs(rclcpp::Duration(l.time_from_start).seconds() - t_cut_rel_old)) ? f : l;
            set_duration(cut_pt.time_from_start, t_cut_rel_old);
            cut_ok = true;
        }
        if (cut_ok)
        {
            { auto _d = rclcpp::Duration(cut_pt.time_from_start) - ((now - start_time_)); set_duration(cut_pt.time_from_start, _d.seconds()); }
            merged.push_back(cut_pt);
        }

        for (const auto &p : traj.points)
        {
            rclcpp::Time ta = absNew(p);
            if (ta > cutoff_abs && ta > now)
            {
                auto x = p;
                { auto _dur = ta - now; set_duration(x.time_from_start, _dur.seconds()); }
                merged.push_back(x);
            }
        }
        std::sort(merged.begin(), merged.end(), [](const auto &a, const auto &b)
                  { return rclcpp::Duration(a.time_from_start).seconds() < rclcpp::Duration(b.time_from_start).seconds(); });
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

        trajectory_msgs::msg::JointTrajectoryPoint cmd_pt;
        cmd_pt.positions.resize(N_JOINTS);
        cmd_pt.velocities.resize(N_JOINTS);
        for (int j = 0; j < N_JOINTS; ++j)
        {
            cmd_pt.positions[j] = next_x(j);
            cmd_pt.velocities[j] = limitVel(next_x.segment(N_JOINTS, N_JOINTS), state_max_.tail(N_JOINTS))(j);
        }
        cmd_pub_->publish(cmd_pt);
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
        RCLCPP_INFO_STREAM(node_->get_logger(), "[" << robot_name_ << "] initGraph: Creating graph components...");
        graph_ = std::make_shared<FactorGraphRobot>();
        int dof = N_JOINTS * 2;
        vnodes_.resize(horizon_steps_ + 1);
        dyna_fnodes_.resize(horizon_steps_);
        obs_fnodes_.resize(horizon_steps_);
        path_fnodes_.resize(horizon_steps_);
        box_fnodes_.resize(horizon_steps_);

        // 1. 初始化变量节点 (VNode)，为每一步骤设置独立的维度名称
        RCLCPP_INFO_STREAM(node_->get_logger(), "[" << robot_name_ << "] initGraph: Building VNodes...");
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

        RCLCPP_INFO_STREAM(node_->get_logger(), "[" << robot_name_ << "] initGraph: Building FNodes...");
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
        RCLCPP_INFO_STREAM(node_->get_logger(), "[" << robot_name_ << "] initGraph: Done.");
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
            if (rclcpp::Duration(traj_buffer_[i].time_from_start).seconds() > tk)
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
        double t0 = rclcpp::Duration(p0.time_from_start).seconds();
        double t1 = rclcpp::Duration(p1.time_from_start).seconds();
        double tau = (tk - t0) / std::max(1e-9, t1 - t0);
        tau = std::max(0.0, std::min(1.0, tau));
        auto pnt = cubicHermiteInterp(p0, p1, tau, t1 - t0);
        pos = Eigen::Map<const Eigen::VectorXd>(pnt.positions.data(), N_JOINTS);
        vel = Eigen::Map<const Eigen::VectorXd>(pnt.velocities.data(), N_JOINTS);
    }

    trajectory_msgs::msg::JointTrajectoryPoint cubicHermiteInterp(const trajectory_msgs::msg::JointTrajectoryPoint &pt0, const trajectory_msgs::msg::JointTrajectoryPoint &pt1, double tau, double dt)
    {
        trajectory_msgs::msg::JointTrajectoryPoint pt = pt0;
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
        set_duration(pt.time_from_start, rclcpp::Duration(pt0.time_from_start).seconds() + tau * dt);
        return pt;
    }

    void trajCb(const trajectory_msgs::msg::JointTrajectory::ConstSharedPtr msg) { setTrajectory(*msg); }
    void selfJsCb(const sensor_msgs::msg::JointState::ConstSharedPtr msg)
    {
        Eigen::VectorXd curq = Eigen::VectorXd::Zero(N_JOINTS);
        Eigen::VectorXd curqd = Eigen::VectorXd::Zero(N_JOINTS);
        for (size_t i = 0; i < msg->name.size(); ++i)
        {
            std::string n = msg->name[i];
            int j = n.back() - '1'; // "..._joint1" -> 0
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
    // void obstacleCb(const visualization_msgs::msg::MarkerArray::ConstSharedPtr msg) {
    //     omap_->updateObstacles(*msg);
    // }

    struct OtherRobot
    {
        std::string name;
        // 仅订阅高频 joint_states
        rclcpp::SubscriptionBase::SharedPtr sub_js_raw;
        Eigen::VectorXd q = Eigen::VectorXd::Zero(N_JOINTS);
        Eigen::VectorXd qd = Eigen::VectorXd::Zero(N_JOINTS);
        std::shared_ptr<RobotDescription> model;
        bool has_state = false;
        std::vector<std::shared_ptr<RemoteVNode>> remote_vnodes;
        std::vector<std::shared_ptr<SSADistFNode>> interarm_fnode;
    };

    // void neighborsCb(const std_msgs::msg::String::ConstSharedPtr msg)
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
    //             RCLCPP_INFO_STREAM(node_->get_logger(), "[" << robot_name_ << "] Adding neighbor: " << n);
    //             // 新增机器人，创建模型和订阅
    //             OtherRobot o;
    //             o.name = n;
    //             o.model = std::make_shared<RobotDescription>("Panda", 1, safe_margin_);
    //             InitRobot(*o.model, n, nh);

    //             RCLCPP_INFO_STREAM(node_->get_logger(), "[" << robot_name_ << "] Subscribing to " << n << " joint_states");
    //             // 仅订阅 /name/joint_states
    //             std::string raw_topic = "/" + n + "/joint_states";
    //             o.sub_js_raw = nh.subscribe<sensor_msgs::msg::JointState>(raw_topic, 1, boost::bind(&GBPMpcController::otherJsCb, this, _1, n));

    //             RCLCPP_INFO_STREAM(node_->get_logger(), "[" << robot_name_ << "] Creating RemoteVNodes");
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

    //             RCLCPP_INFO_STREAM(node_->get_logger(), "[" << robot_name_ << "] Creating SSADistFNodes");
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
    //             RCLCPP_INFO_STREAM(node_->get_logger(), "[" << robot_name_ << "] Done adding neighbor: " << n);
    //         }
    //     }
    // }

    // void otherJsCb(const sensor_msgs::msg::JointState::ConstSharedPtr msg, const std::string &name)
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

    static void InitRobot(RobotDescription &rb, const std::string &arm_id, std::shared_ptr<rclcpp::Node> node)
    {
        std::vector<double> xyz, rpy;
        std::string p_xyz = "robots." + arm_id + ".base_xyz";
        std::string p_rpy = "robots." + arm_id + ".base_rpy";
        node->declare_parameter<std::vector<double>>(p_xyz, {0.0, 0.0, 0.0});
        node->get_parameter(p_xyz, xyz);
        if (xyz.size() != 3)
            xyz = {0.0, 0.0, 0.0};
        node->declare_parameter<std::vector<double>>(p_rpy, {0.0, 0.0, 0.0});
        node->get_parameter(p_rpy, rpy);
        if (rpy.size() != 3)
            rpy = {0.0, 0.0, 0.0};
        rb.set_base(Eigen::Vector3d(xyz[0], xyz[1], xyz[2]), Eigen::Vector3d(rpy[0], rpy[1], rpy[2]));
        std::string pkg_path = ament_index_cpp::get_package_share_directory("controller");
        rb.loadCollisionSphere(pkg_path + "/config/franka_sphere.yaml");
    }

    std::string robot_name_;
    std::shared_ptr<rclcpp::Node> node_;
    rclcpp::Publisher<trajectory_msgs::msg::JointTrajectoryPoint>::SharedPtr cmd_pub_;
    rclcpp::SubscriptionBase::SharedPtr traj_sub_, js_sub_, obstacle_sub_, neighbors_sub_;

    std::shared_ptr<RobotDescription> panda_;
    std::shared_ptr<ObstacleMap> omap_;
    std::vector<trajectory_msgs::msg::JointTrajectoryPoint> traj_buffer_;
    trajectory_msgs::msg::JointTrajectoryPoint last_point_;

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
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("controller_node");
    node->declare_parameter<std::string>("robot_name", "panda01");
    std::string robot_name = node->get_parameter("robot_name").as_string();

    GBPMpcController ctrl(robot_name, node);

    int rate = 1000;
    node->declare_parameter("buffer_rate", 500); node->get_parameter("buffer_rate", rate);
    rclcpp::Rate r(rate);
    std::cout << "GBPMpcController running with update rate: " << rate << " Hz" << std::endl;

    while (rclcpp::ok())
    {
        rclcpp::spin_some(node);
        if ((ctrl.start_time_.seconds() == 0.0 && ctrl.start_time_.nanoseconds() == 0))
        {
            r.sleep();
            continue;
        }
        rclcpp::Time now = node->now();
        double t_rel = std::max(0.0, (now - ctrl.start_time_).seconds());
        auto time_1 = node->now();
        ctrl.update(t_rel);
        auto time_2 = node->now();
        double elapsed_ms = (time_2 - time_1).seconds() * 1000.0;
        RCLCPP_INFO_THROTTLE(node->get_logger(), *node->get_clock(), 1000, "[%s] Update cycle time: %.2f ms", robot_name.c_str(), elapsed_ms);
        r.sleep();
    }
    return 0;
}
