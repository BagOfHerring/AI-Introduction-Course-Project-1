// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from mujoco_ros_msgs:srv/GetSimInfo.idl
// generated code does not contain a copyright notice

#include "mujoco_ros_msgs/srv/detail/get_sim_info__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_mujoco_ros_msgs
const rosidl_type_hash_t *
mujoco_ros_msgs__srv__GetSimInfo__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xb7, 0xc5, 0x1c, 0xbb, 0xf9, 0x5d, 0x31, 0x35,
      0x72, 0x29, 0xfe, 0x39, 0x00, 0x6a, 0x1a, 0x73,
      0xe5, 0xcf, 0x23, 0x96, 0xba, 0x4f, 0x62, 0xe1,
      0xf2, 0xba, 0x2f, 0x6a, 0x9d, 0x74, 0x89, 0xe5,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_mujoco_ros_msgs
const rosidl_type_hash_t *
mujoco_ros_msgs__srv__GetSimInfo_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x18, 0xcd, 0x7b, 0x88, 0x41, 0x38, 0xfb, 0xae,
      0x0e, 0x5d, 0x90, 0xca, 0x43, 0x9f, 0xfe, 0xc9,
      0x99, 0x94, 0xd6, 0x98, 0x5e, 0xe9, 0xb6, 0xcf,
      0xc1, 0x54, 0x26, 0x01, 0x74, 0xed, 0xa2, 0x84,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_mujoco_ros_msgs
const rosidl_type_hash_t *
mujoco_ros_msgs__srv__GetSimInfo_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x2a, 0x82, 0x16, 0xf9, 0x36, 0x66, 0xa4, 0xc1,
      0x7f, 0x89, 0x9a, 0xd2, 0x41, 0xf9, 0x6b, 0xc2,
      0xf2, 0x45, 0xca, 0xd9, 0xfe, 0x57, 0x5b, 0xca,
      0x5b, 0x2b, 0xe7, 0x94, 0xd8, 0x24, 0x99, 0x79,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_mujoco_ros_msgs
const rosidl_type_hash_t *
mujoco_ros_msgs__srv__GetSimInfo_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x42, 0xa0, 0x78, 0x1f, 0x69, 0x5c, 0xbd, 0x3a,
      0xcd, 0x41, 0x9a, 0x6e, 0xc3, 0x3c, 0x9a, 0x14,
      0xc7, 0x9e, 0xa7, 0xeb, 0xb1, 0x79, 0x55, 0xac,
      0xe6, 0x1c, 0x89, 0xf4, 0x5d, 0x48, 0x79, 0xa8,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "mujoco_ros_msgs/msg/detail/state_uint__functions.h"
#include "mujoco_ros_msgs/msg/detail/sim_info__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t mujoco_ros_msgs__msg__SimInfo__EXPECTED_HASH = {1, {
    0xaf, 0x18, 0xc9, 0xc3, 0xef, 0x8b, 0x91, 0xda,
    0xb3, 0x67, 0xc1, 0x0e, 0x5b, 0x0e, 0xde, 0xb5,
    0x31, 0x67, 0xff, 0x22, 0xbb, 0x42, 0xaa, 0x5c,
    0x26, 0xc1, 0x64, 0x22, 0x25, 0x12, 0xac, 0x05,
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

