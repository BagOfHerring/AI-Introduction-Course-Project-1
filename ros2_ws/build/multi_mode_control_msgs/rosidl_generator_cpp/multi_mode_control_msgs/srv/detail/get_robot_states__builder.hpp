// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from multi_mode_control_msgs:srv/GetRobotStates.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "multi_mode_control_msgs/srv/get_robot_states.hpp"


#ifndef MULTI_MODE_CONTROL_MSGS__SRV__DETAIL__GET_ROBOT_STATES__BUILDER_HPP_
#define MULTI_MODE_CONTROL_MSGS__SRV__DETAIL__GET_ROBOT_STATES__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "multi_mode_control_msgs/srv/detail/get_robot_states__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace multi_mode_control_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::multi_mode_control_msgs::srv::GetRobotStates_Request>()
{
  return ::multi_mode_control_msgs::srv::GetRobotStates_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace multi_mode_control_msgs


namespace multi_mode_control_msgs
{

namespace srv
{

namespace builder
{

class Init_GetRobotStates_Response_states
{
public:
  Init_GetRobotStates_Response_states()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::multi_mode_control_msgs::srv::GetRobotStates_Response states(::multi_mode_control_msgs::srv::GetRobotStates_Response::_states_type arg)
  {
    msg_.states = std::move(arg);
    return std::move(msg_);
  }

private:
  ::multi_mode_control_msgs::srv::GetRobotStates_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::multi_mode_control_msgs::srv::GetRobotStates_Response>()
{
  return multi_mode_control_msgs::srv::builder::Init_GetRobotStates_Response_states();
}

}  // namespace multi_mode_control_msgs


namespace multi_mode_control_msgs
{

namespace srv
{

namespace builder
{

class Init_GetRobotStates_Event_response
{
public:
  explicit Init_GetRobotStates_Event_response(::multi_mode_control_msgs::srv::GetRobotStates_Event & msg)
  : msg_(msg)
  {}
  ::multi_mode_control_msgs::srv::GetRobotStates_Event response(::multi_mode_control_msgs::srv::GetRobotStates_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::multi_mode_control_msgs::srv::GetRobotStates_Event msg_;
};

class Init_GetRobotStates_Event_request
{
public:
  explicit Init_GetRobotStates_Event_request(::multi_mode_control_msgs::srv::GetRobotStates_Event & msg)
  : msg_(msg)
  {}
  Init_GetRobotStates_Event_response request(::multi_mode_control_msgs::srv::GetRobotStates_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_GetRobotStates_Event_response(msg_);
  }

private:
  ::multi_mode_control_msgs::srv::GetRobotStates_Event msg_;
};

class Init_GetRobotStates_Event_info
{
public:
  Init_GetRobotStates_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetRobotStates_Event_request info(::multi_mode_control_msgs::srv::GetRobotStates_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_GetRobotStates_Event_request(msg_);
  }

private:
  ::multi_mode_control_msgs::srv::GetRobotStates_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::multi_mode_control_msgs::srv::GetRobotStates_Event>()
{
  return multi_mode_control_msgs::srv::builder::Init_GetRobotStates_Event_info();
}

}  // namespace multi_mode_control_msgs

#endif  // MULTI_MODE_CONTROL_MSGS__SRV__DETAIL__GET_ROBOT_STATES__BUILDER_HPP_
