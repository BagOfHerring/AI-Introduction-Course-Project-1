// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mujoco_ros_msgs:srv/GetPluginStats.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "mujoco_ros_msgs/srv/get_plugin_stats.h"


#ifndef MUJOCO_ROS_MSGS__SRV__DETAIL__GET_PLUGIN_STATS__STRUCT_H_
#define MUJOCO_ROS_MSGS__SRV__DETAIL__GET_PLUGIN_STATS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GetPluginStats in the package mujoco_ros_msgs.
typedef struct mujoco_ros_msgs__srv__GetPluginStats_Request
{
  uint8_t structure_needs_at_least_one_member;
} mujoco_ros_msgs__srv__GetPluginStats_Request;

// Struct for a sequence of mujoco_ros_msgs__srv__GetPluginStats_Request.
typedef struct mujoco_ros_msgs__srv__GetPluginStats_Request__Sequence
{
  mujoco_ros_msgs__srv__GetPluginStats_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mujoco_ros_msgs__srv__GetPluginStats_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'stats'
#include "mujoco_ros_msgs/msg/detail/plugin_stats__struct.h"

/// Struct defined in srv/GetPluginStats in the package mujoco_ros_msgs.
typedef struct mujoco_ros_msgs__srv__GetPluginStats_Response
{
  mujoco_ros_msgs__msg__PluginStats__Sequence stats;
} mujoco_ros_msgs__srv__GetPluginStats_Response;

// Struct for a sequence of mujoco_ros_msgs__srv__GetPluginStats_Response.
typedef struct mujoco_ros_msgs__srv__GetPluginStats_Response__Sequence
{
  mujoco_ros_msgs__srv__GetPluginStats_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mujoco_ros_msgs__srv__GetPluginStats_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  mujoco_ros_msgs__srv__GetPluginStats_Event__request__MAX_SIZE = 1
};
// response
enum
{
  mujoco_ros_msgs__srv__GetPluginStats_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/GetPluginStats in the package mujoco_ros_msgs.
typedef struct mujoco_ros_msgs__srv__GetPluginStats_Event
{
  service_msgs__msg__ServiceEventInfo info;
  mujoco_ros_msgs__srv__GetPluginStats_Request__Sequence request;
  mujoco_ros_msgs__srv__GetPluginStats_Response__Sequence response;
} mujoco_ros_msgs__srv__GetPluginStats_Event;

// Struct for a sequence of mujoco_ros_msgs__srv__GetPluginStats_Event.
typedef struct mujoco_ros_msgs__srv__GetPluginStats_Event__Sequence
{
  mujoco_ros_msgs__srv__GetPluginStats_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mujoco_ros_msgs__srv__GetPluginStats_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MUJOCO_ROS_MSGS__SRV__DETAIL__GET_PLUGIN_STATS__STRUCT_H_
