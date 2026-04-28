// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from multi_mode_control_msgs:srv/SetThresholds.idl
// generated code does not contain a copyright notice

#include "multi_mode_control_msgs/srv/detail/set_thresholds__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_multi_mode_control_msgs
const rosidl_type_hash_t *
multi_mode_control_msgs__srv__SetThresholds__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xed, 0x07, 0x33, 0x58, 0x0f, 0xc3, 0xef, 0x30,
      0x31, 0x15, 0xb1, 0xa4, 0x96, 0x73, 0x3b, 0x62,
      0x28, 0xac, 0x64, 0xc3, 0xe7, 0x78, 0xa8, 0xcf,
      0x67, 0xd1, 0x82, 0x97, 0x3c, 0xb1, 0x9e, 0x6d,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_multi_mode_control_msgs
const rosidl_type_hash_t *
multi_mode_control_msgs__srv__SetThresholds_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x0a, 0x64, 0xf8, 0xf4, 0x01, 0x18, 0xc9, 0xcf,
      0x9a, 0x41, 0x37, 0x18, 0x45, 0xce, 0xcf, 0xdb,
      0xa1, 0xa1, 0xea, 0x11, 0x3f, 0x83, 0xa6, 0xaa,
      0xf4, 0x29, 0x3b, 0x00, 0x4b, 0xff, 0x78, 0x9d,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_multi_mode_control_msgs
const rosidl_type_hash_t *
multi_mode_control_msgs__srv__SetThresholds_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xf7, 0xba, 0x36, 0x91, 0xec, 0x6e, 0xa8, 0xf2,
      0xd6, 0x76, 0x3f, 0x27, 0x3b, 0xb8, 0x17, 0x6b,
      0x43, 0x72, 0x94, 0xc5, 0xa8, 0x12, 0x70, 0xb7,
      0x9d, 0x7c, 0xfe, 0x67, 0x04, 0xfc, 0x6e, 0x5c,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_multi_mode_control_msgs
const rosidl_type_hash_t *
multi_mode_control_msgs__srv__SetThresholds_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x31, 0xc9, 0x68, 0x5a, 0x98, 0x9f, 0x1e, 0x0b,
      0xb0, 0x22, 0x6d, 0x16, 0x24, 0x76, 0x2e, 0x27,
      0x24, 0x93, 0x9e, 0x25, 0x66, 0x43, 0xe8, 0x4c,
      0xdf, 0xa2, 0x8b, 0x01, 0x0f, 0x00, 0x1b, 0x4a,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "multi_mode_control_msgs/msg/detail/contact_thresholds__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "multi_mode_control_msgs/msg/detail/joint_array__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t multi_mode_control_msgs__msg__ContactThresholds__EXPECTED_HASH = {1, {
    0x24, 0xba, 0x80, 0x96, 0xac, 0xae, 0xe2, 0xa4,
    0xc5, 0x82, 0x69, 0xc9, 0xec, 0x27, 0x98, 0x21,
    0xd1, 0x04, 0x70, 0xcf, 0x2c, 0x74, 0x0d, 0x2b,
    0x59, 0x10, 0x2f, 0x0d, 0x16, 0xc9, 0x01, 0xd9,
  }};