static char mujoco_ros_msgs__srv__GetSimInfo__TYPE_NAME[] = "mujoco_ros_msgs/srv/GetSimInfo";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char mujoco_ros_msgs__msg__SimInfo__TYPE_NAME[] = "mujoco_ros_msgs/msg/SimInfo";
static char mujoco_ros_msgs__msg__StateUint__TYPE_NAME[] = "mujoco_ros_msgs/msg/StateUint";
static char mujoco_ros_msgs__srv__GetSimInfo_Event__TYPE_NAME[] = "mujoco_ros_msgs/srv/GetSimInfo_Event";
static char mujoco_ros_msgs__srv__GetSimInfo_Request__TYPE_NAME[] = "mujoco_ros_msgs/srv/GetSimInfo_Request";
static char mujoco_ros_msgs__srv__GetSimInfo_Response__TYPE_NAME[] = "mujoco_ros_msgs/srv/GetSimInfo_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char mujoco_ros_msgs__srv__GetSimInfo__FIELD_NAME__request_message[] = "request_message";
static char mujoco_ros_msgs__srv__GetSimInfo__FIELD_NAME__response_message[] = "response_message";
static char mujoco_ros_msgs__srv__GetSimInfo__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field mujoco_ros_msgs__srv__GetSimInfo__FIELDS[] = {
  {
    {mujoco_ros_msgs__srv__GetSimInfo__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {mujoco_ros_msgs__srv__GetSimInfo_Request__TYPE_NAME, 38, 38},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__GetSimInfo__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {mujoco_ros_msgs__srv__GetSimInfo_Response__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__GetSimInfo__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {mujoco_ros_msgs__srv__GetSimInfo_Event__TYPE_NAME, 36, 36},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription mujoco_ros_msgs__srv__GetSimInfo__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__SimInfo__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__StateUint__TYPE_NAME, 29, 29},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__GetSimInfo_Event__TYPE_NAME, 36, 36},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__GetSimInfo_Request__TYPE_NAME, 38, 38},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__GetSimInfo_Response__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mujoco_ros_msgs__srv__GetSimInfo__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mujoco_ros_msgs__srv__GetSimInfo__TYPE_NAME, 30, 30},
      {mujoco_ros_msgs__srv__GetSimInfo__FIELDS, 3, 3},
    },
    {mujoco_ros_msgs__srv__GetSimInfo__REFERENCED_TYPE_DESCRIPTIONS, 7, 7},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&mujoco_ros_msgs__msg__SimInfo__EXPECTED_HASH, mujoco_ros_msgs__msg__SimInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = mujoco_ros_msgs__msg__SimInfo__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&mujoco_ros_msgs__msg__StateUint__EXPECTED_HASH, mujoco_ros_msgs__msg__StateUint__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = mujoco_ros_msgs__msg__StateUint__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = mujoco_ros_msgs__srv__GetSimInfo_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = mujoco_ros_msgs__srv__GetSimInfo_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[5].fields = mujoco_ros_msgs__srv__GetSimInfo_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[6].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char mujoco_ros_msgs__srv__GetSimInfo_Request__FIELD_NAME__structure_needs_at_least_one_member[] = "structure_needs_at_least_one_member";

