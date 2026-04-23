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
// 新增：互臂距离
#include "utilities_function/dist_interarm_sphere.h"
// 新增：绑定带参回调
#include <boost/bind.hpp>

// 固定 7 关节（Panda）
static constexpr int N_JOINTS = 7;

class ReactiveSSAController
{
public:
    ReactiveSSAController(const std::string &robot_name, ros::NodeHandle &nh_pub)
        : robot_name_(robot_name), nh_(nh_pub)
    {
        // 参数
        // 检测是否param存在，若无则使用默认值
        if (!nh_pub.hasParam("robot_name"))
        {
            ROS_WARN("Parameter 'robot_name' not found. Using default value 'panda_1'.");
        }
        lock_horizon_ = nh_pub.param("lock_horizon", 0.05); // 轨迹拼接冻结窗口(s)
        safety_on_ = nh_pub.param("safety_control_ON", true);
        safe_margin_ = nh_pub.param("safe_margin", 0.06); // 安全距离(m)
        k_safe_gain_ = nh_pub.param("k_safe_gain", 10.0); // 安全约束增益
        update_rate_ = nh_pub.param("buffer_rate", 100);  // 控制频率(Hz)
        // SSA 参数
        ssa_k1_ = nh_pub.param("ssa_k1", 0.02);        // φ(x,ẋ) 中的 k1 系数
        vmax_coeff_ = nh_pub.param("vmax_coeff", 0.3); // 速度缩放系数
        amax_coeff_ = nh_pub.param("amax_coeff", 0.3); // 加速度缩放系数
        // 新增：平滑聚合超参数（<=0 关闭，>0 使用soft-min/log-sum-exp）
        smooth_alpha_ = nh_pub.param("smooth_min_alpha", 20.0);
        // 新增：轨迹跟踪反馈参数与可选预投影
        track_kp_ = nh_pub.param("track_kp", 0.0);
        track_kd_ = nh_pub.param("track_kd", 0.3);
        preproject_feedback_ = nh_pub.param("preproject_feedback", false);
        // 新增：分类型安全阈值（在聚合前减去）
        safety_thresh_obstacle_ = nh_pub.param("safety_thresh_obstacle", 0.09);
        safety_thresh_ground_ = nh_pub.param("safety_thresh_ground", 0.09);
        safety_thresh_rr_ = nh_pub.param("safety_thresh_rr", 0.09);

        // 话题（单臂）
        std::string input_topic = "/" + robot_name_ + "/trajectory";
        std::string output_topic = "/" + robot_name_ + "/joint_impedance_tracking_controller_velocity/equilibrium_config";
        std::string self_js = "/" + robot_name_ + "/joint_states";
        // 改为使用 MarkerArray 类型的障碍物话题（与 cplus_dev 一致）
        std::string obstacle_topic = "/moving_obstacles";

        cmd_pub_ = nh_pub.advertise<trajectory_msgs::JointTrajectoryPoint>(output_topic, 1);
        traj_sub_ = nh_pub.subscribe(input_topic, 1, &ReactiveSSAController::trajCb, this);
        js_sub_ = nh_pub.subscribe(self_js, 1, &ReactiveSSAController::selfJsCb, this);
        obstacle_sub_ = nh_pub.subscribe(obstacle_topic, 1, &ReactiveSSAController::obstacleCb, this);
        // 新增：订阅上层提供的邻居列表（逗号分隔字符串）
        neighbors_sub_ = nh_pub.subscribe("/" + robot_name_ + "/connected_agents", 1, &ReactiveSSAController::neighborsCb, this);

        // 机器人底座与模型（仅单臂）
        panda_ = std::make_shared<RobotDescription>("Panda", 1, safe_margin_);
        InitRobot(*panda_, robot_name_, nh_pub);

        // 从 RobotDescription 读取关节速度/加速度上限，并应用系数缩放
        q_dot_max_ = vmax_coeff_ * panda_->dthetamax.col(0);
        a_max_vec_ = amax_coeff_ * panda_->ddthetamax.col(0);

        q_ = Eigen::VectorXd::Zero(N_JOINTS);
        qd_ = Eigen::VectorXd::Zero(N_JOINTS);
        last_point_.time_from_start = ros::Duration(0.0);
        start_time_ = ros::Time(0);
    }

