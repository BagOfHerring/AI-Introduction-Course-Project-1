// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from franka_msgs:srv/SetForceTorqueCollisionBehavior.idl
// generated code does not contain a copyright notice

#include "franka_msgs/srv/detail/set_force_torque_collision_behavior__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
const rosidl_type_hash_t *
franka_msgs__srv__SetForceTorqueCollisionBehavior__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x49, 0x86, 0x92, 0xc6, 0x8c, 0xbe, 0x7d, 0x86,
      0x8c, 0xa0, 0xb9, 0x02, 0x56, 0xf9, 0xf3, 0xc7,
      0xa5, 0x1b, 0x44, 0xb5, 0xb3, 0x3d, 0x7a, 0x39,
      0xd2, 0x8f, 0xc0, 0x6a, 0xb0, 0x1b, 0xd2, 0xe2,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
const rosidl_type_hash_t *
franka_msgs__srv__SetForceTorqueCollisionBehavior_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x9a, 0x07, 0xd7, 0xd3, 0x51, 0xf9, 0x55, 0xc2,
      0xf9, 0x58, 0x7d, 0x39, 0x8e, 0xff, 0xcd, 0xed,
      0xc9, 0x38, 0x88, 0xc8, 0x09, 0x30, 0x51, 0xa0,
      0x5d, 0x8f, 0x14, 0xd8, 0xd1, 0xd9, 0x02, 0x1d,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
const rosidl_type_hash_t *
franka_msgs__srv__SetForceTorqueCollisionBehavior_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x60, 0x7e, 0xaf, 0x62, 0xdb, 0x4b, 0x8a, 0xa0,
      0x60, 0x3a, 0x07, 0x3a, 0xeb, 0xb9, 0x3f, 0xcf,
      0xc5, 0xdd, 0xba, 0x82, 0x18, 0x12, 0x38, 0xb4,
      0xcf, 0xb6, 0x32, 0x38, 0x79, 0xd3, 0x5b, 0xbc,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
const rosidl_type_hash_t *
franka_msgs__srv__SetForceTorqueCollisionBehavior_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x05, 0xe1, 0x9f, 0x70, 0x2f, 0x72, 0xe5, 0x61,
      0x0c, 0xd8, 0xd3, 0xb8, 0xc0, 0xa4, 0x2b, 0x96,
      0x41, 0x4f, 0xf0, 0x22, 0xe6, 0x41, 0x31, 0x88,
      0x0e, 0x34, 0xf5, 0xd8, 0x26, 0x4b, 0x59, 0x8a,
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

