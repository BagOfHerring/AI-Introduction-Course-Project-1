// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from multi_mode_control_msgs:srv/GetRobotStates.idl
// generated code does not contain a copyright notice

#include "multi_mode_control_msgs/srv/detail/get_robot_states__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_multi_mode_control_msgs
const rosidl_type_hash_t *
multi_mode_control_msgs__srv__GetRobotStates__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xd0, 0xbe, 0xb4, 0x70, 0x01, 0x87, 0xf2, 0x8f,
      0x8f, 0xd8, 0xc2, 0x9a, 0x4b, 0xd0, 0x9e, 0x16,
      0xc5, 0x39, 0x04, 0xda, 0x25, 0xc3, 0x33, 0x0b,
      0x54, 0x8e, 0x86, 0xa0, 0x65, 0x61, 0x84, 0x31,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_multi_mode_control_msgs
const rosidl_type_hash_t *
multi_mode_control_msgs__srv__GetRobotStates_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x0e, 0x80, 0x20, 0x9d, 0x63, 0x25, 0xb8, 0x70,
      0x75, 0xd3, 0xc9, 0x0a, 0x1e, 0x14, 0x6c, 0xf5,
      0x6a, 0x93, 0xa4, 0x39, 0x91, 0x77, 0xb7, 0x87,
      0x36, 0xb9, 0x3a, 0xfb, 0xf1, 0xaa, 0x40, 0xa3,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_multi_mode_control_msgs
const rosidl_type_hash_t *
multi_mode_control_msgs__srv__GetRobotStates_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x6b, 0x1c, 0x0d, 0x81, 0x2d, 0x76, 0x84, 0x8e,
      0xcc, 0x03, 0x8d, 0x1a, 0x47, 0xf4, 0xd5, 0x7e,
      0xd9, 0xad, 0xd7, 0x9f, 0x14, 0xd6, 0xbe, 0x65,
      0x84, 0x59, 0x03, 0x81, 0xa4, 0x95, 0x98, 0xba,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_multi_mode_control_msgs
const rosidl_type_hash_t *
multi_mode_control_msgs__srv__GetRobotStates_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xdc, 0xa1, 0xda, 0x66, 0x61, 0xeb, 0xb0, 0xf3,
      0x3b, 0xd9, 0xf8, 0x67, 0x04, 0xa5, 0x51, 0xde,
      0xb4, 0xa3, 0xc7, 0x48, 0x42, 0x09, 0x64, 0x0a,
      0xc7, 0x9e, 0x5c, 0x15, 0x74, 0x0d, 0x64, 0xf9,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "std_msgs/msg/detail/header__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "franka_msgs/msg/detail/franka_state__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"
#include "franka_msgs/msg/detail/errors__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t franka_msgs__msg__Errors__EXPECTED_HASH = {1, {
    0xe9, 0x8b, 0xbe, 0x02, 0x75, 0x43, 0x2f, 0x4d,
    0x9b, 0x5b, 0x74, 0xc1, 0x1d, 0x4c, 0xda, 0x27,
    0x7d, 0x7d, 0x2b, 0xcf, 0x85, 0x93, 0xd8, 0x99,
    0x60, 0x70, 0x94, 0x35, 0x74, 0x02, 0x59, 0x76,
  }};
