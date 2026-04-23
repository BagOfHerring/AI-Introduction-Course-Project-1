// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from mujoco_ros_msgs:msg/StateUint.idl
// generated code does not contain a copyright notice

#include "mujoco_ros_msgs/msg/detail/state_uint__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_mujoco_ros_msgs
const rosidl_type_hash_t *
mujoco_ros_msgs__msg__StateUint__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xc6, 0x0f, 0x38, 0x4b, 0xc4, 0x42, 0x5d, 0xfa,
      0x47, 0x4e, 0x8e, 0x98, 0x60, 0x2b, 0x00, 0xd1,
      0x8d, 0x86, 0x5f, 0x4e, 0x70, 0x05, 0xb3, 0x3d,
      0xcb, 0xa6, 0x77, 0x96, 0x00, 0x1a, 0xd8, 0x28,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char mujoco_ros_msgs__msg__StateUint__TYPE_NAME[] = "mujoco_ros_msgs/msg/StateUint";

// Define type names, field names, and default values
static char mujoco_ros_msgs__msg__StateUint__FIELD_NAME__value[] = "value";
static char mujoco_ros_msgs__msg__StateUint__FIELD_NAME__description[] = "description";

static rosidl_runtime_c__type_description__Field mujoco_ros_msgs__msg__StateUint__FIELDS[] = {
  {
    {mujoco_ros_msgs__msg__StateUint__FIELD_NAME__value, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__StateUint__FIELD_NAME__description, 11, 11},
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
mujoco_ros_msgs__msg__StateUint__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mujoco_ros_msgs__msg__StateUint__TYPE_NAME, 29, 29},
      {mujoco_ros_msgs__msg__StateUint__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "uint8 value\n"
  "string description";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
mujoco_ros_msgs__msg__StateUint__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mujoco_ros_msgs__msg__StateUint__TYPE_NAME, 29, 29},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 31, 31},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mujoco_ros_msgs__msg__StateUint__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mujoco_ros_msgs__msg__StateUint__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
