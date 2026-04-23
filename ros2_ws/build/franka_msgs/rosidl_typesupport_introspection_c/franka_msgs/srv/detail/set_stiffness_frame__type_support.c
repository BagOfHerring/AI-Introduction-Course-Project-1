// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from franka_msgs:srv/SetStiffnessFrame.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "franka_msgs/srv/detail/set_stiffness_frame__rosidl_typesupport_introspection_c.h"
#include "franka_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "franka_msgs/srv/detail/set_stiffness_frame__functions.h"
#include "franka_msgs/srv/detail/set_stiffness_frame__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void franka_msgs__srv__SetStiffnessFrame_Request__rosidl_typesupport_introspection_c__SetStiffnessFrame_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  franka_msgs__srv__SetStiffnessFrame_Request__init(message_memory);
}

void franka_msgs__srv__SetStiffnessFrame_Request__rosidl_typesupport_introspection_c__SetStiffnessFrame_Request_fini_function(void * message_memory)
{
  franka_msgs__srv__SetStiffnessFrame_Request__fini(message_memory);
}

size_t franka_msgs__srv__SetStiffnessFrame_Request__rosidl_typesupport_introspection_c__size_function__SetStiffnessFrame_Request__transformation(
  const void * untyped_member)
{
  (void)untyped_member;
  return 16;
}