static const rosidl_type_hash_t franka_msgs__msg__FrankaState__EXPECTED_HASH = {1, {
    0x59, 0xaa, 0x1b, 0xb0, 0x64, 0xa7, 0x6d, 0x6a,
    0x23, 0x05, 0xe4, 0x83, 0x8b, 0x8a, 0x9d, 0xaa,
    0x81, 0xb8, 0x91, 0x9b, 0x9c, 0xb4, 0x5d, 0x23,
    0x61, 0x54, 0x46, 0xcc, 0x35, 0x04, 0x21, 0x6d,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
#endif

static char multi_mode_control_msgs__srv__GetRobotStates__TYPE_NAME[] = "multi_mode_control_msgs/srv/GetRobotStates";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char franka_msgs__msg__Errors__TYPE_NAME[] = "franka_msgs/msg/Errors";
static char franka_msgs__msg__FrankaState__TYPE_NAME[] = "franka_msgs/msg/FrankaState";
static char multi_mode_control_msgs__srv__GetRobotStates_Event__TYPE_NAME[] = "multi_mode_control_msgs/srv/GetRobotStates_Event";
static char multi_mode_control_msgs__srv__GetRobotStates_Request__TYPE_NAME[] = "multi_mode_control_msgs/srv/GetRobotStates_Request";
static char multi_mode_control_msgs__srv__GetRobotStates_Response__TYPE_NAME[] = "multi_mode_control_msgs/srv/GetRobotStates_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";

// Define type names, field names, and default values
static char multi_mode_control_msgs__srv__GetRobotStates__FIELD_NAME__request_message[] = "request_message";
static char multi_mode_control_msgs__srv__GetRobotStates__FIELD_NAME__response_message[] = "response_message";
static char multi_mode_control_msgs__srv__GetRobotStates__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field multi_mode_control_msgs__srv__GetRobotStates__FIELDS[] = {
  {
    {multi_mode_control_msgs__srv__GetRobotStates__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {multi_mode_control_msgs__srv__GetRobotStates_Request__TYPE_NAME, 50, 50},
    },
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__GetRobotStates__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {multi_mode_control_msgs__srv__GetRobotStates_Response__TYPE_NAME, 51, 51},
    },
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__GetRobotStates__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {multi_mode_control_msgs__srv__GetRobotStates_Event__TYPE_NAME, 48, 48},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription multi_mode_control_msgs__srv__GetRobotStates__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__TYPE_NAME, 22, 22},
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__GetRobotStates_Event__TYPE_NAME, 48, 48},
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__GetRobotStates_Request__TYPE_NAME, 50, 50},
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__GetRobotStates_Response__TYPE_NAME, 51, 51},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
multi_mode_control_msgs__srv__GetRobotStates__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {multi_mode_control_msgs__srv__GetRobotStates__TYPE_NAME, 42, 42},
      {multi_mode_control_msgs__srv__GetRobotStates__FIELDS, 3, 3},
    },
    {multi_mode_control_msgs__srv__GetRobotStates__REFERENCED_TYPE_DESCRIPTIONS, 8, 8},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&franka_msgs__msg__Errors__EXPECTED_HASH, franka_msgs__msg__Errors__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = franka_msgs__msg__Errors__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&franka_msgs__msg__FrankaState__EXPECTED_HASH, franka_msgs__msg__FrankaState__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = franka_msgs__msg__FrankaState__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = multi_mode_control_msgs__srv__GetRobotStates_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = multi_mode_control_msgs__srv__GetRobotStates_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[5].fields = multi_mode_control_msgs__srv__GetRobotStates_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[6].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[7].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char multi_mode_control_msgs__srv__GetRobotStates_Request__FIELD_NAME__structure_needs_at_least_one_member[] = "structure_needs_at_least_one_member";

static rosidl_runtime_c__type_description__Field multi_mode_control_msgs__srv__GetRobotStates_Request__FIELDS[] = {
  {
    {multi_mode_control_msgs__srv__GetRobotStates_Request__FIELD_NAME__structure_needs_at_least_one_member, 35, 35},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
multi_mode_control_msgs__srv__GetRobotStates_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {multi_mode_control_msgs__srv__GetRobotStates_Request__TYPE_NAME, 50, 50},
      {multi_mode_control_msgs__srv__GetRobotStates_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char multi_mode_control_msgs__srv__GetRobotStates_Response__FIELD_NAME__states[] = "states";

static rosidl_runtime_c__type_description__Field multi_mode_control_msgs__srv__GetRobotStates_Response__FIELDS[] = {
  {
    {multi_mode_control_msgs__srv__GetRobotStates_Response__FIELD_NAME__states, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {franka_msgs__msg__FrankaState__TYPE_NAME, 27, 27},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription multi_mode_control_msgs__srv__GetRobotStates_Response__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__TYPE_NAME, 22, 22},
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
multi_mode_control_msgs__srv__GetRobotStates_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {multi_mode_control_msgs__srv__GetRobotStates_Response__TYPE_NAME, 51, 51},
      {multi_mode_control_msgs__srv__GetRobotStates_Response__FIELDS, 1, 1},
    },
    {multi_mode_control_msgs__srv__GetRobotStates_Response__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&franka_msgs__msg__Errors__EXPECTED_HASH, franka_msgs__msg__Errors__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = franka_msgs__msg__Errors__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&franka_msgs__msg__FrankaState__EXPECTED_HASH, franka_msgs__msg__FrankaState__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = franka_msgs__msg__FrankaState__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char multi_mode_control_msgs__srv__GetRobotStates_Event__FIELD_NAME__info[] = "info";
static char multi_mode_control_msgs__srv__GetRobotStates_Event__FIELD_NAME__request[] = "request";
static char multi_mode_control_msgs__srv__GetRobotStates_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field multi_mode_control_msgs__srv__GetRobotStates_Event__FIELDS[] = {
  {
    {multi_mode_control_msgs__srv__GetRobotStates_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__GetRobotStates_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {multi_mode_control_msgs__srv__GetRobotStates_Request__TYPE_NAME, 50, 50},
    },
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__GetRobotStates_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {multi_mode_control_msgs__srv__GetRobotStates_Response__TYPE_NAME, 51, 51},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription multi_mode_control_msgs__srv__GetRobotStates_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__TYPE_NAME, 22, 22},
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__GetRobotStates_Request__TYPE_NAME, 50, 50},
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__GetRobotStates_Response__TYPE_NAME, 51, 51},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
multi_mode_control_msgs__srv__GetRobotStates_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {multi_mode_control_msgs__srv__GetRobotStates_Event__TYPE_NAME, 48, 48},
      {multi_mode_control_msgs__srv__GetRobotStates_Event__FIELDS, 3, 3},
    },
    {multi_mode_control_msgs__srv__GetRobotStates_Event__REFERENCED_TYPE_DESCRIPTIONS, 7, 7},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&franka_msgs__msg__Errors__EXPECTED_HASH, franka_msgs__msg__Errors__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = franka_msgs__msg__Errors__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&franka_msgs__msg__FrankaState__EXPECTED_HASH, franka_msgs__msg__FrankaState__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = franka_msgs__msg__FrankaState__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = multi_mode_control_msgs__srv__GetRobotStates_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = multi_mode_control_msgs__srv__GetRobotStates_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[5].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[6].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "---\n"
  "franka_msgs/FrankaState[] states";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
multi_mode_control_msgs__srv__GetRobotStates__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {multi_mode_control_msgs__srv__GetRobotStates__TYPE_NAME, 42, 42},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 37, 37},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
multi_mode_control_msgs__srv__GetRobotStates_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {multi_mode_control_msgs__srv__GetRobotStates_Request__TYPE_NAME, 50, 50},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
multi_mode_control_msgs__srv__GetRobotStates_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {multi_mode_control_msgs__srv__GetRobotStates_Response__TYPE_NAME, 51, 51},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
multi_mode_control_msgs__srv__GetRobotStates_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {multi_mode_control_msgs__srv__GetRobotStates_Event__TYPE_NAME, 48, 48},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
multi_mode_control_msgs__srv__GetRobotStates__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[9];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 9, 9};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *multi_mode_control_msgs__srv__GetRobotStates__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *franka_msgs__msg__Errors__get_individual_type_description_source(NULL);
    sources[3] = *franka_msgs__msg__FrankaState__get_individual_type_description_source(NULL);
    sources[4] = *multi_mode_control_msgs__srv__GetRobotStates_Event__get_individual_type_description_source(NULL);
    sources[5] = *multi_mode_control_msgs__srv__GetRobotStates_Request__get_individual_type_description_source(NULL);
    sources[6] = *multi_mode_control_msgs__srv__GetRobotStates_Response__get_individual_type_description_source(NULL);
    sources[7] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[8] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
multi_mode_control_msgs__srv__GetRobotStates_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *multi_mode_control_msgs__srv__GetRobotStates_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
multi_mode_control_msgs__srv__GetRobotStates_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *multi_mode_control_msgs__srv__GetRobotStates_Response__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *franka_msgs__msg__Errors__get_individual_type_description_source(NULL);
    sources[3] = *franka_msgs__msg__FrankaState__get_individual_type_description_source(NULL);
    sources[4] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
multi_mode_control_msgs__srv__GetRobotStates_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[8];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 8, 8};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *multi_mode_control_msgs__srv__GetRobotStates_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *franka_msgs__msg__Errors__get_individual_type_description_source(NULL);
    sources[3] = *franka_msgs__msg__FrankaState__get_individual_type_description_source(NULL);
    sources[4] = *multi_mode_control_msgs__srv__GetRobotStates_Request__get_individual_type_description_source(NULL);
    sources[5] = *multi_mode_control_msgs__srv__GetRobotStates_Response__get_individual_type_description_source(NULL);
    sources[6] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[7] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
