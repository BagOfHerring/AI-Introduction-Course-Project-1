#include <franka_example_controllers/subscriber/joint_impedance_controller.hpp>

#include <algorithm>
#include <cassert>
#include <cmath>
#include <exception>
#include <string>

#include <Eigen/Eigen>

namespace franka_example_controllers {

std::string JointImpedanceController::resolve_arm_id() const {
  if (!arm_id_.empty()) {
    return arm_id_;
  }
  if (get_node() != nullptr && get_node()->has_parameter("arm_id")) {
    return get_node()->get_parameter("arm_id").as_string();
  }
  return "panda";
}

controller_interface::InterfaceConfiguration
JointImpedanceController::command_interface_configuration() const {
  controller_interface::InterfaceConfiguration config;
  config.type = controller_interface::interface_configuration_type::INDIVIDUAL;
  const auto arm_id = resolve_arm_id();

  for (int i = 1; i <= num_joints; ++i) {
    config.names.push_back(arm_id + "_joint" + std::to_string(i) + "/effort");
  }
  return config;
}

controller_interface::InterfaceConfiguration
JointImpedanceController::state_interface_configuration() const {
  controller_interface::InterfaceConfiguration config;
  config.type = controller_interface::interface_configuration_type::INDIVIDUAL;
  const auto arm_id = resolve_arm_id();
  for (int i = 1; i <= num_joints; ++i) {
    config.names.push_back(arm_id + "_joint" + std::to_string(i) + "/position");
    config.names.push_back(arm_id + "_joint" + std::to_string(i) + "/velocity");
  }
  auto robot_model =
      franka_semantic_components::FrankaRobotModel(arm_id + "/robot_model", arm_id);
  for (const auto& franka_robot_model_name : robot_model.get_state_interface_names()) {
    config.names.push_back(franka_robot_model_name);
  }
  return config;
}

controller_interface::return_type
JointImpedanceController::update(
    const rclcpp::Time& /*time*/,
    const rclcpp::Duration& /*period*/) {
  updateJointStates();
  Eigen::Map<const Vector7d> coriolis(
    franka_robot_model_->getCoriolisForceVector().data());
  Vector7d q_goal;
  Vector7d qd_goal;
  {
    std::lock_guard<std::mutex> lock(target_mutex_);
    q_goal = q_d_;
    qd_goal = qd_d_;
  }
  const double kAlpha = 0.99;
  dq_filtered_ = (1 - kAlpha) * dq_filtered_ + kAlpha * dq_;
  Vector7d tau_d_calculated =
      k_gains_.cwiseProduct(q_goal - q_) + d_gains_.cwiseProduct(
        qd_goal - dq_filtered_) + coriolis;
  for (int i = 0; i < num_joints; ++i) {
    command_interfaces_[i].set_value(tau_d_calculated(i));
  }
  return controller_interface::return_type::OK;
}

CallbackReturn
JointImpedanceController::on_init() {
  try {
    auto_declare<std::string>("arm_id", "panda");
    auto_declare<std::string>("command_topic", "");
    auto_declare<std::vector<double>>("k_gains", {});
    auto_declare<std::vector<double>>("d_gains", {});
  } catch (const std::exception& e) {
    fprintf(stderr, "Exception thrown during init stage with message: %s \n", e.what());
    return CallbackReturn::ERROR;
  }
  return CallbackReturn::SUCCESS;
}

CallbackReturn
JointImpedanceController::on_configure(
    const rclcpp_lifecycle::State& /*previous_state*/) {
  arm_id_ = resolve_arm_id();
  command_topic_ = get_node()->get_parameter("command_topic").as_string();
  if (command_topic_.empty()) {
    command_topic_ = "/" + arm_id_ + "/joint_impedance_cmd";
  }
  franka_robot_model_ = std::make_unique<franka_semantic_components::FrankaRobotModel>(
      franka_semantic_components::FrankaRobotModel(arm_id_ + "/robot_model",
                                                   arm_id_));
  sub_desired_joint_ =
      get_node()->create_subscription<trajectory_msgs::msg::JointTrajectoryPoint>(
          command_topic_, 1,
          std::bind(&JointImpedanceController::desiredJointCallback, this, std::placeholders::_1));
  auto k_gains = get_node()->get_parameter("k_gains").as_double_array();
  auto d_gains = get_node()->get_parameter("d_gains").as_double_array();
  if (k_gains.empty()) {
    RCLCPP_FATAL(get_node()->get_logger(), "k_gains parameter not set");
    return CallbackReturn::FAILURE;
  }
  if (k_gains.size() != static_cast<uint>(num_joints)) {
    RCLCPP_FATAL(get_node()->get_logger(), "k_gains should be of size %d but is of size %ld",
                 num_joints, k_gains.size());
    return CallbackReturn::FAILURE;
  }
  if (d_gains.empty()) {
    RCLCPP_FATAL(get_node()->get_logger(), "d_gains parameter not set");
    return CallbackReturn::FAILURE;
  }
  if (d_gains.size() != static_cast<uint>(num_joints)) {
    RCLCPP_FATAL(get_node()->get_logger(), "d_gains should be of size %d but is of size %ld",
                 num_joints, d_gains.size());
    return CallbackReturn::FAILURE;
  }
  for (int i = 0; i < num_joints; ++i) {
    d_gains_(i) = d_gains.at(i);
    k_gains_(i) = k_gains.at(i);
  }
  dq_filtered_.setZero();
  return CallbackReturn::SUCCESS;
}

CallbackReturn
JointImpedanceController::on_activate(
    const rclcpp_lifecycle::State& /*previous_state*/) {
  updateJointStates();
  franka_robot_model_->assign_loaned_state_interfaces(state_interfaces_);
  {
    std::lock_guard<std::mutex> lock(target_mutex_);
    q_d_ = q_;
    qd_d_.setZero();
  }
  return CallbackReturn::SUCCESS;
}

void JointImpedanceController::updateJointStates() {
  for (auto i = 0; i < num_joints; ++i) {
    const auto& position_interface = state_interfaces_.at(2 * i);
    const auto& velocity_interface = state_interfaces_.at(2 * i + 1);

    assert(position_interface.get_interface_name() == "position");
    assert(velocity_interface.get_interface_name() == "velocity");

    q_(i) = position_interface.get_value();
    dq_(i) = velocity_interface.get_value();
  }
}

void JointImpedanceController::desiredJointCallback(
  const trajectory_msgs::msg::JointTrajectoryPoint::SharedPtr msg) {
  if (msg == nullptr || msg->positions.size() < static_cast<size_t>(num_joints)) {
    RCLCPP_WARN_THROTTLE(
        get_node()->get_logger(), *get_node()->get_clock(), 2000,
        "Ignoring joint impedance command on %s because positions size is < %d",
        command_topic_.c_str(), num_joints);
    return;
  }

  std::lock_guard<std::mutex> lock(target_mutex_);
  for (auto i = 0; i < num_joints; ++i) {
    q_d_(i) = msg->positions[i];
  }
  if (msg->velocities.size() >= static_cast<size_t>(num_joints)) {
    for (auto i = 0; i < num_joints; ++i) {
      qd_d_(i) = msg->velocities[i];
    }
  } else {
    qd_d_.setZero();
  }
}

}  // namespace franka_example_controllers
#include "pluginlib/class_list_macros.hpp"
// NOLINTNEXTLINE
PLUGINLIB_EXPORT_CLASS(franka_example_controllers::JointImpedanceController,
                       controller_interface::ControllerInterface)
