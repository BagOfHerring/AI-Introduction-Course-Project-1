// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from mujoco_ros_msgs:msg/EqualityConstraintType.idl
// generated code does not contain a copyright notice

#include "mujoco_ros_msgs/msg/detail/equality_constraint_type__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_mujoco_ros_msgs
const rosidl_type_hash_t *
mujoco_ros_msgs__msg__EqualityConstraintType__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xe1, 0x33, 0x46, 0xdc, 0x86, 0x14, 0xfd, 0xc2,
      0x3c, 0x9c, 0x47, 0xe3, 0x25, 0x90, 0xd9, 0x66,
      0x7b, 0x62, 0xa1, 0xba, 0xb0, 0xe5, 0x01, 0xa7,
      0xae, 0x1b, 0x90, 0x51, 0xff, 0x60, 0xbd, 0xdf,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char mujoco_ros_msgs__msg__EqualityConstraintType__TYPE_NAME[] = "mujoco_ros_msgs/msg/EqualityConstraintType";

// Define type names, field names, and default values
static char mujoco_ros_msgs__msg__EqualityConstraintType__FIELD_NAME__value[] = "value";

static rosidl_runtime_c__type_description__Field mujoco_ros_msgs__msg__EqualityConstraintType__FIELDS[] = {
  {
    {mujoco_ros_msgs__msg__EqualityConstraintType__FIELD_NAME__value, 5, 5},
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
mujoco_ros_msgs__msg__EqualityConstraintType__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mujoco_ros_msgs__msg__EqualityConstraintType__TYPE_NAME, 42, 42},
      {mujoco_ros_msgs__msg__EqualityConstraintType__FIELDS, 1, 1},
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
  "uint16 CONNECT=0\n"
  "uint16 WELD=1\n"
  "uint16 JOINT=2\n"
  "uint16 TENDON=3";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
mujoco_ros_msgs__msg__EqualityConstraintType__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mujoco_ros_msgs__msg__EqualityConstraintType__TYPE_NAME, 42, 42},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 75, 75},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mujoco_ros_msgs__msg__EqualityConstraintType__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mujoco_ros_msgs__msg__EqualityConstraintType__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
