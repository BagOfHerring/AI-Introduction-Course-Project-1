// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from mujoco_ros_msgs:srv/SetGeomProperties.idl
// generated code does not contain a copyright notice

#include "mujoco_ros_msgs/srv/detail/set_geom_properties__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_mujoco_ros_msgs
const rosidl_type_hash_t *
mujoco_ros_msgs__srv__SetGeomProperties__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x5b, 0x46, 0x4c, 0xe3, 0xfd, 0xad, 0xe5, 0xdb,
      0xce, 0x7e, 0x67, 0xd0, 0x72, 0x90, 0x3f, 0xea,
      0x8d, 0x09, 0xb6, 0xf1, 0x18, 0x69, 0x35, 0xda,
      0x3c, 0xba, 0x5c, 0x94, 0x07, 0x02, 0x1f, 0xf0,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_mujoco_ros_msgs
const rosidl_type_hash_t *
mujoco_ros_msgs__srv__SetGeomProperties_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x68, 0xd5, 0x50, 0xb1, 0x98, 0x22, 0x7a, 0xd2,
      0xf4, 0x52, 0xce, 0x90, 0xce, 0x33, 0xd4, 0xc0,
      0x2c, 0xa0, 0xe9, 0x9d, 0x22, 0xbb, 0x77, 0xeb,
      0x85, 0x76, 0xa8, 0x04, 0xd1, 0x2a, 0x50, 0xcb,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_mujoco_ros_msgs
const rosidl_type_hash_t *
mujoco_ros_msgs__srv__SetGeomProperties_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xa1, 0xf0, 0x00, 0xfb, 0xf8, 0x10, 0x6c, 0xda,
      0xb1, 0xe4, 0xe1, 0x98, 0x05, 0x62, 0x70, 0x97,
      0x63, 0x82, 0xe7, 0xa0, 0x8f, 0xeb, 0x48, 0x12,
      0x95, 0xf2, 0xab, 0x35, 0x1a, 0x22, 0x06, 0xc1,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_mujoco_ros_msgs
const rosidl_type_hash_t *
mujoco_ros_msgs__srv__SetGeomProperties_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x96, 0xa5, 0x62, 0x37, 0xc7, 0x01, 0x3d, 0xee,
      0x31, 0x70, 0xea, 0xf0, 0x90, 0x98, 0x3a, 0x3d,
      0xdc, 0x1e, 0xa6, 0xc5, 0x56, 0x07, 0x38, 0xed,
      0xf3, 0x8c, 0x5a, 0x26, 0xc0, 0xc4, 0xce, 0x5d,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "mujoco_ros_msgs/msg/detail/geom_properties__functions.h"
#include "mujoco_ros_msgs/msg/detail/geom_type__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t mujoco_ros_msgs__msg__GeomProperties__EXPECTED_HASH = {1, {
    0xd7, 0x84, 0xc1, 0xa7, 0xb6, 0xd6, 0x59, 0x6f,
    0x40, 0x04, 0xc0, 0xe1, 0xe5, 0x0e, 0x84, 0xe2,
    0xa1, 0xe1, 0x0b, 0x08, 0x34, 0xc9, 0x86, 0x9f,
    0x6a, 0x37, 0x1c, 0xdf, 0xc4, 0x22, 0xe3, 0x2d,
  }};
