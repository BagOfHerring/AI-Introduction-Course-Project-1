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
#include <unordered_map>
#include <thread>
#include "Robot_classes/RobotDescription.h"
#include "utilities_function/dist_arm_3D_sphere.h"
#include "Robot_classes/CollisionSphere.h"
#include "utilities_function/ObstacleSeq.hpp"
// 新增：互臂距离
#include "utilities_function/dist_interarm_sphere.h"
// 新增：绑定带参回调
// #include <boost/bind.hpp>  // Replaced with std::bind/lambdas

// Helper: assign rclcpp::Duration to builtin_interfaces::msg::Duration
static void set_duration(builtin_interfaces::msg::Duration &d, double seconds) {
    int32_t sec = static_cast<int32_t>(seconds);
    uint32_t nsec = static_cast<uint32_t>((seconds - sec) * 1e9);
    d.sec = sec;
    d.nanosec = nsec;
}
static builtin_interfaces::msg::Duration make_duration(double seconds) {
    builtin_interfaces::msg::Duration d;
    set_duration(d, seconds);
    return d;
}

// 固定 7 关节（Panda）
static constexpr int N_JOINTS = 7;

class ReactiveSSAController
{
public:
    ReactiveSSAController(const std::string &robot_name, std::shared_ptr<rclcpp::Node> node)
        : robot_name_(robot_name), node_(node)
    {
        // 参数
        // 检测是否param存在，若无则使用默认值
        if (!node->has_parameter("robot_name"))
        {
            RCLCPP_WARN(node_->get_logger(), "Parameter 'robot_name' not found. Using default value 'panda01'.");
        }
        lock_horizon_ = node->declare_parameter("lock_horizon", 0.05); // 轨迹拼接冻结窗口(s)
        safety_on_ = node->declare_parameter("safety_control_ON", true);
        safe_margin_ = node->declare_parameter("safe_margin", 0.06); // 安全距离(m)
        k_safe_gain_ = node->declare_parameter("k_safe_gain", 10.0); // 安全约束增益
        update_rate_ = node->declare_parameter("buffer_rate", 100);  // 控制频率(Hz)
        // SSA 参数
        ssa_k1_ = node->declare_parameter("ssa_k1", 0.02);        // φ(x,ẋ) 中的 k1 系数
        vmax_coeff_ = node->declare_parameter("vmax_coeff", 0.3); // 速度缩放系数
        amax_coeff_ = node->declare_parameter("amax_coeff", 0.3); // 加速度缩放系数
        // 新增：平滑聚合超参数（<=0 关闭，>0 使用soft-min/log-sum-exp）
        smooth_alpha_ = node->declare_parameter("smooth_min_alpha", 20.0);
        // 新增：轨迹跟踪反馈参数与可选预投影
        track_kp_ = node->declare_parameter("track_kp", 0.0);
        track_kd_ = node->declare_parameter("track_kd", 0.3);
        preproject_feedback_ = node->declare_parameter("preproject_feedback", false);
        // 新增：分类型安全阈值（在聚合前减去）
        safety_thresh_obstacle_ = node->declare_parameter("safety_thresh_obstacle", 0.09);
        safety_thresh_ground_ = node->declare_parameter("safety_thresh_ground", 0.09);
        safety_thresh_rr_ = node->declare_parameter("safety_thresh_rr", 0.09);

        // 话题（单臂）
        std::string input_topic = "/" + robot_name_ + "/trajectory";
        std::string output_topic = "/" + robot_name_ + "/joint_impedance_cmd";
        std::string joint_states_topic = "/joint_states";
        // 改为使用 MarkerArray 类型的障碍物话题（与 cplus_dev 一致）
        std::string obstacle_topic = "/moving_obstacles";

        cmd_pub_ = node->create_publisher<trajectory_msgs::msg::JointTrajectoryPoint>(output_topic, 1);
        traj_sub_ = node->create_subscription<trajectory_msgs::msg::JointTrajectory>(input_topic, 1, std::bind(&ReactiveSSAController::trajCb, this, std::placeholders::_1));
        js_sub_ = node->create_subscription<sensor_msgs::msg::JointState>(joint_states_topic, 1, std::bind(&ReactiveSSAController::jointStatesCb, this, std::placeholders::_1));
        obstacle_sub_ = node->create_subscription<visualization_msgs::msg::MarkerArray>(obstacle_topic, 1, std::bind(&ReactiveSSAController::obstacleCb, this, std::placeholders::_1));
        // 新增：订阅上层提供的邻居列表（逗号分隔字符串）
        neighbors_sub_ = node->create_subscription<std_msgs::msg::String>("/" + robot_name_ + "/connected_agents", 1, std::bind(&ReactiveSSAController::neighborsCb, this, std::placeholders::_1));

        // 机器人底座与模型（仅单臂）
        panda_ = std::make_shared<RobotDescription>("Panda", 1, safe_margin_);
        InitRobot(*panda_, robot_name_, node);

        // 从 RobotDescription 读取关节速度/加速度上限，并应用系数缩放
        q_dot_max_ = vmax_coeff_ * panda_->dthetamax.col(0);
        a_max_vec_ = amax_coeff_ * panda_->ddthetamax.col(0);

        q_ = Eigen::VectorXd::Zero(N_JOINTS);
        qd_ = Eigen::VectorXd::Zero(N_JOINTS);
        set_duration(last_point_.time_from_start, 0.0);
        start_time_ = rclcpp::Time(0, 0, node_->get_clock()->get_clock_type());
    }

