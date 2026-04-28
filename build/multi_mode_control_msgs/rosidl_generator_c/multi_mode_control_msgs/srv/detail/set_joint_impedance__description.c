// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from multi_mode_control_msgs:srv/SetJointImpedance.idl
// generated code does not contain a copyright notice

#include "multi_mode_control_msgs/srv/detail/set_joint_impedance__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_multi_mode_control_msgs
const rosidl_type_hash_t *
multi_mode_control_msgs__srv__SetJointImpedance__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x12, 0x05, 0x39, 0xcc, 0x43, 0x4a, 0x8f, 0x9a,
      0x1e, 0xe9, 0x99, 0x1f, 0xf5, 0x82, 0xc1, 0x0b,
      0xcc, 0x30, 0xc1, 0xe3, 0x0c, 0x5d, 0xe6, 0x28,
      0x53, 0xd2, 0xa9, 0x81, 0x3c, 0x23, 0xfe, 0xee,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_multi_mode_control_msgs
const rosidl_type_hash_t *
multi_mode_control_msgs__srv__SetJointImpedance_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x01, 0x75, 0xa0, 0x88, 0xf5, 0x9a, 0xdf, 0xc8,
      0xc4, 0xf7, 0x79, 0xa7, 0x96, 0x43, 0xc6, 0x9e,
      0x43, 0xa3, 0x37, 0x90, 0x70, 0x7b, 0xcb, 0x88,
      0xce, 0x8f, 0x19, 0x0e, 0x83, 0xa9, 0x60, 0x96,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_multi_mode_control_msgs
const rosidl_type_hash_t *
multi_mode_control_msgs__srv__SetJointImpedance_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x25, 0xdc, 0xef, 0x56, 0x8e, 0x84, 0x15, 0x62,
      0xae, 0xdd, 0x28, 0x6e, 0xa2, 0x7c, 0x0a, 0x28,
      0x2d, 0x19, 0x76, 0x5a, 0x92, 0x3d, 0xca, 0xae,
      0xa4, 0x81, 0x59, 0xef, 0x07, 0x46, 0x68, 0x6d,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_multi_mode_control_msgs
const rosidl_type_hash_t *
multi_mode_control_msgs__srv__SetJointImpedance_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x0a, 0x79, 0xb1, 0x31, 0xbc, 0x5b, 0x8d, 0x26,
      0x50, 0xa2, 0xa1, 0x39, 0x0b, 0x0c, 0x5b, 0x7f,
      0xcb, 0x3a, 0xc7, 0x4c, 0x37, 0x1b, 0xda, 0x4b,
      0x08, 0x40, 0x1e, 0xdf, 0x19, 0x06, 0x13, 0x4d,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "service_msgs/msg/detail/service_event_info__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"

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

