// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from mujoco_ros_msgs:srv/GetSimInfo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "mujoco_ros_msgs/srv/get_sim_info.hpp"


#ifndef MUJOCO_ROS_MSGS__SRV__DETAIL__GET_SIM_INFO__TRAITS_HPP_
#define MUJOCO_ROS_MSGS__SRV__DETAIL__GET_SIM_INFO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "mujoco_ros_msgs/srv/detail/get_sim_info__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace mujoco_ros_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetSimInfo_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetSimInfo_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetSimInfo_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace mujoco_ros_msgs

namespace rosidl_generator_traits
{

[[deprecated("use mujoco_ros_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const mujoco_ros_msgs::srv::GetSimInfo_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  mujoco_ros_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mujoco_ros_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const mujoco_ros_msgs::srv::GetSimInfo_Request & msg)
{
  return mujoco_ros_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<mujoco_ros_msgs::srv::GetSimInfo_Request>()
{
  return "mujoco_ros_msgs::srv::GetSimInfo_Request";
}

template<>
inline const char * name<mujoco_ros_msgs::srv::GetSimInfo_Request>()
{
  return "mujoco_ros_msgs/srv/GetSimInfo_Request";
}

template<>
struct has_fixed_size<mujoco_ros_msgs::srv::GetSimInfo_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<mujoco_ros_msgs::srv::GetSimInfo_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<mujoco_ros_msgs::srv::GetSimInfo_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'state'
#include "mujoco_ros_msgs/msg/detail/sim_info__traits.hpp"

namespace mujoco_ros_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetSimInfo_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: state
  {
    out << "state: ";
    to_flow_style_yaml(msg.state, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetSimInfo_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state:\n";
    to_block_style_yaml(msg.state, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetSimInfo_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace mujoco_ros_msgs

namespace rosidl_generator_traits
{

[[deprecated("use mujoco_ros_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const mujoco_ros_msgs::srv::GetSimInfo_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  mujoco_ros_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mujoco_ros_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const mujoco_ros_msgs::srv::GetSimInfo_Response & msg)
{
  return mujoco_ros_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<mujoco_ros_msgs::srv::GetSimInfo_Response>()
{
  return "mujoco_ros_msgs::srv::GetSimInfo_Response";
}

template<>
inline const char * name<mujoco_ros_msgs::srv::GetSimInfo_Response>()
{
  return "mujoco_ros_msgs/srv/GetSimInfo_Response";
}

template<>
struct has_fixed_size<mujoco_ros_msgs::srv::GetSimInfo_Response>
  : std::integral_constant<bool, has_fixed_size<mujoco_ros_msgs::msg::SimInfo>::value> {};

template<>
struct has_bounded_size<mujoco_ros_msgs::srv::GetSimInfo_Response>
  : std::integral_constant<bool, has_bounded_size<mujoco_ros_msgs::msg::SimInfo>::value> {};

template<>
struct is_message<mujoco_ros_msgs::srv::GetSimInfo_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace mujoco_ros_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetSimInfo_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetSimInfo_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetSimInfo_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace mujoco_ros_msgs

namespace rosidl_generator_traits
{

[[deprecated("use mujoco_ros_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const mujoco_ros_msgs::srv::GetSimInfo_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  mujoco_ros_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mujoco_ros_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const mujoco_ros_msgs::srv::GetSimInfo_Event & msg)
{
  return mujoco_ros_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<mujoco_ros_msgs::srv::GetSimInfo_Event>()
{
  return "mujoco_ros_msgs::srv::GetSimInfo_Event";
}

template<>
inline const char * name<mujoco_ros_msgs::srv::GetSimInfo_Event>()
{
  return "mujoco_ros_msgs/srv/GetSimInfo_Event";
}

template<>
struct has_fixed_size<mujoco_ros_msgs::srv::GetSimInfo_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<mujoco_ros_msgs::srv::GetSimInfo_Event>
  : std::integral_constant<bool, has_bounded_size<mujoco_ros_msgs::srv::GetSimInfo_Request>::value && has_bounded_size<mujoco_ros_msgs::srv::GetSimInfo_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<mujoco_ros_msgs::srv::GetSimInfo_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<mujoco_ros_msgs::srv::GetSimInfo>()
{
  return "mujoco_ros_msgs::srv::GetSimInfo";
}

template<>
inline const char * name<mujoco_ros_msgs::srv::GetSimInfo>()
{
  return "mujoco_ros_msgs/srv/GetSimInfo";
}

template<>
struct has_fixed_size<mujoco_ros_msgs::srv::GetSimInfo>
  : std::integral_constant<
    bool,
    has_fixed_size<mujoco_ros_msgs::srv::GetSimInfo_Request>::value &&
    has_fixed_size<mujoco_ros_msgs::srv::GetSimInfo_Response>::value
  >
{
};

template<>
struct has_bounded_size<mujoco_ros_msgs::srv::GetSimInfo>
  : std::integral_constant<
    bool,
    has_bounded_size<mujoco_ros_msgs::srv::GetSimInfo_Request>::value &&
    has_bounded_size<mujoco_ros_msgs::srv::GetSimInfo_Response>::value
  >
{
};

template<>
struct is_service<mujoco_ros_msgs::srv::GetSimInfo>
  : std::true_type
{
};

template<>
struct is_service_request<mujoco_ros_msgs::srv::GetSimInfo_Request>
  : std::true_type
{
};

template<>
struct is_service_response<mujoco_ros_msgs::srv::GetSimInfo_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MUJOCO_ROS_MSGS__SRV__DETAIL__GET_SIM_INFO__TRAITS_HPP_
