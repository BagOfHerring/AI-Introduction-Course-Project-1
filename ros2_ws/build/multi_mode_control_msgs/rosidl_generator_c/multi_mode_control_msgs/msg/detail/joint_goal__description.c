// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from multi_mode_control_msgs:msg/JointGoal.idl
// generated code does not contain a copyright notice

#include "multi_mode_control_msgs/msg/detail/joint_goal__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_multi_mode_control_msgs
const rosidl_type_hash_t *
multi_mode_control_msgs__msg__JointGoal__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xec, 0xc7, 0x25, 0x1b, 0xf0, 0xbd, 0xeb, 0xc4,
      0x95, 0x15, 0x26, 0x40, 0x62, 0x74, 0x36, 0xbc,
      0x37, 0xcf, 0x87, 0x6b, 0x51, 0xdb, 0xff, 0xa0,
      0x73, 0xe8, 0xc1, 0xe5, 0xc0, 0x32, 0x92, 0x3d,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char multi_mode_control_msgs__msg__JointGoal__TYPE_NAME[] = "multi_mode_control_msgs/msg/JointGoal";

// Define type names, field names, and default values
static char multi_mode_control_msgs__msg__JointGoal__FIELD_NAME__q[] = "q";
static char multi_mode_control_msgs__msg__JointGoal__FIELD_NAME__qd[] = "qd";

static rosidl_runtime_c__type_description__Field multi_mode_control_msgs__msg__JointGoal__FIELDS[] = {
  {
    {multi_mode_control_msgs__msg__JointGoal__FIELD_NAME__q, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      7,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__msg__JointGoal__FIELD_NAME__qd, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      7,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
multi_mode_control_msgs__msg__JointGoal__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {multi_mode_control_msgs__msg__JointGoal__TYPE_NAME, 37, 37},
      {multi_mode_control_msgs__msg__JointGoal__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float64[7] q\n"
  "float64[7] qd";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
multi_mode_control_msgs__msg__JointGoal__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {multi_mode_control_msgs__msg__JointGoal__TYPE_NAME, 37, 37},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 27, 27},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
multi_mode_control_msgs__msg__JointGoal__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *multi_mode_control_msgs__msg__JointGoal__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
