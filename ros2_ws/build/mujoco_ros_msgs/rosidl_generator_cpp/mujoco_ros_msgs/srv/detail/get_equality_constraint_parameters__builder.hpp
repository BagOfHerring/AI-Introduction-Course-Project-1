// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mujoco_ros_msgs:srv/GetEqualityConstraintParameters.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "mujoco_ros_msgs/srv/get_equality_constraint_parameters.hpp"


#ifndef MUJOCO_ROS_MSGS__SRV__DETAIL__GET_EQUALITY_CONSTRAINT_PARAMETERS__BUILDER_HPP_
#define MUJOCO_ROS_MSGS__SRV__DETAIL__GET_EQUALITY_CONSTRAINT_PARAMETERS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mujoco_ros_msgs/srv/detail/get_equality_constraint_parameters__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mujoco_ros_msgs
{

namespace srv
{

namespace builder
{

class Init_GetEqualityConstraintParameters_Request_admin_hash
{
public:
  explicit Init_GetEqualityConstraintParameters_Request_admin_hash(::mujoco_ros_msgs::srv::GetEqualityConstraintParameters_Request & msg)
  : msg_(msg)
  {}
  ::mujoco_ros_msgs::srv::GetEqualityConstraintParameters_Request admin_hash(::mujoco_ros_msgs::srv::GetEqualityConstraintParameters_Request::_admin_hash_type arg)
  {
    msg_.admin_hash = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mujoco_ros_msgs::srv::GetEqualityConstraintParameters_Request msg_;
};

class Init_GetEqualityConstraintParameters_Request_names
{
public:
  Init_GetEqualityConstraintParameters_Request_names()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetEqualityConstraintParameters_Request_admin_hash names(::mujoco_ros_msgs::srv::GetEqualityConstraintParameters_Request::_names_type arg)
  {
    msg_.names = std::move(arg);
    return Init_GetEqualityConstraintParameters_Request_admin_hash(msg_);
  }

private:
  ::mujoco_ros_msgs::srv::GetEqualityConstraintParameters_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mujoco_ros_msgs::srv::GetEqualityConstraintParameters_Request>()
{
  return mujoco_ros_msgs::srv::builder::Init_GetEqualityConstraintParameters_Request_names();
}

}  // namespace mujoco_ros_msgs


namespace mujoco_ros_msgs
{

namespace srv
{

namespace builder
{

class Init_GetEqualityConstraintParameters_Response_status_message
{
public:
  explicit Init_GetEqualityConstraintParameters_Response_status_message(::mujoco_ros_msgs::srv::GetEqualityConstraintParameters_Response & msg)
  : msg_(msg)
  {}
  ::mujoco_ros_msgs::srv::GetEqualityConstraintParameters_Response status_message(::mujoco_ros_msgs::srv::GetEqualityConstraintParameters_Response::_status_message_type arg)
  {
    msg_.status_message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mujoco_ros_msgs::srv::GetEqualityConstraintParameters_Response msg_;
};

class Init_GetEqualityConstraintParameters_Response_success
{
public:
  explicit Init_GetEqualityConstraintParameters_Response_success(::mujoco_ros_msgs::srv::GetEqualityConstraintParameters_Response & msg)
  : msg_(msg)
  {}
  Init_GetEqualityConstraintParameters_Response_status_message success(::mujoco_ros_msgs::srv::GetEqualityConstraintParameters_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_GetEqualityConstraintParameters_Response_status_message(msg_);
  }

private:
  ::mujoco_ros_msgs::srv::GetEqualityConstraintParameters_Response msg_;
};

class Init_GetEqualityConstraintParameters_Response_parameters
{
public:
  Init_GetEqualityConstraintParameters_Response_parameters()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetEqualityConstraintParameters_Response_success parameters(::mujoco_ros_msgs::srv::GetEqualityConstraintParameters_Response::_parameters_type arg)
  {
    msg_.parameters = std::move(arg);
    return Init_GetEqualityConstraintParameters_Response_success(msg_);
  }

private:
  ::mujoco_ros_msgs::srv::GetEqualityConstraintParameters_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mujoco_ros_msgs::srv::GetEqualityConstraintParameters_Response>()
{
  return mujoco_ros_msgs::srv::builder::Init_GetEqualityConstraintParameters_Response_parameters();
}

}  // namespace mujoco_ros_msgs


namespace mujoco_ros_msgs
{

namespace srv
{

namespace builder
{

class Init_GetEqualityConstraintParameters_Event_response
{
public:
  explicit Init_GetEqualityConstraintParameters_Event_response(::mujoco_ros_msgs::srv::GetEqualityConstraintParameters_Event & msg)
  : msg_(msg)
  {}
  ::mujoco_ros_msgs::srv::GetEqualityConstraintParameters_Event response(::mujoco_ros_msgs::srv::GetEqualityConstraintParameters_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mujoco_ros_msgs::srv::GetEqualityConstraintParameters_Event msg_;
};

class Init_GetEqualityConstraintParameters_Event_request
{
public:
  explicit Init_GetEqualityConstraintParameters_Event_request(::mujoco_ros_msgs::srv::GetEqualityConstraintParameters_Event & msg)
  : msg_(msg)
  {}
  Init_GetEqualityConstraintParameters_Event_response request(::mujoco_ros_msgs::srv::GetEqualityConstraintParameters_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_GetEqualityConstraintParameters_Event_response(msg_);
  }

private:
  ::mujoco_ros_msgs::srv::GetEqualityConstraintParameters_Event msg_;
};

class Init_GetEqualityConstraintParameters_Event_info
{
public:
  Init_GetEqualityConstraintParameters_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetEqualityConstraintParameters_Event_request info(::mujoco_ros_msgs::srv::GetEqualityConstraintParameters_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_GetEqualityConstraintParameters_Event_request(msg_);
  }

private:
  ::mujoco_ros_msgs::srv::GetEqualityConstraintParameters_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mujoco_ros_msgs::srv::GetEqualityConstraintParameters_Event>()
{
  return mujoco_ros_msgs::srv::builder::Init_GetEqualityConstraintParameters_Event_info();
}

}  // namespace mujoco_ros_msgs

#endif  // MUJOCO_ROS_MSGS__SRV__DETAIL__GET_EQUALITY_CONSTRAINT_PARAMETERS__BUILDER_HPP_