static rosidl_runtime_c__type_description__Field mujoco_ros_msgs__srv__GetSimInfo_Request__FIELDS[] = {
  {
    {mujoco_ros_msgs__srv__GetSimInfo_Request__FIELD_NAME__structure_needs_at_least_one_member, 35, 35},
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
mujoco_ros_msgs__srv__GetSimInfo_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mujoco_ros_msgs__srv__GetSimInfo_Request__TYPE_NAME, 38, 38},
      {mujoco_ros_msgs__srv__GetSimInfo_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char mujoco_ros_msgs__srv__GetSimInfo_Response__FIELD_NAME__state[] = "state";

static rosidl_runtime_c__type_description__Field mujoco_ros_msgs__srv__GetSimInfo_Response__FIELDS[] = {
  {
    {mujoco_ros_msgs__srv__GetSimInfo_Response__FIELD_NAME__state, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {mujoco_ros_msgs__msg__SimInfo__TYPE_NAME, 27, 27},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription mujoco_ros_msgs__srv__GetSimInfo_Response__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {mujoco_ros_msgs__msg__SimInfo__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__StateUint__TYPE_NAME, 29, 29},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mujoco_ros_msgs__srv__GetSimInfo_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mujoco_ros_msgs__srv__GetSimInfo_Response__TYPE_NAME, 39, 39},
      {mujoco_ros_msgs__srv__GetSimInfo_Response__FIELDS, 1, 1},
    },
    {mujoco_ros_msgs__srv__GetSimInfo_Response__REFERENCED_TYPE_DESCRIPTIONS, 2, 2},
  };
  if (!constructed) {
    assert(0 == memcmp(&mujoco_ros_msgs__msg__SimInfo__EXPECTED_HASH, mujoco_ros_msgs__msg__SimInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = mujoco_ros_msgs__msg__SimInfo__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&mujoco_ros_msgs__msg__StateUint__EXPECTED_HASH, mujoco_ros_msgs__msg__StateUint__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = mujoco_ros_msgs__msg__StateUint__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char mujoco_ros_msgs__srv__GetSimInfo_Event__FIELD_NAME__info[] = "info";
static char mujoco_ros_msgs__srv__GetSimInfo_Event__FIELD_NAME__request[] = "request";
static char mujoco_ros_msgs__srv__GetSimInfo_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field mujoco_ros_msgs__srv__GetSimInfo_Event__FIELDS[] = {
  {
    {mujoco_ros_msgs__srv__GetSimInfo_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__GetSimInfo_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {mujoco_ros_msgs__srv__GetSimInfo_Request__TYPE_NAME, 38, 38},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__GetSimInfo_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {mujoco_ros_msgs__srv__GetSimInfo_Response__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription mujoco_ros_msgs__srv__GetSimInfo_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__SimInfo__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__StateUint__TYPE_NAME, 29, 29},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__GetSimInfo_Request__TYPE_NAME, 38, 38},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__GetSimInfo_Response__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mujoco_ros_msgs__srv__GetSimInfo_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mujoco_ros_msgs__srv__GetSimInfo_Event__TYPE_NAME, 36, 36},
      {mujoco_ros_msgs__srv__GetSimInfo_Event__FIELDS, 3, 3},
    },
    {mujoco_ros_msgs__srv__GetSimInfo_Event__REFERENCED_TYPE_DESCRIPTIONS, 6, 6},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&mujoco_ros_msgs__msg__SimInfo__EXPECTED_HASH, mujoco_ros_msgs__msg__SimInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = mujoco_ros_msgs__msg__SimInfo__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&mujoco_ros_msgs__msg__StateUint__EXPECTED_HASH, mujoco_ros_msgs__msg__StateUint__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = mujoco_ros_msgs__msg__StateUint__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = mujoco_ros_msgs__srv__GetSimInfo_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = mujoco_ros_msgs__srv__GetSimInfo_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[5].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "---\n"
  "mujoco_ros_msgs/SimInfo state";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
mujoco_ros_msgs__srv__GetSimInfo__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mujoco_ros_msgs__srv__GetSimInfo__TYPE_NAME, 30, 30},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 34, 34},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
mujoco_ros_msgs__srv__GetSimInfo_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mujoco_ros_msgs__srv__GetSimInfo_Request__TYPE_NAME, 38, 38},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
mujoco_ros_msgs__srv__GetSimInfo_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mujoco_ros_msgs__srv__GetSimInfo_Response__TYPE_NAME, 39, 39},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
mujoco_ros_msgs__srv__GetSimInfo_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mujoco_ros_msgs__srv__GetSimInfo_Event__TYPE_NAME, 36, 36},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mujoco_ros_msgs__srv__GetSimInfo__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[8];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 8, 8};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mujoco_ros_msgs__srv__GetSimInfo__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *mujoco_ros_msgs__msg__SimInfo__get_individual_type_description_source(NULL);
    sources[3] = *mujoco_ros_msgs__msg__StateUint__get_individual_type_description_source(NULL);
    sources[4] = *mujoco_ros_msgs__srv__GetSimInfo_Event__get_individual_type_description_source(NULL);
    sources[5] = *mujoco_ros_msgs__srv__GetSimInfo_Request__get_individual_type_description_source(NULL);
    sources[6] = *mujoco_ros_msgs__srv__GetSimInfo_Response__get_individual_type_description_source(NULL);
    sources[7] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mujoco_ros_msgs__srv__GetSimInfo_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mujoco_ros_msgs__srv__GetSimInfo_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mujoco_ros_msgs__srv__GetSimInfo_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[3];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 3, 3};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mujoco_ros_msgs__srv__GetSimInfo_Response__get_individual_type_description_source(NULL),
    sources[1] = *mujoco_ros_msgs__msg__SimInfo__get_individual_type_description_source(NULL);
    sources[2] = *mujoco_ros_msgs__msg__StateUint__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mujoco_ros_msgs__srv__GetSimInfo_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[7];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 7, 7};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mujoco_ros_msgs__srv__GetSimInfo_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *mujoco_ros_msgs__msg__SimInfo__get_individual_type_description_source(NULL);
    sources[3] = *mujoco_ros_msgs__msg__StateUint__get_individual_type_description_source(NULL);
    sources[4] = *mujoco_ros_msgs__srv__GetSimInfo_Request__get_individual_type_description_source(NULL);
    sources[5] = *mujoco_ros_msgs__srv__GetSimInfo_Response__get_individual_type_description_source(NULL);
    sources[6] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
