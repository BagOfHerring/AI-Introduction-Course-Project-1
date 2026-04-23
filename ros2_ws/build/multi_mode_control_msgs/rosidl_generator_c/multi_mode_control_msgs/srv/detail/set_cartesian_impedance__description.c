// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from multi_mode_control_msgs:srv/SetCartesianImpedance.idl
// generated code does not contain a copyright notice

#include "multi_mode_control_msgs/srv/detail/set_cartesian_impedance__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_multi_mode_control_msgs
const rosidl_type_hash_t *
multi_mode_control_msgs__srv__SetCartesianImpedance__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x5c, 0xfb, 0x2b, 0xe6, 0xee, 0xd4, 0x8d, 0xe9,
      0x3d, 0x87, 0xdb, 0x53, 0x1a, 0xd2, 0xd3, 0xa4,
      0x61, 0x2b, 0xb0, 0x04, 0x1d, 0xa3, 0x4a, 0xca,
      0x13, 0xa4, 0x47, 0xcc, 0xaf, 0xb4, 0xf3, 0x0f,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_multi_mode_control_msgs
const rosidl_type_hash_t *
multi_mode_control_msgs__srv__SetCartesianImpedance_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x33, 0x21, 0x63, 0x71, 0x11, 0x8f, 0xaf, 0x87,
      0x63, 0x5d, 0x52, 0x9a, 0x4f, 0x65, 0xfc, 0x59,
      0x2f, 0x3a, 0xce, 0x63, 0xd5, 0x80, 0x6e, 0x2b,
      0x95, 0xf4, 0x54, 0x03, 0x19, 0x5a, 0x40, 0x79,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_multi_mode_control_msgs
const rosidl_type_hash_t *
multi_mode_control_msgs__srv__SetCartesianImpedance_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xc1, 0x34, 0x4a, 0xff, 0xa0, 0x80, 0xaf, 0x49,
      0xf4, 0xbf, 0xc9, 0x97, 0xe9, 0x8f, 0x29, 0xe9,
      0x6b, 0x6c, 0xa4, 0xfb, 0x98, 0x67, 0x71, 0xbe,
      0x25, 0x08, 0x34, 0xa2, 0x6f, 0x15, 0xcb, 0xc7,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_multi_mode_control_msgs
const rosidl_type_hash_t *
multi_mode_control_msgs__srv__SetCartesianImpedance_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x37, 0xa5, 0xf2, 0x76, 0x81, 0x06, 0xfe, 0x78,
      0x8e, 0x46, 0xff, 0xbc, 0x99, 0x03, 0x03, 0x97,
      0xe4, 0x55, 0x49, 0xfa, 0xd2, 0x2d, 0x92, 0xad,
      0x20, 0x1f, 0xfd, 0x3f, 0x15, 0x5a, 0x43, 0x9d,
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

