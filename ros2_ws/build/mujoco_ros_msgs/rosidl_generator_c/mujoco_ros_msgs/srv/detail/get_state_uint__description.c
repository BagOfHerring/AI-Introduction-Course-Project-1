// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from mujoco_ros_msgs:srv/GetStateUint.idl
// generated code does not contain a copyright notice

#include "mujoco_ros_msgs/srv/detail/get_state_uint__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_mujoco_ros_msgs
const rosidl_type_hash_t *
mujoco_ros_msgs__srv__GetStateUint__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x1d, 0x39, 0xc6, 0x04, 0xcc, 0xc4, 0x44, 0x9c,
      0x15, 0xcc, 0xbd, 0x07, 0xca, 0xc4, 0x72, 0x3b,
      0x8c, 0xc7, 0x89, 0xac, 0x0e, 0x0a, 0xd7, 0x0a,
      0xbc, 0xc1, 0x47, 0xa7, 0x9a, 0x2e, 0xb1, 0x55,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_mujoco_ros_msgs
const rosidl_type_hash_t *
mujoco_ros_msgs__srv__GetStateUint_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xde, 0x56, 0xa2, 0x00, 0xce, 0xf0, 0x4f, 0xfb,
      0x51, 0xfe, 0x6b, 0x23, 0xe8, 0xc1, 0xd7, 0xec,
      0x7c, 0x42, 0x71, 0xfc, 0x4f, 0xc8, 0x5f, 0x35,
      0x59, 0xa0, 0x6d, 0xfa, 0x77, 0xfd, 0x9f, 0xa6,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_mujoco_ros_msgs
const rosidl_type_hash_t *
mujoco_ros_msgs__srv__GetStateUint_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xec, 0xe8, 0x0e, 0xf3, 0x6c, 0x5d, 0xbd, 0xd6,
      0xc0, 0xf1, 0x6f, 0x6f, 0x18, 0x51, 0x5e, 0xac,
      0xf7, 0x9f, 0x7a, 0x44, 0x5f, 0x2d, 0xc7, 0x1b,
      0x41, 0xc4, 0x61, 0xa3, 0xef, 0x57, 0xb8, 0x86,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_mujoco_ros_msgs
const rosidl_type_hash_t *
mujoco_ros_msgs__srv__GetStateUint_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x27, 0xbc, 0x6c, 0x44, 0x28, 0x11, 0x19, 0x5a,
      0x9b, 0xaf, 0x5e, 0x49, 0xdb, 0x3f, 0xed, 0xc6,
      0x94, 0x34, 0x51, 0x51, 0xab, 0xb4, 0x0c, 0xa7,
      0x28, 0xa8, 0xfa, 0x26, 0x81, 0x06, 0xf5, 0x8c,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "mujoco_ros_msgs/msg/detail/state_uint__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t mujoco_ros_msgs__msg__StateUint__EXPECTED_HASH = {1, {
    0xc6, 0x0f, 0x38, 0x4b, 0xc4, 0x42, 0x5d, 0xfa,
    0x47, 0x4e, 0x8e, 0x98, 0x60, 0x2b, 0x00, 0xd1,
    0x8d, 0x86, 0x5f, 0x4e, 0x70, 0x05, 0xb3, 0x3d,
    0xcb, 0xa6, 0x77, 0x96, 0x00, 0x1a, 0xd8, 0x28,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char mujoco_ros_msgs__srv__GetStateUint__TYPE_NAME[] = "mujoco_ros_msgs/srv/GetStateUint";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char mujoco_ros_msgs__msg__StateUint__TYPE_NAME[] = "mujoco_ros_msgs/msg/StateUint";
static char mujoco_ros_msgs__srv__GetStateUint_Event__TYPE_NAME[] = "mujoco_ros_msgs/srv/GetStateUint_Event";
static char mujoco_ros_msgs__srv__GetStateUint_Request__TYPE_NAME[] = "mujoco_ros_msgs/srv/GetStateUint_Request";
static char mujoco_ros_msgs__srv__GetStateUint_Response__TYPE_NAME[] = "mujoco_ros_msgs/srv/GetStateUint_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char mujoco_ros_msgs__srv__GetStateUint__FIELD_NAME__request_message[] = "request_message";
static char mujoco_ros_msgs__srv__GetStateUint__FIELD_NAME__response_message[] = "response_message";
static char mujoco_ros_msgs__srv__GetStateUint__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field mujoco_ros_msgs__srv__GetStateUint__FIELDS[] = {
  {
    {mujoco_ros_msgs__srv__GetStateUint__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {mujoco_ros_msgs__srv__GetStateUint_Request__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__GetStateUint__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {mujoco_ros_msgs__srv__GetStateUint_Response__TYPE_NAME, 41, 41},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__GetStateUint__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {mujoco_ros_msgs__srv__GetStateUint_Event__TYPE_NAME, 38, 38},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription mujoco_ros_msgs__srv__GetStateUint__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__StateUint__TYPE_NAME, 29, 29},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__GetStateUint_Event__TYPE_NAME, 38, 38},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__GetStateUint_Request__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__GetStateUint_Response__TYPE_NAME, 41, 41},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mujoco_ros_msgs__srv__GetStateUint__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mujoco_ros_msgs__srv__GetStateUint__TYPE_NAME, 32, 32},
      {mujoco_ros_msgs__srv__GetStateUint__FIELDS, 3, 3},
    },
    {mujoco_ros_msgs__srv__GetStateUint__REFERENCED_TYPE_DESCRIPTIONS, 6, 6},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&mujoco_ros_msgs__msg__StateUint__EXPECTED_HASH, mujoco_ros_msgs__msg__StateUint__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = mujoco_ros_msgs__msg__StateUint__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = mujoco_ros_msgs__srv__GetStateUint_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = mujoco_ros_msgs__srv__GetStateUint_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = mujoco_ros_msgs__srv__GetStateUint_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[5].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char mujoco_ros_msgs__srv__GetStateUint_Request__FIELD_NAME__structure_needs_at_least_one_member[] = "structure_needs_at_least_one_member";

