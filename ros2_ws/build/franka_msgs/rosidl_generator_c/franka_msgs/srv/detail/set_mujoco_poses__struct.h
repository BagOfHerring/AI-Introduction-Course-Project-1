// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from franka_msgs:srv/SetMujocoPoses.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "franka_msgs/srv/set_mujoco_poses.h"


#ifndef FRANKA_MSGS__SRV__DETAIL__SET_MUJOCO_POSES__STRUCT_H_
#define FRANKA_MSGS__SRV__DETAIL__SET_MUJOCO_POSES__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'objects'
#include "geometry_msgs/msg/detail/pose_stamped__struct.h"

/// Struct defined in srv/SetMujocoPoses in the package franka_msgs.
typedef struct franka_msgs__srv__SetMujocoPoses_Request
{
  geometry_msgs__msg__PoseStamped__Sequence objects;
} franka_msgs__srv__SetMujocoPoses_Request;

// Struct for a sequence of franka_msgs__srv__SetMujocoPoses_Request.
typedef struct franka_msgs__srv__SetMujocoPoses_Request__Sequence
{
  franka_msgs__srv__SetMujocoPoses_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} franka_msgs__srv__SetMujocoPoses_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'valid'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/SetMujocoPoses in the package franka_msgs.
typedef struct franka_msgs__srv__SetMujocoPoses_Response
{
  rosidl_runtime_c__boolean__Sequence valid;
} franka_msgs__srv__SetMujocoPoses_Response;

// Struct for a sequence of franka_msgs__srv__SetMujocoPoses_Response.
typedef struct franka_msgs__srv__SetMujocoPoses_Response__Sequence
{
  franka_msgs__srv__SetMujocoPoses_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} franka_msgs__srv__SetMujocoPoses_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  franka_msgs__srv__SetMujocoPoses_Event__request__MAX_SIZE = 1
};
// response
enum
{
  franka_msgs__srv__SetMujocoPoses_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/SetMujocoPoses in the package franka_msgs.
typedef struct franka_msgs__srv__SetMujocoPoses_Event
{
  service_msgs__msg__ServiceEventInfo info;
  franka_msgs__srv__SetMujocoPoses_Request__Sequence request;
  franka_msgs__srv__SetMujocoPoses_Response__Sequence response;
} franka_msgs__srv__SetMujocoPoses_Event;

// Struct for a sequence of franka_msgs__srv__SetMujocoPoses_Event.
typedef struct franka_msgs__srv__SetMujocoPoses_Event__Sequence
{
  franka_msgs__srv__SetMujocoPoses_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} franka_msgs__srv__SetMujocoPoses_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FRANKA_MSGS__SRV__DETAIL__SET_MUJOCO_POSES__STRUCT_H_