static const rosidl_type_hash_t multi_mode_control_msgs__msg__JointArray__EXPECTED_HASH = {1, {
    0x55, 0xbe, 0x3e, 0xc4, 0xe2, 0xfa, 0xae, 0x74,
    0x25, 0xbf, 0x87, 0x86, 0x39, 0xe2, 0x7d, 0xb9,
    0x4a, 0x6b, 0x6c, 0x41, 0x87, 0x15, 0xa8, 0x46,
    0x2b, 0x54, 0xca, 0x8a, 0x51, 0xdf, 0xf9, 0x27,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char multi_mode_control_msgs__srv__SetThresholds__TYPE_NAME[] = "multi_mode_control_msgs/srv/SetThresholds";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char multi_mode_control_msgs__msg__ContactThresholds__TYPE_NAME[] = "multi_mode_control_msgs/msg/ContactThresholds";
static char multi_mode_control_msgs__msg__JointArray__TYPE_NAME[] = "multi_mode_control_msgs/msg/JointArray";
static char multi_mode_control_msgs__srv__SetThresholds_Event__TYPE_NAME[] = "multi_mode_control_msgs/srv/SetThresholds_Event";
static char multi_mode_control_msgs__srv__SetThresholds_Request__TYPE_NAME[] = "multi_mode_control_msgs/srv/SetThresholds_Request";
static char multi_mode_control_msgs__srv__SetThresholds_Response__TYPE_NAME[] = "multi_mode_control_msgs/srv/SetThresholds_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char multi_mode_control_msgs__srv__SetThresholds__FIELD_NAME__request_message[] = "request_message";
static char multi_mode_control_msgs__srv__SetThresholds__FIELD_NAME__response_message[] = "response_message";
static char multi_mode_control_msgs__srv__SetThresholds__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field multi_mode_control_msgs__srv__SetThresholds__FIELDS[] = {
  {
    {multi_mode_control_msgs__srv__SetThresholds__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {multi_mode_control_msgs__srv__SetThresholds_Request__TYPE_NAME, 49, 49},
    },
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetThresholds__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {multi_mode_control_msgs__srv__SetThresholds_Response__TYPE_NAME, 50, 50},
    },
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetThresholds__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {multi_mode_control_msgs__srv__SetThresholds_Event__TYPE_NAME, 47, 47},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription multi_mode_control_msgs__srv__SetThresholds__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__msg__ContactThresholds__TYPE_NAME, 45, 45},
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__msg__JointArray__TYPE_NAME, 38, 38},
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetThresholds_Event__TYPE_NAME, 47, 47},
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetThresholds_Request__TYPE_NAME, 49, 49},
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetThresholds_Response__TYPE_NAME, 50, 50},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
multi_mode_control_msgs__srv__SetThresholds__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {multi_mode_control_msgs__srv__SetThresholds__TYPE_NAME, 41, 41},
      {multi_mode_control_msgs__srv__SetThresholds__FIELDS, 3, 3},
    },
    {multi_mode_control_msgs__srv__SetThresholds__REFERENCED_TYPE_DESCRIPTIONS, 7, 7},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&multi_mode_control_msgs__msg__ContactThresholds__EXPECTED_HASH, multi_mode_control_msgs__msg__ContactThresholds__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = multi_mode_control_msgs__msg__ContactThresholds__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&multi_mode_control_msgs__msg__JointArray__EXPECTED_HASH, multi_mode_control_msgs__msg__JointArray__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = multi_mode_control_msgs__msg__JointArray__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = multi_mode_control_msgs__srv__SetThresholds_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = multi_mode_control_msgs__srv__SetThresholds_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[5].fields = multi_mode_control_msgs__srv__SetThresholds_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[6].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char multi_mode_control_msgs__srv__SetThresholds_Request__FIELD_NAME__level1[] = "level1";
static char multi_mode_control_msgs__srv__SetThresholds_Request__FIELD_NAME__level2[] = "level2";

