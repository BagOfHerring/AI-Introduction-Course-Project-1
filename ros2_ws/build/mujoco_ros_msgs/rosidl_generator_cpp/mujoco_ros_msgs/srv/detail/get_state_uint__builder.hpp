// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mujoco_ros_msgs:srv/GetStateUint.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "mujoco_ros_msgs/srv/get_state_uint.hpp"


#ifndef MUJOCO_ROS_MSGS__SRV__DETAIL__GET_STATE_UINT__BUILDER_HPP_
#define MUJOCO_ROS_MSGS__SRV__DETAIL__GET_STATE_UINT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mujoco_ros_msgs/srv/detail/get_state_uint__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mujoco_ros_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mujoco_ros_msgs::srv::GetStateUint_Request>()
{
  return ::mujoco_ros_msgs::srv::GetStateUint_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace mujoco_ros_msgs


namespace mujoco_ros_msgs
{

namespace srv
{

namespace builder
{

class Init_GetStateUint_Response_state
{
public:
  Init_GetStateUint_Response_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::mujoco_ros_msgs::srv::GetStateUint_Response state(::mujoco_ros_msgs::srv::GetStateUint_Response::_state_type arg)
  {
    msg_.state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mujoco_ros_msgs::srv::GetStateUint_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mujoco_ros_msgs::srv::GetStateUint_Response>()
{
  return mujoco_ros_msgs::srv::builder::Init_GetStateUint_Response_state();
}

}  // namespace mujoco_ros_msgs


namespace mujoco_ros_msgs
{

namespace srv
{

namespace builder
{

class Init_GetStateUint_Event_response
{
public:
  explicit Init_GetStateUint_Event_response(::mujoco_ros_msgs::srv::GetStateUint_Event & msg)
  : msg_(msg)
  {}
  ::mujoco_ros_msgs::srv::GetStateUint_Event response(::mujoco_ros_msgs::srv::GetStateUint_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mujoco_ros_msgs::srv::GetStateUint_Event msg_;
};

class Init_GetStateUint_Event_request
{
public:
  explicit Init_GetStateUint_Event_request(::mujoco_ros_msgs::srv::GetStateUint_Event & msg)
  : msg_(msg)
  {}
  Init_GetStateUint_Event_response request(::mujoco_ros_msgs::srv::GetStateUint_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_GetStateUint_Event_response(msg_);
  }

private:
  ::mujoco_ros_msgs::srv::GetStateUint_Event msg_;
};

class Init_GetStateUint_Event_info
{
public:
  Init_GetStateUint_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetStateUint_Event_request info(::mujoco_ros_msgs::srv::GetStateUint_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_GetStateUint_Event_request(msg_);
  }

private:
  ::mujoco_ros_msgs::srv::GetStateUint_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mujoco_ros_msgs::srv::GetStateUint_Event>()
{
  return mujoco_ros_msgs::srv::builder::Init_GetStateUint_Event_info();
}

}  // namespace mujoco_ros_msgs

#endif  // MUJOCO_ROS_MSGS__SRV__DETAIL__GET_STATE_UINT__BUILDER_HPP_
