#include <iostream>
#include "to_cxx.rs.h"
#include "cxx.h"
#include <Eigen/Dense>
// int main()
// {
//     try
//     {
//         // Eigen 向量
//         Eigen::VectorXd e(6);
//         e << 1, 2, 3, 4, 5, 6;
//         std::cout << "e: " << e.transpose() << std::endl;

//         // Eigen::VectorXd -> rust::Vec<double>
//         rust::Vec<double> v;
//         v.reserve(static_cast<std::size_t>(e.size()));
//         for (Eigen::Index i = 0; i < e.size(); ++i)
//         {
//             v.push_back(e[i]);
//         }
//         // rust::Box<ExRobot> robot = ExRobot::attach();
//         // 使用其他机器人时（以franka 为例）
//         rust::Box<FrankaRobot>
//             robot = FrankaRobot::attach("192.16.0.3");

//         auto stream = robot->start_streaming();

//         for (int i = 0; i < 100; i++)
//         {
//             // stream->move_to(CxxMotionType{
//             //     .mode = CxxMotionTypeMode::Joint,
//             //     .values = rust::Vec<double>({0.0, -1.57, 1.57, 0.0, 1.57, 0.0}),
//             // });
//             stream->move_to(CxxMotionType{
//                 .mode = CxxMotionTypeMode::Joint,
//                 .values = v,
//             });
//         }

//         return 0;
//     }
//     catch (const std::exception &e)
//     {
//         std::cerr << "Exception: " << e.what() << "\n";
//         return 1;
//     }
// }

#include <ros/ros.h>
#include <trajectory_msgs/JointTrajectory.h>
#include <trajectory_msgs/JointTrajectoryPoint.h>
#include <sensor_msgs/JointState.h>
#include <std_msgs/Bool.h>
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
#include "Robot_classes/RobotDescription.h"
#include "utilities_function/dist_arm_3D_sphere.h"
#include "Robot_classes/CollisionSphere.h"
#include "utilities_function/ObstacleSeq.hpp"
#include "to_cxx.rs.h"
#include "cxx.h"
// 固定 7 关节（Panda）
static constexpr int N_JOINTS = 7;

