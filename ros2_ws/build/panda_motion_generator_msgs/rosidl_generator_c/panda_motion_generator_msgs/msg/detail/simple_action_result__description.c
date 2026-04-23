// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from panda_motion_generator_msgs:msg/SimpleActionResult.idl
// generated code does not contain a copyright notice

#include "panda_motion_generator_msgs/msg/detail/simple_action_result__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_panda_motion_generator_msgs
const rosidl_type_hash_t *
panda_motion_generator_msgs__msg__SimpleActionResult__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x52, 0xc3, 0x93, 0x08, 0xe9, 0x34, 0x8a, 0x69,
      0x00, 0x00, 0x01, 0x21, 0x6f, 0x60, 0xe2, 0xc5,
      0x63, 0x19, 0xa1, 0x1d, 0xe0, 0x0b, 0x19, 0x87,
      0xbb, 0x01, 0xe8, 0x51, 0xa4, 0x28, 0xa7, 0x2a,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char panda_motion_generator_msgs__msg__SimpleActionResult__TYPE_NAME[] = "panda_motion_generator_msgs/msg/SimpleActionResult";

// Define type names, field names, and default values
static char panda_motion_generator_msgs__msg__SimpleActionResult__FIELD_NAME__state[] = "state";
static char panda_motion_generator_msgs__msg__SimpleActionResult__FIELD_NAME__error[] = "error";

static rosidl_runtime_c__type_description__Field panda_motion_generator_msgs__msg__SimpleActionResult__FIELDS[] = {
  {
    {panda_motion_generator_msgs__msg__SimpleActionResult__FIELD_NAME__state, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {panda_motion_generator_msgs__msg__SimpleActionResult__FIELD_NAME__error, 5, 5},
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
panda_motion_generator_msgs__msg__SimpleActionResult__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {panda_motion_generator_msgs__msg__SimpleActionResult__TYPE_NAME, 50, 50},
      {panda_motion_generator_msgs__msg__SimpleActionResult__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int32 SUCCESS = 0\n"
  "int32 FAILURE = 1\n"
  "int32 REJECTED = 2\n"
  "int32 ABORTED = 3\n"
  "int32 PREEMPTED = 4\n"
  "int32 state\n"
  "string error";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
panda_motion_generator_msgs__msg__SimpleActionResult__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {panda_motion_generator_msgs__msg__SimpleActionResult__TYPE_NAME, 50, 50},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 118, 118},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
panda_motion_generator_msgs__msg__SimpleActionResult__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *panda_motion_generator_msgs__msg__SimpleActionResult__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
