// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from mujoco_ros_msgs:msg/SimInfo.idl
// generated code does not contain a copyright notice

#include "mujoco_ros_msgs/msg/detail/sim_info__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_mujoco_ros_msgs
const rosidl_type_hash_t *
mujoco_ros_msgs__msg__SimInfo__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xaf, 0x18, 0xc9, 0xc3, 0xef, 0x8b, 0x91, 0xda,
      0xb3, 0x67, 0xc1, 0x0e, 0x5b, 0x0e, 0xde, 0xb5,
      0x31, 0x67, 0xff, 0x22, 0xbb, 0x42, 0xaa, 0x5c,
      0x26, 0xc1, 0x64, 0x22, 0x25, 0x12, 0xac, 0x05,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "mujoco_ros_msgs/msg/detail/state_uint__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t mujoco_ros_msgs__msg__StateUint__EXPECTED_HASH = {1, {
    0xc6, 0x0f, 0x38, 0x4b, 0xc4, 0x42, 0x5d, 0xfa,
    0x47, 0x4e, 0x8e, 0x98, 0x60, 0x2b, 0x00, 0xd1,
    0x8d, 0x86, 0x5f, 0x4e, 0x70, 0x05, 0xb3, 0x3d,
    0xcb, 0xa6, 0x77, 0x96, 0x00, 0x1a, 0xd8, 0x28,
  }};
#endif

static char mujoco_ros_msgs__msg__SimInfo__TYPE_NAME[] = "mujoco_ros_msgs/msg/SimInfo";
static char mujoco_ros_msgs__msg__StateUint__TYPE_NAME[] = "mujoco_ros_msgs/msg/StateUint";

// Define type names, field names, and default values
static char mujoco_ros_msgs__msg__SimInfo__FIELD_NAME__model_path[] = "model_path";
static char mujoco_ros_msgs__msg__SimInfo__FIELD_NAME__model_valid[] = "model_valid";
static char mujoco_ros_msgs__msg__SimInfo__FIELD_NAME__load_count[] = "load_count";
static char mujoco_ros_msgs__msg__SimInfo__FIELD_NAME__loading_state[] = "loading_state";
static char mujoco_ros_msgs__msg__SimInfo__FIELD_NAME__paused[] = "paused";
static char mujoco_ros_msgs__msg__SimInfo__FIELD_NAME__pending_sim_steps[] = "pending_sim_steps";
static char mujoco_ros_msgs__msg__SimInfo__FIELD_NAME__rt_measured[] = "rt_measured";
static char mujoco_ros_msgs__msg__SimInfo__FIELD_NAME__rt_setting[] = "rt_setting";

static rosidl_runtime_c__type_description__Field mujoco_ros_msgs__msg__SimInfo__FIELDS[] = {
  {
    {mujoco_ros_msgs__msg__SimInfo__FIELD_NAME__model_path, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__SimInfo__FIELD_NAME__model_valid, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__SimInfo__FIELD_NAME__load_count, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__SimInfo__FIELD_NAME__loading_state, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {mujoco_ros_msgs__msg__StateUint__TYPE_NAME, 29, 29},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__SimInfo__FIELD_NAME__paused, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__SimInfo__FIELD_NAME__pending_sim_steps, 17, 17},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__SimInfo__FIELD_NAME__rt_measured, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__SimInfo__FIELD_NAME__rt_setting, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription mujoco_ros_msgs__msg__SimInfo__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {mujoco_ros_msgs__msg__StateUint__TYPE_NAME, 29, 29},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mujoco_ros_msgs__msg__SimInfo__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mujoco_ros_msgs__msg__SimInfo__TYPE_NAME, 27, 27},
      {mujoco_ros_msgs__msg__SimInfo__FIELDS, 8, 8},
    },
    {mujoco_ros_msgs__msg__SimInfo__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&mujoco_ros_msgs__msg__StateUint__EXPECTED_HASH, mujoco_ros_msgs__msg__StateUint__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = mujoco_ros_msgs__msg__StateUint__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string model_path\n"
  "bool model_valid\n"
  "uint16 load_count # counter of (re)loads\n"
  "mujoco_ros_msgs/StateUint loading_state\n"
  "bool paused\n"
  "uint16 pending_sim_steps\n"
  "float32 rt_measured # measured real-time factor\n"
  "float32 rt_setting # desired real-time factor";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
mujoco_ros_msgs__msg__SimInfo__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mujoco_ros_msgs__msg__SimInfo__TYPE_NAME, 27, 27},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 247, 247},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mujoco_ros_msgs__msg__SimInfo__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mujoco_ros_msgs__msg__SimInfo__get_individual_type_description_source(NULL),
    sources[1] = *mujoco_ros_msgs__msg__StateUint__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