static rosidl_runtime_c__type_description__Field multi_mode_control_msgs__srv__SetThresholds_Request__FIELDS[] = {
  {
    {multi_mode_control_msgs__srv__SetThresholds_Request__FIELD_NAME__level1, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {multi_mode_control_msgs__msg__ContactThresholds__TYPE_NAME, 45, 45},
    },
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetThresholds_Request__FIELD_NAME__level2, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {multi_mode_control_msgs__msg__ContactThresholds__TYPE_NAME, 45, 45},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription multi_mode_control_msgs__srv__SetThresholds_Request__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {multi_mode_control_msgs__msg__ContactThresholds__TYPE_NAME, 45, 45},
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__msg__JointArray__TYPE_NAME, 38, 38},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
multi_mode_control_msgs__srv__SetThresholds_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {multi_mode_control_msgs__srv__SetThresholds_Request__TYPE_NAME, 49, 49},
      {multi_mode_control_msgs__srv__SetThresholds_Request__FIELDS, 2, 2},
    },
    {multi_mode_control_msgs__srv__SetThresholds_Request__REFERENCED_TYPE_DESCRIPTIONS, 2, 2},
  };
  if (!constructed) {
    assert(0 == memcmp(&multi_mode_control_msgs__msg__ContactThresholds__EXPECTED_HASH, multi_mode_control_msgs__msg__ContactThresholds__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = multi_mode_control_msgs__msg__ContactThresholds__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&multi_mode_control_msgs__msg__JointArray__EXPECTED_HASH, multi_mode_control_msgs__msg__JointArray__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = multi_mode_control_msgs__msg__JointArray__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char multi_mode_control_msgs__srv__SetThresholds_Response__FIELD_NAME__structure_needs_at_least_one_member[] = "structure_needs_at_least_one_member";

static rosidl_runtime_c__type_description__Field multi_mode_control_msgs__srv__SetThresholds_Response__FIELDS[] = {
  {
    {multi_mode_control_msgs__srv__SetThresholds_Response__FIELD_NAME__structure_needs_at_least_one_member, 35, 35},
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
multi_mode_control_msgs__srv__SetThresholds_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {multi_mode_control_msgs__srv__SetThresholds_Response__TYPE_NAME, 50, 50},
      {multi_mode_control_msgs__srv__SetThresholds_Response__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char multi_mode_control_msgs__srv__SetThresholds_Event__FIELD_NAME__info[] = "info";
static char multi_mode_control_msgs__srv__SetThresholds_Event__FIELD_NAME__request[] = "request";
static char multi_mode_control_msgs__srv__SetThresholds_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field multi_mode_control_msgs__srv__SetThresholds_Event__FIELDS[] = {
  {
    {multi_mode_control_msgs__srv__SetThresholds_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetThresholds_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {multi_mode_control_msgs__srv__SetThresholds_Request__TYPE_NAME, 49, 49},
    },
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetThresholds_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {multi_mode_control_msgs__srv__SetThresholds_Response__TYPE_NAME, 50, 50},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription multi_mode_control_msgs__srv__SetThresholds_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__msg__ContactThresholds__TYPE_NAME, 45, 45},
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__msg__JointArray__TYPE_NAME, 38, 38},
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetThresholds_Request__TYPE_NAME, 49, 49},
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetThresholds_Response__TYPE_NAME, 50, 50},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
multi_mode_control_msgs__srv__SetThresholds_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {multi_mode_control_msgs__srv__SetThresholds_Event__TYPE_NAME, 47, 47},
      {multi_mode_control_msgs__srv__SetThresholds_Event__FIELDS, 3, 3},
    },
    {multi_mode_control_msgs__srv__SetThresholds_Event__REFERENCED_TYPE_DESCRIPTIONS, 6, 6},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&multi_mode_control_msgs__msg__ContactThresholds__EXPECTED_HASH, multi_mode_control_msgs__msg__ContactThresholds__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = multi_mode_control_msgs__msg__ContactThresholds__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&multi_mode_control_msgs__msg__JointArray__EXPECTED_HASH, multi_mode_control_msgs__msg__JointArray__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = multi_mode_control_msgs__msg__JointArray__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = multi_mode_control_msgs__srv__SetThresholds_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = multi_mode_control_msgs__srv__SetThresholds_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[5].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "ContactThresholds level1\n"
  "ContactThresholds level2\n"
  "---";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
multi_mode_control_msgs__srv__SetThresholds__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {multi_mode_control_msgs__srv__SetThresholds__TYPE_NAME, 41, 41},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 54, 54},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
multi_mode_control_msgs__srv__SetThresholds_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {multi_mode_control_msgs__srv__SetThresholds_Request__TYPE_NAME, 49, 49},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
multi_mode_control_msgs__srv__SetThresholds_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {multi_mode_control_msgs__srv__SetThresholds_Response__TYPE_NAME, 50, 50},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
multi_mode_control_msgs__srv__SetThresholds_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {multi_mode_control_msgs__srv__SetThresholds_Event__TYPE_NAME, 47, 47},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
multi_mode_control_msgs__srv__SetThresholds__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[8];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 8, 8};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *multi_mode_control_msgs__srv__SetThresholds__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *multi_mode_control_msgs__msg__ContactThresholds__get_individual_type_description_source(NULL);
    sources[3] = *multi_mode_control_msgs__msg__JointArray__get_individual_type_description_source(NULL);
    sources[4] = *multi_mode_control_msgs__srv__SetThresholds_Event__get_individual_type_description_source(NULL);
    sources[5] = *multi_mode_control_msgs__srv__SetThresholds_Request__get_individual_type_description_source(NULL);
    sources[6] = *multi_mode_control_msgs__srv__SetThresholds_Response__get_individual_type_description_source(NULL);
    sources[7] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
multi_mode_control_msgs__srv__SetThresholds_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[3];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 3, 3};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *multi_mode_control_msgs__srv__SetThresholds_Request__get_individual_type_description_source(NULL),
    sources[1] = *multi_mode_control_msgs__msg__ContactThresholds__get_individual_type_description_source(NULL);
    sources[2] = *multi_mode_control_msgs__msg__JointArray__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
multi_mode_control_msgs__srv__SetThresholds_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *multi_mode_control_msgs__srv__SetThresholds_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
multi_mode_control_msgs__srv__SetThresholds_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[7];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 7, 7};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *multi_mode_control_msgs__srv__SetThresholds_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *multi_mode_control_msgs__msg__ContactThresholds__get_individual_type_description_source(NULL);
    sources[3] = *multi_mode_control_msgs__msg__JointArray__get_individual_type_description_source(NULL);
    sources[4] = *multi_mode_control_msgs__srv__SetThresholds_Request__get_individual_type_description_source(NULL);
    sources[5] = *multi_mode_control_msgs__srv__SetThresholds_Response__get_individual_type_description_source(NULL);
    sources[6] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
