// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from multi_mode_control_msgs:srv/SetControllers.idl
// generated code does not contain a copyright notice

#include "multi_mode_control_msgs/srv/detail/set_controllers__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_multi_mode_control_msgs
const rosidl_type_hash_t *
multi_mode_control_msgs__srv__SetControllers__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x35, 0x0e, 0xeb, 0xcc, 0xc2, 0x4d, 0xee, 0xd4,
      0x86, 0x1e, 0x6f, 0x12, 0x01, 0x53, 0xa5, 0x0f,
      0xb2, 0x32, 0xb6, 0x85, 0x8a, 0xf0, 0x5b, 0x87,
      0x17, 0x76, 0x34, 0xdc, 0x54, 0x20, 0x67, 0xe7,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_multi_mode_control_msgs
const rosidl_type_hash_t *
multi_mode_control_msgs__srv__SetControllers_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xe1, 0xd7, 0x00, 0x37, 0x98, 0xe9, 0xa5, 0xcb,
      0x77, 0xa9, 0x31, 0x8e, 0xbe, 0x6b, 0x13, 0x30,
      0x5a, 0xe6, 0xfc, 0x95, 0xe7, 0x43, 0xdd, 0xa4,
      0xe5, 0xc0, 0xb9, 0x33, 0xe5, 0x13, 0x22, 0x25,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_multi_mode_control_msgs
const rosidl_type_hash_t *
multi_mode_control_msgs__srv__SetControllers_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x36, 0x74, 0x32, 0x31, 0x1b, 0x74, 0x2e, 0xf8,
      0xe2, 0x6b, 0x02, 0x07, 0x99, 0xe2, 0xee, 0xaf,
      0x49, 0x33, 0xbb, 0x79, 0xd0, 0x18, 0xe5, 0x77,
      0x45, 0xe1, 0xb4, 0xc0, 0x72, 0xfa, 0xb7, 0xa7,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_multi_mode_control_msgs
const rosidl_type_hash_t *
multi_mode_control_msgs__srv__SetControllers_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x11, 0x0a, 0xf1, 0xf4, 0x95, 0x7b, 0x8f, 0x91,
      0x3a, 0x1f, 0x5f, 0xe7, 0x6c, 0xf4, 0x87, 0xe7,
      0x21, 0x48, 0x8b, 0x3e, 0x82, 0x71, 0x7d, 0x37,
      0xd5, 0x18, 0xe5, 0x51, 0xd7, 0xcd, 0xfa, 0xe8,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "service_msgs/msg/detail/service_event_info__functions.h"
#include "multi_mode_control_msgs/msg/detail/controller__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t multi_mode_control_msgs__msg__Controller__EXPECTED_HASH = {1, {
    0x71, 0xd0, 0xfc, 0xd5, 0x60, 0x46, 0x0d, 0xde,
    0x93, 0xe9, 0x40, 0x24, 0x26, 0x8b, 0x7e, 0x28,
    0xcd, 0x50, 0x30, 0x40, 0xc5, 0x95, 0xd9, 0xdc,
    0x2c, 0xc2, 0x5b, 0xda, 0x4a, 0x70, 0x05, 0x61,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char multi_mode_control_msgs__srv__SetControllers__TYPE_NAME[] = "multi_mode_control_msgs/srv/SetControllers";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char multi_mode_control_msgs__msg__Controller__TYPE_NAME[] = "multi_mode_control_msgs/msg/Controller";
static char multi_mode_control_msgs__srv__SetControllers_Event__TYPE_NAME[] = "multi_mode_control_msgs/srv/SetControllers_Event";
static char multi_mode_control_msgs__srv__SetControllers_Request__TYPE_NAME[] = "multi_mode_control_msgs/srv/SetControllers_Request";
static char multi_mode_control_msgs__srv__SetControllers_Response__TYPE_NAME[] = "multi_mode_control_msgs/srv/SetControllers_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char multi_mode_control_msgs__srv__SetControllers__FIELD_NAME__request_message[] = "request_message";
static char multi_mode_control_msgs__srv__SetControllers__FIELD_NAME__response_message[] = "response_message";
static char multi_mode_control_msgs__srv__SetControllers__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field multi_mode_control_msgs__srv__SetControllers__FIELDS[] = {
  {
    {multi_mode_control_msgs__srv__SetControllers__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {multi_mode_control_msgs__srv__SetControllers_Request__TYPE_NAME, 50, 50},
    },
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetControllers__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {multi_mode_control_msgs__srv__SetControllers_Response__TYPE_NAME, 51, 51},
    },
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetControllers__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {multi_mode_control_msgs__srv__SetControllers_Event__TYPE_NAME, 48, 48},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription multi_mode_control_msgs__srv__SetControllers__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__msg__Controller__TYPE_NAME, 38, 38},
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetControllers_Event__TYPE_NAME, 48, 48},
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetControllers_Request__TYPE_NAME, 50, 50},
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetControllers_Response__TYPE_NAME, 51, 51},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
multi_mode_control_msgs__srv__SetControllers__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {multi_mode_control_msgs__srv__SetControllers__TYPE_NAME, 42, 42},
      {multi_mode_control_msgs__srv__SetControllers__FIELDS, 3, 3},
    },
    {multi_mode_control_msgs__srv__SetControllers__REFERENCED_TYPE_DESCRIPTIONS, 6, 6},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&multi_mode_control_msgs__msg__Controller__EXPECTED_HASH, multi_mode_control_msgs__msg__Controller__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = multi_mode_control_msgs__msg__Controller__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = multi_mode_control_msgs__srv__SetControllers_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = multi_mode_control_msgs__srv__SetControllers_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = multi_mode_control_msgs__srv__SetControllers_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[5].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char multi_mode_control_msgs__srv__SetControllers_Request__FIELD_NAME__controllers[] = "controllers";

