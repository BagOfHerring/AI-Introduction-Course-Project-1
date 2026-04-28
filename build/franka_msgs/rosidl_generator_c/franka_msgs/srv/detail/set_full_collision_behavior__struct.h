// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from franka_msgs:srv/SetFullCollisionBehavior.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "franka_msgs/srv/set_full_collision_behavior.h"


#ifndef FRANKA_MSGS__SRV__DETAIL__SET_FULL_COLLISION_BEHAVIOR__STRUCT_H_
#define FRANKA_MSGS__SRV__DETAIL__SET_FULL_COLLISION_BEHAVIOR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SetFullCollisionBehavior in the package franka_msgs.
typedef struct franka_msgs__srv__SetFullCollisionBehavior_Request
{
  double lower_torque_thresholds_acceleration[7];
  double upper_torque_thresholds_acceleration[7];
  double lower_torque_thresholds_nominal[7];
  double upper_torque_thresholds_nominal[7];
  double lower_force_thresholds_acceleration[6];
  double upper_force_thresholds_acceleration[6];
  double lower_force_thresholds_nominal[6];
  double upper_force_thresholds_nominal[6];
} franka_msgs__srv__SetFullCollisionBehavior_Request;

// Struct for a sequence of franka_msgs__srv__SetFullCollisionBehavior_Request.
typedef struct franka_msgs__srv__SetFullCollisionBehavior_Request__Sequence
{
  franka_msgs__srv__SetFullCollisionBehavior_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} franka_msgs__srv__SetFullCollisionBehavior_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'error'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SetFullCollisionBehavior in the package franka_msgs.
typedef struct franka_msgs__srv__SetFullCollisionBehavior_Response
{
  bool success;
  rosidl_runtime_c__String error;
} franka_msgs__srv__SetFullCollisionBehavior_Response;

// Struct for a sequence of franka_msgs__srv__SetFullCollisionBehavior_Response.
typedef struct franka_msgs__srv__SetFullCollisionBehavior_Response__Sequence
{
  franka_msgs__srv__SetFullCollisionBehavior_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} franka_msgs__srv__SetFullCollisionBehavior_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  franka_msgs__srv__SetFullCollisionBehavior_Event__request__MAX_SIZE = 1
};
// response
enum
{
  franka_msgs__srv__SetFullCollisionBehavior_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/SetFullCollisionBehavior in the package franka_msgs.
typedef struct franka_msgs__srv__SetFullCollisionBehavior_Event
{
  service_msgs__msg__ServiceEventInfo info;
  franka_msgs__srv__SetFullCollisionBehavior_Request__Sequence request;
  franka_msgs__srv__SetFullCollisionBehavior_Response__Sequence response;
} franka_msgs__srv__SetFullCollisionBehavior_Event;

// Struct for a sequence of franka_msgs__srv__SetFullCollisionBehavior_Event.
typedef struct franka_msgs__srv__SetFullCollisionBehavior_Event__Sequence
{
  franka_msgs__srv__SetFullCollisionBehavior_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} franka_msgs__srv__SetFullCollisionBehavior_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FRANKA_MSGS__SRV__DETAIL__SET_FULL_COLLISION_BEHAVIOR__STRUCT_H_