    // 轨迹时间对齐与合并（与buffer_controller同结构，线性插值切分点）
    void setTrajectory(const trajectory_msgs::msg::JointTrajectory &traj)
    {
        std::cout << robot_name_ << "setTrajectory called." << std::endl;
        if (traj.points.empty())
            return;
        rclcpp::Time now = node_->now();
        rclcpp::Time new_base = (traj.header.stamp.sec == 0 && traj.header.stamp.nanosec == 0) ? now : rclcpp::Time(traj.header.stamp);
        // std::cout << robot_name_ << "now: " << now << ", new_base: " << new_base << std::endl;
        // std::cout << robot_name_ << "Received trajectory with " << traj.points.size() << " points, starting at " << new_base << std::endl;
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
                { auto _dur = ta - now; x.time_from_start.sec = static_cast<int32_t>(_dur.seconds()); x.time_from_start.nanosec = static_cast<uint32_t>((_dur.seconds() - static_cast<int32_t>(_dur.seconds())) * 1e9); }
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
                    // cut_pt = linearInterp(traj_buffer_[i], traj_buffer_[i + 1], tau);
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
            { auto _d = rclcpp::Duration(cut_pt.time_from_start) - (now - start_time_); cut_pt.time_from_start.sec = static_cast<int32_t>(_d.seconds()); cut_pt.time_from_start.nanosec = static_cast<uint32_t>((_d.seconds() - static_cast<int32_t>(_d.seconds())) * 1e9); }
            merged.push_back(cut_pt);
        }

