// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mujoco_ros_msgs:srv/SetMocapState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "mujoco_ros_msgs/srv/set_mocap_state.hpp"


#ifndef MUJOCO_ROS_MSGS__SRV__DETAIL__SET_MOCAP_STATE__BUILDER_HPP_
#define MUJOCO_ROS_MSGS__SRV__DETAIL__SET_MOCAP_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mujoco_ros_msgs/srv/detail/set_mocap_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mujoco_ros_msgs
{

namespace srv
{

namespace builder
{

class Init_SetMocapState_Request_mocap_state
{
public:
  Init_SetMocapState_Request_mocap_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::mujoco_ros_msgs::srv::SetMocapState_Request mocap_state(::mujoco_ros_msgs::srv::SetMocapState_Request::_mocap_state_type arg)
  {
    msg_.mocap_state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mujoco_ros_msgs::srv::SetMocapState_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mujoco_ros_msgs::srv::SetMocapState_Request>()
{
  return mujoco_ros_msgs::srv::builder::Init_SetMocapState_Request_mocap_state();
}

}  // namespace mujoco_ros_msgs


namespace mujoco_ros_msgs
{

namespace srv
{

namespace builder
{

class Init_SetMocapState_Response_success
{
public:
  Init_SetMocapState_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::mujoco_ros_msgs::srv::SetMocapState_Response success(::mujoco_ros_msgs::srv::SetMocapState_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mujoco_ros_msgs::srv::SetMocapState_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mujoco_ros_msgs::srv::SetMocapState_Response>()
{
  return mujoco_ros_msgs::srv::builder::Init_SetMocapState_Response_success();
}

}  // namespace mujoco_ros_msgs


namespace mujoco_ros_msgs
{

namespace srv
{

namespace builder
{

class Init_SetMocapState_Event_response
{
public:
  explicit Init_SetMocapState_Event_response(::mujoco_ros_msgs::srv::SetMocapState_Event & msg)
  : msg_(msg)
  {}
  ::mujoco_ros_msgs::srv::SetMocapState_Event response(::mujoco_ros_msgs::srv::SetMocapState_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mujoco_ros_msgs::srv::SetMocapState_Event msg_;
};

class Init_SetMocapState_Event_request
{
public:
  explicit Init_SetMocapState_Event_request(::mujoco_ros_msgs::srv::SetMocapState_Event & msg)
  : msg_(msg)
  {}
  Init_SetMocapState_Event_response request(::mujoco_ros_msgs::srv::SetMocapState_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_SetMocapState_Event_response(msg_);
  }

private:
  ::mujoco_ros_msgs::srv::SetMocapState_Event msg_;
};

class Init_SetMocapState_Event_info
{
public:
  Init_SetMocapState_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetMocapState_Event_request info(::mujoco_ros_msgs::srv::SetMocapState_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_SetMocapState_Event_request(msg_);
  }

private:
  ::mujoco_ros_msgs::srv::SetMocapState_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mujoco_ros_msgs::srv::SetMocapState_Event>()
{
  return mujoco_ros_msgs::srv::builder::Init_SetMocapState_Event_info();
}

}  // namespace mujoco_ros_msgs

#endif  // MUJOCO_ROS_MSGS__SRV__DETAIL__SET_MOCAP_STATE__BUILDER_HPP_
