// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mujoco_ros_msgs:srv/GetPluginStats.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "mujoco_ros_msgs/srv/get_plugin_stats.hpp"


#ifndef MUJOCO_ROS_MSGS__SRV__DETAIL__GET_PLUGIN_STATS__BUILDER_HPP_
#define MUJOCO_ROS_MSGS__SRV__DETAIL__GET_PLUGIN_STATS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mujoco_ros_msgs/srv/detail/get_plugin_stats__struct.hpp"
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
auto build<::mujoco_ros_msgs::srv::GetPluginStats_Request>()
{
  return ::mujoco_ros_msgs::srv::GetPluginStats_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace mujoco_ros_msgs


namespace mujoco_ros_msgs
{

namespace srv
{

namespace builder
{

class Init_GetPluginStats_Response_stats
{
public:
  Init_GetPluginStats_Response_stats()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::mujoco_ros_msgs::srv::GetPluginStats_Response stats(::mujoco_ros_msgs::srv::GetPluginStats_Response::_stats_type arg)
  {
    msg_.stats = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mujoco_ros_msgs::srv::GetPluginStats_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mujoco_ros_msgs::srv::GetPluginStats_Response>()
{
  return mujoco_ros_msgs::srv::builder::Init_GetPluginStats_Response_stats();
}

}  // namespace mujoco_ros_msgs


namespace mujoco_ros_msgs
{

namespace srv
{

namespace builder
{

class Init_GetPluginStats_Event_response
{
public:
  explicit Init_GetPluginStats_Event_response(::mujoco_ros_msgs::srv::GetPluginStats_Event & msg)
  : msg_(msg)
  {}
  ::mujoco_ros_msgs::srv::GetPluginStats_Event response(::mujoco_ros_msgs::srv::GetPluginStats_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mujoco_ros_msgs::srv::GetPluginStats_Event msg_;
};

class Init_GetPluginStats_Event_request
{
public:
  explicit Init_GetPluginStats_Event_request(::mujoco_ros_msgs::srv::GetPluginStats_Event & msg)
  : msg_(msg)
  {}
  Init_GetPluginStats_Event_response request(::mujoco_ros_msgs::srv::GetPluginStats_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_GetPluginStats_Event_response(msg_);
  }

private:
  ::mujoco_ros_msgs::srv::GetPluginStats_Event msg_;
};

class Init_GetPluginStats_Event_info
{
public:
  Init_GetPluginStats_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetPluginStats_Event_request info(::mujoco_ros_msgs::srv::GetPluginStats_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_GetPluginStats_Event_request(msg_);
  }

private:
  ::mujoco_ros_msgs::srv::GetPluginStats_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mujoco_ros_msgs::srv::GetPluginStats_Event>()
{
  return mujoco_ros_msgs::srv::builder::Init_GetPluginStats_Event_info();
}

}  // namespace mujoco_ros_msgs

#endif  // MUJOCO_ROS_MSGS__SRV__DETAIL__GET_PLUGIN_STATS__BUILDER_HPP_
