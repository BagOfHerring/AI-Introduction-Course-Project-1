// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from mujoco_ros_msgs:msg/EqualityConstraintParameters.idl
// generated code does not contain a copyright notice

#include "mujoco_ros_msgs/msg/detail/equality_constraint_parameters__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_mujoco_ros_msgs
const rosidl_type_hash_t *
mujoco_ros_msgs__msg__EqualityConstraintParameters__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xdb, 0x68, 0x6b, 0x03, 0x50, 0x01, 0x94, 0x26,
      0x3d, 0xc7, 0x16, 0x1c, 0x15, 0xf7, 0xe3, 0xa1,
      0x85, 0x8c, 0x06, 0xb2, 0xcf, 0xe2, 0x82, 0x3d,
      0x02, 0xa2, 0xa7, 0x69, 0x71, 0x44, 0xd0, 0x0a,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "geometry_msgs/msg/detail/vector3__functions.h"
#include "geometry_msgs/msg/detail/pose__functions.h"
#include "geometry_msgs/msg/detail/quaternion__functions.h"
#include "mujoco_ros_msgs/msg/detail/equality_constraint_type__functions.h"
#include "mujoco_ros_msgs/msg/detail/solver_parameters__functions.h"
#include "geometry_msgs/msg/detail/point__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t geometry_msgs__msg__Point__EXPECTED_HASH = {1, {
    0x69, 0x63, 0x08, 0x48, 0x42, 0xa9, 0xb0, 0x44,
    0x94, 0xd6, 0xb2, 0x94, 0x1d, 0x11, 0x44, 0x47,
    0x08, 0xd8, 0x92, 0xda, 0x2f, 0x4b, 0x09, 0x84,
    0x3b, 0x9c, 0x43, 0xf4, 0x2a, 0x7f, 0x68, 0x81,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__Pose__EXPECTED_HASH = {1, {
    0xd5, 0x01, 0x95, 0x4e, 0x94, 0x76, 0xce, 0xa2,
    0x99, 0x69, 0x84, 0xe8, 0x12, 0x05, 0x4b, 0x68,
    0x02, 0x6a, 0xe0, 0xbf, 0xae, 0x78, 0x9d, 0x9a,
    0x10, 0xb2, 0x3d, 0xaf, 0x35, 0xcc, 0x90, 0xfa,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__Quaternion__EXPECTED_HASH = {1, {
    0x8a, 0x76, 0x5f, 0x66, 0x77, 0x8c, 0x8f, 0xf7,
    0xc8, 0xab, 0x94, 0xaf, 0xcc, 0x59, 0x0a, 0x2e,
    0xd5, 0x32, 0x5a, 0x1d, 0x9a, 0x07, 0x6f, 0xff,
    0xf3, 0x8f, 0xbc, 0xe3, 0x6f, 0x45, 0x86, 0x84,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__Vector3__EXPECTED_HASH = {1, {
    0xcc, 0x12, 0xfe, 0x83, 0xe4, 0xc0, 0x27, 0x19,
    0xf1, 0xce, 0x80, 0x70, 0xbf, 0xd1, 0x4a, 0xec,
    0xd4, 0x0f, 0x75, 0xa9, 0x66, 0x96, 0xa6, 0x7a,
    0x2a, 0x1f, 0x37, 0xf7, 0xdb, 0xb0, 0x76, 0x5d,
  }};
static const rosidl_type_hash_t mujoco_ros_msgs__msg__EqualityConstraintType__EXPECTED_HASH = {1, {
    0xe1, 0x33, 0x46, 0xdc, 0x86, 0x14, 0xfd, 0xc2,
    0x3c, 0x9c, 0x47, 0xe3, 0x25, 0x90, 0xd9, 0x66,
    0x7b, 0x62, 0xa1, 0xba, 0xb0, 0xe5, 0x01, 0xa7,
    0xae, 0x1b, 0x90, 0x51, 0xff, 0x60, 0xbd, 0xdf,
  }};
static const rosidl_type_hash_t mujoco_ros_msgs__msg__SolverParameters__EXPECTED_HASH = {1, {
    0xcd, 0x99, 0x72, 0xec, 0x97, 0x0b, 0x13, 0xe9,
    0xbd, 0x6e, 0xad, 0x9b, 0xf9, 0xee, 0x02, 0x6a,
    0x20, 0x56, 0x26, 0xee, 0x59, 0x30, 0x0a, 0xc4,
    0x1c, 0x8a, 0xbc, 0x1c, 0x24, 0x5f, 0x02, 0x45,
  }};
#endif

static char mujoco_ros_msgs__msg__EqualityConstraintParameters__TYPE_NAME[] = "mujoco_ros_msgs/msg/EqualityConstraintParameters";
static char geometry_msgs__msg__Point__TYPE_NAME[] = "geometry_msgs/msg/Point";
static char geometry_msgs__msg__Pose__TYPE_NAME[] = "geometry_msgs/msg/Pose";
static char geometry_msgs__msg__Quaternion__TYPE_NAME[] = "geometry_msgs/msg/Quaternion";
static char geometry_msgs__msg__Vector3__TYPE_NAME[] = "geometry_msgs/msg/Vector3";
static char mujoco_ros_msgs__msg__EqualityConstraintType__TYPE_NAME[] = "mujoco_ros_msgs/msg/EqualityConstraintType";
static char mujoco_ros_msgs__msg__SolverParameters__TYPE_NAME[] = "mujoco_ros_msgs/msg/SolverParameters";

// Define type names, field names, and default values
static char mujoco_ros_msgs__msg__EqualityConstraintParameters__FIELD_NAME__name[] = "name";
static char mujoco_ros_msgs__msg__EqualityConstraintParameters__FIELD_NAME__type[] = "type";
static char mujoco_ros_msgs__msg__EqualityConstraintParameters__FIELD_NAME__solver_parameters[] = "solver_parameters";
static char mujoco_ros_msgs__msg__EqualityConstraintParameters__FIELD_NAME__active[] = "active";
static char mujoco_ros_msgs__msg__EqualityConstraintParameters__FIELD_NAME__class_param[] = "class_param";
static char mujoco_ros_msgs__msg__EqualityConstraintParameters__FIELD_NAME__element1[] = "element1";
static char mujoco_ros_msgs__msg__EqualityConstraintParameters__FIELD_NAME__element2[] = "element2";
static char mujoco_ros_msgs__msg__EqualityConstraintParameters__FIELD_NAME__torquescale[] = "torquescale";
static char mujoco_ros_msgs__msg__EqualityConstraintParameters__FIELD_NAME__anchor[] = "anchor";
static char mujoco_ros_msgs__msg__EqualityConstraintParameters__FIELD_NAME__relpose[] = "relpose";
static char mujoco_ros_msgs__msg__EqualityConstraintParameters__FIELD_NAME__polycoef[] = "polycoef";

static rosidl_runtime_c__type_description__Field mujoco_ros_msgs__msg__EqualityConstraintParameters__FIELDS[] = {
  {
    {mujoco_ros_msgs__msg__EqualityConstraintParameters__FIELD_NAME__name, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__EqualityConstraintParameters__FIELD_NAME__type, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {mujoco_ros_msgs__msg__EqualityConstraintType__TYPE_NAME, 42, 42},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__EqualityConstraintParameters__FIELD_NAME__solver_parameters, 17, 17},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {mujoco_ros_msgs__msg__SolverParameters__TYPE_NAME, 36, 36},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__EqualityConstraintParameters__FIELD_NAME__active, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__EqualityConstraintParameters__FIELD_NAME__class_param, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__EqualityConstraintParameters__FIELD_NAME__element1, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__EqualityConstraintParameters__FIELD_NAME__element2, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__EqualityConstraintParameters__FIELD_NAME__torquescale, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__EqualityConstraintParameters__FIELD_NAME__anchor, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__Vector3__TYPE_NAME, 25, 25},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__EqualityConstraintParameters__FIELD_NAME__relpose, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__Pose__TYPE_NAME, 22, 22},
    },
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__EqualityConstraintParameters__FIELD_NAME__polycoef, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription mujoco_ros_msgs__msg__EqualityConstraintParameters__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Pose__TYPE_NAME, 22, 22},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Quaternion__TYPE_NAME, 28, 28},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Vector3__TYPE_NAME, 25, 25},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__EqualityConstraintType__TYPE_NAME, 42, 42},
    {NULL, 0, 0},
  },
  {
    {mujoco_ros_msgs__msg__SolverParameters__TYPE_NAME, 36, 36},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mujoco_ros_msgs__msg__EqualityConstraintParameters__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mujoco_ros_msgs__msg__EqualityConstraintParameters__TYPE_NAME, 48, 48},
      {mujoco_ros_msgs__msg__EqualityConstraintParameters__FIELDS, 11, 11},
    },
    {mujoco_ros_msgs__msg__EqualityConstraintParameters__REFERENCED_TYPE_DESCRIPTIONS, 6, 6},
  };
  if (!constructed) {
    assert(0 == memcmp(&geometry_msgs__msg__Point__EXPECTED_HASH, geometry_msgs__msg__Point__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = geometry_msgs__msg__Point__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Pose__EXPECTED_HASH, geometry_msgs__msg__Pose__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = geometry_msgs__msg__Pose__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Quaternion__EXPECTED_HASH, geometry_msgs__msg__Quaternion__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = geometry_msgs__msg__Quaternion__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Vector3__EXPECTED_HASH, geometry_msgs__msg__Vector3__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = geometry_msgs__msg__Vector3__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&mujoco_ros_msgs__msg__EqualityConstraintType__EXPECTED_HASH, mujoco_ros_msgs__msg__EqualityConstraintType__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = mujoco_ros_msgs__msg__EqualityConstraintType__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&mujoco_ros_msgs__msg__SolverParameters__EXPECTED_HASH, mujoco_ros_msgs__msg__SolverParameters__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[5].fields = mujoco_ros_msgs__msg__SolverParameters__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string name\n"
  "mujoco_ros_msgs/EqualityConstraintType type\n"
  "mujoco_ros_msgs/SolverParameters solver_parameters\n"
  "bool active\n"
  "string class_param\n"
  "string element1\n"
  "string element2\n"
  "float64 torquescale\n"
  "geometry_msgs/Vector3 anchor\n"
  "geometry_msgs/Pose relpose\n"
  "float64[] polycoef";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
mujoco_ros_msgs__msg__EqualityConstraintParameters__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mujoco_ros_msgs__msg__EqualityConstraintParameters__TYPE_NAME, 48, 48},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 265, 265},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mujoco_ros_msgs__msg__EqualityConstraintParameters__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[7];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 7, 7};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mujoco_ros_msgs__msg__EqualityConstraintParameters__get_individual_type_description_source(NULL),
    sources[1] = *geometry_msgs__msg__Point__get_individual_type_description_source(NULL);
    sources[2] = *geometry_msgs__msg__Pose__get_individual_type_description_source(NULL);
    sources[3] = *geometry_msgs__msg__Quaternion__get_individual_type_description_source(NULL);
    sources[4] = *geometry_msgs__msg__Vector3__get_individual_type_description_source(NULL);
    sources[5] = *mujoco_ros_msgs__msg__EqualityConstraintType__get_individual_type_description_source(NULL);
    sources[6] = *mujoco_ros_msgs__msg__SolverParameters__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
