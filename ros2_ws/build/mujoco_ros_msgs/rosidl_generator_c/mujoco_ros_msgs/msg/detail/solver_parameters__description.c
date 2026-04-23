// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from mujoco_ros_msgs:msg/SolverParameters.idl
// generated code does not contain a copyright notice

#include "mujoco_ros_msgs/msg/detail/solver_parameters__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_mujoco_ros_msgs
const rosidl_type_hash_t *
mujoco_ros_msgs__msg__SolverParameters__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xcd, 0x99, 0x72, 0xec, 0x97, 0x0b, 0x13, 0xe9,
      0xbd, 0x6e, 0xad, 0x9b, 0xf9, 0xee, 0x02, 0x6a,
      0x20, 0x56, 0x26, 0xee, 0x59, 0x30, 0x0a, 0xc4,
      0x1c, 0x8a, 0xbc, 0x1c, 0x24, 0x5f, 0x02, 0x45,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char mujoco_ros_msgs__msg__SolverParameters__TYPE_NAME[] = "mujoco_ros_msgs/msg/SolverParameters";

// Define type names, field names, and default values
static char mujoco_ros_msgs__msg__SolverParameters__FIELD_NAME__dmin[] = "dmin";
static char mujoco_ros_msgs__msg__SolverParameters__FIELD_NAME__dmax[] = "dmax";
static char mujoco_ros_msgs__msg__SolverParameters__FIELD_NAME__width[] = "width";
static char mujoco_ros_msgs__msg__SolverParameters__FIELD_NAME__midpoint[] = "midpoint";
static char mujoco_ros_msgs__msg__SolverParameters__FIELD_NAME__power[] = "power";
static char mujoco_ros_msgs__msg__SolverParameters__FIELD_NAME__timeconst[] = "timeconst";
static char mujoco_ros_msgs__msg__SolverParameters__FIELD_NAME__dampratio[] = "dampratio";

static rosidl_runtime_c__type_description__Field mujoco_ros_msgs__msg__SolverParameters__FIELDS[] = {
  {
    {mujoco_ros_msgs__msg__SolverParameters__FIELD_NAME__dmin, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__SolverParameters__FIELD_NAME__dmax, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__SolverParameters__FIELD_NAME__width, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__SolverParameters__FIELD_NAME__midpoint, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__SolverParameters__FIELD_NAME__power, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__SolverParameters__FIELD_NAME__timeconst, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__SolverParameters__FIELD_NAME__dampratio, 9, 9},
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
mujoco_ros_msgs__msg__SolverParameters__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mujoco_ros_msgs__msg__SolverParameters__TYPE_NAME, 36, 36},
      {mujoco_ros_msgs__msg__SolverParameters__FIELDS, 7, 7},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# solimp parameters\n"
  "\n"
  "float64 dmin\n"
  "float64 dmax\n"
  "float64 width\n"
  "float64 midpoint\n"
  "float64 power\n"
  "\n"
  "# solref parameters\n"
  "\n"
  "float64 timeconst\n"
  "float64 dampratio";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
mujoco_ros_msgs__msg__SolverParameters__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mujoco_ros_msgs__msg__SolverParameters__TYPE_NAME, 36, 36},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 150, 150},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mujoco_ros_msgs__msg__SolverParameters__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mujoco_ros_msgs__msg__SolverParameters__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