static rosidl_runtime_c__type_description__Field multi_mode_control_msgs__srv__SetControllers_Request__FIELDS[] = {
  {
    {multi_mode_control_msgs__srv__SetControllers_Request__FIELD_NAME__controllers, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {multi_mode_control_msgs__msg__Controller__TYPE_NAME, 38, 38},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription multi_mode_control_msgs__srv__SetControllers_Request__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {multi_mode_control_msgs__msg__Controller__TYPE_NAME, 38, 38},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
multi_mode_control_msgs__srv__SetControllers_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {multi_mode_control_msgs__srv__SetControllers_Request__TYPE_NAME, 50, 50},
      {multi_mode_control_msgs__srv__SetControllers_Request__FIELDS, 1, 1},
    },
    {multi_mode_control_msgs__srv__SetControllers_Request__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&multi_mode_control_msgs__msg__Controller__EXPECTED_HASH, multi_mode_control_msgs__msg__Controller__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = multi_mode_control_msgs__msg__Controller__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char multi_mode_control_msgs__srv__SetControllers_Response__FIELD_NAME__structure_needs_at_least_one_member[] = "structure_needs_at_least_one_member";

static rosidl_runtime_c__type_description__Field multi_mode_control_msgs__srv__SetControllers_Response__FIELDS[] = {
  {
    {multi_mode_control_msgs__srv__SetControllers_Response__FIELD_NAME__structure_needs_at_least_one_member, 35, 35},
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
multi_mode_control_msgs__srv__SetControllers_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {multi_mode_control_msgs__srv__SetControllers_Response__TYPE_NAME, 51, 51},
      {multi_mode_control_msgs__srv__SetControllers_Response__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char multi_mode_control_msgs__srv__SetControllers_Event__FIELD_NAME__info[] = "info";
static char multi_mode_control_msgs__srv__SetControllers_Event__FIELD_NAME__request[] = "request";
static char multi_mode_control_msgs__srv__SetControllers_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field multi_mode_control_msgs__srv__SetControllers_Event__FIELDS[] = {
  {
    {multi_mode_control_msgs__srv__SetControllers_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetControllers_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {multi_mode_control_msgs__srv__SetControllers_Request__TYPE_NAME, 50, 50},
    },
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetControllers_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {multi_mode_control_msgs__srv__SetControllers_Response__TYPE_NAME, 51, 51},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription multi_mode_control_msgs__srv__SetControllers_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__msg__Controller__TYPE_NAME, 38, 38},
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetControllers_Request__TYPE_NAME, 50, 50},
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__srv__SetControllers_Response__TYPE_NAME, 51, 51},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
multi_mode_control_msgs__srv__SetControllers_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {multi_mode_control_msgs__srv__SetControllers_Event__TYPE_NAME, 48, 48},
      {multi_mode_control_msgs__srv__SetControllers_Event__FIELDS, 3, 3},
    },
    {multi_mode_control_msgs__srv__SetControllers_Event__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&multi_mode_control_msgs__msg__Controller__EXPECTED_HASH, multi_mode_control_msgs__msg__Controller__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = multi_mode_control_msgs__msg__Controller__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = multi_mode_control_msgs__srv__SetControllers_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = multi_mode_control_msgs__srv__SetControllers_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "Controller[] controllers\n"
  "---";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
multi_mode_control_msgs__srv__SetControllers__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {multi_mode_control_msgs__srv__SetControllers__TYPE_NAME, 42, 42},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 29, 29},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
multi_mode_control_msgs__srv__SetControllers_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {multi_mode_control_msgs__srv__SetControllers_Request__TYPE_NAME, 50, 50},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
multi_mode_control_msgs__srv__SetControllers_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {multi_mode_control_msgs__srv__SetControllers_Response__TYPE_NAME, 51, 51},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
multi_mode_control_msgs__srv__SetControllers_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {multi_mode_control_msgs__srv__SetControllers_Event__TYPE_NAME, 48, 48},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
multi_mode_control_msgs__srv__SetControllers__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[7];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 7, 7};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *multi_mode_control_msgs__srv__SetControllers__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *multi_mode_control_msgs__msg__Controller__get_individual_type_description_source(NULL);
    sources[3] = *multi_mode_control_msgs__srv__SetControllers_Event__get_individual_type_description_source(NULL);
    sources[4] = *multi_mode_control_msgs__srv__SetControllers_Request__get_individual_type_description_source(NULL);
    sources[5] = *multi_mode_control_msgs__srv__SetControllers_Response__get_individual_type_description_source(NULL);
    sources[6] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
multi_mode_control_msgs__srv__SetControllers_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *multi_mode_control_msgs__srv__SetControllers_Request__get_individual_type_description_source(NULL),
    sources[1] = *multi_mode_control_msgs__msg__Controller__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
multi_mode_control_msgs__srv__SetControllers_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *multi_mode_control_msgs__srv__SetControllers_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
multi_mode_control_msgs__srv__SetControllers_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *multi_mode_control_msgs__srv__SetControllers_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *multi_mode_control_msgs__msg__Controller__get_individual_type_description_source(NULL);
    sources[3] = *multi_mode_control_msgs__srv__SetControllers_Request__get_individual_type_description_source(NULL);
    sources[4] = *multi_mode_control_msgs__srv__SetControllers_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
