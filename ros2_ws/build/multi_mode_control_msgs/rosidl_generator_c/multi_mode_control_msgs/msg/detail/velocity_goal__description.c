// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from multi_mode_control_msgs:msg/VelocityGoal.idl
// generated code does not contain a copyright notice

#include "multi_mode_control_msgs/msg/detail/velocity_goal__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_multi_mode_control_msgs
const rosidl_type_hash_t *
multi_mode_control_msgs__msg__VelocityGoal__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x77, 0x19, 0x67, 0xa8, 0x79, 0x40, 0xa1, 0x82,
      0xa3, 0x26, 0xe7, 0xf1, 0xcb, 0xdb, 0x54, 0x2a,
      0x24, 0x82, 0xa5, 0x82, 0x0e, 0x19, 0x19, 0xfd,
      0x23, 0x72, 0xa5, 0xc0, 0x59, 0xd1, 0x40, 0xd1,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char multi_mode_control_msgs__msg__VelocityGoal__TYPE_NAME[] = "multi_mode_control_msgs/msg/VelocityGoal";

// Define type names, field names, and default values
static char multi_mode_control_msgs__msg__VelocityGoal__FIELD_NAME__qd[] = "qd";

static rosidl_runtime_c__type_description__Field multi_mode_control_msgs__msg__VelocityGoal__FIELDS[] = {
  {
    {multi_mode_control_msgs__msg__VelocityGoal__FIELD_NAME__qd, 2, 2},
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
multi_mode_control_msgs__msg__VelocityGoal__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {multi_mode_control_msgs__msg__VelocityGoal__TYPE_NAME, 40, 40},
      {multi_mode_control_msgs__msg__VelocityGoal__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float64[7] qd";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
multi_mode_control_msgs__msg__VelocityGoal__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {multi_mode_control_msgs__msg__VelocityGoal__TYPE_NAME, 40, 40},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 14, 14},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
multi_mode_control_msgs__msg__VelocityGoal__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *multi_mode_control_msgs__msg__VelocityGoal__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
