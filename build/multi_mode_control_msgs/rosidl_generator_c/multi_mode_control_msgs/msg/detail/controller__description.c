// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from multi_mode_control_msgs:msg/Controller.idl
// generated code does not contain a copyright notice

#include "multi_mode_control_msgs/msg/detail/controller__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_multi_mode_control_msgs
const rosidl_type_hash_t *
multi_mode_control_msgs__msg__Controller__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x71, 0xd0, 0xfc, 0xd5, 0x60, 0x46, 0x0d, 0xde,
      0x93, 0xe9, 0x40, 0x24, 0x26, 0x8b, 0x7e, 0x28,
      0xcd, 0x50, 0x30, 0x40, 0xc5, 0x95, 0xd9, 0xdc,
      0x2c, 0xc2, 0x5b, 0xda, 0x4a, 0x70, 0x05, 0x61,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char multi_mode_control_msgs__msg__Controller__TYPE_NAME[] = "multi_mode_control_msgs/msg/Controller";

// Define type names, field names, and default values
static char multi_mode_control_msgs__msg__Controller__FIELD_NAME__name[] = "name";
static char multi_mode_control_msgs__msg__Controller__FIELD_NAME__resources[] = "resources";

static rosidl_runtime_c__type_description__Field multi_mode_control_msgs__msg__Controller__FIELDS[] = {
  {
    {multi_mode_control_msgs__msg__Controller__FIELD_NAME__name, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__msg__Controller__FIELD_NAME__resources, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
multi_mode_control_msgs__msg__Controller__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {multi_mode_control_msgs__msg__Controller__TYPE_NAME, 38, 38},
      {multi_mode_control_msgs__msg__Controller__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string name\n"
  "string[] resources";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
multi_mode_control_msgs__msg__Controller__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {multi_mode_control_msgs__msg__Controller__TYPE_NAME, 38, 38},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 31, 31},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
multi_mode_control_msgs__msg__Controller__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *multi_mode_control_msgs__msg__Controller__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
