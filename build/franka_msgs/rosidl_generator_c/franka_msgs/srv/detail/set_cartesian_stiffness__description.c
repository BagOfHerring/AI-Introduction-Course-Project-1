// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from franka_msgs:srv/SetCartesianStiffness.idl
// generated code does not contain a copyright notice

#include "franka_msgs/srv/detail/set_cartesian_stiffness__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
const rosidl_type_hash_t *
franka_msgs__srv__SetCartesianStiffness__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x2c, 0xb3, 0x0a, 0xf5, 0x4f, 0xce, 0xf0, 0xeb,
      0xa4, 0x4d, 0x47, 0x36, 0xf9, 0x2d, 0x42, 0x25,
      0x60, 0x99, 0xc6, 0x2f, 0xfd, 0x00, 0xfa, 0xd8,
      0xd1, 0x13, 0x21, 0x49, 0x04, 0xaa, 0x47, 0x66,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
const rosidl_type_hash_t *
franka_msgs__srv__SetCartesianStiffness_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x25, 0x0c, 0x36, 0x75, 0x7c, 0xdf, 0xd9, 0x45,
      0x15, 0x2f, 0x5f, 0xf0, 0x2e, 0x38, 0xc7, 0x59,
      0xad, 0x77, 0xc0, 0x63, 0x84, 0xe3, 0x2d, 0x0f,
      0xcf, 0xa6, 0xfe, 0x9e, 0x1e, 0x17, 0x70, 0xde,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
const rosidl_type_hash_t *
franka_msgs__srv__SetCartesianStiffness_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x46, 0x69, 0xb9, 0xd9, 0xb6, 0x84, 0x21, 0x32,
      0xa7, 0xe8, 0x0e, 0xec, 0x0d, 0xd7, 0x20, 0xb1,
      0x04, 0x82, 0x82, 0x63, 0xff, 0x26, 0x75, 0x82,
      0xca, 0x86, 0xe6, 0x80, 0xd0, 0x5f, 0x4c, 0x55,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
const rosidl_type_hash_t *
franka_msgs__srv__SetCartesianStiffness_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x93, 0x2f, 0xe7, 0xe0, 0xae, 0xdc, 0x5d, 0xfe,
      0x31, 0xba, 0x2a, 0xd8, 0xdd, 0x88, 0x56, 0x3b,
      0xaa, 0xba, 0x1c, 0xac, 0x9f, 0x4d, 0x4c, 0x19,
      0xa4, 0x89, 0xfb, 0xe0, 0x3e, 0x74, 0x9f, 0xd6,
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

