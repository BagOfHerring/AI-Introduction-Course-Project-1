// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mujoco_ros_msgs:srv/SetPause.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "mujoco_ros_msgs/srv/set_pause.hpp"


#ifndef MUJOCO_ROS_MSGS__SRV__DETAIL__SET_PAUSE__BUILDER_HPP_
#define MUJOCO_ROS_MSGS__SRV__DETAIL__SET_PAUSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mujoco_ros_msgs/srv/detail/set_pause__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mujoco_ros_msgs
{

namespace srv
{

namespace builder
{

class Init_SetPause_Request_admin_hash
{
public:
  explicit Init_SetPause_Request_admin_hash(::mujoco_ros_msgs::srv::SetPause_Request & msg)
  : msg_(msg)
  {}
  ::mujoco_ros_msgs::srv::SetPause_Request admin_hash(::mujoco_ros_msgs::srv::SetPause_Request::_admin_hash_type arg)
  {
    msg_.admin_hash = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mujoco_ros_msgs::srv::SetPause_Request msg_;
};

class Init_SetPause_Request_paused
{
public:
  Init_SetPause_Request_paused()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetPause_Request_admin_hash paused(::mujoco_ros_msgs::srv::SetPause_Request::_paused_type arg)
  {
    msg_.paused = std::move(arg);
    return Init_SetPause_Request_admin_hash(msg_);
  }

private:
  ::mujoco_ros_msgs::srv::SetPause_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mujoco_ros_msgs::srv::SetPause_Request>()
{
  return mujoco_ros_msgs::srv::builder::Init_SetPause_Request_paused();
}

}  // namespace mujoco_ros_msgs


namespace mujoco_ros_msgs
{

namespace srv
{

namespace builder
{

class Init_SetPause_Response_success
{
public:
  Init_SetPause_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::mujoco_ros_msgs::srv::SetPause_Response success(::mujoco_ros_msgs::srv::SetPause_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mujoco_ros_msgs::srv::SetPause_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mujoco_ros_msgs::srv::SetPause_Response>()
{
  return mujoco_ros_msgs::srv::builder::Init_SetPause_Response_success();
}

}  // namespace mujoco_ros_msgs


namespace mujoco_ros_msgs
{

namespace srv
{

namespace builder
{

class Init_SetPause_Event_response
{
public:
  explicit Init_SetPause_Event_response(::mujoco_ros_msgs::srv::SetPause_Event & msg)
  : msg_(msg)
  {}
  ::mujoco_ros_msgs::srv::SetPause_Event response(::mujoco_ros_msgs::srv::SetPause_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mujoco_ros_msgs::srv::SetPause_Event msg_;
};

class Init_SetPause_Event_request
{
public:
  explicit Init_SetPause_Event_request(::mujoco_ros_msgs::srv::SetPause_Event & msg)
  : msg_(msg)
  {}
  Init_SetPause_Event_response request(::mujoco_ros_msgs::srv::SetPause_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_SetPause_Event_response(msg_);
  }

private:
  ::mujoco_ros_msgs::srv::SetPause_Event msg_;
};

class Init_SetPause_Event_info
{
public:
  Init_SetPause_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetPause_Event_request info(::mujoco_ros_msgs::srv::SetPause_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_SetPause_Event_request(msg_);
  }

private:
  ::mujoco_ros_msgs::srv::SetPause_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mujoco_ros_msgs::srv::SetPause_Event>()
{
  return mujoco_ros_msgs::srv::builder::Init_SetPause_Event_info();
}

}  // namespace mujoco_ros_msgs

#endif  // MUJOCO_ROS_MSGS__SRV__DETAIL__SET_PAUSE__BUILDER_HPP_