const void * franka_msgs__srv__SetStiffnessFrame_Request__rosidl_typesupport_introspection_c__get_const_function__SetStiffnessFrame_Request__transformation(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * franka_msgs__srv__SetStiffnessFrame_Request__rosidl_typesupport_introspection_c__get_function__SetStiffnessFrame_Request__transformation(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void franka_msgs__srv__SetStiffnessFrame_Request__rosidl_typesupport_introspection_c__fetch_function__SetStiffnessFrame_Request__transformation(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    franka_msgs__srv__SetStiffnessFrame_Request__rosidl_typesupport_introspection_c__get_const_function__SetStiffnessFrame_Request__transformation(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void franka_msgs__srv__SetStiffnessFrame_Request__rosidl_typesupport_introspection_c__assign_function__SetStiffnessFrame_Request__transformation(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    franka_msgs__srv__SetStiffnessFrame_Request__rosidl_typesupport_introspection_c__get_function__SetStiffnessFrame_Request__transformation(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember franka_msgs__srv__SetStiffnessFrame_Request__rosidl_typesupport_introspection_c__SetStiffnessFrame_Request_message_member_array[1] = {
  {
    "transformation",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    16,  // array size
    false,  // is upper bound
    offsetof(franka_msgs__srv__SetStiffnessFrame_Request, transformation),  // bytes offset in struct
    NULL,  // default value
    franka_msgs__srv__SetStiffnessFrame_Request__rosidl_typesupport_introspection_c__size_function__SetStiffnessFrame_Request__transformation,  // size() function pointer
    franka_msgs__srv__SetStiffnessFrame_Request__rosidl_typesupport_introspection_c__get_const_function__SetStiffnessFrame_Request__transformation,  // get_const(index) function pointer
    franka_msgs__srv__SetStiffnessFrame_Request__rosidl_typesupport_introspection_c__get_function__SetStiffnessFrame_Request__transformation,  // get(index) function pointer
    franka_msgs__srv__SetStiffnessFrame_Request__rosidl_typesupport_introspection_c__fetch_function__SetStiffnessFrame_Request__transformation,  // fetch(index, &value) function pointer
    franka_msgs__srv__SetStiffnessFrame_Request__rosidl_typesupport_introspection_c__assign_function__SetStiffnessFrame_Request__transformation,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers franka_msgs__srv__SetStiffnessFrame_Request__rosidl_typesupport_introspection_c__SetStiffnessFrame_Request_message_members = {
  "franka_msgs__srv",  // message namespace
  "SetStiffnessFrame_Request",  // message name
  1,  // number of fields
  sizeof(franka_msgs__srv__SetStiffnessFrame_Request),
  false,  // has_any_key_member_
  franka_msgs__srv__SetStiffnessFrame_Request__rosidl_typesupport_introspection_c__SetStiffnessFrame_Request_message_member_array,  // message members
  franka_msgs__srv__SetStiffnessFrame_Request__rosidl_typesupport_introspection_c__SetStiffnessFrame_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  franka_msgs__srv__SetStiffnessFrame_Request__rosidl_typesupport_introspection_c__SetStiffnessFrame_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t franka_msgs__srv__SetStiffnessFrame_Request__rosidl_typesupport_introspection_c__SetStiffnessFrame_Request_message_type_support_handle = {
  0,
  &franka_msgs__srv__SetStiffnessFrame_Request__rosidl_typesupport_introspection_c__SetStiffnessFrame_Request_message_members,
  get_message_typesupport_handle_function,
  &franka_msgs__srv__SetStiffnessFrame_Request__get_type_hash,
  &franka_msgs__srv__SetStiffnessFrame_Request__get_type_description,
  &franka_msgs__srv__SetStiffnessFrame_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_franka_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, franka_msgs, srv, SetStiffnessFrame_Request)() {
  if (!franka_msgs__srv__SetStiffnessFrame_Request__rosidl_typesupport_introspection_c__SetStiffnessFrame_Request_message_type_support_handle.typesupport_identifier) {
    franka_msgs__srv__SetStiffnessFrame_Request__rosidl_typesupport_introspection_c__SetStiffnessFrame_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &franka_msgs__srv__SetStiffnessFrame_Request__rosidl_typesupport_introspection_c__SetStiffnessFrame_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "franka_msgs/srv/detail/set_stiffness_frame__rosidl_typesupport_introspection_c.h"
// already included above
// #include "franka_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "franka_msgs/srv/detail/set_stiffness_frame__functions.h"
// already included above
// #include "franka_msgs/srv/detail/set_stiffness_frame__struct.h"


// Include directives for member types
// Member `error`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void franka_msgs__srv__SetStiffnessFrame_Response__rosidl_typesupport_introspection_c__SetStiffnessFrame_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  franka_msgs__srv__SetStiffnessFrame_Response__init(message_memory);
}

void franka_msgs__srv__SetStiffnessFrame_Response__rosidl_typesupport_introspection_c__SetStiffnessFrame_Response_fini_function(void * message_memory)
{
  franka_msgs__srv__SetStiffnessFrame_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember franka_msgs__srv__SetStiffnessFrame_Response__rosidl_typesupport_introspection_c__SetStiffnessFrame_Response_message_member_array[2] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(franka_msgs__srv__SetStiffnessFrame_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "error",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(franka_msgs__srv__SetStiffnessFrame_Response, error),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers franka_msgs__srv__SetStiffnessFrame_Response__rosidl_typesupport_introspection_c__SetStiffnessFrame_Response_message_members = {
  "franka_msgs__srv",  // message namespace
  "SetStiffnessFrame_Response",  // message name
  2,  // number of fields
  sizeof(franka_msgs__srv__SetStiffnessFrame_Response),
  false,  // has_any_key_member_
  franka_msgs__srv__SetStiffnessFrame_Response__rosidl_typesupport_introspection_c__SetStiffnessFrame_Response_message_member_array,  // message members
  franka_msgs__srv__SetStiffnessFrame_Response__rosidl_typesupport_introspection_c__SetStiffnessFrame_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  franka_msgs__srv__SetStiffnessFrame_Response__rosidl_typesupport_introspection_c__SetStiffnessFrame_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t franka_msgs__srv__SetStiffnessFrame_Response__rosidl_typesupport_introspection_c__SetStiffnessFrame_Response_message_type_support_handle = {
  0,
  &franka_msgs__srv__SetStiffnessFrame_Response__rosidl_typesupport_introspection_c__SetStiffnessFrame_Response_message_members,
  get_message_typesupport_handle_function,
  &franka_msgs__srv__SetStiffnessFrame_Response__get_type_hash,
  &franka_msgs__srv__SetStiffnessFrame_Response__get_type_description,
  &franka_msgs__srv__SetStiffnessFrame_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_franka_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, franka_msgs, srv, SetStiffnessFrame_Response)() {
  if (!franka_msgs__srv__SetStiffnessFrame_Response__rosidl_typesupport_introspection_c__SetStiffnessFrame_Response_message_type_support_handle.typesupport_identifier) {
    franka_msgs__srv__SetStiffnessFrame_Response__rosidl_typesupport_introspection_c__SetStiffnessFrame_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &franka_msgs__srv__SetStiffnessFrame_Response__rosidl_typesupport_introspection_c__SetStiffnessFrame_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "franka_msgs/srv/detail/set_stiffness_frame__rosidl_typesupport_introspection_c.h"
// already included above
// #include "franka_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "franka_msgs/srv/detail/set_stiffness_frame__functions.h"
// already included above
// #include "franka_msgs/srv/detail/set_stiffness_frame__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "franka_msgs/srv/set_stiffness_frame.h"
// Member `request`
// Member `response`
// already included above
// #include "franka_msgs/srv/detail/set_stiffness_frame__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__SetStiffnessFrame_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  franka_msgs__srv__SetStiffnessFrame_Event__init(message_memory);
}

void franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__SetStiffnessFrame_Event_fini_function(void * message_memory)
{
  franka_msgs__srv__SetStiffnessFrame_Event__fini(message_memory);
}

size_t franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__size_function__SetStiffnessFrame_Event__request(
  const void * untyped_member)
{
  const franka_msgs__srv__SetStiffnessFrame_Request__Sequence * member =
    (const franka_msgs__srv__SetStiffnessFrame_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__get_const_function__SetStiffnessFrame_Event__request(
  const void * untyped_member, size_t index)
{
  const franka_msgs__srv__SetStiffnessFrame_Request__Sequence * member =
    (const franka_msgs__srv__SetStiffnessFrame_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__get_function__SetStiffnessFrame_Event__request(
  void * untyped_member, size_t index)
{
  franka_msgs__srv__SetStiffnessFrame_Request__Sequence * member =
    (franka_msgs__srv__SetStiffnessFrame_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__fetch_function__SetStiffnessFrame_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const franka_msgs__srv__SetStiffnessFrame_Request * item =
    ((const franka_msgs__srv__SetStiffnessFrame_Request *)
    franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__get_const_function__SetStiffnessFrame_Event__request(untyped_member, index));
  franka_msgs__srv__SetStiffnessFrame_Request * value =
    (franka_msgs__srv__SetStiffnessFrame_Request *)(untyped_value);
  *value = *item;
}

void franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__assign_function__SetStiffnessFrame_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  franka_msgs__srv__SetStiffnessFrame_Request * item =
    ((franka_msgs__srv__SetStiffnessFrame_Request *)
    franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__get_function__SetStiffnessFrame_Event__request(untyped_member, index));
  const franka_msgs__srv__SetStiffnessFrame_Request * value =
    (const franka_msgs__srv__SetStiffnessFrame_Request *)(untyped_value);
  *item = *value;
}

bool franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__resize_function__SetStiffnessFrame_Event__request(
  void * untyped_member, size_t size)
{
  franka_msgs__srv__SetStiffnessFrame_Request__Sequence * member =
    (franka_msgs__srv__SetStiffnessFrame_Request__Sequence *)(untyped_member);
  franka_msgs__srv__SetStiffnessFrame_Request__Sequence__fini(member);
  return franka_msgs__srv__SetStiffnessFrame_Request__Sequence__init(member, size);
}

size_t franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__size_function__SetStiffnessFrame_Event__response(
  const void * untyped_member)
{
  const franka_msgs__srv__SetStiffnessFrame_Response__Sequence * member =
    (const franka_msgs__srv__SetStiffnessFrame_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__get_const_function__SetStiffnessFrame_Event__response(
  const void * untyped_member, size_t index)
{
  const franka_msgs__srv__SetStiffnessFrame_Response__Sequence * member =
    (const franka_msgs__srv__SetStiffnessFrame_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__get_function__SetStiffnessFrame_Event__response(
  void * untyped_member, size_t index)
{
  franka_msgs__srv__SetStiffnessFrame_Response__Sequence * member =
    (franka_msgs__srv__SetStiffnessFrame_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__fetch_function__SetStiffnessFrame_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const franka_msgs__srv__SetStiffnessFrame_Response * item =
    ((const franka_msgs__srv__SetStiffnessFrame_Response *)
    franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__get_const_function__SetStiffnessFrame_Event__response(untyped_member, index));
  franka_msgs__srv__SetStiffnessFrame_Response * value =
    (franka_msgs__srv__SetStiffnessFrame_Response *)(untyped_value);
  *value = *item;
}

void franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__assign_function__SetStiffnessFrame_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  franka_msgs__srv__SetStiffnessFrame_Response * item =
    ((franka_msgs__srv__SetStiffnessFrame_Response *)
    franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__get_function__SetStiffnessFrame_Event__response(untyped_member, index));
  const franka_msgs__srv__SetStiffnessFrame_Response * value =
    (const franka_msgs__srv__SetStiffnessFrame_Response *)(untyped_value);
  *item = *value;
}

bool franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__resize_function__SetStiffnessFrame_Event__response(
  void * untyped_member, size_t size)
{
  franka_msgs__srv__SetStiffnessFrame_Response__Sequence * member =
    (franka_msgs__srv__SetStiffnessFrame_Response__Sequence *)(untyped_member);
  franka_msgs__srv__SetStiffnessFrame_Response__Sequence__fini(member);
  return franka_msgs__srv__SetStiffnessFrame_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__SetStiffnessFrame_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(franka_msgs__srv__SetStiffnessFrame_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(franka_msgs__srv__SetStiffnessFrame_Event, request),  // bytes offset in struct
    NULL,  // default value
    franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__size_function__SetStiffnessFrame_Event__request,  // size() function pointer
    franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__get_const_function__SetStiffnessFrame_Event__request,  // get_const(index) function pointer
    franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__get_function__SetStiffnessFrame_Event__request,  // get(index) function pointer
    franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__fetch_function__SetStiffnessFrame_Event__request,  // fetch(index, &value) function pointer
    franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__assign_function__SetStiffnessFrame_Event__request,  // assign(index, value) function pointer
    franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__resize_function__SetStiffnessFrame_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(franka_msgs__srv__SetStiffnessFrame_Event, response),  // bytes offset in struct
    NULL,  // default value
    franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__size_function__SetStiffnessFrame_Event__response,  // size() function pointer
    franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__get_const_function__SetStiffnessFrame_Event__response,  // get_const(index) function pointer
    franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__get_function__SetStiffnessFrame_Event__response,  // get(index) function pointer
    franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__fetch_function__SetStiffnessFrame_Event__response,  // fetch(index, &value) function pointer
    franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__assign_function__SetStiffnessFrame_Event__response,  // assign(index, value) function pointer
    franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__resize_function__SetStiffnessFrame_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__SetStiffnessFrame_Event_message_members = {
  "franka_msgs__srv",  // message namespace
  "SetStiffnessFrame_Event",  // message name
  3,  // number of fields
  sizeof(franka_msgs__srv__SetStiffnessFrame_Event),
  false,  // has_any_key_member_
  franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__SetStiffnessFrame_Event_message_member_array,  // message members
  franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__SetStiffnessFrame_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__SetStiffnessFrame_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__SetStiffnessFrame_Event_message_type_support_handle = {
  0,
  &franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__SetStiffnessFrame_Event_message_members,
  get_message_typesupport_handle_function,
  &franka_msgs__srv__SetStiffnessFrame_Event__get_type_hash,
  &franka_msgs__srv__SetStiffnessFrame_Event__get_type_description,
  &franka_msgs__srv__SetStiffnessFrame_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_franka_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, franka_msgs, srv, SetStiffnessFrame_Event)() {
  franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__SetStiffnessFrame_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__SetStiffnessFrame_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, franka_msgs, srv, SetStiffnessFrame_Request)();
  franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__SetStiffnessFrame_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, franka_msgs, srv, SetStiffnessFrame_Response)();
  if (!franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__SetStiffnessFrame_Event_message_type_support_handle.typesupport_identifier) {
    franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__SetStiffnessFrame_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__SetStiffnessFrame_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "franka_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "franka_msgs/srv/detail/set_stiffness_frame__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers franka_msgs__srv__detail__set_stiffness_frame__rosidl_typesupport_introspection_c__SetStiffnessFrame_service_members = {
  "franka_msgs__srv",  // service namespace
  "SetStiffnessFrame",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // franka_msgs__srv__detail__set_stiffness_frame__rosidl_typesupport_introspection_c__SetStiffnessFrame_Request_message_type_support_handle,
  NULL,  // response message
  // franka_msgs__srv__detail__set_stiffness_frame__rosidl_typesupport_introspection_c__SetStiffnessFrame_Response_message_type_support_handle
  NULL  // event_message
  // franka_msgs__srv__detail__set_stiffness_frame__rosidl_typesupport_introspection_c__SetStiffnessFrame_Response_message_type_support_handle
};


static rosidl_service_type_support_t franka_msgs__srv__detail__set_stiffness_frame__rosidl_typesupport_introspection_c__SetStiffnessFrame_service_type_support_handle = {
  0,
  &franka_msgs__srv__detail__set_stiffness_frame__rosidl_typesupport_introspection_c__SetStiffnessFrame_service_members,
  get_service_typesupport_handle_function,
  &franka_msgs__srv__SetStiffnessFrame_Request__rosidl_typesupport_introspection_c__SetStiffnessFrame_Request_message_type_support_handle,
  &franka_msgs__srv__SetStiffnessFrame_Response__rosidl_typesupport_introspection_c__SetStiffnessFrame_Response_message_type_support_handle,
  &franka_msgs__srv__SetStiffnessFrame_Event__rosidl_typesupport_introspection_c__SetStiffnessFrame_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    franka_msgs,
    srv,
    SetStiffnessFrame
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    franka_msgs,
    srv,
    SetStiffnessFrame
  ),
  &franka_msgs__srv__SetStiffnessFrame__get_type_hash,
  &franka_msgs__srv__SetStiffnessFrame__get_type_description,
  &franka_msgs__srv__SetStiffnessFrame__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, franka_msgs, srv, SetStiffnessFrame_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, franka_msgs, srv, SetStiffnessFrame_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, franka_msgs, srv, SetStiffnessFrame_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_franka_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, franka_msgs, srv, SetStiffnessFrame)(void) {
  if (!franka_msgs__srv__detail__set_stiffness_frame__rosidl_typesupport_introspection_c__SetStiffnessFrame_service_type_support_handle.typesupport_identifier) {
    franka_msgs__srv__detail__set_stiffness_frame__rosidl_typesupport_introspection_c__SetStiffnessFrame_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)franka_msgs__srv__detail__set_stiffness_frame__rosidl_typesupport_introspection_c__SetStiffnessFrame_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, franka_msgs, srv, SetStiffnessFrame_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, franka_msgs, srv, SetStiffnessFrame_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, franka_msgs, srv, SetStiffnessFrame_Event)()->data;
  }

  return &franka_msgs__srv__detail__set_stiffness_frame__rosidl_typesupport_introspection_c__SetStiffnessFrame_service_type_support_handle;
}