class ReactiveSSAController
{
public:
    ReactiveSSAController(const std::string &robot_name, ros::NodeHandle &nh_pub,
                          rust::Box<FrankaRobot> &real_robot, rust::cxxbridge1::Box<FrankaHandle> &stream)
        : robot_name_(robot_name)
    {
        // 参数
        // 检测是否param存在，若无则使用默认值
        if (!nh_pub.hasParam("robot_name"))
        {
            ROS_WARN("Parameter 'robot_name' not found. Using default value 'panda_1'.");
        }
        lock_horizon_ = nh_pub.param("lock_horizon", 0.1); // 轨迹拼接冻结窗口(s)
        safety_on_ = nh_pub.param("safety_control_ON", true);
        safe_margin_ = nh_pub.param("safe_margin", 0.06); // 安全距离(m)
        k_safe_gain_ = nh_pub.param("k_safe_gain", 10.0); // 安全约束增益
        update_rate_ = nh_pub.param("buffer_rate", 100);  // 控制频率(Hz)
        // SSA 参数
        ssa_k1_ = nh_pub.param("ssa_k1", 0.02);        // φ(x,ẋ) 中的 k1 系数
        vmax_coeff_ = nh_pub.param("vmax_coeff", 0.3); // 速度缩放系数
        amax_coeff_ = nh_pub.param("amax_coeff", 0.3); // 加速度缩放系数

        // IP 参数
        robot_ip_ = nh_pub.param("robot_ip", std::string("172.16.0.2"));

        // 话题（单臂）
        std::string input_topic = "/" + robot_name_ + "/trajectory";
        // std::string output_topic = "/" + robot_name_ + "/joint_impedance_tracking_controller_velocity/equilibrium_config";
        std::string self_js = "/" + robot_name_ + "/joint_states";
        // 改为使用 MarkerArray 类型的障碍物话题（与 cplus_dev 一致）
        std::string obstacle_topic = "/moving_obstacles";

        // cmd_pub_ = nh_pub.advertise<trajectory_msgs::JointTrajectoryPoint>(output_topic, 1);
        traj_sub_ = nh_pub.subscribe(input_topic, 1, &ReactiveSSAController::trajCb, this);
        js_sub_ = nh_pub.subscribe(self_js, 1, &ReactiveSSAController::selfJsCb, this);
        obstacle_sub_ = nh_pub.subscribe(obstacle_topic, 1, &ReactiveSSAController::obstacleCb, this);

        // 机器人底座与模型（仅单臂）
        panda_ = std::make_shared<RobotDescription>("Panda", 1, safe_margin_);
        InitRobot(*panda_, robot_name_, nh_pub);

        // 类型连接
        real_robot_ = &real_robot;
        stream_ = &stream;

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
        if (safety_on_ && obstacle_exist_)
        {

            grad = calcObstacleGrad(distance);
            need_safe = (distance <= safe_margin_);
        }
        if (!need_safe)
        {
            publish(pt_nom);
            last_point_ = pt_nom;
            return;
        }

        // 当前速度（来自传感器），名义速度与名义加速度
        Eigen::VectorXd v_curr(N_JOINTS);
        for (int j = 0; j < N_JOINTS; ++j)
            v_curr[j] = qd_(j);
        Eigen::VectorXd v_nom(N_JOINTS);
        if (!pt_nom.velocities.empty() && pt_nom.velocities.size() == (size_t)N_JOINTS)
            for (int j = 0; j < N_JOINTS; ++j)
                v_nom[j] = pt_nom.velocities[j];
        else
            v_nom = finiteDiffVelocityAround(t);
        Eigen::VectorXd a_nom = (v_nom - v_curr) / std::max(1e-6, dt);

        // 使用velocitySSA 进行投影,小参数会比ACC-SSA更明显一些
        Eigen::VectorXd v_cmd = velocitySSA(v_nom, k_safe_gain_);
        Eigen::VectorXd v_next = limitVel(v_cmd, q_dot_max_);
        Eigen::VectorXd q_next(N_JOINTS);
        for (int j = 0; j < N_JOINTS; ++j)
            q_next[j] = q_(j) + v_cmd[j] * dt;

        // 使用 Acceleration-SSA 进行投影
        // Eigen::VectorXd a_cmd = accelerationSSA(a_nom, v_curr, k_safe_gain_, ssa_k1_);
        // std::cout << "Distance: " << distance << " m, a_nom: " << a_nom.transpose() << " , a_cmd: " << a_cmd.transpose() << std::endl;
        // // 按关节限幅
        // a_cmd = limitAcc(a_cmd, a_max_vec_);
        // Eigen::VectorXd v_next = v_curr + a_cmd * dt;
        // v_next = limitVel(v_next, q_dot_max_);
        // Eigen::VectorXd q_next(N_JOINTS);
        // for (int j = 0; j < N_JOINTS; ++j)
        //     q_next[j] = q_(j) + v_next[j] * dt;

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

    void publish(const trajectory_msgs::JointTrajectoryPoint &pt)
    {
        // 发布单点轨迹
        rust::Vec<double> v;
        v.reserve(static_cast<std::size_t>(pt.positions.size()));
        for (const auto &pos : pt.positions)
            v.push_back(pos);
        (*stream_)->move_to(CxxMotionType{
            .mode = CxxMotionTypeMode::Joint,
            .values = v,
        });

        // 传统话题发布（保留）
        // cmd_pub_.publish(pt);
    }

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

    // 计算到最近障碍的距离梯度（基于 dist_arm_3D_sphere + 最近点雅可比）
    Eigen::VectorXd calcObstacleGrad(double &distance)
    {
        Eigen::VectorXd grad = Eigen::VectorXd::Zero(N_JOINTS);
        if (!panda_)
            return grad;
        // 最近距离
        auto dist_res = dist_arm_3D_sphere(q_, *panda_, obstacles_);
        distance = dist_res.min_dist;
        if (!std::isfinite(distance))
            return grad;
        // 方向：从障碍到机器人最近点
        Eigen::Vector3d closest_vec = dist_res.robot_point - dist_res.obs_point;
        double norm_val = closest_vec.norm();
        if (norm_val < 1e-12)
            return grad;
        Eigen::Vector3d dist_dx = closest_vec / norm_val;
        // 对应碰撞球的位姿雅可比（取位置 3xN）
        Eigen::MatrixXd J6 = panda_->getJacobian_world_index(q_, dist_res.min_idx);
        Eigen::MatrixXd Jpos = J6.bottomRows(3);
        grad = dist_dx.transpose() * Jpos; // 1xN -> as row; cast to col below
        return grad;
    }

    // 新增：在任意关节位姿 q 上计算障碍距离梯度（∂D/∂q），返回列向量，distance 返回 D
    Eigen::VectorXd calcObstacleGradAt(const Eigen::VectorXd &q_query, double &distance) const
    {
        Eigen::VectorXd grad = Eigen::VectorXd::Zero(N_JOINTS);
        if (!panda_)
        {
            distance = std::numeric_limits<double>::infinity();
            return grad;
        }
        auto dist_res = dist_arm_3D_sphere(q_query, *panda_, obstacles_);
        distance = dist_res.min_dist;
        if (!std::isfinite(distance))
            return grad;
        Eigen::Vector3d closest_vec = dist_res.robot_point - dist_res.obs_point;
        double norm_val = closest_vec.norm();
        if (norm_val < 1e-12)
            return grad;
        Eigen::Vector3d dist_dx = closest_vec / norm_val; // 距离方向
        Eigen::MatrixXd J6 = panda_->getJacobian_world_index(q_query, dist_res.min_idx);
        Eigen::MatrixXd Jpos = J6.bottomRows(3);
        grad = dist_dx.transpose() * Jpos; // ∂D/∂q
        return grad;
    }

    // 新增：Velocity-SSA 投影
    // v_nom: 名义关节速度；ks: 安全收敛增益
    // 返回修正后的速度（未施加饱和/限幅）
    Eigen::VectorXd velocitySSA(const Eigen::VectorXd &v_nom, double ks) const
    {
        if (!safety_on_ || !obstacle_exist_)
            return v_nom;
        double D = 0.0;
        Eigen::VectorXd gradD = const_cast<ReactiveSSAController *>(this)->calcObstacleGrad(D); // ∂D/∂q
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
        if (!safety_on_ || !obstacle_exist_)
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
    ros::Publisher cmd_pub_;
    ros::Subscriber traj_sub_, js_sub_, obstacle_sub_;

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

    // IP 参数
    std::string robot_ip_;
    rust::Box<FrankaRobot> *real_robot_;
    // streaming
    rust::cxxbridge1::Box<FrankaHandle> *stream_;

    Eigen::VectorXd q_, qd_;
    Eigen::VectorXd q_dot_max_; // 来自 RobotDescription 的正向最大速度列，并经缩放
    Eigen::VectorXd a_max_vec_; // 来自 RobotDescription 的正向最大加速度列，并经缩放

    std::shared_ptr<RobotDescription> panda_;
    bool obstacle_exist_{false};
    std::vector<ObstacleSeq> obstacles_;
};

int main(int argc, char **argv)
{
    ros::init(argc, argv, "rust_controller");
    ros::NodeHandle nh;
    std::string robot_name = nh.param<std::string>("robot_name", "panda_1");
    std::string robot_ip = nh.param<std::string>("robot_ip", "172.16.0.2");
    std::cout << "Robot name: " << robot_name << ", IP: " << robot_ip << std::endl;
    rust::Box<FrankaRobot> real_robot = FrankaRobot::attach(robot_ip);
    rust::cxxbridge1::Box<FrankaHandle> stream = real_robot->start_streaming();

    auto ctl = std::make_shared<ReactiveSSAController>(robot_name, nh, real_robot, stream);
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