static char franka_msgs__srv__SetCartesianStiffness__TYPE_NAME[] = "franka_msgs/srv/SetCartesianStiffness";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char franka_msgs__srv__SetCartesianStiffness_Event__TYPE_NAME[] = "franka_msgs/srv/SetCartesianStiffness_Event";
static char franka_msgs__srv__SetCartesianStiffness_Request__TYPE_NAME[] = "franka_msgs/srv/SetCartesianStiffness_Request";
static char franka_msgs__srv__SetCartesianStiffness_Response__TYPE_NAME[] = "franka_msgs/srv/SetCartesianStiffness_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char franka_msgs__srv__SetCartesianStiffness__FIELD_NAME__request_message[] = "request_message";
static char franka_msgs__srv__SetCartesianStiffness__FIELD_NAME__response_message[] = "response_message";
static char franka_msgs__srv__SetCartesianStiffness__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field franka_msgs__srv__SetCartesianStiffness__FIELDS[] = {
  {
    {franka_msgs__srv__SetCartesianStiffness__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {franka_msgs__srv__SetCartesianStiffness_Request__TYPE_NAME, 45, 45},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__srv__SetCartesianStiffness__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {franka_msgs__srv__SetCartesianStiffness_Response__TYPE_NAME, 46, 46},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__srv__SetCartesianStiffness__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {franka_msgs__srv__SetCartesianStiffness_Event__TYPE_NAME, 43, 43},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription franka_msgs__srv__SetCartesianStiffness__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {franka_msgs__srv__SetCartesianStiffness_Event__TYPE_NAME, 43, 43},
    {NULL, 0, 0},
  },
  {
    {franka_msgs__srv__SetCartesianStiffness_Request__TYPE_NAME, 45, 45},
    {NULL, 0, 0},
  },
  {
    {franka_msgs__srv__SetCartesianStiffness_Response__TYPE_NAME, 46, 46},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
franka_msgs__srv__SetCartesianStiffness__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {franka_msgs__srv__SetCartesianStiffness__TYPE_NAME, 37, 37},
      {franka_msgs__srv__SetCartesianStiffness__FIELDS, 3, 3},
    },
    {franka_msgs__srv__SetCartesianStiffness__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = franka_msgs__srv__SetCartesianStiffness_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = franka_msgs__srv__SetCartesianStiffness_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = franka_msgs__srv__SetCartesianStiffness_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char franka_msgs__srv__SetCartesianStiffness_Request__FIELD_NAME__cartesian_stiffness[] = "cartesian_stiffness";

static rosidl_runtime_c__type_description__Field franka_msgs__srv__SetCartesianStiffness_Request__FIELDS[] = {
  {
    {franka_msgs__srv__SetCartesianStiffness_Request__FIELD_NAME__cartesian_stiffness, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      6,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
franka_msgs__srv__SetCartesianStiffness_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {franka_msgs__srv__SetCartesianStiffness_Request__TYPE_NAME, 45, 45},
      {franka_msgs__srv__SetCartesianStiffness_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char franka_msgs__srv__SetCartesianStiffness_Response__FIELD_NAME__success[] = "success";
static char franka_msgs__srv__SetCartesianStiffness_Response__FIELD_NAME__error[] = "error";

static rosidl_runtime_c__type_description__Field franka_msgs__srv__SetCartesianStiffness_Response__FIELDS[] = {
  {
    {franka_msgs__srv__SetCartesianStiffness_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__srv__SetCartesianStiffness_Response__FIELD_NAME__error, 5, 5},
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
franka_msgs__srv__SetCartesianStiffness_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {franka_msgs__srv__SetCartesianStiffness_Response__TYPE_NAME, 46, 46},
      {franka_msgs__srv__SetCartesianStiffness_Response__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char franka_msgs__srv__SetCartesianStiffness_Event__FIELD_NAME__info[] = "info";
static char franka_msgs__srv__SetCartesianStiffness_Event__FIELD_NAME__request[] = "request";
static char franka_msgs__srv__SetCartesianStiffness_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field franka_msgs__srv__SetCartesianStiffness_Event__FIELDS[] = {
  {
    {franka_msgs__srv__SetCartesianStiffness_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__srv__SetCartesianStiffness_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {franka_msgs__srv__SetCartesianStiffness_Request__TYPE_NAME, 45, 45},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__srv__SetCartesianStiffness_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {franka_msgs__srv__SetCartesianStiffness_Response__TYPE_NAME, 46, 46},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription franka_msgs__srv__SetCartesianStiffness_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {franka_msgs__srv__SetCartesianStiffness_Request__TYPE_NAME, 45, 45},
    {NULL, 0, 0},
  },
  {
    {franka_msgs__srv__SetCartesianStiffness_Response__TYPE_NAME, 46, 46},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
franka_msgs__srv__SetCartesianStiffness_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {franka_msgs__srv__SetCartesianStiffness_Event__TYPE_NAME, 43, 43},
      {franka_msgs__srv__SetCartesianStiffness_Event__FIELDS, 3, 3},
    },
    {franka_msgs__srv__SetCartesianStiffness_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = franka_msgs__srv__SetCartesianStiffness_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = franka_msgs__srv__SetCartesianStiffness_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Cartesian stiffness represented as (x, y, z, roll, pitch, yaw).\n"
  "# The values are used in the direction of the stiffness frame.\n"
  "float64[6] cartesian_stiffness\n"
  "---\n"
  "bool success\n"
  "string error";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
franka_msgs__srv__SetCartesianStiffness__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {franka_msgs__srv__SetCartesianStiffness__TYPE_NAME, 37, 37},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 190, 190},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
franka_msgs__srv__SetCartesianStiffness_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {franka_msgs__srv__SetCartesianStiffness_Request__TYPE_NAME, 45, 45},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
franka_msgs__srv__SetCartesianStiffness_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {franka_msgs__srv__SetCartesianStiffness_Response__TYPE_NAME, 46, 46},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
franka_msgs__srv__SetCartesianStiffness_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {franka_msgs__srv__SetCartesianStiffness_Event__TYPE_NAME, 43, 43},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
franka_msgs__srv__SetCartesianStiffness__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *franka_msgs__srv__SetCartesianStiffness__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *franka_msgs__srv__SetCartesianStiffness_Event__get_individual_type_description_source(NULL);
    sources[3] = *franka_msgs__srv__SetCartesianStiffness_Request__get_individual_type_description_source(NULL);
    sources[4] = *franka_msgs__srv__SetCartesianStiffness_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
franka_msgs__srv__SetCartesianStiffness_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *franka_msgs__srv__SetCartesianStiffness_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
franka_msgs__srv__SetCartesianStiffness_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *franka_msgs__srv__SetCartesianStiffness_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
franka_msgs__srv__SetCartesianStiffness_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *franka_msgs__srv__SetCartesianStiffness_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *franka_msgs__srv__SetCartesianStiffness_Request__get_individual_type_description_source(NULL);
    sources[3] = *franka_msgs__srv__SetCartesianStiffness_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