static const rosidl_type_hash_t mujoco_ros_msgs__msg__GeomType__EXPECTED_HASH = {1, {
    0x8a, 0xa1, 0x86, 0xb7, 0x7b, 0x4a, 0x47, 0xf5,
    0x9a, 0xd1, 0xe0, 0x79, 0x98, 0x0f, 0xc1, 0x9e,
    0x78, 0x3d, 0xcc, 0x42, 0x10, 0xce, 0x61, 0x60,
    0xd7, 0x8b, 0xcf, 0x6d, 0x59, 0x83, 0xf8, 0xa6,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char mujoco_ros_msgs__srv__SetGeomProperties__TYPE_NAME[] = "mujoco_ros_msgs/srv/SetGeomProperties";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char mujoco_ros_msgs__msg__GeomProperties__TYPE_NAME[] = "mujoco_ros_msgs/msg/GeomProperties";
static char mujoco_ros_msgs__msg__GeomType__TYPE_NAME[] = "mujoco_ros_msgs/msg/GeomType";
static char mujoco_ros_msgs__srv__SetGeomProperties_Event__TYPE_NAME[] = "mujoco_ros_msgs/srv/SetGeomProperties_Event";
static char mujoco_ros_msgs__srv__SetGeomProperties_Request__TYPE_NAME[] = "mujoco_ros_msgs/srv/SetGeomProperties_Request";
static char mujoco_ros_msgs__srv__SetGeomProperties_Response__TYPE_NAME[] = "mujoco_ros_msgs/srv/SetGeomProperties_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char mujoco_ros_msgs__srv__SetGeomProperties__FIELD_NAME__request_message[] = "request_message";
static char mujoco_ros_msgs__srv__SetGeomProperties__FIELD_NAME__response_message[] = "response_message";
static char mujoco_ros_msgs__srv__SetGeomProperties__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field mujoco_ros_msgs__srv__SetGeomProperties__FIELDS[] = {
  {
    {mujoco_ros_msgs__srv__SetGeomProperties__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {mujoco_ros_msgs__srv__SetGeomProperties_Request__TYPE_NAME, 45, 45},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__SetGeomProperties__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {mujoco_ros_msgs__srv__SetGeomProperties_Response__TYPE_NAME, 46, 46},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__SetGeomProperties__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {mujoco_ros_msgs__srv__SetGeomProperties_Event__TYPE_NAME, 43, 43},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription mujoco_ros_msgs__srv__SetGeomProperties__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__GeomProperties__TYPE_NAME, 34, 34},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__GeomType__TYPE_NAME, 28, 28},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__SetGeomProperties_Event__TYPE_NAME, 43, 43},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__SetGeomProperties_Request__TYPE_NAME, 45, 45},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__SetGeomProperties_Response__TYPE_NAME, 46, 46},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mujoco_ros_msgs__srv__SetGeomProperties__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mujoco_ros_msgs__srv__SetGeomProperties__TYPE_NAME, 37, 37},
      {mujoco_ros_msgs__srv__SetGeomProperties__FIELDS, 3, 3},
    },
    {mujoco_ros_msgs__srv__SetGeomProperties__REFERENCED_TYPE_DESCRIPTIONS, 7, 7},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&mujoco_ros_msgs__msg__GeomProperties__EXPECTED_HASH, mujoco_ros_msgs__msg__GeomProperties__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = mujoco_ros_msgs__msg__GeomProperties__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&mujoco_ros_msgs__msg__GeomType__EXPECTED_HASH, mujoco_ros_msgs__msg__GeomType__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = mujoco_ros_msgs__msg__GeomType__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = mujoco_ros_msgs__srv__SetGeomProperties_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = mujoco_ros_msgs__srv__SetGeomProperties_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[5].fields = mujoco_ros_msgs__srv__SetGeomProperties_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[6].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char mujoco_ros_msgs__srv__SetGeomProperties_Request__FIELD_NAME__properties[] = "properties";
static char mujoco_ros_msgs__srv__SetGeomProperties_Request__FIELD_NAME__set_type[] = "set_type";
static char mujoco_ros_msgs__srv__SetGeomProperties_Request__FIELD_NAME__set_mass[] = "set_mass";
static char mujoco_ros_msgs__srv__SetGeomProperties_Request__FIELD_NAME__set_friction[] = "set_friction";
static char mujoco_ros_msgs__srv__SetGeomProperties_Request__FIELD_NAME__set_size[] = "set_size";
static char mujoco_ros_msgs__srv__SetGeomProperties_Request__FIELD_NAME__admin_hash[] = "admin_hash";

