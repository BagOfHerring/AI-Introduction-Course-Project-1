// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from multi_mode_control_msgs:msg/JointArray.idl
// generated code does not contain a copyright notice

#include "multi_mode_control_msgs/msg/detail/joint_array__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_multi_mode_control_msgs
const rosidl_type_hash_t *
multi_mode_control_msgs__msg__JointArray__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x55, 0xbe, 0x3e, 0xc4, 0xe2, 0xfa, 0xae, 0x74,
      0x25, 0xbf, 0x87, 0x86, 0x39, 0xe2, 0x7d, 0xb9,
      0x4a, 0x6b, 0x6c, 0x41, 0x87, 0x15, 0xa8, 0x46,
      0x2b, 0x54, 0xca, 0x8a, 0x51, 0xdf, 0xf9, 0x27,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char multi_mode_control_msgs__msg__JointArray__TYPE_NAME[] = "multi_mode_control_msgs/msg/JointArray";

// Define type names, field names, and default values
static char multi_mode_control_msgs__msg__JointArray__FIELD_NAME__data[] = "data";

static rosidl_runtime_c__type_description__Field multi_mode_control_msgs__msg__JointArray__FIELDS[] = {
  {
    {multi_mode_control_msgs__msg__JointArray__FIELD_NAME__data, 4, 4},
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
multi_mode_control_msgs__msg__JointArray__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {multi_mode_control_msgs__msg__JointArray__TYPE_NAME, 38, 38},
      {multi_mode_control_msgs__msg__JointArray__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float64[7] data";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
multi_mode_control_msgs__msg__JointArray__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {multi_mode_control_msgs__msg__JointArray__TYPE_NAME, 38, 38},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 16, 16},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
multi_mode_control_msgs__msg__JointArray__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *multi_mode_control_msgs__msg__JointArray__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
