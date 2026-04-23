// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from multi_mode_control_msgs:srv/SetRecoveryMode.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "multi_mode_control_msgs/srv/set_recovery_mode.h"


#ifndef MULTI_MODE_CONTROL_MSGS__SRV__DETAIL__SET_RECOVERY_MODE__STRUCT_H_
#define MULTI_MODE_CONTROL_MSGS__SRV__DETAIL__SET_RECOVERY_MODE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'AUTO'.
enum
{
  multi_mode_control_msgs__srv__SetRecoveryMode_Request__AUTO = 0l
};

/// Constant 'MANUAL'.
enum
{
  multi_mode_control_msgs__srv__SetRecoveryMode_Request__MANUAL = 1l
};

/// Constant 'PROGRAM'.
enum
{
  multi_mode_control_msgs__srv__SetRecoveryMode_Request__PROGRAM = 2l
};

/// Struct defined in srv/SetRecoveryMode in the package multi_mode_control_msgs.
typedef struct multi_mode_control_msgs__srv__SetRecoveryMode_Request
{
  int32_t mode;
  double timeout;
} multi_mode_control_msgs__srv__SetRecoveryMode_Request;

// Struct for a sequence of multi_mode_control_msgs__srv__SetRecoveryMode_Request.
typedef struct multi_mode_control_msgs__srv__SetRecoveryMode_Request__Sequence
{
  multi_mode_control_msgs__srv__SetRecoveryMode_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} multi_mode_control_msgs__srv__SetRecoveryMode_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/SetRecoveryMode in the package multi_mode_control_msgs.
typedef struct multi_mode_control_msgs__srv__SetRecoveryMode_Response
{
  uint8_t structure_needs_at_least_one_member;
} multi_mode_control_msgs__srv__SetRecoveryMode_Response;

// Struct for a sequence of multi_mode_control_msgs__srv__SetRecoveryMode_Response.
typedef struct multi_mode_control_msgs__srv__SetRecoveryMode_Response__Sequence
{
  multi_mode_control_msgs__srv__SetRecoveryMode_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} multi_mode_control_msgs__srv__SetRecoveryMode_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  multi_mode_control_msgs__srv__SetRecoveryMode_Event__request__MAX_SIZE = 1
};
// response
enum
{
  multi_mode_control_msgs__srv__SetRecoveryMode_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/SetRecoveryMode in the package multi_mode_control_msgs.
typedef struct multi_mode_control_msgs__srv__SetRecoveryMode_Event
{
  service_msgs__msg__ServiceEventInfo info;
  multi_mode_control_msgs__srv__SetRecoveryMode_Request__Sequence request;
  multi_mode_control_msgs__srv__SetRecoveryMode_Response__Sequence response;
} multi_mode_control_msgs__srv__SetRecoveryMode_Event;

// Struct for a sequence of multi_mode_control_msgs__srv__SetRecoveryMode_Event.
typedef struct multi_mode_control_msgs__srv__SetRecoveryMode_Event__Sequence
{
  multi_mode_control_msgs__srv__SetRecoveryMode_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} multi_mode_control_msgs__srv__SetRecoveryMode_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MULTI_MODE_CONTROL_MSGS__SRV__DETAIL__SET_RECOVERY_MODE__STRUCT_H_