static rosidl_runtime_c__type_description__Field mujoco_ros_msgs__srv__SetGeomProperties_Request__FIELDS[] = {
  {
    {mujoco_ros_msgs__srv__SetGeomProperties_Request__FIELD_NAME__properties, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {mujoco_ros_msgs__msg__GeomProperties__TYPE_NAME, 34, 34},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__SetGeomProperties_Request__FIELD_NAME__set_type, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__SetGeomProperties_Request__FIELD_NAME__set_mass, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__SetGeomProperties_Request__FIELD_NAME__set_friction, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__SetGeomProperties_Request__FIELD_NAME__set_size, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__SetGeomProperties_Request__FIELD_NAME__admin_hash, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription mujoco_ros_msgs__srv__SetGeomProperties_Request__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {mujoco_ros_msgs__msg__GeomProperties__TYPE_NAME, 34, 34},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__GeomType__TYPE_NAME, 28, 28},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mujoco_ros_msgs__srv__SetGeomProperties_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mujoco_ros_msgs__srv__SetGeomProperties_Request__TYPE_NAME, 45, 45},
      {mujoco_ros_msgs__srv__SetGeomProperties_Request__FIELDS, 6, 6},
    },
    {mujoco_ros_msgs__srv__SetGeomProperties_Request__REFERENCED_TYPE_DESCRIPTIONS, 2, 2},
  };
  if (!constructed) {
    assert(0 == memcmp(&mujoco_ros_msgs__msg__GeomProperties__EXPECTED_HASH, mujoco_ros_msgs__msg__GeomProperties__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = mujoco_ros_msgs__msg__GeomProperties__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&mujoco_ros_msgs__msg__GeomType__EXPECTED_HASH, mujoco_ros_msgs__msg__GeomType__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = mujoco_ros_msgs__msg__GeomType__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char mujoco_ros_msgs__srv__SetGeomProperties_Response__FIELD_NAME__success[] = "success";
static char mujoco_ros_msgs__srv__SetGeomProperties_Response__FIELD_NAME__status_message[] = "status_message";

static rosidl_runtime_c__type_description__Field mujoco_ros_msgs__srv__SetGeomProperties_Response__FIELDS[] = {
  {
    {mujoco_ros_msgs__srv__SetGeomProperties_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__SetGeomProperties_Response__FIELD_NAME__status_message, 14, 14},
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
mujoco_ros_msgs__srv__SetGeomProperties_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mujoco_ros_msgs__srv__SetGeomProperties_Response__TYPE_NAME, 46, 46},
      {mujoco_ros_msgs__srv__SetGeomProperties_Response__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char mujoco_ros_msgs__srv__SetGeomProperties_Event__FIELD_NAME__info[] = "info";
static char mujoco_ros_msgs__srv__SetGeomProperties_Event__FIELD_NAME__request[] = "request";
static char mujoco_ros_msgs__srv__SetGeomProperties_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field mujoco_ros_msgs__srv__SetGeomProperties_Event__FIELDS[] = {
  {
    {mujoco_ros_msgs__srv__SetGeomProperties_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__SetGeomProperties_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {mujoco_ros_msgs__srv__SetGeomProperties_Request__TYPE_NAME, 45, 45},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__SetGeomProperties_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {mujoco_ros_msgs__srv__SetGeomProperties_Response__TYPE_NAME, 46, 46},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription mujoco_ros_msgs__srv__SetGeomProperties_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__GeomProperties__TYPE_NAME, 34, 34},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__GeomType__TYPE_NAME, 28, 28},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__SetGeomProperties_Request__TYPE_NAME, 45, 45},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__srv__SetGeomProperties_Response__TYPE_NAME, 46, 46},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mujoco_ros_msgs__srv__SetGeomProperties_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mujoco_ros_msgs__srv__SetGeomProperties_Event__TYPE_NAME, 43, 43},
      {mujoco_ros_msgs__srv__SetGeomProperties_Event__FIELDS, 3, 3},
    },
    {mujoco_ros_msgs__srv__SetGeomProperties_Event__REFERENCED_TYPE_DESCRIPTIONS, 6, 6},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&mujoco_ros_msgs__msg__GeomProperties__EXPECTED_HASH, mujoco_ros_msgs__msg__GeomProperties__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = mujoco_ros_msgs__msg__GeomProperties__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&mujoco_ros_msgs__msg__GeomType__EXPECTED_HASH, mujoco_ros_msgs__msg__GeomType__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = mujoco_ros_msgs__msg__GeomType__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = mujoco_ros_msgs__srv__SetGeomProperties_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = mujoco_ros_msgs__srv__SetGeomProperties_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[5].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "mujoco_ros_msgs/GeomProperties properties\n"
  "bool set_type\n"
  "bool set_mass\n"
  "bool set_friction\n"
  "bool set_size\n"
  "string admin_hash\n"
  "---\n"
  "bool success\n"
  "string status_message";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
mujoco_ros_msgs__srv__SetGeomProperties__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mujoco_ros_msgs__srv__SetGeomProperties__TYPE_NAME, 37, 37},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 159, 159},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
mujoco_ros_msgs__srv__SetGeomProperties_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mujoco_ros_msgs__srv__SetGeomProperties_Request__TYPE_NAME, 45, 45},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
mujoco_ros_msgs__srv__SetGeomProperties_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mujoco_ros_msgs__srv__SetGeomProperties_Response__TYPE_NAME, 46, 46},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
mujoco_ros_msgs__srv__SetGeomProperties_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mujoco_ros_msgs__srv__SetGeomProperties_Event__TYPE_NAME, 43, 43},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mujoco_ros_msgs__srv__SetGeomProperties__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[8];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 8, 8};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mujoco_ros_msgs__srv__SetGeomProperties__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *mujoco_ros_msgs__msg__GeomProperties__get_individual_type_description_source(NULL);
    sources[3] = *mujoco_ros_msgs__msg__GeomType__get_individual_type_description_source(NULL);
    sources[4] = *mujoco_ros_msgs__srv__SetGeomProperties_Event__get_individual_type_description_source(NULL);
    sources[5] = *mujoco_ros_msgs__srv__SetGeomProperties_Request__get_individual_type_description_source(NULL);
    sources[6] = *mujoco_ros_msgs__srv__SetGeomProperties_Response__get_individual_type_description_source(NULL);
    sources[7] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mujoco_ros_msgs__srv__SetGeomProperties_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[3];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 3, 3};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mujoco_ros_msgs__srv__SetGeomProperties_Request__get_individual_type_description_source(NULL),
    sources[1] = *mujoco_ros_msgs__msg__GeomProperties__get_individual_type_description_source(NULL);
    sources[2] = *mujoco_ros_msgs__msg__GeomType__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mujoco_ros_msgs__srv__SetGeomProperties_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mujoco_ros_msgs__srv__SetGeomProperties_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mujoco_ros_msgs__srv__SetGeomProperties_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[7];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 7, 7};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mujoco_ros_msgs__srv__SetGeomProperties_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *mujoco_ros_msgs__msg__GeomProperties__get_individual_type_description_source(NULL);
    sources[3] = *mujoco_ros_msgs__msg__GeomType__get_individual_type_description_source(NULL);
    sources[4] = *mujoco_ros_msgs__srv__SetGeomProperties_Request__get_individual_type_description_source(NULL);
    sources[5] = *mujoco_ros_msgs__srv__SetGeomProperties_Response__get_individual_type_description_source(NULL);
    sources[6] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
