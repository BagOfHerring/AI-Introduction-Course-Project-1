// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from mujoco_ros_msgs:srv/SetGravity.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "mujoco_ros_msgs/srv/detail/set_gravity__struct.h"
#include "mujoco_ros_msgs/srv/detail/set_gravity__type_support.h"
#include "mujoco_ros_msgs/srv/detail/set_gravity__functions.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace mujoco_ros_msgs
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _SetGravity_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetGravity_Request_type_support_ids_t;

static const _SetGravity_Request_type_support_ids_t _SetGravity_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SetGravity_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetGravity_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetGravity_Request_type_support_symbol_names_t _SetGravity_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, mujoco_ros_msgs, srv, SetGravity_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mujoco_ros_msgs, srv, SetGravity_Request)),
  }
};

typedef struct _SetGravity_Request_type_support_data_t
{
  void * data[2];
} _SetGravity_Request_type_support_data_t;

static _SetGravity_Request_type_support_data_t _SetGravity_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetGravity_Request_message_typesupport_map = {
  2,
  "mujoco_ros_msgs",
  &_SetGravity_Request_message_typesupport_ids.typesupport_identifier[0],
  &_SetGravity_Request_message_typesupport_symbol_names.symbol_name[0],
  &_SetGravity_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetGravity_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetGravity_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &mujoco_ros_msgs__srv__SetGravity_Request__get_type_hash,
  &mujoco_ros_msgs__srv__SetGravity_Request__get_type_description,
  &mujoco_ros_msgs__srv__SetGravity_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace mujoco_ros_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, mujoco_ros_msgs, srv, SetGravity_Request)() {
  return &::mujoco_ros_msgs::srv::rosidl_typesupport_c::SetGravity_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "mujoco_ros_msgs/srv/detail/set_gravity__struct.h"
// already included above
// #include "mujoco_ros_msgs/srv/detail/set_gravity__type_support.h"
// already included above
// #include "mujoco_ros_msgs/srv/detail/set_gravity__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace mujoco_ros_msgs
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _SetGravity_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetGravity_Response_type_support_ids_t;

static const _SetGravity_Response_type_support_ids_t _SetGravity_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SetGravity_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetGravity_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetGravity_Response_type_support_symbol_names_t _SetGravity_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, mujoco_ros_msgs, srv, SetGravity_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mujoco_ros_msgs, srv, SetGravity_Response)),
  }
};

typedef struct _SetGravity_Response_type_support_data_t
{
  void * data[2];
} _SetGravity_Response_type_support_data_t;

static _SetGravity_Response_type_support_data_t _SetGravity_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetGravity_Response_message_typesupport_map = {
  2,
  "mujoco_ros_msgs",
  &_SetGravity_Response_message_typesupport_ids.typesupport_identifier[0],
  &_SetGravity_Response_message_typesupport_symbol_names.symbol_name[0],
  &_SetGravity_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetGravity_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetGravity_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &mujoco_ros_msgs__srv__SetGravity_Response__get_type_hash,
  &mujoco_ros_msgs__srv__SetGravity_Response__get_type_description,
  &mujoco_ros_msgs__srv__SetGravity_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace mujoco_ros_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, mujoco_ros_msgs, srv, SetGravity_Response)() {
  return &::mujoco_ros_msgs::srv::rosidl_typesupport_c::SetGravity_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "mujoco_ros_msgs/srv/detail/set_gravity__struct.h"
// already included above
// #include "mujoco_ros_msgs/srv/detail/set_gravity__type_support.h"
// already included above
// #include "mujoco_ros_msgs/srv/detail/set_gravity__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace mujoco_ros_msgs
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _SetGravity_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetGravity_Event_type_support_ids_t;

static const _SetGravity_Event_type_support_ids_t _SetGravity_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SetGravity_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetGravity_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetGravity_Event_type_support_symbol_names_t _SetGravity_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, mujoco_ros_msgs, srv, SetGravity_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mujoco_ros_msgs, srv, SetGravity_Event)),
  }
};

typedef struct _SetGravity_Event_type_support_data_t
{
  void * data[2];
} _SetGravity_Event_type_support_data_t;

static _SetGravity_Event_type_support_data_t _SetGravity_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetGravity_Event_message_typesupport_map = {
  2,
  "mujoco_ros_msgs",
  &_SetGravity_Event_message_typesupport_ids.typesupport_identifier[0],
  &_SetGravity_Event_message_typesupport_symbol_names.symbol_name[0],
  &_SetGravity_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetGravity_Event_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetGravity_Event_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &mujoco_ros_msgs__srv__SetGravity_Event__get_type_hash,
  &mujoco_ros_msgs__srv__SetGravity_Event__get_type_description,
  &mujoco_ros_msgs__srv__SetGravity_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace mujoco_ros_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, mujoco_ros_msgs, srv, SetGravity_Event)() {
  return &::mujoco_ros_msgs::srv::rosidl_typesupport_c::SetGravity_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "mujoco_ros_msgs/srv/detail/set_gravity__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
#include "service_msgs/msg/service_event_info.h"
#include "builtin_interfaces/msg/time.h"

namespace mujoco_ros_msgs
{

namespace srv
{

namespace rosidl_typesupport_c
{
typedef struct _SetGravity_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetGravity_type_support_ids_t;

static const _SetGravity_type_support_ids_t _SetGravity_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SetGravity_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetGravity_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetGravity_type_support_symbol_names_t _SetGravity_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, mujoco_ros_msgs, srv, SetGravity)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mujoco_ros_msgs, srv, SetGravity)),
  }
};

typedef struct _SetGravity_type_support_data_t
{
  void * data[2];
} _SetGravity_type_support_data_t;

static _SetGravity_type_support_data_t _SetGravity_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetGravity_service_typesupport_map = {
  2,
  "mujoco_ros_msgs",
  &_SetGravity_service_typesupport_ids.typesupport_identifier[0],
  &_SetGravity_service_typesupport_symbol_names.symbol_name[0],
  &_SetGravity_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t SetGravity_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetGravity_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
  &SetGravity_Request_message_type_support_handle,
  &SetGravity_Response_message_type_support_handle,
  &SetGravity_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    mujoco_ros_msgs,
    srv,
    SetGravity
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    mujoco_ros_msgs,
    srv,
    SetGravity
  ),
  &mujoco_ros_msgs__srv__SetGravity__get_type_hash,
  &mujoco_ros_msgs__srv__SetGravity__get_type_description,
  &mujoco_ros_msgs__srv__SetGravity__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace mujoco_ros_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, mujoco_ros_msgs, srv, SetGravity)() {
  return &::mujoco_ros_msgs::srv::rosidl_typesupport_c::SetGravity_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif
