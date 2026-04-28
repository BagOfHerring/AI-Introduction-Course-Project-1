// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from mujoco_ros_msgs:srv/SetFloat.idl
// generated code does not contain a copyright notice

#include "mujoco_ros_msgs/srv/detail/set_float__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_mujoco_ros_msgs
const rosidl_type_hash_t *
mujoco_ros_msgs__srv__SetFloat__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xe5, 0xd6, 0x84, 0x3f, 0x89, 0xb4, 0x63, 0x86,
      0x1e, 0x0a, 0x78, 0x26, 0x40, 0x65, 0xf7, 0x89,
      0xa8, 0xd6, 0x2f, 0x73, 0xf2, 0x31, 0xa8, 0x8c,
      0xac, 0xb1, 0x7b, 0x46, 0x88, 0x10, 0x6a, 0x2d,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_mujoco_ros_msgs
const rosidl_type_hash_t *
mujoco_ros_msgs__srv__SetFloat_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x12, 0x5e, 0xb5, 0x9c, 0x6a, 0x99, 0xb3, 0x99,
      0xe4, 0x06, 0xcf, 0x53, 0x67, 0x4e, 0x5c, 0x2d,
      0x40, 0xa4, 0x99, 0xd3, 0xfd, 0x94, 0x27, 0x7c,
      0x0b, 0xc5, 0xee, 0xb7, 0x05, 0xce, 0xb6, 0xe6,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_mujoco_ros_msgs
const rosidl_type_hash_t *
mujoco_ros_msgs__srv__SetFloat_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x42, 0xb6, 0xee, 0xa1, 0xfe, 0x24, 0xef, 0xba,
      0x41, 0x2c, 0x9f, 0xd1, 0xde, 0x26, 0x90, 0xc4,
      0x1c, 0xc0, 0xb8, 0x75, 0xb9, 0xf5, 0x07, 0x4f,
      0x5c, 0xfe, 0x3a, 0xab, 0x0a, 0x44, 0x20, 0x0b,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_mujoco_ros_msgs
const rosidl_type_hash_t *
mujoco_ros_msgs__srv__SetFloat_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xce, 0x44, 0x35, 0xba, 0x42, 0xf9, 0xd9, 0xca,
      0x72, 0x18, 0x1b, 0x60, 0xd9, 0x8c, 0x4a, 0xc6,
      0xf5, 0x9b, 0x5b, 0x99, 0x19, 0x23, 0x00, 0x91,
      0xbd, 0x79, 0xf8, 0x6c, 0x3f, 0x0a, 0x39, 0xd0,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char mujoco_ros_msgs__srv__SetFloat__TYPE_NAME[] = "mujoco_ros_msgs/srv/SetFloat";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char mujoco_ros_msgs__srv__SetFloat_Event__TYPE_NAME[] = "mujoco_ros_msgs/srv/SetFloat_Event";
