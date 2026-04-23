// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from panda_motion_generator_msgs:msg/JointPose.idl
// generated code does not contain a copyright notice

#include "panda_motion_generator_msgs/msg/detail/joint_pose__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_panda_motion_generator_msgs
const rosidl_type_hash_t *
panda_motion_generator_msgs__msg__JointPose__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xac, 0x5e, 0x82, 0x3f, 0xa1, 0x8c, 0x75, 0x32,
      0xa5, 0x3d, 0xe2, 0x13, 0x14, 0xa2, 0x18, 0xe2,
      0x6f, 0xb4, 0x04, 0xf2, 0x7c, 0x24, 0xa0, 0x8d,
      0xf0, 0x20, 0x40, 0x49, 0x85, 0xf6, 0xd7, 0x44,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char panda_motion_generator_msgs__msg__JointPose__TYPE_NAME[] = "panda_motion_generator_msgs/msg/JointPose";

// Define type names, field names, and default values
static char panda_motion_generator_msgs__msg__JointPose__FIELD_NAME__q[] = "q";

static rosidl_runtime_c__type_description__Field panda_motion_generator_msgs__msg__JointPose__FIELDS[] = {
  {
    {panda_motion_generator_msgs__msg__JointPose__FIELD_NAME__q, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
panda_motion_generator_msgs__msg__JointPose__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {panda_motion_generator_msgs__msg__JointPose__TYPE_NAME, 41, 41},
      {panda_motion_generator_msgs__msg__JointPose__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float64[] q";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
panda_motion_generator_msgs__msg__JointPose__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {panda_motion_generator_msgs__msg__JointPose__TYPE_NAME, 41, 41},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 12, 12},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
panda_motion_generator_msgs__msg__JointPose__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *panda_motion_generator_msgs__msg__JointPose__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
