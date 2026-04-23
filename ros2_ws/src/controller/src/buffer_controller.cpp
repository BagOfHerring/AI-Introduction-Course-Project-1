#include "buffer_controller.h"
#include <algorithm>
#include <chrono>

// Helper: assign rclcpp::Duration to builtin_interfaces::msg::Duration
static inline void set_duration(builtin_interfaces::msg::Duration &d, double seconds) {
    int32_t sec = static_cast<int32_t>(seconds);
    uint32_t nsec = static_cast<uint32_t>((seconds - sec) * 1e9);
    d.sec = sec;
    d.nanosec = nsec;
}

BufferController::BufferController(const std::string &robot_name, rclcpp::Node::SharedPtr node, const std::string &output_topic)
    : robot_name_(robot_name), node_(node)
{
    cmd_pub_ = node->create_publisher<trajectory_msgs::msg::JointTrajectoryPoint>(output_topic, 1);
    // 允许通过参数配置冻结窗口（秒），默认0.1
    double lh = lock_horizon_;
    if (node->get_parameter("lock_horizon", lh))
        lock_horizon_ = lh;
}

void BufferController::setTrajectory(const trajectory_msgs::msg::JointTrajectory &traj)
{
    // std::lock_guard<std::mutex> lk(mtx_);
    // 确定新轨迹的时间基准
    rclcpp::Time now = node_->now();
    rclcpp::Time new_base = traj.header.stamp.sec == 0 && traj.header.stamp.nanosec == 0 ? now : rclcpp::Time(traj.header.stamp);
    // 首次接收：直接采用并记录起始时间（若stamp为0则用now）
    if (traj_buffer_.empty())
    {
        traj_buffer_ = traj.points;
        start_time_ = new_base;
        return;
    }

    // 有缓冲：切分时刻= max(规划开始+锁定窗口, 当前时刻)，避免新轨迹滞后导致拼接越过已执行部分
    rclcpp::Time cutoff_abs_by_start = start_time_ + rclcpp::Duration::from_seconds(lock_horizon_);
    rclcpp::Time cutoff_abs = (now > cutoff_abs_by_start) ? now : cutoff_abs_by_start;
    double t_cut_rel = (cutoff_abs - start_time_).seconds();
    double t_cut_rel_new = (cutoff_abs - now).seconds(); // 相对于新轨迹
    // std::cout << "start_time_: " << start_time_ << " traj_stamp: " << new_base << "now: " << now << std::endl;
    // for (const auto &pt : last_point_.positions)
    // {
    //     std::cout << pt << " ";
    // }
    // std::cout << std::endl;
    // std::cout << "last_point_: " << rclcpp::Duration(last_point_.time_from_start).seconds() << std::endl;
    // std::cout << "t_cut_rel_new: " << t_cut_rel_new << std::endl;

    auto absTimeOld = [&](const trajectory_msgs::msg::JointTrajectoryPoint &pt)
    {
        return start_time_ + pt.time_from_start;
    };
    auto absTimeNew = [&](const trajectory_msgs::msg::JointTrajectoryPoint &pt)
    {
        return new_base + pt.time_from_start;
    };

    std::vector<trajectory_msgs::msg::JointTrajectoryPoint> merged;

    // 1) 先加入当前时刻的轨迹点, 保留旧轨迹中绝对时间严格早于切分时刻的点（t_abs < cutoff_abs）且大于now的轨迹点
    trajectory_msgs::msg::JointTrajectoryPoint now_point = last_point_;
    set_duration(now_point.time_from_start, 0.0);

    merged.push_back(now_point);
    for (const auto &pt : traj_buffer_)
    {
        if (absTimeOld(pt) < cutoff_abs && absTimeOld(pt) > now)
        {
            trajectory_msgs::msg::JointTrajectoryPoint pt_conv = pt;
            pt_conv.time_from_start = absTimeOld(pt) - now;
            // std::cout << "add old:" << pt_conv.time_from_start << std::endl;
            merged.push_back(std::move(pt_conv));
        }
    }
    // std::cout << "raw merged.size()" << merged.size() << std::endl;
    // 2) 在切分时刻处生成一个显式分隔点（保证连续性）
    trajectory_msgs::msg::JointTrajectoryPoint cut_pt;
    bool cut_ok = false;
    const double eps = 1e-9;

    // 2.1 若旧轨迹存在时间接近 t_cut_rel 的点，直接使用
    for (const auto &pt : traj_buffer_)
    {
        if (std::abs(rclcpp::Duration(pt.time_from_start).seconds() - t_cut_rel) < eps)
        {
            cut_pt = pt;
            cut_ok = true;
            break;
        }
    }

    // 2.2 否则在旧轨迹中找到包围区间，用三次Hermite插值求切分点
    if (!cut_ok && traj_buffer_.size() >= 2)
    {
        for (size_t i = 0; i + 1 < traj_buffer_.size(); ++i)
        {
            const auto &a = traj_buffer_[i];
            const auto &b = traj_buffer_[i + 1];
            double ta = rclcpp::Duration(a.time_from_start).seconds();
            double tb = rclcpp::Duration(b.time_from_start).seconds();
            if (ta <= t_cut_rel && t_cut_rel <= tb && tb > ta)
            {
                double tau = (t_cut_rel - ta) / (tb - ta);
                cut_pt = linearInterp(a, b, tau);
                set_duration(cut_pt.time_from_start, t_cut_rel);
                cut_ok = true;
                break;
            }
        }
    }

    // 2.3 若仍无法计算，复制最接近端点并设置其时间戳为切分时刻
    if (!cut_ok && !traj_buffer_.empty())
    {
        const auto &first = traj_buffer_.front();
        const auto &last = traj_buffer_.back();
        double d_first = std::abs(rclcpp::Duration(first.time_from_start).seconds() - t_cut_rel);
        double d_last = std::abs(rclcpp::Duration(last.time_from_start).seconds() - t_cut_rel);
        cut_pt = (d_first <= d_last) ? first : last;
        set_duration(cut_pt.time_from_start, t_cut_rel);
        cut_ok = true;
    }

    if (cut_ok)
    {
        { auto _d = rclcpp::Duration(cut_pt.time_from_start) - (now - start_time_); set_duration(cut_pt.time_from_start, _d.seconds()); } // 以now为新基准
        merged.push_back(cut_pt);
    }

    // 3) 仅保留新轨迹中绝对时间严格晚于切分时刻的点（t_abs_new > cutoff_abs），并对齐为旧基准
    for (const auto &pt : traj.points)
    {
        rclcpp::Time t_abs = absTimeNew(pt);
        if (t_abs > cutoff_abs && t_abs > now)
        {
            trajectory_msgs::msg::JointTrajectoryPoint pt_conv = pt;
            pt_conv.time_from_start = t_abs - now;
            merged.push_back(std::move(pt_conv));
        }
    }

    // 输出merged中的数据的time_from_start
    // for (const auto &pt : merged)
    // {
    //     std::cout << rclcpp::Duration(pt.time_from_start).seconds() << " ";
    // }
    // std::cout << std::endl;
    // std::cout << "============================" << std::endl;

    // 4) 排序并替换
    std::sort(merged.begin(), merged.end(), [](const auto &a, const auto &b)
              { return rclcpp::Duration(a.time_from_start).seconds() < rclcpp::Duration(b.time_from_start).seconds(); });

    traj_buffer_.swap(merged);

    // 更新当前的轨迹的开始时间
    start_time_ = now;
}

