// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from multi_mode_control_msgs:srv/SetReflex.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "multi_mode_control_msgs/srv/set_reflex.hpp"


#ifndef MULTI_MODE_CONTROL_MSGS__SRV__DETAIL__SET_REFLEX__BUILDER_HPP_
#define MULTI_MODE_CONTROL_MSGS__SRV__DETAIL__SET_REFLEX__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "multi_mode_control_msgs/srv/detail/set_reflex__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace multi_mode_control_msgs
{

namespace srv
{

namespace builder
{

class Init_SetReflex_Request_level2
{
public:
  explicit Init_SetReflex_Request_level2(::multi_mode_control_msgs::srv::SetReflex_Request & msg)
  : msg_(msg)
  {}
  ::multi_mode_control_msgs::srv::SetReflex_Request level2(::multi_mode_control_msgs::srv::SetReflex_Request::_level2_type arg)
  {
    msg_.level2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::multi_mode_control_msgs::srv::SetReflex_Request msg_;
};

class Init_SetReflex_Request_level1
{
public:
  Init_SetReflex_Request_level1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetReflex_Request_level2 level1(::multi_mode_control_msgs::srv::SetReflex_Request::_level1_type arg)
  {
    msg_.level1 = std::move(arg);
    return Init_SetReflex_Request_level2(msg_);
  }

private:
  ::multi_mode_control_msgs::srv::SetReflex_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::multi_mode_control_msgs::srv::SetReflex_Request>()
{
  return multi_mode_control_msgs::srv::builder::Init_SetReflex_Request_level1();
}

}  // namespace multi_mode_control_msgs


namespace multi_mode_control_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::multi_mode_control_msgs::srv::SetReflex_Response>()
{
  return ::multi_mode_control_msgs::srv::SetReflex_Response(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace multi_mode_control_msgs


namespace multi_mode_control_msgs
{

namespace srv
{

namespace builder
{

class Init_SetReflex_Event_response
{
public:
  explicit Init_SetReflex_Event_response(::multi_mode_control_msgs::srv::SetReflex_Event & msg)
  : msg_(msg)
  {}
  ::multi_mode_control_msgs::srv::SetReflex_Event response(::multi_mode_control_msgs::srv::SetReflex_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::multi_mode_control_msgs::srv::SetReflex_Event msg_;
};

class Init_SetReflex_Event_request
{
public:
  explicit Init_SetReflex_Event_request(::multi_mode_control_msgs::srv::SetReflex_Event & msg)
  : msg_(msg)
  {}
  Init_SetReflex_Event_response request(::multi_mode_control_msgs::srv::SetReflex_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_SetReflex_Event_response(msg_);
  }

private:
  ::multi_mode_control_msgs::srv::SetReflex_Event msg_;
};

class Init_SetReflex_Event_info
{
public:
  Init_SetReflex_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetReflex_Event_request info(::multi_mode_control_msgs::srv::SetReflex_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_SetReflex_Event_request(msg_);
  }

private:
  ::multi_mode_control_msgs::srv::SetReflex_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::multi_mode_control_msgs::srv::SetReflex_Event>()
{
  return multi_mode_control_msgs::srv::builder::Init_SetReflex_Event_info();
}

}  // namespace multi_mode_control_msgs

#endif  // MULTI_MODE_CONTROL_MSGS__SRV__DETAIL__SET_REFLEX__BUILDER_HPP_
