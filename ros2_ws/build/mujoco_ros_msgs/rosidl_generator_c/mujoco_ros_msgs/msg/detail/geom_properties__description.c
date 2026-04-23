// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from mujoco_ros_msgs:msg/GeomProperties.idl
// generated code does not contain a copyright notice

#include "mujoco_ros_msgs/msg/detail/geom_properties__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_mujoco_ros_msgs
const rosidl_type_hash_t *
mujoco_ros_msgs__msg__GeomProperties__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xd7, 0x84, 0xc1, 0xa7, 0xb6, 0xd6, 0x59, 0x6f,
      0x40, 0x04, 0xc0, 0xe1, 0xe5, 0x0e, 0x84, 0xe2,
      0xa1, 0xe1, 0x0b, 0x08, 0x34, 0xc9, 0x86, 0x9f,
      0x6a, 0x37, 0x1c, 0xdf, 0xc4, 0x22, 0xe3, 0x2d,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "mujoco_ros_msgs/msg/detail/geom_type__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t mujoco_ros_msgs__msg__GeomType__EXPECTED_HASH = {1, {
    0x8a, 0xa1, 0x86, 0xb7, 0x7b, 0x4a, 0x47, 0xf5,
    0x9a, 0xd1, 0xe0, 0x79, 0x98, 0x0f, 0xc1, 0x9e,
    0x78, 0x3d, 0xcc, 0x42, 0x10, 0xce, 0x61, 0x60,
    0xd7, 0x8b, 0xcf, 0x6d, 0x59, 0x83, 0xf8, 0xa6,
  }};
#endif

static char mujoco_ros_msgs__msg__GeomProperties__TYPE_NAME[] = "mujoco_ros_msgs/msg/GeomProperties";
static char mujoco_ros_msgs__msg__GeomType__TYPE_NAME[] = "mujoco_ros_msgs/msg/GeomType";

// Define type names, field names, and default values
static char mujoco_ros_msgs__msg__GeomProperties__FIELD_NAME__name[] = "name";
static char mujoco_ros_msgs__msg__GeomProperties__FIELD_NAME__type[] = "type";
static char mujoco_ros_msgs__msg__GeomProperties__FIELD_NAME__body_mass[] = "body_mass";
static char mujoco_ros_msgs__msg__GeomProperties__FIELD_NAME__size_0[] = "size_0";
static char mujoco_ros_msgs__msg__GeomProperties__FIELD_NAME__size_1[] = "size_1";
static char mujoco_ros_msgs__msg__GeomProperties__FIELD_NAME__size_2[] = "size_2";
static char mujoco_ros_msgs__msg__GeomProperties__FIELD_NAME__friction_slide[] = "friction_slide";
static char mujoco_ros_msgs__msg__GeomProperties__FIELD_NAME__friction_spin[] = "friction_spin";
static char mujoco_ros_msgs__msg__GeomProperties__FIELD_NAME__friction_roll[] = "friction_roll";

static rosidl_runtime_c__type_description__Field mujoco_ros_msgs__msg__GeomProperties__FIELDS[] = {
  {
    {mujoco_ros_msgs__msg__GeomProperties__FIELD_NAME__name, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__GeomProperties__FIELD_NAME__type, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {mujoco_ros_msgs__msg__GeomType__TYPE_NAME, 28, 28},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__GeomProperties__FIELD_NAME__body_mass, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__GeomProperties__FIELD_NAME__size_0, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__GeomProperties__FIELD_NAME__size_1, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__GeomProperties__FIELD_NAME__size_2, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__GeomProperties__FIELD_NAME__friction_slide, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__GeomProperties__FIELD_NAME__friction_spin, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__GeomProperties__FIELD_NAME__friction_roll, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription mujoco_ros_msgs__msg__GeomProperties__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {mujoco_ros_msgs__msg__GeomType__TYPE_NAME, 28, 28},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mujoco_ros_msgs__msg__GeomProperties__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mujoco_ros_msgs__msg__GeomProperties__TYPE_NAME, 34, 34},
      {mujoco_ros_msgs__msg__GeomProperties__FIELDS, 9, 9},
    },
    {mujoco_ros_msgs__msg__GeomProperties__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&mujoco_ros_msgs__msg__GeomType__EXPECTED_HASH, mujoco_ros_msgs__msg__GeomType__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = mujoco_ros_msgs__msg__GeomType__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string name\n"
  "mujoco_ros_msgs/GeomType type\n"
  "float32 body_mass # total mass of the body this geom belongs to\n"
  "float32 size_0\n"
  "float32 size_1\n"
  "float32 size_2\n"
  "float32 friction_slide\n"
  "float32 friction_spin\n"
  "float32 friction_roll";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
mujoco_ros_msgs__msg__GeomProperties__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mujoco_ros_msgs__msg__GeomProperties__TYPE_NAME, 34, 34},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 218, 218},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mujoco_ros_msgs__msg__GeomProperties__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mujoco_ros_msgs__msg__GeomProperties__get_individual_type_description_source(NULL),
    sources[1] = *mujoco_ros_msgs__msg__GeomType__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