static char franka_msgs__srv__SetForceTorqueCollisionBehavior__TYPE_NAME[] = "franka_msgs/srv/SetForceTorqueCollisionBehavior";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char franka_msgs__srv__SetForceTorqueCollisionBehavior_Event__TYPE_NAME[] = "franka_msgs/srv/SetForceTorqueCollisionBehavior_Event";
static char franka_msgs__srv__SetForceTorqueCollisionBehavior_Request__TYPE_NAME[] = "franka_msgs/srv/SetForceTorqueCollisionBehavior_Request";
static char franka_msgs__srv__SetForceTorqueCollisionBehavior_Response__TYPE_NAME[] = "franka_msgs/srv/SetForceTorqueCollisionBehavior_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char franka_msgs__srv__SetForceTorqueCollisionBehavior__FIELD_NAME__request_message[] = "request_message";
static char franka_msgs__srv__SetForceTorqueCollisionBehavior__FIELD_NAME__response_message[] = "response_message";
static char franka_msgs__srv__SetForceTorqueCollisionBehavior__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field franka_msgs__srv__SetForceTorqueCollisionBehavior__FIELDS[] = {
  {
    {franka_msgs__srv__SetForceTorqueCollisionBehavior__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {franka_msgs__srv__SetForceTorqueCollisionBehavior_Request__TYPE_NAME, 55, 55},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__srv__SetForceTorqueCollisionBehavior__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {franka_msgs__srv__SetForceTorqueCollisionBehavior_Response__TYPE_NAME, 56, 56},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__srv__SetForceTorqueCollisionBehavior__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {franka_msgs__srv__SetForceTorqueCollisionBehavior_Event__TYPE_NAME, 53, 53},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription franka_msgs__srv__SetForceTorqueCollisionBehavior__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {franka_msgs__srv__SetForceTorqueCollisionBehavior_Event__TYPE_NAME, 53, 53},
    {NULL, 0, 0},
  },
  {
    {franka_msgs__srv__SetForceTorqueCollisionBehavior_Request__TYPE_NAME, 55, 55},
    {NULL, 0, 0},
  },
  {
    {franka_msgs__srv__SetForceTorqueCollisionBehavior_Response__TYPE_NAME, 56, 56},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
franka_msgs__srv__SetForceTorqueCollisionBehavior__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {franka_msgs__srv__SetForceTorqueCollisionBehavior__TYPE_NAME, 47, 47},
      {franka_msgs__srv__SetForceTorqueCollisionBehavior__FIELDS, 3, 3},
    },
    {franka_msgs__srv__SetForceTorqueCollisionBehavior__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = franka_msgs__srv__SetForceTorqueCollisionBehavior_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = franka_msgs__srv__SetForceTorqueCollisionBehavior_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = franka_msgs__srv__SetForceTorqueCollisionBehavior_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char franka_msgs__srv__SetForceTorqueCollisionBehavior_Request__FIELD_NAME__lower_torque_thresholds_nominal[] = "lower_torque_thresholds_nominal";
static char franka_msgs__srv__SetForceTorqueCollisionBehavior_Request__FIELD_NAME__upper_torque_thresholds_nominal[] = "upper_torque_thresholds_nominal";
static char franka_msgs__srv__SetForceTorqueCollisionBehavior_Request__FIELD_NAME__lower_force_thresholds_nominal[] = "lower_force_thresholds_nominal";
static char franka_msgs__srv__SetForceTorqueCollisionBehavior_Request__FIELD_NAME__upper_force_thresholds_nominal[] = "upper_force_thresholds_nominal";

static rosidl_runtime_c__type_description__Field franka_msgs__srv__SetForceTorqueCollisionBehavior_Request__FIELDS[] = {
  {
    {franka_msgs__srv__SetForceTorqueCollisionBehavior_Request__FIELD_NAME__lower_torque_thresholds_nominal, 31, 31},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      7,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__srv__SetForceTorqueCollisionBehavior_Request__FIELD_NAME__upper_torque_thresholds_nominal, 31, 31},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      7,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__srv__SetForceTorqueCollisionBehavior_Request__FIELD_NAME__lower_force_thresholds_nominal, 30, 30},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      6,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__srv__SetForceTorqueCollisionBehavior_Request__FIELD_NAME__upper_force_thresholds_nominal, 30, 30},
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
franka_msgs__srv__SetForceTorqueCollisionBehavior_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {franka_msgs__srv__SetForceTorqueCollisionBehavior_Request__TYPE_NAME, 55, 55},
      {franka_msgs__srv__SetForceTorqueCollisionBehavior_Request__FIELDS, 4, 4},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char franka_msgs__srv__SetForceTorqueCollisionBehavior_Response__FIELD_NAME__success[] = "success";
static char franka_msgs__srv__SetForceTorqueCollisionBehavior_Response__FIELD_NAME__error[] = "error";

static rosidl_runtime_c__type_description__Field franka_msgs__srv__SetForceTorqueCollisionBehavior_Response__FIELDS[] = {
  {
    {franka_msgs__srv__SetForceTorqueCollisionBehavior_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__srv__SetForceTorqueCollisionBehavior_Response__FIELD_NAME__error, 5, 5},
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
franka_msgs__srv__SetForceTorqueCollisionBehavior_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {franka_msgs__srv__SetForceTorqueCollisionBehavior_Response__TYPE_NAME, 56, 56},
      {franka_msgs__srv__SetForceTorqueCollisionBehavior_Response__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char franka_msgs__srv__SetForceTorqueCollisionBehavior_Event__FIELD_NAME__info[] = "info";
static char franka_msgs__srv__SetForceTorqueCollisionBehavior_Event__FIELD_NAME__request[] = "request";
static char franka_msgs__srv__SetForceTorqueCollisionBehavior_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field franka_msgs__srv__SetForceTorqueCollisionBehavior_Event__FIELDS[] = {
  {
    {franka_msgs__srv__SetForceTorqueCollisionBehavior_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__srv__SetForceTorqueCollisionBehavior_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {franka_msgs__srv__SetForceTorqueCollisionBehavior_Request__TYPE_NAME, 55, 55},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__srv__SetForceTorqueCollisionBehavior_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {franka_msgs__srv__SetForceTorqueCollisionBehavior_Response__TYPE_NAME, 56, 56},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription franka_msgs__srv__SetForceTorqueCollisionBehavior_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {franka_msgs__srv__SetForceTorqueCollisionBehavior_Request__TYPE_NAME, 55, 55},
    {NULL, 0, 0},
  },
  {
    {franka_msgs__srv__SetForceTorqueCollisionBehavior_Response__TYPE_NAME, 56, 56},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
franka_msgs__srv__SetForceTorqueCollisionBehavior_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {franka_msgs__srv__SetForceTorqueCollisionBehavior_Event__TYPE_NAME, 53, 53},
      {franka_msgs__srv__SetForceTorqueCollisionBehavior_Event__FIELDS, 3, 3},
    },
    {franka_msgs__srv__SetForceTorqueCollisionBehavior_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = franka_msgs__srv__SetForceTorqueCollisionBehavior_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = franka_msgs__srv__SetForceTorqueCollisionBehavior_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float64[7] lower_torque_thresholds_nominal\n"
  "float64[7] upper_torque_thresholds_nominal\n"
  "float64[6] lower_force_thresholds_nominal\n"
  "float64[6] upper_force_thresholds_nominal\n"
  "---\n"
  "bool success\n"
  "string error\n"
  "";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
franka_msgs__srv__SetForceTorqueCollisionBehavior__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {franka_msgs__srv__SetForceTorqueCollisionBehavior__TYPE_NAME, 47, 47},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 201, 201},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
franka_msgs__srv__SetForceTorqueCollisionBehavior_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {franka_msgs__srv__SetForceTorqueCollisionBehavior_Request__TYPE_NAME, 55, 55},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
franka_msgs__srv__SetForceTorqueCollisionBehavior_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {franka_msgs__srv__SetForceTorqueCollisionBehavior_Response__TYPE_NAME, 56, 56},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
franka_msgs__srv__SetForceTorqueCollisionBehavior_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {franka_msgs__srv__SetForceTorqueCollisionBehavior_Event__TYPE_NAME, 53, 53},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
franka_msgs__srv__SetForceTorqueCollisionBehavior__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *franka_msgs__srv__SetForceTorqueCollisionBehavior__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *franka_msgs__srv__SetForceTorqueCollisionBehavior_Event__get_individual_type_description_source(NULL);
    sources[3] = *franka_msgs__srv__SetForceTorqueCollisionBehavior_Request__get_individual_type_description_source(NULL);
    sources[4] = *franka_msgs__srv__SetForceTorqueCollisionBehavior_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
franka_msgs__srv__SetForceTorqueCollisionBehavior_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *franka_msgs__srv__SetForceTorqueCollisionBehavior_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
franka_msgs__srv__SetForceTorqueCollisionBehavior_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *franka_msgs__srv__SetForceTorqueCollisionBehavior_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
franka_msgs__srv__SetForceTorqueCollisionBehavior_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *franka_msgs__srv__SetForceTorqueCollisionBehavior_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *franka_msgs__srv__SetForceTorqueCollisionBehavior_Request__get_individual_type_description_source(NULL);
    sources[3] = *franka_msgs__srv__SetForceTorqueCollisionBehavior_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
