// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from franka_msgs:msg/GraspEpsilon.idl
// generated code does not contain a copyright notice

#include "franka_msgs/msg/detail/grasp_epsilon__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
const rosidl_type_hash_t *
franka_msgs__msg__GraspEpsilon__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x38, 0x7f, 0xda, 0x91, 0xae, 0x73, 0x24, 0xc1,
      0x44, 0x95, 0x8f, 0xa6, 0x17, 0xe7, 0xd5, 0xdc,
      0x21, 0xf9, 0x9d, 0x6b, 0x05, 0x4b, 0x14, 0x1b,
      0x07, 0x3e, 0xad, 0x3d, 0x08, 0x2f, 0x46, 0xd3,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char franka_msgs__msg__GraspEpsilon__TYPE_NAME[] = "franka_msgs/msg/GraspEpsilon";

// Define type names, field names, and default values
static char franka_msgs__msg__GraspEpsilon__FIELD_NAME__inner[] = "inner";
static char franka_msgs__msg__GraspEpsilon__DEFAULT_VALUE__inner[] = "0.005";
static char franka_msgs__msg__GraspEpsilon__FIELD_NAME__outer[] = "outer";
static char franka_msgs__msg__GraspEpsilon__DEFAULT_VALUE__outer[] = "0.005";

static rosidl_runtime_c__type_description__Field franka_msgs__msg__GraspEpsilon__FIELDS[] = {
  {
    {franka_msgs__msg__GraspEpsilon__FIELD_NAME__inner, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {franka_msgs__msg__GraspEpsilon__DEFAULT_VALUE__inner, 5, 5},
  },
  {
    {franka_msgs__msg__GraspEpsilon__FIELD_NAME__outer, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {franka_msgs__msg__GraspEpsilon__DEFAULT_VALUE__outer, 5, 5},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
franka_msgs__msg__GraspEpsilon__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {franka_msgs__msg__GraspEpsilon__TYPE_NAME, 28, 28},
      {franka_msgs__msg__GraspEpsilon__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Maximum tolerated deviation when the actual grasped width\n"
  "# is smaller than the commanded grasp width. Unit: [m]\n"
  "float64 inner 0.005\n"
  "\n"
  "# Maximum tolerated deviation when the actual grasped width\n"
  "# is larger than the commanded grasp width. Unit: [m]\n"
  "float64 outer 0.005";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
franka_msgs__msg__GraspEpsilon__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {franka_msgs__msg__GraspEpsilon__TYPE_NAME, 28, 28},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 269, 269},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
franka_msgs__msg__GraspEpsilon__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *franka_msgs__msg__GraspEpsilon__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
