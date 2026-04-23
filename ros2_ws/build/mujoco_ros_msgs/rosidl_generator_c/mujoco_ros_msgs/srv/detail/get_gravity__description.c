// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from mujoco_ros_msgs:srv/GetGravity.idl
// generated code does not contain a copyright notice

#include "mujoco_ros_msgs/srv/detail/get_gravity__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_mujoco_ros_msgs
const rosidl_type_hash_t *
mujoco_ros_msgs__srv__GetGravity__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x8a, 0x91, 0x13, 0x81, 0x2a, 0x02, 0xbd, 0x69,
      0x20, 0xaa, 0x5c, 0xaf, 0xcc, 0xb2, 0x2f, 0xb2,
      0x98, 0x7a, 0x3a, 0xb5, 0x3f, 0x49, 0x2a, 0x27,
      0x96, 0x8e, 0xe7, 0x62, 0xfd, 0x65, 0xd0, 0x70,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_mujoco_ros_msgs
const rosidl_type_hash_t *
mujoco_ros_msgs__srv__GetGravity_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xc7, 0x16, 0xc2, 0xcf, 0xdc, 0xc7, 0xe9, 0xf5,
      0x62, 0x3d, 0xf5, 0xf5, 0xb0, 0xb4, 0x95, 0xf5,
      0x23, 0xbd, 0xbd, 0x63, 0x69, 0x5b, 0xc1, 0x7e,
      0x47, 0x2b, 0x56, 0x26, 0xdd, 0xf1, 0x64, 0x4d,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_mujoco_ros_msgs
const rosidl_type_hash_t *
mujoco_ros_msgs__srv__GetGravity_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x68, 0x89, 0x4f, 0xb5, 0x71, 0xf4, 0xf8, 0x32,
      0x75, 0x56, 0x14, 0x8d, 0x60, 0xa2, 0x68, 0x73,
      0x49, 0x4a, 0x36, 0x4e, 0x58, 0x2e, 0xe1, 0x75,
      0xe5, 0xf1, 0x9c, 0xe0, 0x07, 0xc4, 0xf2, 0xab,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_mujoco_ros_msgs
const rosidl_type_hash_t *
mujoco_ros_msgs__srv__GetGravity_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x99, 0x90, 0xbd, 0xfd, 0x61, 0x27, 0x0e, 0x61,
      0x02, 0x65, 0x89, 0x3c, 0xec, 0xfc, 0x14, 0x74,
      0xbf, 0x11, 0xe2, 0x70, 0x80, 0x0e, 0x73, 0x3f,
      0xde, 0xc2, 0xe0, 0x03, 0x5d, 0x71, 0xa8, 0x2a,
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

