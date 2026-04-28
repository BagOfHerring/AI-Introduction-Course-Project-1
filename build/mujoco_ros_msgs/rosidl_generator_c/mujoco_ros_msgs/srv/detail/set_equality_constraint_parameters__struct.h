// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mujoco_ros_msgs:srv/SetEqualityConstraintParameters.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "mujoco_ros_msgs/srv/set_equality_constraint_parameters.h"


#ifndef MUJOCO_ROS_MSGS__SRV__DETAIL__SET_EQUALITY_CONSTRAINT_PARAMETERS__STRUCT_H_
#define MUJOCO_ROS_MSGS__SRV__DETAIL__SET_EQUALITY_CONSTRAINT_PARAMETERS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'parameters'
#include "mujoco_ros_msgs/msg/detail/equality_constraint_parameters__struct.h"
// Member 'admin_hash'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SetEqualityConstraintParameters in the package mujoco_ros_msgs.
typedef struct mujoco_ros_msgs__srv__SetEqualityConstraintParameters_Request
{
  mujoco_ros_msgs__msg__EqualityConstraintParameters__Sequence parameters;
  rosidl_runtime_c__String admin_hash;
} mujoco_ros_msgs__srv__SetEqualityConstraintParameters_Request;

// Struct for a sequence of mujoco_ros_msgs__srv__SetEqualityConstraintParameters_Request.
typedef struct mujoco_ros_msgs__srv__SetEqualityConstraintParameters_Request__Sequence
{
  mujoco_ros_msgs__srv__SetEqualityConstraintParameters_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mujoco_ros_msgs__srv__SetEqualityConstraintParameters_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'status_message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SetEqualityConstraintParameters in the package mujoco_ros_msgs.
typedef struct mujoco_ros_msgs__srv__SetEqualityConstraintParameters_Response
{
  bool success;
  rosidl_runtime_c__String status_message;
} mujoco_ros_msgs__srv__SetEqualityConstraintParameters_Response;

// Struct for a sequence of mujoco_ros_msgs__srv__SetEqualityConstraintParameters_Response.
typedef struct mujoco_ros_msgs__srv__SetEqualityConstraintParameters_Response__Sequence
{
  mujoco_ros_msgs__srv__SetEqualityConstraintParameters_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mujoco_ros_msgs__srv__SetEqualityConstraintParameters_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  mujoco_ros_msgs__srv__SetEqualityConstraintParameters_Event__request__MAX_SIZE = 1
};
// response
enum
{
  mujoco_ros_msgs__srv__SetEqualityConstraintParameters_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/SetEqualityConstraintParameters in the package mujoco_ros_msgs.
typedef struct mujoco_ros_msgs__srv__SetEqualityConstraintParameters_Event
{
  service_msgs__msg__ServiceEventInfo info;
  mujoco_ros_msgs__srv__SetEqualityConstraintParameters_Request__Sequence request;
  mujoco_ros_msgs__srv__SetEqualityConstraintParameters_Response__Sequence response;
} mujoco_ros_msgs__srv__SetEqualityConstraintParameters_Event;

// Struct for a sequence of mujoco_ros_msgs__srv__SetEqualityConstraintParameters_Event.
typedef struct mujoco_ros_msgs__srv__SetEqualityConstraintParameters_Event__Sequence
{
  mujoco_ros_msgs__srv__SetEqualityConstraintParameters_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mujoco_ros_msgs__srv__SetEqualityConstraintParameters_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MUJOCO_ROS_MSGS__SRV__DETAIL__SET_EQUALITY_CONSTRAINT_PARAMETERS__STRUCT_H_