static char multi_mode_control_msgs__srv__SetJointImpedance__TYPE_NAME[] = "multi_mode_control_msgs/srv/SetJointImpedance";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char multi_mode_control_msgs__srv__SetJointImpedance_Event__TYPE_NAME[] = "multi_mode_control_msgs/srv/SetJointImpedance_Event";
static char multi_mode_control_msgs__srv__SetJointImpedance_Request__TYPE_NAME[] = "multi_mode_control_msgs/srv/SetJointImpedance_Request";
static char multi_mode_control_msgs__srv__SetJointImpedance_Response__TYPE_NAME[] = "multi_mode_control_msgs/srv/SetJointImpedance_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char multi_mode_control_msgs__srv__SetJointImpedance__FIELD_NAME__request_message[] = "request_message";
static char multi_mode_control_msgs__srv__SetJointImpedance__FIELD_NAME__response_message[] = "response_message";
static char multi_mode_control_msgs__srv__SetJointImpedance__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field multi_mode_control_msgs__srv__SetJointImpedance__FIELDS[] = {
  {
    {multi_mode_control_msgs__srv__SetJointImpedance__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {multi_mode_control_msgs__srv__SetJointImpedance_Request__TYPE_NAME, 53, 53},
    },
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetJointImpedance__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {multi_mode_control_msgs__srv__SetJointImpedance_Response__TYPE_NAME, 54, 54},
    },
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetJointImpedance__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {multi_mode_control_msgs__srv__SetJointImpedance_Event__TYPE_NAME, 51, 51},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription multi_mode_control_msgs__srv__SetJointImpedance__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetJointImpedance_Event__TYPE_NAME, 51, 51},
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetJointImpedance_Request__TYPE_NAME, 53, 53},
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetJointImpedance_Response__TYPE_NAME, 54, 54},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
multi_mode_control_msgs__srv__SetJointImpedance__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {multi_mode_control_msgs__srv__SetJointImpedance__TYPE_NAME, 45, 45},
      {multi_mode_control_msgs__srv__SetJointImpedance__FIELDS, 3, 3},
    },
    {multi_mode_control_msgs__srv__SetJointImpedance__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = multi_mode_control_msgs__srv__SetJointImpedance_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = multi_mode_control_msgs__srv__SetJointImpedance_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = multi_mode_control_msgs__srv__SetJointImpedance_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char multi_mode_control_msgs__srv__SetJointImpedance_Request__FIELD_NAME__stiffness_scale[] = "stiffness_scale";

static rosidl_runtime_c__type_description__Field multi_mode_control_msgs__srv__SetJointImpedance_Request__FIELDS[] = {
  {
    {multi_mode_control_msgs__srv__SetJointImpedance_Request__FIELD_NAME__stiffness_scale, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
multi_mode_control_msgs__srv__SetJointImpedance_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {multi_mode_control_msgs__srv__SetJointImpedance_Request__TYPE_NAME, 53, 53},
      {multi_mode_control_msgs__srv__SetJointImpedance_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char multi_mode_control_msgs__srv__SetJointImpedance_Response__FIELD_NAME__structure_needs_at_least_one_member[] = "structure_needs_at_least_one_member";

static rosidl_runtime_c__type_description__Field multi_mode_control_msgs__srv__SetJointImpedance_Response__FIELDS[] = {
  {
    {multi_mode_control_msgs__srv__SetJointImpedance_Response__FIELD_NAME__structure_needs_at_least_one_member, 35, 35},
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
multi_mode_control_msgs__srv__SetJointImpedance_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {multi_mode_control_msgs__srv__SetJointImpedance_Response__TYPE_NAME, 54, 54},
      {multi_mode_control_msgs__srv__SetJointImpedance_Response__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char multi_mode_control_msgs__srv__SetJointImpedance_Event__FIELD_NAME__info[] = "info";
static char multi_mode_control_msgs__srv__SetJointImpedance_Event__FIELD_NAME__request[] = "request";
static char multi_mode_control_msgs__srv__SetJointImpedance_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field multi_mode_control_msgs__srv__SetJointImpedance_Event__FIELDS[] = {
  {
    {multi_mode_control_msgs__srv__SetJointImpedance_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetJointImpedance_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {multi_mode_control_msgs__srv__SetJointImpedance_Request__TYPE_NAME, 53, 53},
    },
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetJointImpedance_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {multi_mode_control_msgs__srv__SetJointImpedance_Response__TYPE_NAME, 54, 54},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription multi_mode_control_msgs__srv__SetJointImpedance_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetJointImpedance_Request__TYPE_NAME, 53, 53},
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetJointImpedance_Response__TYPE_NAME, 54, 54},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
multi_mode_control_msgs__srv__SetJointImpedance_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {multi_mode_control_msgs__srv__SetJointImpedance_Event__TYPE_NAME, 51, 51},
      {multi_mode_control_msgs__srv__SetJointImpedance_Event__FIELDS, 3, 3},
    },
    {multi_mode_control_msgs__srv__SetJointImpedance_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = multi_mode_control_msgs__srv__SetJointImpedance_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = multi_mode_control_msgs__srv__SetJointImpedance_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float64 stiffness_scale\n"
  "---";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
multi_mode_control_msgs__srv__SetJointImpedance__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {multi_mode_control_msgs__srv__SetJointImpedance__TYPE_NAME, 45, 45},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 28, 28},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
multi_mode_control_msgs__srv__SetJointImpedance_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {multi_mode_control_msgs__srv__SetJointImpedance_Request__TYPE_NAME, 53, 53},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
multi_mode_control_msgs__srv__SetJointImpedance_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {multi_mode_control_msgs__srv__SetJointImpedance_Response__TYPE_NAME, 54, 54},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
multi_mode_control_msgs__srv__SetJointImpedance_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {multi_mode_control_msgs__srv__SetJointImpedance_Event__TYPE_NAME, 51, 51},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
multi_mode_control_msgs__srv__SetJointImpedance__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *multi_mode_control_msgs__srv__SetJointImpedance__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *multi_mode_control_msgs__srv__SetJointImpedance_Event__get_individual_type_description_source(NULL);
    sources[3] = *multi_mode_control_msgs__srv__SetJointImpedance_Request__get_individual_type_description_source(NULL);
    sources[4] = *multi_mode_control_msgs__srv__SetJointImpedance_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
multi_mode_control_msgs__srv__SetJointImpedance_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *multi_mode_control_msgs__srv__SetJointImpedance_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
multi_mode_control_msgs__srv__SetJointImpedance_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *multi_mode_control_msgs__srv__SetJointImpedance_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
multi_mode_control_msgs__srv__SetJointImpedance_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *multi_mode_control_msgs__srv__SetJointImpedance_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *multi_mode_control_msgs__srv__SetJointImpedance_Request__get_individual_type_description_source(NULL);
    sources[3] = *multi_mode_control_msgs__srv__SetJointImpedance_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
