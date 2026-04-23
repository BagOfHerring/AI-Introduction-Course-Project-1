// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from franka_msgs:srv/SetMujocoPoses.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "franka_msgs/srv/set_mujoco_poses.hpp"


#ifndef FRANKA_MSGS__SRV__DETAIL__SET_MUJOCO_POSES__TRAITS_HPP_
#define FRANKA_MSGS__SRV__DETAIL__SET_MUJOCO_POSES__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "franka_msgs/srv/detail/set_mujoco_poses__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'objects'
#include "geometry_msgs/msg/detail/pose_stamped__traits.hpp"

namespace franka_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetMujocoPoses_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: objects
  {
    if (msg.objects.size() == 0) {
      out << "objects: []";
    } else {
      out << "objects: [";
      size_t pending_items = msg.objects.size();
      for (auto item : msg.objects) {
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
  const SetMujocoPoses_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: objects
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.objects.size() == 0) {
      out << "objects: []\n";
    } else {
      out << "objects:\n";
      for (auto item : msg.objects) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetMujocoPoses_Request & msg, bool use_flow_style = false)
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

}  // namespace franka_msgs

namespace rosidl_generator_traits
{

[[deprecated("use franka_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const franka_msgs::srv::SetMujocoPoses_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  franka_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use franka_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const franka_msgs::srv::SetMujocoPoses_Request & msg)
{
  return franka_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<franka_msgs::srv::SetMujocoPoses_Request>()
{
  return "franka_msgs::srv::SetMujocoPoses_Request";
}

template<>
inline const char * name<franka_msgs::srv::SetMujocoPoses_Request>()
{
  return "franka_msgs/srv/SetMujocoPoses_Request";
}

template<>
struct has_fixed_size<franka_msgs::srv::SetMujocoPoses_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<franka_msgs::srv::SetMujocoPoses_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<franka_msgs::srv::SetMujocoPoses_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace franka_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetMujocoPoses_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: valid
  {
    if (msg.valid.size() == 0) {
      out << "valid: []";
    } else {
      out << "valid: [";
      size_t pending_items = msg.valid.size();
      for (auto item : msg.valid) {
        rosidl_generator_traits::value_to_yaml(item, out);
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
  const SetMujocoPoses_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.valid.size() == 0) {
      out << "valid: []\n";
    } else {
      out << "valid:\n";
      for (auto item : msg.valid) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetMujocoPoses_Response & msg, bool use_flow_style = false)
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

}  // namespace franka_msgs

namespace rosidl_generator_traits
{

[[deprecated("use franka_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const franka_msgs::srv::SetMujocoPoses_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  franka_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use franka_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const franka_msgs::srv::SetMujocoPoses_Response & msg)
{
  return franka_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<franka_msgs::srv::SetMujocoPoses_Response>()
{
  return "franka_msgs::srv::SetMujocoPoses_Response";
}

template<>
inline const char * name<franka_msgs::srv::SetMujocoPoses_Response>()
{
  return "franka_msgs/srv/SetMujocoPoses_Response";
}

template<>
struct has_fixed_size<franka_msgs::srv::SetMujocoPoses_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<franka_msgs::srv::SetMujocoPoses_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<franka_msgs::srv::SetMujocoPoses_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace franka_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetMujocoPoses_Event & msg,
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
  const SetMujocoPoses_Event & msg,
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

inline std::string to_yaml(const SetMujocoPoses_Event & msg, bool use_flow_style = false)
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

}  // namespace franka_msgs

namespace rosidl_generator_traits
{

[[deprecated("use franka_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const franka_msgs::srv::SetMujocoPoses_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  franka_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use franka_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const franka_msgs::srv::SetMujocoPoses_Event & msg)
{
  return franka_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<franka_msgs::srv::SetMujocoPoses_Event>()
{
  return "franka_msgs::srv::SetMujocoPoses_Event";
}

template<>
inline const char * name<franka_msgs::srv::SetMujocoPoses_Event>()
{
  return "franka_msgs/srv/SetMujocoPoses_Event";
}

template<>
struct has_fixed_size<franka_msgs::srv::SetMujocoPoses_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<franka_msgs::srv::SetMujocoPoses_Event>
  : std::integral_constant<bool, has_bounded_size<franka_msgs::srv::SetMujocoPoses_Request>::value && has_bounded_size<franka_msgs::srv::SetMujocoPoses_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<franka_msgs::srv::SetMujocoPoses_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<franka_msgs::srv::SetMujocoPoses>()
{
  return "franka_msgs::srv::SetMujocoPoses";
}

template<>
inline const char * name<franka_msgs::srv::SetMujocoPoses>()
{
  return "franka_msgs/srv/SetMujocoPoses";
}

template<>
struct has_fixed_size<franka_msgs::srv::SetMujocoPoses>
  : std::integral_constant<
    bool,
    has_fixed_size<franka_msgs::srv::SetMujocoPoses_Request>::value &&
    has_fixed_size<franka_msgs::srv::SetMujocoPoses_Response>::value
  >
{
};

template<>
struct has_bounded_size<franka_msgs::srv::SetMujocoPoses>
  : std::integral_constant<
    bool,
    has_bounded_size<franka_msgs::srv::SetMujocoPoses_Request>::value &&
    has_bounded_size<franka_msgs::srv::SetMujocoPoses_Response>::value
  >
{
};

template<>
struct is_service<franka_msgs::srv::SetMujocoPoses>
  : std::true_type
{
};

template<>
struct is_service_request<franka_msgs::srv::SetMujocoPoses_Request>
  : std::true_type
{
};

template<>
struct is_service_response<franka_msgs::srv::SetMujocoPoses_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // FRANKA_MSGS__SRV__DETAIL__SET_MUJOCO_POSES__TRAITS_HPP_
