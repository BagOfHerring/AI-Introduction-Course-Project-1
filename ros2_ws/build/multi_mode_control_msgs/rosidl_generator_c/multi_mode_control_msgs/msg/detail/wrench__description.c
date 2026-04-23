// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from multi_mode_control_msgs:msg/Wrench.idl
// generated code does not contain a copyright notice

#include "multi_mode_control_msgs/msg/detail/wrench__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_multi_mode_control_msgs
const rosidl_type_hash_t *
multi_mode_control_msgs__msg__Wrench__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x32, 0xfd, 0xd5, 0xdf, 0x0d, 0x9c, 0xa6, 0xa2,
      0xf8, 0x54, 0x94, 0x8d, 0xd2, 0xd6, 0x31, 0xaa,
      0x2b, 0x57, 0x73, 0xfb, 0x35, 0xa0, 0x07, 0x0a,
      0x7a, 0xfa, 0xa6, 0x92, 0x67, 0x4d, 0x1e, 0x7d,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char multi_mode_control_msgs__msg__Wrench__TYPE_NAME[] = "multi_mode_control_msgs/msg/Wrench";

// Define type names, field names, and default values
static char multi_mode_control_msgs__msg__Wrench__FIELD_NAME__data[] = "data";

static rosidl_runtime_c__type_description__Field multi_mode_control_msgs__msg__Wrench__FIELDS[] = {
  {
    {multi_mode_control_msgs__msg__Wrench__FIELD_NAME__data, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      6,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
multi_mode_control_msgs__msg__Wrench__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {multi_mode_control_msgs__msg__Wrench__TYPE_NAME, 34, 34},
      {multi_mode_control_msgs__msg__Wrench__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float64[6] data";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
multi_mode_control_msgs__msg__Wrench__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {multi_mode_control_msgs__msg__Wrench__TYPE_NAME, 34, 34},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 16, 16},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
multi_mode_control_msgs__msg__Wrench__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *multi_mode_control_msgs__msg__Wrench__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
