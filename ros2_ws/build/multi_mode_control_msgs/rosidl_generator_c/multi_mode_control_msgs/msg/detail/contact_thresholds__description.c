// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from multi_mode_control_msgs:msg/ContactThresholds.idl
// generated code does not contain a copyright notice

#include "multi_mode_control_msgs/msg/detail/contact_thresholds__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_multi_mode_control_msgs
const rosidl_type_hash_t *
multi_mode_control_msgs__msg__ContactThresholds__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x24, 0xba, 0x80, 0x96, 0xac, 0xae, 0xe2, 0xa4,
      0xc5, 0x82, 0x69, 0xc9, 0xec, 0x27, 0x98, 0x21,
      0xd1, 0x04, 0x70, 0xcf, 0x2c, 0x74, 0x0d, 0x2b,
      0x59, 0x10, 0x2f, 0x0d, 0x16, 0xc9, 0x01, 0xd9,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "multi_mode_control_msgs/msg/detail/joint_array__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t multi_mode_control_msgs__msg__JointArray__EXPECTED_HASH = {1, {
    0x55, 0xbe, 0x3e, 0xc4, 0xe2, 0xfa, 0xae, 0x74,
    0x25, 0xbf, 0x87, 0x86, 0x39, 0xe2, 0x7d, 0xb9,
    0x4a, 0x6b, 0x6c, 0x41, 0x87, 0x15, 0xa8, 0x46,
    0x2b, 0x54, 0xca, 0x8a, 0x51, 0xdf, 0xf9, 0x27,
  }};
#endif

static char multi_mode_control_msgs__msg__ContactThresholds__TYPE_NAME[] = "multi_mode_control_msgs/msg/ContactThresholds";
static char multi_mode_control_msgs__msg__JointArray__TYPE_NAME[] = "multi_mode_control_msgs/msg/JointArray";

// Define type names, field names, and default values
static char multi_mode_control_msgs__msg__ContactThresholds__FIELD_NAME__f_max[] = "f_max";
static char multi_mode_control_msgs__msg__ContactThresholds__FIELD_NAME__f_min[] = "f_min";
static char multi_mode_control_msgs__msg__ContactThresholds__FIELD_NAME__tau_max[] = "tau_max";
static char multi_mode_control_msgs__msg__ContactThresholds__FIELD_NAME__tau_min[] = "tau_min";
static char multi_mode_control_msgs__msg__ContactThresholds__FIELD_NAME__f_abs_max[] = "f_abs_max";
static char multi_mode_control_msgs__msg__ContactThresholds__FIELD_NAME__m_abs_max[] = "m_abs_max";
static char multi_mode_control_msgs__msg__ContactThresholds__FIELD_NAME__abs_mode[] = "abs_mode";
static char multi_mode_control_msgs__msg__ContactThresholds__FIELD_NAME__directional_mode[] = "directional_mode";
static char multi_mode_control_msgs__msg__ContactThresholds__FIELD_NAME__torque_mode[] = "torque_mode";

static rosidl_runtime_c__type_description__Field multi_mode_control_msgs__msg__ContactThresholds__FIELDS[] = {
  {
    {multi_mode_control_msgs__msg__ContactThresholds__FIELD_NAME__f_max, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      6,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__msg__ContactThresholds__FIELD_NAME__f_min, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      6,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__msg__ContactThresholds__FIELD_NAME__tau_max, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {multi_mode_control_msgs__msg__JointArray__TYPE_NAME, 38, 38},
    },
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__msg__ContactThresholds__FIELD_NAME__tau_min, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {multi_mode_control_msgs__msg__JointArray__TYPE_NAME, 38, 38},
    },
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__msg__ContactThresholds__FIELD_NAME__f_abs_max, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__msg__ContactThresholds__FIELD_NAME__m_abs_max, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__msg__ContactThresholds__FIELD_NAME__abs_mode, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__msg__ContactThresholds__FIELD_NAME__directional_mode, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_mode_control_msgs__msg__ContactThresholds__FIELD_NAME__torque_mode, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription multi_mode_control_msgs__msg__ContactThresholds__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {multi_mode_control_msgs__msg__JointArray__TYPE_NAME, 38, 38},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
multi_mode_control_msgs__msg__ContactThresholds__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {multi_mode_control_msgs__msg__ContactThresholds__TYPE_NAME, 45, 45},
      {multi_mode_control_msgs__msg__ContactThresholds__FIELDS, 9, 9},
    },
    {multi_mode_control_msgs__msg__ContactThresholds__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&multi_mode_control_msgs__msg__JointArray__EXPECTED_HASH, multi_mode_control_msgs__msg__JointArray__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = multi_mode_control_msgs__msg__JointArray__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float64[6]   f_max\n"
  "float64[6]   f_min\n"
  "JointArray[] tau_max\n"
  "JointArray[] tau_min\n"
  "float64      f_abs_max\n"
  "float64      m_abs_max\n"
  "bool         abs_mode\n"
  "bool         directional_mode\n"
  "bool         torque_mode";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
multi_mode_control_msgs__msg__ContactThresholds__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {multi_mode_control_msgs__msg__ContactThresholds__TYPE_NAME, 45, 45},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 203, 203},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
multi_mode_control_msgs__msg__ContactThresholds__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *multi_mode_control_msgs__msg__ContactThresholds__get_individual_type_description_source(NULL),
    sources[1] = *multi_mode_control_msgs__msg__JointArray__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