static char mujoco_ros_msgs__srv__SetFloat_Request__TYPE_NAME[] = "mujoco_ros_msgs/srv/SetFloat_Request";
static char mujoco_ros_msgs__srv__SetFloat_Response__TYPE_NAME[] = "mujoco_ros_msgs/srv/SetFloat_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char mujoco_ros_msgs__srv__SetFloat__FIELD_NAME__request_message[] = "request_message";
static char mujoco_ros_msgs__srv__SetFloat__FIELD_NAME__response_message[] = "response_message";
static char mujoco_ros_msgs__srv__SetFloat__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field mujoco_ros_msgs__srv__SetFloat__FIELDS[] = {
  {
    {mujoco_ros_msgs__srv__SetFloat__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {mujoco_ros_msgs__srv__SetFloat_Request__TYPE_NAME, 36, 36},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__SetFloat__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {mujoco_ros_msgs__srv__SetFloat_Response__TYPE_NAME, 37, 37},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__SetFloat__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {mujoco_ros_msgs__srv__SetFloat_Event__TYPE_NAME, 34, 34},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription mujoco_ros_msgs__srv__SetFloat__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__SetFloat_Event__TYPE_NAME, 34, 34},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__SetFloat_Request__TYPE_NAME, 36, 36},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__SetFloat_Response__TYPE_NAME, 37, 37},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mujoco_ros_msgs__srv__SetFloat__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mujoco_ros_msgs__srv__SetFloat__TYPE_NAME, 28, 28},
      {mujoco_ros_msgs__srv__SetFloat__FIELDS, 3, 3},
    },
    {mujoco_ros_msgs__srv__SetFloat__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = mujoco_ros_msgs__srv__SetFloat_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = mujoco_ros_msgs__srv__SetFloat_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = mujoco_ros_msgs__srv__SetFloat_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char mujoco_ros_msgs__srv__SetFloat_Request__FIELD_NAME__value[] = "value";
static char mujoco_ros_msgs__srv__SetFloat_Request__FIELD_NAME__admin_hash[] = "admin_hash";

static rosidl_runtime_c__type_description__Field mujoco_ros_msgs__srv__SetFloat_Request__FIELDS[] = {
  {
    {mujoco_ros_msgs__srv__SetFloat_Request__FIELD_NAME__value, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__SetFloat_Request__FIELD_NAME__admin_hash, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mujoco_ros_msgs__srv__SetFloat_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mujoco_ros_msgs__srv__SetFloat_Request__TYPE_NAME, 36, 36},
      {mujoco_ros_msgs__srv__SetFloat_Request__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char mujoco_ros_msgs__srv__SetFloat_Response__FIELD_NAME__success[] = "success";

static rosidl_runtime_c__type_description__Field mujoco_ros_msgs__srv__SetFloat_Response__FIELDS[] = {
  {
    {mujoco_ros_msgs__srv__SetFloat_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mujoco_ros_msgs__srv__SetFloat_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mujoco_ros_msgs__srv__SetFloat_Response__TYPE_NAME, 37, 37},
      {mujoco_ros_msgs__srv__SetFloat_Response__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char mujoco_ros_msgs__srv__SetFloat_Event__FIELD_NAME__info[] = "info";
static char mujoco_ros_msgs__srv__SetFloat_Event__FIELD_NAME__request[] = "request";
static char mujoco_ros_msgs__srv__SetFloat_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field mujoco_ros_msgs__srv__SetFloat_Event__FIELDS[] = {
  {
    {mujoco_ros_msgs__srv__SetFloat_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__SetFloat_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {mujoco_ros_msgs__srv__SetFloat_Request__TYPE_NAME, 36, 36},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__SetFloat_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {mujoco_ros_msgs__srv__SetFloat_Response__TYPE_NAME, 37, 37},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription mujoco_ros_msgs__srv__SetFloat_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__SetFloat_Request__TYPE_NAME, 36, 36},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__SetFloat_Response__TYPE_NAME, 37, 37},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mujoco_ros_msgs__srv__SetFloat_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mujoco_ros_msgs__srv__SetFloat_Event__TYPE_NAME, 34, 34},
      {mujoco_ros_msgs__srv__SetFloat_Event__FIELDS, 3, 3},
    },
    {mujoco_ros_msgs__srv__SetFloat_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = mujoco_ros_msgs__srv__SetFloat_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = mujoco_ros_msgs__srv__SetFloat_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float64 value\n"
  "string admin_hash\n"
  "---\n"
  "bool success";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
mujoco_ros_msgs__srv__SetFloat__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mujoco_ros_msgs__srv__SetFloat__TYPE_NAME, 28, 28},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 49, 49},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
mujoco_ros_msgs__srv__SetFloat_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mujoco_ros_msgs__srv__SetFloat_Request__TYPE_NAME, 36, 36},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
mujoco_ros_msgs__srv__SetFloat_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mujoco_ros_msgs__srv__SetFloat_Response__TYPE_NAME, 37, 37},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
mujoco_ros_msgs__srv__SetFloat_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mujoco_ros_msgs__srv__SetFloat_Event__TYPE_NAME, 34, 34},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mujoco_ros_msgs__srv__SetFloat__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mujoco_ros_msgs__srv__SetFloat__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *mujoco_ros_msgs__srv__SetFloat_Event__get_individual_type_description_source(NULL);
    sources[3] = *mujoco_ros_msgs__srv__SetFloat_Request__get_individual_type_description_source(NULL);
    sources[4] = *mujoco_ros_msgs__srv__SetFloat_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mujoco_ros_msgs__srv__SetFloat_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mujoco_ros_msgs__srv__SetFloat_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mujoco_ros_msgs__srv__SetFloat_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mujoco_ros_msgs__srv__SetFloat_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mujoco_ros_msgs__srv__SetFloat_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mujoco_ros_msgs__srv__SetFloat_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *mujoco_ros_msgs__srv__SetFloat_Request__get_individual_type_description_source(NULL);
    sources[3] = *mujoco_ros_msgs__srv__SetFloat_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