static rosidl_runtime_c__type_description__Field mujoco_ros_msgs__srv__GetStateUint_Request__FIELDS[] = {
  {
    {mujoco_ros_msgs__srv__GetStateUint_Request__FIELD_NAME__structure_needs_at_least_one_member, 35, 35},
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
mujoco_ros_msgs__srv__GetStateUint_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mujoco_ros_msgs__srv__GetStateUint_Request__TYPE_NAME, 40, 40},
      {mujoco_ros_msgs__srv__GetStateUint_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char mujoco_ros_msgs__srv__GetStateUint_Response__FIELD_NAME__state[] = "state";

static rosidl_runtime_c__type_description__Field mujoco_ros_msgs__srv__GetStateUint_Response__FIELDS[] = {
  {
    {mujoco_ros_msgs__srv__GetStateUint_Response__FIELD_NAME__state, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {mujoco_ros_msgs__msg__StateUint__TYPE_NAME, 29, 29},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription mujoco_ros_msgs__srv__GetStateUint_Response__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {mujoco_ros_msgs__msg__StateUint__TYPE_NAME, 29, 29},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mujoco_ros_msgs__srv__GetStateUint_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mujoco_ros_msgs__srv__GetStateUint_Response__TYPE_NAME, 41, 41},
      {mujoco_ros_msgs__srv__GetStateUint_Response__FIELDS, 1, 1},
    },
    {mujoco_ros_msgs__srv__GetStateUint_Response__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&mujoco_ros_msgs__msg__StateUint__EXPECTED_HASH, mujoco_ros_msgs__msg__StateUint__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = mujoco_ros_msgs__msg__StateUint__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char mujoco_ros_msgs__srv__GetStateUint_Event__FIELD_NAME__info[] = "info";
static char mujoco_ros_msgs__srv__GetStateUint_Event__FIELD_NAME__request[] = "request";
static char mujoco_ros_msgs__srv__GetStateUint_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field mujoco_ros_msgs__srv__GetStateUint_Event__FIELDS[] = {
  {
    {mujoco_ros_msgs__srv__GetStateUint_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__GetStateUint_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {mujoco_ros_msgs__srv__GetStateUint_Request__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__GetStateUint_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {mujoco_ros_msgs__srv__GetStateUint_Response__TYPE_NAME, 41, 41},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription mujoco_ros_msgs__srv__GetStateUint_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__StateUint__TYPE_NAME, 29, 29},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__GetStateUint_Request__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__GetStateUint_Response__TYPE_NAME, 41, 41},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mujoco_ros_msgs__srv__GetStateUint_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mujoco_ros_msgs__srv__GetStateUint_Event__TYPE_NAME, 38, 38},
      {mujoco_ros_msgs__srv__GetStateUint_Event__FIELDS, 3, 3},
    },
    {mujoco_ros_msgs__srv__GetStateUint_Event__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&mujoco_ros_msgs__msg__StateUint__EXPECTED_HASH, mujoco_ros_msgs__msg__StateUint__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = mujoco_ros_msgs__msg__StateUint__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = mujoco_ros_msgs__srv__GetStateUint_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = mujoco_ros_msgs__srv__GetStateUint_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "---\n"
  "mujoco_ros_msgs/StateUint state";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
mujoco_ros_msgs__srv__GetStateUint__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mujoco_ros_msgs__srv__GetStateUint__TYPE_NAME, 32, 32},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 36, 36},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
mujoco_ros_msgs__srv__GetStateUint_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mujoco_ros_msgs__srv__GetStateUint_Request__TYPE_NAME, 40, 40},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
mujoco_ros_msgs__srv__GetStateUint_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mujoco_ros_msgs__srv__GetStateUint_Response__TYPE_NAME, 41, 41},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
mujoco_ros_msgs__srv__GetStateUint_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mujoco_ros_msgs__srv__GetStateUint_Event__TYPE_NAME, 38, 38},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mujoco_ros_msgs__srv__GetStateUint__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[7];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 7, 7};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mujoco_ros_msgs__srv__GetStateUint__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *mujoco_ros_msgs__msg__StateUint__get_individual_type_description_source(NULL);
    sources[3] = *mujoco_ros_msgs__srv__GetStateUint_Event__get_individual_type_description_source(NULL);
    sources[4] = *mujoco_ros_msgs__srv__GetStateUint_Request__get_individual_type_description_source(NULL);
    sources[5] = *mujoco_ros_msgs__srv__GetStateUint_Response__get_individual_type_description_source(NULL);
    sources[6] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mujoco_ros_msgs__srv__GetStateUint_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mujoco_ros_msgs__srv__GetStateUint_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mujoco_ros_msgs__srv__GetStateUint_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mujoco_ros_msgs__srv__GetStateUint_Response__get_individual_type_description_source(NULL),
    sources[1] = *mujoco_ros_msgs__msg__StateUint__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mujoco_ros_msgs__srv__GetStateUint_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mujoco_ros_msgs__srv__GetStateUint_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *mujoco_ros_msgs__msg__StateUint__get_individual_type_description_source(NULL);
    sources[3] = *mujoco_ros_msgs__srv__GetStateUint_Request__get_individual_type_description_source(NULL);
    sources[4] = *mujoco_ros_msgs__srv__GetStateUint_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