        for (const auto &p : traj.points)
        {
            rclcpp::Time ta = absNew(p);
            if (ta > cutoff_abs && ta > now)
            {
                auto x = p;
                { auto _dur = ta - now; x.time_from_start.sec = static_cast<int32_t>(_dur.seconds()); x.time_from_start.nanosec = static_cast<uint32_t>((_dur.seconds() - static_cast<int32_t>(_dur.seconds())) * 1e9); }
                merged.push_back(x);
            }
        }
        std::sort(merged.begin(), merged.end(), [](const auto &a, const auto &b)
                  { return rclcpp::Duration(a.time_from_start).seconds() < rclcpp::Duration(b.time_from_start).seconds(); });
        traj_buffer_.swap(merged);
        start_time_ = now;
    }

    // 主循环更新：名义插值 + SSA加速度投影
    void update(double t, double dt)
    {
        if (traj_buffer_.empty())
            return;
        size_t idx = traj_buffer_.size();
        for (size_t i = 1; i < traj_buffer_.size(); ++i)
        {
            if (rclcpp::Duration(traj_buffer_[i].time_from_start).seconds() > t)
            {
                idx = i - 1;
                break;
            }
        }
        // std::cout << "Update at t=" << t << " s, using segment index " << idx << std::endl;
        trajectory_msgs::msg::JointTrajectoryPoint pt_nom;
        if (idx >= traj_buffer_.size() - 1)
        {
            pt_nom = traj_buffer_.back();
            set_duration(pt_nom.time_from_start, t);
        }
        else
        {
            const auto &p0 = traj_buffer_[idx], &p1 = traj_buffer_[idx + 1];
            double t0 = rclcpp::Duration(p0.time_from_start).seconds(), t1 = rclcpp::Duration(p1.time_from_start).seconds();
            double tau = (t - t0) / std::max(1e-9, (t1 - t0));
            // pt_nom = linearInterp(p0, p1, tau);
            pt_nom = cubicHermiteInterp(p0, p1, tau, t1 - t0);
            set_duration(pt_nom.time_from_start, t);
        }
        bool need_safe = false;
        double distance = 1e3;
        Eigen::VectorXd grad = Eigen::VectorXd::Zero(N_JOINTS);
        if (safety_on_)
        {
            grad = calcObstacleGrad(distance);
            need_safe = std::isfinite(distance) && (distance <= safe_margin_);
        }
        // std::cout << "t.sec" << t << "pt_nom.vel: " << (pt_nom.velocities.empty() ? 0.0 : pt_nom.velocities[0]) << std::endl;
        // 展示靠速度积分得到的位置和pt_nom位置的差值

        // 当前速度（来自传感器），名义速度与名义加速度
        Eigen::VectorXd v_curr(N_JOINTS);
        for (int j = 0; j < N_JOINTS; ++j)
            v_curr[j] = qd_(j);

        // 读取 q_nom 与 qd_nom
        Eigen::VectorXd q_nom(N_JOINTS);
        for (int j = 0; j < N_JOINTS; ++j)
            q_nom[j] = pt_nom.positions[j];
        Eigen::VectorXd qd_nom(N_JOINTS);
        if (!pt_nom.velocities.empty() && pt_nom.velocities.size() == (size_t)N_JOINTS)
            for (int j = 0; j < N_JOINTS; ++j)
                qd_nom[j] = pt_nom.velocities[j];
        else
            qd_nom = finiteDiffVelocityAround(t);

        // 轨迹跟踪反馈（前馈 + PD），可选在安全子空间预投影
        Eigen::VectorXd v_fb = Eigen::VectorXd::Zero(N_JOINTS);
        if (track_kp_ > 0.0 || track_kd_ > 0.0)
        {
            v_fb = track_kp_ * (q_nom - q_); // just need position feedback
            if (preproject_feedback_ && need_safe)
            {
                Eigen::VectorXd grad_phi = -grad; // ∂φ/∂x
                double dn = grad_phi.squaredNorm();
                if (dn > 1e-12)
                {
                    v_fb -= (grad_phi.dot(v_fb) / dn) * grad_phi; // 不影响最后结果，ssa本身就是投影
                }
            }
        }
        Eigen::VectorXd v_nom = qd_nom + v_fb;

        // 安全：SSA 速度投影或直接通过
        Eigen::VectorXd v_cmd = need_safe ? velocitySSA(v_nom, k_safe_gain_) : v_nom;
        Eigen::VectorXd v_next = limitVel(v_cmd, q_dot_max_);
        Eigen::VectorXd q_next(N_JOINTS);
        for (int j = 0; j < N_JOINTS; ++j)
        {
            // Keep the outgoing command continuous even when safety is inactive.
            // Jumping directly to q_nom after each replan can exceed the
            // downstream controller's acceptance window and show up as twitching.
            q_next[j] = q_(j) + v_next[j] * dt;
        }
        // std::cout << "delat_q: " << (q_nom - q_next).transpose() << std::endl;
        trajectory_msgs::msg::JointTrajectoryPoint pt_safe;
        pt_safe.positions.resize(N_JOINTS);
        pt_safe.velocities.resize(N_JOINTS);
        for (int j = 0; j < N_JOINTS; ++j)
        {
            pt_safe.positions[j] = q_next[j];
            pt_safe.velocities[j] = v_next[j];
        }
        set_duration(pt_safe.time_from_start, t);
        publish(pt_safe);
        last_point_ = pt_safe;
    }

    rclcpp::Time getStartTime() const { return start_time_; }
    int getRate() const { return update_rate_; }