    // 轨迹时间对齐与合并（与buffer_controller同结构，线性插值切分点）
    void setTrajectory(const trajectory_msgs::JointTrajectory &traj)
    {
        std::cout << robot_name_ << "setTrajectory called." << std::endl;
        if (traj.points.empty())
            return;
        ros::Time now = ros::Time::now();
        ros::Time new_base = traj.header.stamp.isZero() ? now : traj.header.stamp;
        // std::cout << robot_name_ << "now: " << now << ", new_base: " << new_base << std::endl;
        // std::cout << robot_name_ << "Received trajectory with " << traj.points.size() << " points, starting at " << new_base << std::endl;
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
                    // cut_pt = linearInterp(traj_buffer_[i], traj_buffer_[i + 1], tau);
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

    // 主循环更新：名义插值 + SSA加速度投影
    void update(double t, double dt)
    {
        if (traj_buffer_.empty())
            return;
        size_t idx = traj_buffer_.size();
        for (size_t i = 1; i < traj_buffer_.size(); ++i)
        {
            if (traj_buffer_[i].time_from_start.toSec() > t)
            {
                idx = i - 1;
                break;
            }
        }
        // std::cout << "Update at t=" << t << " s, using segment index " << idx << std::endl;
        trajectory_msgs::JointTrajectoryPoint pt_nom;
        if (idx >= traj_buffer_.size() - 1)
        {
            pt_nom = traj_buffer_.back();
            pt_nom.time_from_start = ros::Duration(t);
        }
        else
        {
            const auto &p0 = traj_buffer_[idx], &p1 = traj_buffer_[idx + 1];
            double t0 = p0.time_from_start.toSec(), t1 = p1.time_from_start.toSec();
            double tau = (t - t0) / std::max(1e-9, (t1 - t0));
            // pt_nom = linearInterp(p0, p1, tau);
            pt_nom = cubicHermiteInterp(p0, p1, tau, t1 - t0);
            pt_nom.time_from_start = ros::Duration(t);
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
            q_next[j] = need_safe ? q_(j) + v_next[j] * dt : q_nom[j];
        // q_next[j] = q_(j) + v_cmd[j] * dt; // 始终积分，避免漂移
        // std::cout << "delat_q: " << (q_nom - q_next).transpose() << std::endl;
        trajectory_msgs::JointTrajectoryPoint pt_safe;
        pt_safe.positions.resize(N_JOINTS);
        pt_safe.velocities.resize(N_JOINTS);
        for (int j = 0; j < N_JOINTS; ++j)
        {
            pt_safe.positions[j] = q_next[j];
            pt_safe.velocities[j] = v_next[j];
        }
        pt_safe.time_from_start = ros::Duration(t);
        publish(pt_safe);
        last_point_ = pt_safe;
    }

    ros::Time getStartTime() const { return start_time_; }
    int getRate() const { return update_rate_; }

private:
    // 线性插值
    static trajectory_msgs::JointTrajectoryPoint linearInterp(const trajectory_msgs::JointTrajectoryPoint &p0, const trajectory_msgs::JointTrajectoryPoint &p1, double tau)
    {
        trajectory_msgs::JointTrajectoryPoint p = p0;
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
            double dt = std::max(1e-9, p1.time_from_start.toSec() - p0.time_from_start.toSec());
            for (size_t j = 0; j < p.positions.size(); ++j)
                p.velocities[j] = (p1.positions[j] - p0.positions[j]) / dt;
        }
        return p;
    }

    // 三次 Hermite 插值
    static trajectory_msgs::JointTrajectoryPoint cubicHermiteInterp(const trajectory_msgs::JointTrajectoryPoint &pt0, const trajectory_msgs::JointTrajectoryPoint &pt1, double tau, double dt)
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

    // 名义速度估计：用t附近的缓冲点差分
    Eigen::VectorXd finiteDiffVelocityAround(double t_now) const
    {
        if (traj_buffer_.size() < 2)
            return Eigen::VectorXd::Zero(N_JOINTS);
        const trajectory_msgs::JointTrajectoryPoint *L = nullptr, *R = nullptr;
        for (size_t i = 1; i < traj_buffer_.size(); ++i)
        {
            if (traj_buffer_[i].time_from_start.toSec() >= t_now)
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
        double dt = std::max(1e-6, R->time_from_start.toSec() - L->time_from_start.toSec());
        Eigen::VectorXd v(N_JOINTS);
        for (int j = 0; j < N_JOINTS; ++j)
            v[j] = (R->positions[j] - L->positions[j]) / dt;
        return v;
    }

    void publish(const trajectory_msgs::JointTrajectoryPoint &pt) { cmd_pub_.publish(pt); }

    // 机器人/障碍工具
    static void InitRobot(RobotDescription &rb, const std::string &arm_id, ros::NodeHandle &nh)
    {
        // 从全局参数服务器读取：/robots/<name>/base_xyz 与 /robots/<name>/base_rpy
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
        // 仅订阅高频 joint_states
        ros::Subscriber sub_js_raw;
        Eigen::VectorXd q = Eigen::VectorXd::Zero(N_JOINTS);
        std::shared_ptr<RobotDescription> model;
        bool has_state = false;
    };

    void neighborsCb(const std_msgs::String::ConstPtr &msg)
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
        updateNeighbors(names, nh_);
    }

    void updateNeighbors(const std::vector<std::string> &names, ros::NodeHandle nh)
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
                InitRobot(*o.model, n, nh);
                // 仅订阅 /name/joint_states
                std::string raw_topic = "/" + n + "/joint_states";
                o.sub_js_raw = nh.subscribe<sensor_msgs::JointState>(raw_topic, 1, boost::bind(&ReactiveSSAController::otherJsCb, this, _1, n));
                others_.emplace(n, std::move(o));
            }
        }
    }

    void otherJsCb(const sensor_msgs::JointState::ConstPtr &msg, const std::string &name)
    {
        auto it = others_.find(name);
        if (it == others_.end())
            return;
        auto &o = it->second;
        // 简化：按顺序读取前 N_JOINTS 个关节
        if (!msg || msg->position.size() < static_cast<size_t>(N_JOINTS))
            return;
        if (o.q.size() != N_JOINTS)
            o.q = Eigen::VectorXd::Zero(N_JOINTS);
        for (int j = 0; j < N_JOINTS; ++j)
            o.q(j) = msg->position[j];
        o.has_state = true;
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
    void trajCb(const trajectory_msgs::JointTrajectory::ConstPtr &msg) { setTrajectory(*msg); }
    void selfJsCb(const sensor_msgs::JointState::ConstPtr &msg)
    {
        // 根据当前机器人名构造关节名
        std::vector<std::string> names;
        names.reserve(N_JOINTS);
        for (int j = 1; j <= N_JOINTS; ++j)
            names.push_back(robot_name_ + std::string("_joint") + std::to_string(j));

        std::vector<int> idx(N_JOINTS, -1);
        for (size_t i = 0; i < msg->name.size(); ++i)
            for (int j = 0; j < N_JOINTS; ++j)
                if (msg->name[i] == names[j])
                    idx[j] = i;
        for (int j = 0; j < N_JOINTS; ++j)
            if (idx[j] >= 0)
            {
                q_(j) = msg->position[idx[j]];
                qd_(j) = msg->velocity[idx[j]];
            }
    }

    void obstacleCb(const visualization_msgs::MarkerArray::ConstPtr &msg)
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
            if (m.type != visualization_msgs::Marker::SPHERE)
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
    ros::NodeHandle nh_;
    ros::Publisher cmd_pub_;
    ros::Subscriber traj_sub_, js_sub_, obstacle_sub_;
    // 新增：邻居列表订阅
    ros::Subscriber neighbors_sub_;

    std::vector<trajectory_msgs::JointTrajectoryPoint> traj_buffer_;
    trajectory_msgs::JointTrajectoryPoint last_point_;
    ros::Time start_time_;

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
    ros::init(argc, argv, "ssa_controller");
    ros::NodeHandle nh;
    std::string robot_name = nh.param<std::string>("robot_name", "panda_1");
    auto ctl = std::make_shared<ReactiveSSAController>(robot_name, nh);
    ros::Rate rate(ctl->getRate());
    bool first_plan = true;
    while (ros::ok())
    {
        if (first_plan)
        {
            ros::spinOnce();
            ros::Duration(0.1).sleep(); // 等待ROS参数等更新
            first_plan = false;
        }
        double t = (ros::Time::now() - ctl->getStartTime()).toSec();
        double dt = 1.0 / std::max(1, ctl->getRate());

        // 实际速度在0.01-0.02ms,最大0.2ms
        ctl->update(t, dt);

        ros::spinOnce();
        rate.sleep();
    }
    return 0;
}