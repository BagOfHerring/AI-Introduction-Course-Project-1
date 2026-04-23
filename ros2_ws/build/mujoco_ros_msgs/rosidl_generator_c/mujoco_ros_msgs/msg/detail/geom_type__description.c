// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from mujoco_ros_msgs:msg/GeomType.idl
// generated code does not contain a copyright notice

#include "mujoco_ros_msgs/msg/detail/geom_type__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_mujoco_ros_msgs
const rosidl_type_hash_t *
mujoco_ros_msgs__msg__GeomType__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x8a, 0xa1, 0x86, 0xb7, 0x7b, 0x4a, 0x47, 0xf5,
      0x9a, 0xd1, 0xe0, 0x79, 0x98, 0x0f, 0xc1, 0x9e,
      0x78, 0x3d, 0xcc, 0x42, 0x10, 0xce, 0x61, 0x60,
      0xd7, 0x8b, 0xcf, 0x6d, 0x59, 0x83, 0xf8, 0xa6,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char mujoco_ros_msgs__msg__GeomType__TYPE_NAME[] = "mujoco_ros_msgs/msg/GeomType";

// Define type names, field names, and default values
static char mujoco_ros_msgs__msg__GeomType__FIELD_NAME__value[] = "value";

static rosidl_runtime_c__type_description__Field mujoco_ros_msgs__msg__GeomType__FIELDS[] = {
  {
    {mujoco_ros_msgs__msg__GeomType__FIELD_NAME__value, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mujoco_ros_msgs__msg__GeomType__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mujoco_ros_msgs__msg__GeomType__TYPE_NAME, 28, 28},
      {mujoco_ros_msgs__msg__GeomType__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "uint16 value\n"
  "uint16 PLANE=0\n"
  "uint16 HFIELD=1\n"
  "uint16 SPHERE=2\n"
  "uint16 CAPSULE=3\n"
  "uint16 ELLIPSOID=4\n"
  "uint16 CYLINDER=5\n"
  "uint16 BOX=6\n"
  "uint16 MESH=7\n"
  "uint16 GEOM_NONE = 1001";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
mujoco_ros_msgs__msg__GeomType__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mujoco_ros_msgs__msg__GeomType__TYPE_NAME, 28, 28},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 165, 165},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mujoco_ros_msgs__msg__GeomType__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mujoco_ros_msgs__msg__GeomType__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