static char multi_mode_control_msgs__srv__SetCartesianImpedance__TYPE_NAME[] = "multi_mode_control_msgs/srv/SetCartesianImpedance";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char multi_mode_control_msgs__srv__SetCartesianImpedance_Event__TYPE_NAME[] = "multi_mode_control_msgs/srv/SetCartesianImpedance_Event";
static char multi_mode_control_msgs__srv__SetCartesianImpedance_Request__TYPE_NAME[] = "multi_mode_control_msgs/srv/SetCartesianImpedance_Request";
static char multi_mode_control_msgs__srv__SetCartesianImpedance_Response__TYPE_NAME[] = "multi_mode_control_msgs/srv/SetCartesianImpedance_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char multi_mode_control_msgs__srv__SetCartesianImpedance__FIELD_NAME__request_message[] = "request_message";
static char multi_mode_control_msgs__srv__SetCartesianImpedance__FIELD_NAME__response_message[] = "response_message";
static char multi_mode_control_msgs__srv__SetCartesianImpedance__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field multi_mode_control_msgs__srv__SetCartesianImpedance__FIELDS[] = {
  {
    {multi_mode_control_msgs__srv__SetCartesianImpedance__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {multi_mode_control_msgs__srv__SetCartesianImpedance_Request__TYPE_NAME, 57, 57},
    },
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetCartesianImpedance__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {multi_mode_control_msgs__srv__SetCartesianImpedance_Response__TYPE_NAME, 58, 58},
    },
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetCartesianImpedance__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {multi_mode_control_msgs__srv__SetCartesianImpedance_Event__TYPE_NAME, 55, 55},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription multi_mode_control_msgs__srv__SetCartesianImpedance__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetCartesianImpedance_Event__TYPE_NAME, 55, 55},
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetCartesianImpedance_Request__TYPE_NAME, 57, 57},
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetCartesianImpedance_Response__TYPE_NAME, 58, 58},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
multi_mode_control_msgs__srv__SetCartesianImpedance__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {multi_mode_control_msgs__srv__SetCartesianImpedance__TYPE_NAME, 49, 49},
      {multi_mode_control_msgs__srv__SetCartesianImpedance__FIELDS, 3, 3},
    },
    {multi_mode_control_msgs__srv__SetCartesianImpedance__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = multi_mode_control_msgs__srv__SetCartesianImpedance_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = multi_mode_control_msgs__srv__SetCartesianImpedance_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = multi_mode_control_msgs__srv__SetCartesianImpedance_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char multi_mode_control_msgs__srv__SetCartesianImpedance_Request__FIELD_NAME__stiffness[] = "stiffness";
static char multi_mode_control_msgs__srv__SetCartesianImpedance_Request__FIELD_NAME__damping_ratio[] = "damping_ratio";
static char multi_mode_control_msgs__srv__SetCartesianImpedance_Request__FIELD_NAME__nullspace_stiffness[] = "nullspace_stiffness";

static rosidl_runtime_c__type_description__Field multi_mode_control_msgs__srv__SetCartesianImpedance_Request__FIELDS[] = {
  {
    {multi_mode_control_msgs__srv__SetCartesianImpedance_Request__FIELD_NAME__stiffness, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      36,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetCartesianImpedance_Request__FIELD_NAME__damping_ratio, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      6,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetCartesianImpedance_Request__FIELD_NAME__nullspace_stiffness, 19, 19},
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
multi_mode_control_msgs__srv__SetCartesianImpedance_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {multi_mode_control_msgs__srv__SetCartesianImpedance_Request__TYPE_NAME, 57, 57},
      {multi_mode_control_msgs__srv__SetCartesianImpedance_Request__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char multi_mode_control_msgs__srv__SetCartesianImpedance_Response__FIELD_NAME__structure_needs_at_least_one_member[] = "structure_needs_at_least_one_member";

static rosidl_runtime_c__type_description__Field multi_mode_control_msgs__srv__SetCartesianImpedance_Response__FIELDS[] = {
  {
    {multi_mode_control_msgs__srv__SetCartesianImpedance_Response__FIELD_NAME__structure_needs_at_least_one_member, 35, 35},
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
multi_mode_control_msgs__srv__SetCartesianImpedance_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {multi_mode_control_msgs__srv__SetCartesianImpedance_Response__TYPE_NAME, 58, 58},
      {multi_mode_control_msgs__srv__SetCartesianImpedance_Response__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char multi_mode_control_msgs__srv__SetCartesianImpedance_Event__FIELD_NAME__info[] = "info";
static char multi_mode_control_msgs__srv__SetCartesianImpedance_Event__FIELD_NAME__request[] = "request";
static char multi_mode_control_msgs__srv__SetCartesianImpedance_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field multi_mode_control_msgs__srv__SetCartesianImpedance_Event__FIELDS[] = {
  {
    {multi_mode_control_msgs__srv__SetCartesianImpedance_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetCartesianImpedance_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {multi_mode_control_msgs__srv__SetCartesianImpedance_Request__TYPE_NAME, 57, 57},
    },
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetCartesianImpedance_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {multi_mode_control_msgs__srv__SetCartesianImpedance_Response__TYPE_NAME, 58, 58},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription multi_mode_control_msgs__srv__SetCartesianImpedance_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetCartesianImpedance_Request__TYPE_NAME, 57, 57},
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetCartesianImpedance_Response__TYPE_NAME, 58, 58},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
multi_mode_control_msgs__srv__SetCartesianImpedance_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {multi_mode_control_msgs__srv__SetCartesianImpedance_Event__TYPE_NAME, 55, 55},
      {multi_mode_control_msgs__srv__SetCartesianImpedance_Event__FIELDS, 3, 3},
    },
    {multi_mode_control_msgs__srv__SetCartesianImpedance_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = multi_mode_control_msgs__srv__SetCartesianImpedance_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = multi_mode_control_msgs__srv__SetCartesianImpedance_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float64[36] stiffness     # column major\n"
  "float64[6]  damping_ratio\n"
  "float64 nullspace_stiffness\n"
  "---";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
multi_mode_control_msgs__srv__SetCartesianImpedance__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {multi_mode_control_msgs__srv__SetCartesianImpedance__TYPE_NAME, 49, 49},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 99, 99},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
multi_mode_control_msgs__srv__SetCartesianImpedance_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {multi_mode_control_msgs__srv__SetCartesianImpedance_Request__TYPE_NAME, 57, 57},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
multi_mode_control_msgs__srv__SetCartesianImpedance_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {multi_mode_control_msgs__srv__SetCartesianImpedance_Response__TYPE_NAME, 58, 58},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
multi_mode_control_msgs__srv__SetCartesianImpedance_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {multi_mode_control_msgs__srv__SetCartesianImpedance_Event__TYPE_NAME, 55, 55},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
multi_mode_control_msgs__srv__SetCartesianImpedance__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *multi_mode_control_msgs__srv__SetCartesianImpedance__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *multi_mode_control_msgs__srv__SetCartesianImpedance_Event__get_individual_type_description_source(NULL);
    sources[3] = *multi_mode_control_msgs__srv__SetCartesianImpedance_Request__get_individual_type_description_source(NULL);
    sources[4] = *multi_mode_control_msgs__srv__SetCartesianImpedance_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
multi_mode_control_msgs__srv__SetCartesianImpedance_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *multi_mode_control_msgs__srv__SetCartesianImpedance_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
multi_mode_control_msgs__srv__SetCartesianImpedance_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *multi_mode_control_msgs__srv__SetCartesianImpedance_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
multi_mode_control_msgs__srv__SetCartesianImpedance_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *multi_mode_control_msgs__srv__SetCartesianImpedance_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *multi_mode_control_msgs__srv__SetCartesianImpedance_Request__get_individual_type_description_source(NULL);
    sources[3] = *multi_mode_control_msgs__srv__SetCartesianImpedance_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