static char mujoco_ros_msgs__srv__GetGravity__TYPE_NAME[] = "mujoco_ros_msgs/srv/GetGravity";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char mujoco_ros_msgs__srv__GetGravity_Event__TYPE_NAME[] = "mujoco_ros_msgs/srv/GetGravity_Event";
static char mujoco_ros_msgs__srv__GetGravity_Request__TYPE_NAME[] = "mujoco_ros_msgs/srv/GetGravity_Request";
static char mujoco_ros_msgs__srv__GetGravity_Response__TYPE_NAME[] = "mujoco_ros_msgs/srv/GetGravity_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char mujoco_ros_msgs__srv__GetGravity__FIELD_NAME__request_message[] = "request_message";
static char mujoco_ros_msgs__srv__GetGravity__FIELD_NAME__response_message[] = "response_message";
static char mujoco_ros_msgs__srv__GetGravity__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field mujoco_ros_msgs__srv__GetGravity__FIELDS[] = {
  {
    {mujoco_ros_msgs__srv__GetGravity__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {mujoco_ros_msgs__srv__GetGravity_Request__TYPE_NAME, 38, 38},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__GetGravity__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {mujoco_ros_msgs__srv__GetGravity_Response__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__GetGravity__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {mujoco_ros_msgs__srv__GetGravity_Event__TYPE_NAME, 36, 36},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription mujoco_ros_msgs__srv__GetGravity__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__GetGravity_Event__TYPE_NAME, 36, 36},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__GetGravity_Request__TYPE_NAME, 38, 38},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__GetGravity_Response__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mujoco_ros_msgs__srv__GetGravity__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mujoco_ros_msgs__srv__GetGravity__TYPE_NAME, 30, 30},
      {mujoco_ros_msgs__srv__GetGravity__FIELDS, 3, 3},
    },
    {mujoco_ros_msgs__srv__GetGravity__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = mujoco_ros_msgs__srv__GetGravity_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = mujoco_ros_msgs__srv__GetGravity_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = mujoco_ros_msgs__srv__GetGravity_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char mujoco_ros_msgs__srv__GetGravity_Request__FIELD_NAME__admin_hash[] = "admin_hash";

static rosidl_runtime_c__type_description__Field mujoco_ros_msgs__srv__GetGravity_Request__FIELDS[] = {
  {
    {mujoco_ros_msgs__srv__GetGravity_Request__FIELD_NAME__admin_hash, 10, 10},
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
mujoco_ros_msgs__srv__GetGravity_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mujoco_ros_msgs__srv__GetGravity_Request__TYPE_NAME, 38, 38},
      {mujoco_ros_msgs__srv__GetGravity_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char mujoco_ros_msgs__srv__GetGravity_Response__FIELD_NAME__gravity[] = "gravity";
static char mujoco_ros_msgs__srv__GetGravity_Response__FIELD_NAME__success[] = "success";
static char mujoco_ros_msgs__srv__GetGravity_Response__FIELD_NAME__status_message[] = "status_message";

static rosidl_runtime_c__type_description__Field mujoco_ros_msgs__srv__GetGravity_Response__FIELDS[] = {
  {
    {mujoco_ros_msgs__srv__GetGravity_Response__FIELD_NAME__gravity, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      3,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__GetGravity_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__GetGravity_Response__FIELD_NAME__status_message, 14, 14},
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
mujoco_ros_msgs__srv__GetGravity_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mujoco_ros_msgs__srv__GetGravity_Response__TYPE_NAME, 39, 39},
      {mujoco_ros_msgs__srv__GetGravity_Response__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char mujoco_ros_msgs__srv__GetGravity_Event__FIELD_NAME__info[] = "info";
static char mujoco_ros_msgs__srv__GetGravity_Event__FIELD_NAME__request[] = "request";
static char mujoco_ros_msgs__srv__GetGravity_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field mujoco_ros_msgs__srv__GetGravity_Event__FIELDS[] = {
  {
    {mujoco_ros_msgs__srv__GetGravity_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__GetGravity_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {mujoco_ros_msgs__srv__GetGravity_Request__TYPE_NAME, 38, 38},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__GetGravity_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {mujoco_ros_msgs__srv__GetGravity_Response__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription mujoco_ros_msgs__srv__GetGravity_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__GetGravity_Request__TYPE_NAME, 38, 38},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__GetGravity_Response__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mujoco_ros_msgs__srv__GetGravity_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mujoco_ros_msgs__srv__GetGravity_Event__TYPE_NAME, 36, 36},
      {mujoco_ros_msgs__srv__GetGravity_Event__FIELDS, 3, 3},
    },
    {mujoco_ros_msgs__srv__GetGravity_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = mujoco_ros_msgs__srv__GetGravity_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = mujoco_ros_msgs__srv__GetGravity_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string admin_hash\n"
  "---\n"
  "float64[3] gravity\n"
  "bool success\n"
  "string status_message";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
mujoco_ros_msgs__srv__GetGravity__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mujoco_ros_msgs__srv__GetGravity__TYPE_NAME, 30, 30},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 76, 76},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
mujoco_ros_msgs__srv__GetGravity_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mujoco_ros_msgs__srv__GetGravity_Request__TYPE_NAME, 38, 38},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
mujoco_ros_msgs__srv__GetGravity_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mujoco_ros_msgs__srv__GetGravity_Response__TYPE_NAME, 39, 39},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
mujoco_ros_msgs__srv__GetGravity_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mujoco_ros_msgs__srv__GetGravity_Event__TYPE_NAME, 36, 36},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mujoco_ros_msgs__srv__GetGravity__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mujoco_ros_msgs__srv__GetGravity__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *mujoco_ros_msgs__srv__GetGravity_Event__get_individual_type_description_source(NULL);
    sources[3] = *mujoco_ros_msgs__srv__GetGravity_Request__get_individual_type_description_source(NULL);
    sources[4] = *mujoco_ros_msgs__srv__GetGravity_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mujoco_ros_msgs__srv__GetGravity_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mujoco_ros_msgs__srv__GetGravity_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mujoco_ros_msgs__srv__GetGravity_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mujoco_ros_msgs__srv__GetGravity_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mujoco_ros_msgs__srv__GetGravity_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mujoco_ros_msgs__srv__GetGravity_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *mujoco_ros_msgs__srv__GetGravity_Request__get_individual_type_description_source(NULL);
    sources[3] = *mujoco_ros_msgs__srv__GetGravity_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