void BufferController::update(double current_time)
{
    // std::lock_guard<std::mutex> lk(mtx_);
    if (traj_buffer_.empty())
        return;
    // 计算相对于轨迹起始时间的当前时间
    double t = current_time;
    int idx = traj_buffer_.size(); // big value initial
    for (int i = 0; i < traj_buffer_.size(); ++i)
    {
        if (rclcpp::Duration(traj_buffer_[i].time_from_start).seconds() > t)
        {
            idx = i - 1;
            break;
        }
    }
    // 边界处理，当只有一个点或超过最后一个点了，直接发布最后的点
    if (idx >= traj_buffer_.size() - 1 || idx < 0)
    {
        publishCommand(traj_buffer_.back());
        last_point_ = traj_buffer_.back();
        set_duration(last_point_.time_from_start, t);
        return;
    }
    const auto &pt0 = traj_buffer_[idx];
    const auto &pt1 = traj_buffer_[idx + 1];
    double t0 = rclcpp::Duration(pt0.time_from_start).seconds();
    double t1 = rclcpp::Duration(pt1.time_from_start).seconds();
    double tau = (t - t0) / (t1 - t0); // 归一化到[0,1]

    // 线性插值
    auto pt_linear = linearInterp(pt0, pt1, tau);
    publishCommand(pt_linear); // 线性插值
    last_point_ = pt_linear;

    // 三次Hermite插值
    // auto pt_cubic = cubicHermiteInterp(pt0, pt1, tau, t1 - t0);
    // publishCommand(pt_cubic); // 三次多项式插值
    // last_point_ = pt_cubic;
}

// 线性插值函数
trajectory_msgs::msg::JointTrajectoryPoint BufferController::linearInterp(const trajectory_msgs::msg::JointTrajectoryPoint &pt0, const trajectory_msgs::msg::JointTrajectoryPoint &pt1, double tau)
{
    trajectory_msgs::msg::JointTrajectoryPoint pt = pt0;
    for (size_t j = 0; j < pt0.positions.size(); ++j)
    {
        pt.positions[j] = pt0.positions[j] + tau * (pt1.positions[j] - pt0.positions[j]);
        if (pt0.velocities.size() == pt1.velocities.size() && pt0.velocities.size() > j)
            pt.velocities[j] = pt0.velocities[j] + tau * (pt1.velocities[j] - pt0.velocities[j]);
    }
    pt.time_from_start = rclcpp::Duration::from_seconds(rclcpp::Duration(pt0.time_from_start).seconds() + tau * (rclcpp::Duration(pt1.time_from_start).seconds() - rclcpp::Duration(pt0.time_from_start).seconds()));
    return pt;
}

// 三次Hermite插值函数
trajectory_msgs::msg::JointTrajectoryPoint BufferController::cubicHermiteInterp(const trajectory_msgs::msg::JointTrajectoryPoint &pt0, const trajectory_msgs::msg::JointTrajectoryPoint &pt1, double tau, double dt)
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
    pt.time_from_start = rclcpp::Duration::from_seconds(rclcpp::Duration(pt0.time_from_start).seconds() + tau * dt);
    return pt;
}

void BufferController::publishCommand(const trajectory_msgs::msg::JointTrajectoryPoint &pt)
{
    cmd_pub_->publish(pt);
}
