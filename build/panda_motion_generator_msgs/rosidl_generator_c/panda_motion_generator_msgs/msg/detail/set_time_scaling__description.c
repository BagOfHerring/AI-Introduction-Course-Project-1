// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from panda_motion_generator_msgs:msg/SetTimeScaling.idl
// generated code does not contain a copyright notice

#include "panda_motion_generator_msgs/msg/detail/set_time_scaling__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_panda_motion_generator_msgs
const rosidl_type_hash_t *
panda_motion_generator_msgs__msg__SetTimeScaling__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x5d, 0x30, 0x9a, 0xe9, 0x60, 0x72, 0x8a, 0xaf,
      0xe3, 0x16, 0x1a, 0xcb, 0x16, 0xc4, 0x69, 0x66,
      0xf6, 0x9f, 0x3c, 0x52, 0x47, 0x35, 0xd0, 0x4e,
      0xce, 0x57, 0xc2, 0x7b, 0x09, 0x2f, 0xf3, 0xca,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char panda_motion_generator_msgs__msg__SetTimeScaling__TYPE_NAME[] = "panda_motion_generator_msgs/msg/SetTimeScaling";

// Define type names, field names, and default values
static char panda_motion_generator_msgs__msg__SetTimeScaling__FIELD_NAME__steps[] = "steps";
static char panda_motion_generator_msgs__msg__SetTimeScaling__FIELD_NAME__scaling[] = "scaling";

static rosidl_runtime_c__type_description__Field panda_motion_generator_msgs__msg__SetTimeScaling__FIELDS[] = {
  {
    {panda_motion_generator_msgs__msg__SetTimeScaling__FIELD_NAME__steps, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {panda_motion_generator_msgs__msg__SetTimeScaling__FIELD_NAME__scaling, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
panda_motion_generator_msgs__msg__SetTimeScaling__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {panda_motion_generator_msgs__msg__SetTimeScaling__TYPE_NAME, 46, 46},
      {panda_motion_generator_msgs__msg__SetTimeScaling__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int32 steps\n"
  "float64 scaling";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
panda_motion_generator_msgs__msg__SetTimeScaling__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {panda_motion_generator_msgs__msg__SetTimeScaling__TYPE_NAME, 46, 46},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 28, 28},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
panda_motion_generator_msgs__msg__SetTimeScaling__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *panda_motion_generator_msgs__msg__SetTimeScaling__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
