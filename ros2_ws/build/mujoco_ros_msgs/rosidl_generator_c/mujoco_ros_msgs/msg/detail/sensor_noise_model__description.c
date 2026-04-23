// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from mujoco_ros_msgs:msg/SensorNoiseModel.idl
// generated code does not contain a copyright notice

#include "mujoco_ros_msgs/msg/detail/sensor_noise_model__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_mujoco_ros_msgs
const rosidl_type_hash_t *
mujoco_ros_msgs__msg__SensorNoiseModel__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xa6, 0xc3, 0xc3, 0xec, 0x33, 0x2f, 0xae, 0x87,
      0x54, 0xc3, 0x0e, 0x2b, 0x6b, 0x32, 0xe7, 0x51,
      0x74, 0xd7, 0x01, 0xd4, 0x2b, 0x82, 0x94, 0xbe,
      0x87, 0x9b, 0xf4, 0x08, 0x97, 0x15, 0xd2, 0x16,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char mujoco_ros_msgs__msg__SensorNoiseModel__TYPE_NAME[] = "mujoco_ros_msgs/msg/SensorNoiseModel";

// Define type names, field names, and default values
static char mujoco_ros_msgs__msg__SensorNoiseModel__FIELD_NAME__sensor_name[] = "sensor_name";
static char mujoco_ros_msgs__msg__SensorNoiseModel__FIELD_NAME__mean[] = "mean";
static char mujoco_ros_msgs__msg__SensorNoiseModel__FIELD_NAME__std[] = "std";
static char mujoco_ros_msgs__msg__SensorNoiseModel__FIELD_NAME__set_flag[] = "set_flag";

static rosidl_runtime_c__type_description__Field mujoco_ros_msgs__msg__SensorNoiseModel__FIELDS[] = {
  {
    {mujoco_ros_msgs__msg__SensorNoiseModel__FIELD_NAME__sensor_name, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__SensorNoiseModel__FIELD_NAME__mean, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__SensorNoiseModel__FIELD_NAME__std, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__SensorNoiseModel__FIELD_NAME__set_flag, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mujoco_ros_msgs__msg__SensorNoiseModel__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mujoco_ros_msgs__msg__SensorNoiseModel__TYPE_NAME, 36, 36},
      {mujoco_ros_msgs__msg__SensorNoiseModel__FIELDS, 4, 4},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Set the noise model of a sensor defining mean and standard deviation for each dimension\n"
  "# For quaternion sensors noise is calculated in euler angles (rad), converted to a quaternion and then applied. Thus only three mean/std pairs are required!\n"
  "string sensor_name\n"
  "float64[] mean\n"
  "float64[] std\n"
  "uint8 set_flag";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
mujoco_ros_msgs__msg__SensorNoiseModel__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mujoco_ros_msgs__msg__SensorNoiseModel__TYPE_NAME, 36, 36},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 310, 310},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mujoco_ros_msgs__msg__SensorNoiseModel__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mujoco_ros_msgs__msg__SensorNoiseModel__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