private:
    // 线性插值
    static trajectory_msgs::msg::JointTrajectoryPoint linearInterp(const trajectory_msgs::msg::JointTrajectoryPoint &p0, const trajectory_msgs::msg::JointTrajectoryPoint &p1, double tau)
    {
        trajectory_msgs::msg::JointTrajectoryPoint p = p0;
        p.positions.resize(p0.positions.size());
        for (size_t j = 0; j < p0.positions.size(); ++j)
            p.positions[j] = p0.positions[j] + tau * (p1.positions[j] - p0.positions[j]);
        if (!p0.velocities.empty() && p0.velocities.size() == p1.velocities.size())
        {
            p.velocities.resize(p0.velocities.size());
            for (size_t j = 0; j < p0.velocities.size(); ++j)
                p.velocities[j] = p0.velocities[j] + tau * (p1.velocities[j] - p0.velocities[j]);
        }
        else
        {
            p.velocities.resize(p.positions.size());
            double dt = std::max(1e-9, rclcpp::Duration(p1.time_from_start).seconds() - rclcpp::Duration(p0.time_from_start).seconds());
            for (size_t j = 0; j < p.positions.size(); ++j)
                p.velocities[j] = (p1.positions[j] - p0.positions[j]) / dt;
        }
        return p;
    }

    // 三次 Hermite 插值
    static trajectory_msgs::msg::JointTrajectoryPoint cubicHermiteInterp(const trajectory_msgs::msg::JointTrajectoryPoint &pt0, const trajectory_msgs::msg::JointTrajectoryPoint &pt1, double tau, double dt)
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

    // 名义速度估计：用t附近的缓冲点差分
    Eigen::VectorXd finiteDiffVelocityAround(double t_now) const
    {
        if (traj_buffer_.size() < 2)
            return Eigen::VectorXd::Zero(N_JOINTS);
        const trajectory_msgs::msg::JointTrajectoryPoint *L = nullptr, *R = nullptr;
        for (size_t i = 1; i < traj_buffer_.size(); ++i)
        {
            if (rclcpp::Duration(traj_buffer_[i].time_from_start).seconds() >= t_now)
            {
                L = &traj_buffer_[i - 1];
                R = &traj_buffer_[i];
                break;
            }
        }
        if (!L)
        {
            L = &traj_buffer_[traj_buffer_.size() - 2];
            R = &traj_buffer_.back();
        }
        double dt = std::max(1e-6, rclcpp::Duration(R->time_from_start).seconds() - rclcpp::Duration(L->time_from_start).seconds());
        Eigen::VectorXd v(N_JOINTS);
        for (int j = 0; j < N_JOINTS; ++j)
            v[j] = (R->positions[j] - L->positions[j]) / dt;
        return v;
    }

    void publish(const trajectory_msgs::msg::JointTrajectoryPoint &pt) { cmd_pub_->publish(pt); }

    // 机器人/障碍工具
    static void InitRobot(RobotDescription &rb, const std::string &arm_id, std::shared_ptr<rclcpp::Node> node)
    {
        // 从全局参数服务器读取：/robots/<name>/base_xyz 与 /robots/<name>/base_rpy
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

    // 计算到最近障碍的距离梯度（扩展：环境障碍+地面+互臂），返回对应的∂D/∂q
    Eigen::VectorXd calcObstacleGrad(double &distance) const
    {
        Eigen::VectorXd grad_best = Eigen::VectorXd::Zero(N_JOINTS);
        distance = std::numeric_limits<double>::infinity();
        if (!panda_)
            return grad_best;

        // 收集候选项（仅对自身变量的梯度）
        struct Term
        {
            double D;   // 真实距离
            double tau; // 对应类型的阈值
            Eigen::VectorXd g;
        };
        std::vector<Term> terms;
        terms.reserve(1 + 1 + others_.size());

        // 1) 环境球障碍（使用已有最近障碍）
        if (!obstacles_.empty())
        {
            auto dist_res = dist_arm_3D_sphere(q_, *panda_, obstacles_);
            if (std::isfinite(dist_res.min_dist))
            {
                Eigen::Vector3d vec = dist_res.robot_point - dist_res.obs_point;
                double n = vec.norm();
                if (n > 1e-12)
                {
                    Eigen::Vector3d dir = vec / n; // 从障碍指向机器人
                    Eigen::MatrixXd J6 = panda_->getJacobian_world_index(q_, dist_res.min_idx);
                    Eigen::MatrixXd Jpos = J6.bottomRows(3);
                    Eigen::VectorXd g = dir.transpose() * Jpos;
                    terms.push_back({dist_res.min_dist, safety_thresh_obstacle_, g});
                }
            }
        }

        // 2) 地面障碍（z=0 平面）：D = cz - r
        {
            double best_Dg = std::numeric_limits<double>::infinity();
            Eigen::VectorXd best_g = Eigen::VectorXd::Zero(N_JOINTS);
            auto p_list = panda_->getCollisionSphere(q_);
            auto r_list = panda_->sphere_r_list;
            // 忽视前三个连杆的碰地约束
            for (size_t j = 3; j < p_list.size(); ++j)
            {
                for (int k = 0; k < p_list[j].cols(); ++k)
                {
                    double cz = p_list[j].col(k).z();
                    double r = r_list[j](k);
                    double Dg = cz - r; // 距地面余隙
                    if (Dg < best_Dg)
                    {
                        best_Dg = Dg;
                        Eigen::MatrixXd J6 = panda_->getJacobian_world_index(q_, {static_cast<int>(j) + 1, k + 1});
                        Eigen::MatrixXd Jpos = J6.bottomRows(3);
                        best_g = Jpos.row(2).transpose(); // ∂(cz)/∂q
                    }
                }
            }
            if (std::isfinite(best_Dg))
            {
                terms.push_back({best_Dg, safety_thresh_ground_, best_g});
            }
        }

        // 3) 其他已连接机器人（互臂碰撞）
        for (const auto &kv : others_)
        {
            const auto &name = kv.first;
            const auto &other = kv.second;
            if (!other.model || !other.has_state)
                continue;
            auto inter = dist_interarm_sphere(q_, other.q, *panda_, *other.model);
            if (!std::isfinite(inter.min_dist))
                continue;
            // 梯度方向：从对方最近点指向自身最近点
            Eigen::Vector3d vec = inter.robot1_point - inter.robot2_point;
            double n = vec.norm();
            if (n < 1e-12)
                continue;
            Eigen::Vector3d dir = vec / n;
            int link1 = std::get<0>(inter.min_idx);
            int sph1 = std::get<1>(inter.min_idx);
            Eigen::MatrixXd J6 = panda_->getJacobian_world_index(q_, {link1, sph1});
            Eigen::MatrixXd Jpos = J6.bottomRows(3);
            Eigen::VectorXd g = dir.transpose() * Jpos;
            terms.push_back({inter.min_dist, safety_thresh_rr_, g});
        }

        // 选择/聚合
        if (terms.empty())
            return grad_best;

        if (smooth_alpha_ > 0.0)
        {
            // log-sum-exp 近似 min：对 (D_i - tau_i) 聚合
            double max_w = -std::numeric_limits<double>::infinity();
            std::vector<double> logw(terms.size());
            for (size_t i = 0; i < terms.size(); ++i)
            {
                double Dadj = terms[i].D - terms[i].tau;
                logw[i] = -smooth_alpha_ * Dadj;
                if (logw[i] > max_w)
                    max_w = logw[i];
            }
            double Z = 0.0;
            for (double lw : logw)
                Z += std::exp(lw - max_w);
            Eigen::VectorXd g = Eigen::VectorXd::Zero(N_JOINTS);
            double tau_bar = 0.0;    // Σ w_i tau_i
            double D_bar_true = 0.0; // Σ w_i D_i （用于恢复真实距离的近似）
            for (size_t i = 0; i < terms.size(); ++i)
            {
                double wi = std::exp(logw[i] - max_w) / std::max(1e-12, Z); // softmax 权重
                g += wi * terms[i].g;                                       // ∇D ≈ Σ w_i ∇D_i
                tau_bar += wi * terms[i].tau;
                D_bar_true += wi * terms[i].D;
            }
            // 软最小的值（在阈值空间）
            double D_soft_adj = -(1.0 / smooth_alpha_) * (max_w + std::log(std::max(1e-12, Z)));
            // 恢复为真实距离的软近似：两种任选，这里选择权重和（更贴近真实项）
            // double D_soft_true = D_soft_adj + tau_bar;
            double D_soft_true = D_bar_true;
            distance = D_soft_true;
            return g;
        }
        else
        {
            // 使用 (D_i - tau_i) 的最小项来选取梯度，但返回真实 D_i
            size_t imin = 0;
            double Dmin_adj = terms[0].D - terms[0].tau;
            for (size_t i = 1; i < terms.size(); ++i)
            {
                double Dadj = terms[i].D - terms[i].tau;
                if (Dadj < Dmin_adj)
                {
                    Dmin_adj = Dadj;
                    imin = i;
                }
            }
            distance = terms[imin].D; // 恢复真实最小值
            return terms[imin].g;
        }
    }

    // 新增：在给定关节位置 q_eval 处计算距离梯度（用于有限差分）
    Eigen::VectorXd calcObstacleGradAt(const Eigen::VectorXd &q_eval, double &distance) const
    {
        Eigen::VectorXd grad_best = Eigen::VectorXd::Zero(N_JOINTS);
        distance = std::numeric_limits<double>::infinity();
        if (!panda_)
            return grad_best;

        struct Term
        {
            double D;
            double tau;
            Eigen::VectorXd g;
        };
        std::vector<Term> terms;
        terms.reserve(1 + 1 + others_.size());

        // 环境球障碍
        if (!obstacles_.empty())
        {
            auto dist_res = dist_arm_3D_sphere(q_eval, *panda_, obstacles_);
            if (std::isfinite(dist_res.min_dist))
            {
                Eigen::Vector3d vec = dist_res.robot_point - dist_res.obs_point;
                double n = vec.norm();
                if (n > 1e-12)
                {
                    Eigen::Vector3d dir = vec / n;
                    Eigen::MatrixXd J6 = panda_->getJacobian_world_index(q_eval, dist_res.min_idx);
                    Eigen::MatrixXd Jpos = J6.bottomRows(3);
                    Eigen::VectorXd g = dir.transpose() * Jpos;
                    terms.push_back({dist_res.min_dist, safety_thresh_obstacle_, g});
                }
            }
        }

        // 地面障碍 z=0
        {
            double best_Dg = std::numeric_limits<double>::infinity();
            Eigen::VectorXd best_g = Eigen::VectorXd::Zero(N_JOINTS);
            auto p_list = panda_->getCollisionSphere(q_eval);
            auto r_list = panda_->sphere_r_list;
            // 忽视前三个连杆
            for (size_t j = 3; j < p_list.size(); ++j)
            {
                for (int k = 0; k < p_list[j].cols(); ++k)
                {
                    double cz = p_list[j].col(k).z();
                    double r = r_list[j](k);
                    double Dg = cz - r;
                    if (Dg < best_Dg)
                    {
                        best_Dg = Dg;
                        Eigen::MatrixXd J6 = panda_->getJacobian_world_index(q_eval, {static_cast<int>(j) + 1, k + 1});
                        Eigen::MatrixXd Jpos = J6.bottomRows(3);
                        best_g = Jpos.row(2).transpose();
                    }
                }
            }
            if (std::isfinite(best_Dg))
            {
                terms.push_back({best_Dg, safety_thresh_ground_, best_g});
            }
        }

        // 互臂碰撞
        for (const auto &kv : others_)
        {
            const auto &other = kv.second;
            if (!other.model || !other.has_state)
                continue;
            auto inter = dist_interarm_sphere(q_eval, other.q, *panda_, *other.model);
            if (!std::isfinite(inter.min_dist))
                continue;
            Eigen::Vector3d vec = inter.robot1_point - inter.robot2_point;
            double n = vec.norm();
            if (n < 1e-12)
                continue;
            Eigen::Vector3d dir = vec / n;
            int link1 = std::get<0>(inter.min_idx);
            int sph1 = std::get<1>(inter.min_idx);
            Eigen::MatrixXd J6 = panda_->getJacobian_world_index(q_eval, {link1, sph1});
            Eigen::MatrixXd Jpos = J6.bottomRows(3);
            Eigen::VectorXd g = dir.transpose() * Jpos;
            terms.push_back({inter.min_dist, safety_thresh_rr_, g});
        }

        if (terms.empty())
            return grad_best;

        if (smooth_alpha_ > 0.0)
        {
            double max_w = -std::numeric_limits<double>::infinity();
            std::vector<double> logw(terms.size());
            for (size_t i = 0; i < terms.size(); ++i)
            {
                double Dadj = terms[i].D - terms[i].tau;
                logw[i] = -smooth_alpha_ * Dadj;
                if (logw[i] > max_w)
                    max_w = logw[i];
            }
            double Z = 0.0;
            for (double lw : logw)
                Z += std::exp(lw - max_w);
            Eigen::VectorXd g = Eigen::VectorXd::Zero(N_JOINTS);
            double D_bar_true = 0.0;
            for (size_t i = 0; i < terms.size(); ++i)
            {
                double wi = std::exp(logw[i] - max_w) / std::max(1e-12, Z);
                g += wi * terms[i].g;
                D_bar_true += wi * terms[i].D;
            }
            double D_soft_true = D_bar_true;
            distance = D_soft_true;
            return g;
        }
        else
        {
            size_t imin = 0;
            double Dmin_adj = terms[0].D - terms[0].tau;
            for (size_t i = 1; i < terms.size(); ++i)
            {
                double Dadj = terms[i].D - terms[i].tau;
                if (Dadj < Dmin_adj)
                {
                    Dmin_adj = Dadj;
                    imin = i;
                }
            }
            distance = terms[imin].D;
            return terms[imin].g;
        }
    }

    // 新增：邻居管理与回调
    struct OtherRobot
    {
        std::string name;
        Eigen::VectorXd q = Eigen::VectorXd::Zero(N_JOINTS);
        std::shared_ptr<RobotDescription> model;
        bool has_state = false;
    };

    void neighborsCb(const std_msgs::msg::String::ConstSharedPtr msg)
    {
        if (!msg)
            return;
        std::vector<std::string> names;
        std::stringstream ss(msg->data);
        std::string item;
        while (std::getline(ss, item, ','))
        {
            if (!item.empty())
            {
                // 去空格
                item.erase(0, item.find_first_not_of(' '));
                item.erase(item.find_last_not_of(' ') + 1);
                if (!item.empty() && item != robot_name_)
                    names.push_back(item);
            }
        }
        updateNeighbors(names);
    }

    void updateNeighbors(const std::vector<std::string> &names)
    {
        // 移除不存在的
        for (auto it = others_.begin(); it != others_.end();)
        {
            if (std::find(names.begin(), names.end(), it->first) == names.end())
                it = others_.erase(it);
            else
                ++it;
        }
        // 新增或已存在的保持
        for (const auto &n : names)
        {
            if (n == robot_name_)
                continue;
            auto it = others_.find(n);
            if (it == others_.end())
            {
                OtherRobot o;
                o.name = n;
                o.model = std::make_shared<RobotDescription>("Panda", 1, safe_margin_);
                InitRobot(*o.model, n, node_);
                others_.emplace(n, std::move(o));
            }
        }
    }

    bool extractRobotState(
        const sensor_msgs::msg::JointState &msg,
        const std::unordered_map<std::string, size_t> &name_to_index,
        const std::string &robot_name,
        Eigen::VectorXd &q_out,
        Eigen::VectorXd *qd_out = nullptr) const
    {
        Eigen::VectorXd q_tmp = Eigen::VectorXd::Zero(N_JOINTS);
        Eigen::VectorXd qd_tmp = Eigen::VectorXd::Zero(N_JOINTS);

        for (int j = 0; j < N_JOINTS; ++j)
        {
            std::string joint_name = robot_name + std::string("_joint") + std::to_string(j + 1);
            auto it = name_to_index.find(joint_name);
            if (it == name_to_index.end())
                return false;
            const size_t index = it->second;
            if (index >= msg.position.size())
                return false;
            q_tmp(j) = msg.position[index];
            if (qd_out != nullptr)
            {
                qd_tmp(j) = (index < msg.velocity.size()) ? msg.velocity[index] : 0.0;
            }
        }

        q_out = q_tmp;
        if (qd_out != nullptr)
            *qd_out = qd_tmp;
        return true;
    }

    // 新增：Velocity-SSA 投影
    // v_nom: 名义关节速度；ks: 安全收敛增益
    // 返回修正后的速度（未施加饱和/限幅）
    Eigen::VectorXd velocitySSA(const Eigen::VectorXd &v_nom, double ks) const
    {
        if (!safety_on_)
            return v_nom;
        double D = 0.0;
        Eigen::VectorXd gradD = calcObstacleGrad(D); // ∂D/∂q
        if (!std::isfinite(D))
            return v_nom;
        double phi = safe_margin_ - D; // φ0(x)
        if (phi < 0.0)
            return v_nom;                  // 安全，直接通过
        Eigen::VectorXd grad_phi = -gradD; // ∂φ0/∂x = -∂D/∂x
        double denom = grad_phi.squaredNorm();
        if (denom < 1e-12)
            return v_nom;
        double num = ks * phi + grad_phi.dot(v_nom);
        Eigen::VectorXd v_cmd = v_nom - (num / denom) * grad_phi;
        return v_cmd;
    }

    // 新增：Acceleration-SSA 投影（含有限差分近似 Hessian*ẋ 项）
    // a_nom: 名义关节加速度；v_curr: 当前关节速度；ks: 安全收敛增益；k1: SSA 参数（≥0）
    // 返回修正后的加速度（未施加饱和/限幅）
    Eigen::VectorXd accelerationSSA(const Eigen::VectorXd &a_nom, const Eigen::VectorXd &v_curr, double ks, double k1) const
    {
        if (!safety_on_)
            return a_nom;
        // 基础量
        double D = 0.0;
        Eigen::VectorXd gradD = const_cast<ReactiveSSAController *>(this)->calcObstacleGrad(D); // ∂D/∂q at q_
        if (!std::isfinite(D))
            return a_nom;
        Eigen::VectorXd grad_phi0 = -gradD;                           // ∂φ0/∂x = -∂D/∂x
        double Ddot = gradD.dot(v_curr);                              // Ḋ = ∂D/∂x^T ẋ
        double phi = safe_margin_ * safe_margin_ - D * D - k1 * Ddot; // φ(x,ẋ)
        if (phi < 0.0)
            return a_nom; // 安全，直接通过

        // 有限差分近似 Hessian(φ0)*v ≈ (∇φ0(q+εv) - ∇φ0(q-εv)) / (2ε)
        const double eps = 1e-6; // 建议量级在 sqrt(machine_epsilon)，1e-4~1e-6 之间
        // 正向点
        Eigen::VectorXd q_plus = q_ + eps * v_curr;
        double D_plus = 0.0;
        Eigen::VectorXd gradD_plus = calcObstacleGradAt(q_plus, D_plus);
        Eigen::VectorXd grad_phi0_plus = -gradD_plus;

        // 反向点
        Eigen::VectorXd q_minus = q_ - eps * v_curr;
        double D_minus = 0.0;
        Eigen::VectorXd gradD_minus = calcObstacleGradAt(q_minus, D_minus);
        Eigen::VectorXd grad_phi0_minus = -gradD_minus;

        // 中心差分近似 Hessian* v
        Eigen::VectorXd Hphi0_v = (grad_phi0_plus - grad_phi0_minus) / (2.0 * eps);

        // ∇x φ 与 ∇_{ẋ} φ
        Eigen::VectorXd grad_x_phi = 2.0 * D * grad_phi0 + k1 * Hphi0_v;
        Eigen::VectorXd grad_v_phi = k1 * grad_phi0;
        double denom = grad_v_phi.squaredNorm();
        if (denom < 1e-12)
            return a_nom;

        double num = ks * phi + grad_v_phi.dot(a_nom) + grad_x_phi.dot(v_curr);
        Eigen::VectorXd a_cmd = a_nom - (num / denom) * grad_v_phi;
        return a_cmd;
    }

    static Eigen::VectorXd limitVel(const Eigen::VectorXd &v, const Eigen::VectorXd &vmax)
    {
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
    static Eigen::VectorXd limitAcc(const Eigen::VectorXd &a, const Eigen::VectorXd &amax)
    {
        Eigen::VectorXd out = a;
        for (int i = 0; i < N_JOINTS; ++i)
        {
            double lim = std::max(0.0, amax(i));
            if (out(i) > lim)
                out(i) = lim;
            else if (out(i) < -lim)
                out(i) = -lim;
        }
        return out;
    }

    // 回调
    void trajCb(const trajectory_msgs::msg::JointTrajectory::ConstSharedPtr msg) { setTrajectory(*msg); }
    void jointStatesCb(const sensor_msgs::msg::JointState::ConstSharedPtr msg)
    {
        if (!msg)
            return;

        std::unordered_map<std::string, size_t> name_to_index;
        name_to_index.reserve(msg->name.size());
        for (size_t i = 0; i < msg->name.size(); ++i)
            name_to_index.emplace(msg->name[i], i);

        extractRobotState(*msg, name_to_index, robot_name_, q_, &qd_);

        for (auto &[name, other] : others_)
        {
            other.has_state = extractRobotState(*msg, name_to_index, name, other.q, nullptr);
        }
    }

    void obstacleCb(const visualization_msgs::msg::MarkerArray::ConstSharedPtr msg)
    {
        obstacles_.clear();
        if (!msg || msg->markers.empty())
        {
            obstacle_exist_ = false;
            return;
        }
        // 仅解析球形障碍
        for (const auto &m : msg->markers)
        {
            if (m.type != visualization_msgs::msg::Marker::SPHERE)
                continue;
            ObstacleSeq o;
            Eigen::Vector3d c(m.pose.position.x, m.pose.position.y, m.pose.position.z);
            o.p.col(0) = c;
            o.p.col(1) = c;
            // 半径由 scale.x/2（假设各向同性）
            o.r = m.scale.x * 0.5;
            obstacles_.push_back(o);
        }
        obstacle_exist_ = !obstacles_.empty();
    }

private:
    std::string robot_name_;
    std::shared_ptr<rclcpp::Node> node_;
    rclcpp::Publisher<trajectory_msgs::msg::JointTrajectoryPoint>::SharedPtr cmd_pub_;
    rclcpp::SubscriptionBase::SharedPtr traj_sub_, js_sub_, obstacle_sub_;
    // 新增：邻居列表订阅
    rclcpp::SubscriptionBase::SharedPtr neighbors_sub_;

    std::vector<trajectory_msgs::msg::JointTrajectoryPoint> traj_buffer_;
    trajectory_msgs::msg::JointTrajectoryPoint last_point_;
    rclcpp::Time start_time_;

    double lock_horizon_{0.1};
    bool safety_on_{true};
    double safe_margin_{0.06};
    double k_safe_gain_{10.0};
    int update_rate_{100};

    // SSA/限幅参数
    double ssa_k1_{0.0};
    double vmax_coeff_{0.85};
    double amax_coeff_{0.85};
    // 新增：平滑聚合强度
    double smooth_alpha_{0.0};
    // 新增：轨迹跟踪反馈参数
    double track_kp_{0.0};
    double track_kd_{0.0};
    bool preproject_feedback_{false};
    // 新增：分类型安全阈值
    double safety_thresh_obstacle_{0.0};
    double safety_thresh_ground_{0.0};
    double safety_thresh_rr_{0.0};

    Eigen::VectorXd q_, qd_;
    Eigen::VectorXd q_dot_max_; // 来自 RobotDescription 的正向最大速度列，并经缩放
    Eigen::VectorXd a_max_vec_; // 来自 RobotDescription 的正向最大加速度列，并经缩放

    std::shared_ptr<RobotDescription> panda_;
    bool obstacle_exist_{false};
    std::vector<ObstacleSeq> obstacles_;

    // 新增：其他机器人
    std::map<std::string, OtherRobot> others_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("ssa_controller");
    node->declare_parameter<std::string>("robot_name", "panda01");
    std::string robot_name = node->get_parameter("robot_name").as_string();
    auto ctl = std::make_shared<ReactiveSSAController>(robot_name, node);
    const auto sleep_period = std::chrono::duration<double>(1.0 / std::max(1, ctl->getRate()));
    bool first_plan = true;
    while (rclcpp::ok())
    {
        try
        {
            if (first_plan)
            {
                rclcpp::spin_some(node);
                std::this_thread::sleep_for(std::chrono::milliseconds(100)); // 等待ROS参数等更新
                first_plan = false;
            }
            double t = (node->now() - ctl->getStartTime()).seconds();
            double dt = 1.0 / std::max(1, ctl->getRate());

            // 实际速度在0.01-0.02ms,最大0.2ms
            ctl->update(t, dt);

            rclcpp::spin_some(node);
        }
        catch (const rclcpp::exceptions::RCLError &e)
        {
            RCLCPP_INFO(
                node->get_logger(),
                "SSA controller for %s is exiting during ROS shutdown: %s",
                robot_name.c_str(),
                e.what());
            break;
        }

        std::this_thread::sleep_for(sleep_period);
    }
    return 0;
}
