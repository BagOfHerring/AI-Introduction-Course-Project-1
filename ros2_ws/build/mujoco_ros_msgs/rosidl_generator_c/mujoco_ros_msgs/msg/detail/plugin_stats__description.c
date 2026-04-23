// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from mujoco_ros_msgs:msg/PluginStats.idl
// generated code does not contain a copyright notice

#include "mujoco_ros_msgs/msg/detail/plugin_stats__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_mujoco_ros_msgs
const rosidl_type_hash_t *
mujoco_ros_msgs__msg__PluginStats__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x1a, 0xf4, 0x2b, 0xec, 0x3f, 0x7b, 0xc1, 0xd2,
      0xb5, 0x55, 0x00, 0xeb, 0xcc, 0x5b, 0xec, 0xb8,
      0xb8, 0x14, 0x76, 0x39, 0xf9, 0x23, 0x12, 0x1a,
      0x0a, 0xfb, 0xb8, 0xff, 0xbe, 0xe8, 0x4a, 0xc6,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char mujoco_ros_msgs__msg__PluginStats__TYPE_NAME[] = "mujoco_ros_msgs/msg/PluginStats";

// Define type names, field names, and default values
static char mujoco_ros_msgs__msg__PluginStats__FIELD_NAME__plugin_type[] = "plugin_type";
static char mujoco_ros_msgs__msg__PluginStats__FIELD_NAME__load_time[] = "load_time";
static char mujoco_ros_msgs__msg__PluginStats__FIELD_NAME__reset_time[] = "reset_time";
static char mujoco_ros_msgs__msg__PluginStats__FIELD_NAME__ema_steptime_control[] = "ema_steptime_control";
static char mujoco_ros_msgs__msg__PluginStats__FIELD_NAME__ema_steptime_passive[] = "ema_steptime_passive";
static char mujoco_ros_msgs__msg__PluginStats__FIELD_NAME__ema_steptime_render[] = "ema_steptime_render";
static char mujoco_ros_msgs__msg__PluginStats__FIELD_NAME__ema_steptime_last_stage[] = "ema_steptime_last_stage";

static rosidl_runtime_c__type_description__Field mujoco_ros_msgs__msg__PluginStats__FIELDS[] = {
  {
    {mujoco_ros_msgs__msg__PluginStats__FIELD_NAME__plugin_type, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__PluginStats__FIELD_NAME__load_time, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__PluginStats__FIELD_NAME__reset_time, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__PluginStats__FIELD_NAME__ema_steptime_control, 20, 20},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__PluginStats__FIELD_NAME__ema_steptime_passive, 20, 20},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__PluginStats__FIELD_NAME__ema_steptime_render, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__PluginStats__FIELD_NAME__ema_steptime_last_stage, 23, 23},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mujoco_ros_msgs__msg__PluginStats__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mujoco_ros_msgs__msg__PluginStats__TYPE_NAME, 31, 31},
      {mujoco_ros_msgs__msg__PluginStats__FIELDS, 7, 7},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string plugin_type\n"
  "float32 load_time\n"
  "float32 reset_time\n"
  "float32 ema_steptime_control\n"
  "float32 ema_steptime_passive\n"
  "float32 ema_steptime_render\n"
  "float32 ema_steptime_last_stage";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
mujoco_ros_msgs__msg__PluginStats__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mujoco_ros_msgs__msg__PluginStats__TYPE_NAME, 31, 31},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 174, 174},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mujoco_ros_msgs__msg__PluginStats__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mujoco_ros_msgs__msg__PluginStats__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
