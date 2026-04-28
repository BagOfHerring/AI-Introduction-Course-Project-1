// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from franka_msgs:msg/Errors.idl
// generated code does not contain a copyright notice

#include "franka_msgs/msg/detail/errors__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
const rosidl_type_hash_t *
franka_msgs__msg__Errors__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xe9, 0x8b, 0xbe, 0x02, 0x75, 0x43, 0x2f, 0x4d,
      0x9b, 0x5b, 0x74, 0xc1, 0x1d, 0x4c, 0xda, 0x27,
      0x7d, 0x7d, 0x2b, 0xcf, 0x85, 0x93, 0xd8, 0x99,
      0x60, 0x70, 0x94, 0x35, 0x74, 0x02, 0x59, 0x76,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char franka_msgs__msg__Errors__TYPE_NAME[] = "franka_msgs/msg/Errors";

// Define type names, field names, and default values
static char franka_msgs__msg__Errors__FIELD_NAME__joint_position_limits_violation[] = "joint_position_limits_violation";
static char franka_msgs__msg__Errors__FIELD_NAME__cartesian_position_limits_violation[] = "cartesian_position_limits_violation";
static char franka_msgs__msg__Errors__FIELD_NAME__self_collision_avoidance_violation[] = "self_collision_avoidance_violation";
static char franka_msgs__msg__Errors__FIELD_NAME__joint_velocity_violation[] = "joint_velocity_violation";
static char franka_msgs__msg__Errors__FIELD_NAME__cartesian_velocity_violation[] = "cartesian_velocity_violation";
static char franka_msgs__msg__Errors__FIELD_NAME__force_control_safety_violation[] = "force_control_safety_violation";
static char franka_msgs__msg__Errors__FIELD_NAME__joint_reflex[] = "joint_reflex";
static char franka_msgs__msg__Errors__FIELD_NAME__cartesian_reflex[] = "cartesian_reflex";
static char franka_msgs__msg__Errors__FIELD_NAME__max_goal_pose_deviation_violation[] = "max_goal_pose_deviation_violation";
static char franka_msgs__msg__Errors__FIELD_NAME__max_path_pose_deviation_violation[] = "max_path_pose_deviation_violation";
static char franka_msgs__msg__Errors__FIELD_NAME__cartesian_velocity_profile_safety_violation[] = "cartesian_velocity_profile_safety_violation";
static char franka_msgs__msg__Errors__FIELD_NAME__joint_position_motion_generator_start_pose_invalid[] = "joint_position_motion_generator_start_pose_invalid";
static char franka_msgs__msg__Errors__FIELD_NAME__joint_motion_generator_position_limits_violation[] = "joint_motion_generator_position_limits_violation";
static char franka_msgs__msg__Errors__FIELD_NAME__joint_motion_generator_velocity_limits_violation[] = "joint_motion_generator_velocity_limits_violation";
static char franka_msgs__msg__Errors__FIELD_NAME__joint_motion_generator_velocity_discontinuity[] = "joint_motion_generator_velocity_discontinuity";
static char franka_msgs__msg__Errors__FIELD_NAME__joint_motion_generator_acceleration_discontinuity[] = "joint_motion_generator_acceleration_discontinuity";
static char franka_msgs__msg__Errors__FIELD_NAME__cartesian_position_motion_generator_start_pose_invalid[] = "cartesian_position_motion_generator_start_pose_invalid";
static char franka_msgs__msg__Errors__FIELD_NAME__cartesian_motion_generator_elbow_limit_violation[] = "cartesian_motion_generator_elbow_limit_violation";
static char franka_msgs__msg__Errors__FIELD_NAME__cartesian_motion_generator_velocity_limits_violation[] = "cartesian_motion_generator_velocity_limits_violation";
static char franka_msgs__msg__Errors__FIELD_NAME__cartesian_motion_generator_velocity_discontinuity[] = "cartesian_motion_generator_velocity_discontinuity";
static char franka_msgs__msg__Errors__FIELD_NAME__cartesian_motion_generator_acceleration_discontinuity[] = "cartesian_motion_generator_acceleration_discontinuity";
static char franka_msgs__msg__Errors__FIELD_NAME__cartesian_motion_generator_elbow_sign_inconsistent[] = "cartesian_motion_generator_elbow_sign_inconsistent";
static char franka_msgs__msg__Errors__FIELD_NAME__cartesian_motion_generator_start_elbow_invalid[] = "cartesian_motion_generator_start_elbow_invalid";
static char franka_msgs__msg__Errors__FIELD_NAME__cartesian_motion_generator_joint_position_limits_violation[] = "cartesian_motion_generator_joint_position_limits_violation";
static char franka_msgs__msg__Errors__FIELD_NAME__cartesian_motion_generator_joint_velocity_limits_violation[] = "cartesian_motion_generator_joint_velocity_limits_violation";
static char franka_msgs__msg__Errors__FIELD_NAME__cartesian_motion_generator_joint_velocity_discontinuity[] = "cartesian_motion_generator_joint_velocity_discontinuity";
static char franka_msgs__msg__Errors__FIELD_NAME__cartesian_motion_generator_joint_acceleration_discontinuity[] = "cartesian_motion_generator_joint_acceleration_discontinuity";
static char franka_msgs__msg__Errors__FIELD_NAME__cartesian_position_motion_generator_invalid_frame[] = "cartesian_position_motion_generator_invalid_frame";
static char franka_msgs__msg__Errors__FIELD_NAME__force_controller_desired_force_tolerance_violation[] = "force_controller_desired_force_tolerance_violation";
static char franka_msgs__msg__Errors__FIELD_NAME__controller_torque_discontinuity[] = "controller_torque_discontinuity";
static char franka_msgs__msg__Errors__FIELD_NAME__start_elbow_sign_inconsistent[] = "start_elbow_sign_inconsistent";
static char franka_msgs__msg__Errors__FIELD_NAME__communication_constraints_violation[] = "communication_constraints_violation";
static char franka_msgs__msg__Errors__FIELD_NAME__power_limit_violation[] = "power_limit_violation";
static char franka_msgs__msg__Errors__FIELD_NAME__joint_p2p_insufficient_torque_for_planning[] = "joint_p2p_insufficient_torque_for_planning";
static char franka_msgs__msg__Errors__FIELD_NAME__tau_j_range_violation[] = "tau_j_range_violation";
static char franka_msgs__msg__Errors__FIELD_NAME__instability_detected[] = "instability_detected";
static char franka_msgs__msg__Errors__FIELD_NAME__joint_move_in_wrong_direction[] = "joint_move_in_wrong_direction";
static char franka_msgs__msg__Errors__FIELD_NAME__cartesian_spline_motion_generator_violation[] = "cartesian_spline_motion_generator_violation";
static char franka_msgs__msg__Errors__FIELD_NAME__joint_via_motion_generator_planning_joint_limit_violation[] = "joint_via_motion_generator_planning_joint_limit_violation";
static char franka_msgs__msg__Errors__FIELD_NAME__base_acceleration_initialization_timeout[] = "base_acceleration_initialization_timeout";
static char franka_msgs__msg__Errors__FIELD_NAME__base_acceleration_invalid_reading[] = "base_acceleration_invalid_reading";

static rosidl_runtime_c__type_description__Field franka_msgs__msg__Errors__FIELDS[] = {
  {
    {franka_msgs__msg__Errors__FIELD_NAME__joint_position_limits_violation, 31, 31},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__cartesian_position_limits_violation, 35, 35},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__self_collision_avoidance_violation, 34, 34},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__joint_velocity_violation, 24, 24},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__cartesian_velocity_violation, 28, 28},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__force_control_safety_violation, 30, 30},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__joint_reflex, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__cartesian_reflex, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__max_goal_pose_deviation_violation, 33, 33},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__max_path_pose_deviation_violation, 33, 33},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__cartesian_velocity_profile_safety_violation, 43, 43},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__joint_position_motion_generator_start_pose_invalid, 50, 50},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__joint_motion_generator_position_limits_violation, 48, 48},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__joint_motion_generator_velocity_limits_violation, 48, 48},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__joint_motion_generator_velocity_discontinuity, 45, 45},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__joint_motion_generator_acceleration_discontinuity, 49, 49},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__cartesian_position_motion_generator_start_pose_invalid, 54, 54},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__cartesian_motion_generator_elbow_limit_violation, 48, 48},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__cartesian_motion_generator_velocity_limits_violation, 52, 52},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__cartesian_motion_generator_velocity_discontinuity, 49, 49},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__cartesian_motion_generator_acceleration_discontinuity, 53, 53},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__cartesian_motion_generator_elbow_sign_inconsistent, 50, 50},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__cartesian_motion_generator_start_elbow_invalid, 46, 46},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__cartesian_motion_generator_joint_position_limits_violation, 58, 58},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__cartesian_motion_generator_joint_velocity_limits_violation, 58, 58},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__cartesian_motion_generator_joint_velocity_discontinuity, 55, 55},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__cartesian_motion_generator_joint_acceleration_discontinuity, 59, 59},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__cartesian_position_motion_generator_invalid_frame, 49, 49},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__force_controller_desired_force_tolerance_violation, 50, 50},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__controller_torque_discontinuity, 31, 31},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__start_elbow_sign_inconsistent, 29, 29},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__communication_constraints_violation, 35, 35},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__power_limit_violation, 21, 21},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__joint_p2p_insufficient_torque_for_planning, 42, 42},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__tau_j_range_violation, 21, 21},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__instability_detected, 20, 20},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__joint_move_in_wrong_direction, 29, 29},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__cartesian_spline_motion_generator_violation, 43, 43},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__joint_via_motion_generator_planning_joint_limit_violation, 57, 57},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__base_acceleration_initialization_timeout, 40, 40},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__FIELD_NAME__base_acceleration_invalid_reading, 33, 33},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
franka_msgs__msg__Errors__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {franka_msgs__msg__Errors__TYPE_NAME, 22, 22},
      {franka_msgs__msg__Errors__FIELDS, 41, 41},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "bool joint_position_limits_violation\n"
  "bool cartesian_position_limits_violation\n"
  "bool self_collision_avoidance_violation\n"
  "bool joint_velocity_violation\n"
  "bool cartesian_velocity_violation\n"
  "bool force_control_safety_violation\n"
  "bool joint_reflex\n"
  "bool cartesian_reflex\n"
  "bool max_goal_pose_deviation_violation\n"
  "bool max_path_pose_deviation_violation\n"
  "bool cartesian_velocity_profile_safety_violation\n"
  "bool joint_position_motion_generator_start_pose_invalid\n"
  "bool joint_motion_generator_position_limits_violation\n"
  "bool joint_motion_generator_velocity_limits_violation\n"
  "bool joint_motion_generator_velocity_discontinuity\n"
  "bool joint_motion_generator_acceleration_discontinuity\n"
  "bool cartesian_position_motion_generator_start_pose_invalid\n"
  "bool cartesian_motion_generator_elbow_limit_violation\n"
  "bool cartesian_motion_generator_velocity_limits_violation\n"
  "bool cartesian_motion_generator_velocity_discontinuity\n"
  "bool cartesian_motion_generator_acceleration_discontinuity\n"
  "bool cartesian_motion_generator_elbow_sign_inconsistent\n"
  "bool cartesian_motion_generator_start_elbow_invalid\n"
  "bool cartesian_motion_generator_joint_position_limits_violation\n"
  "bool cartesian_motion_generator_joint_velocity_limits_violation\n"
  "bool cartesian_motion_generator_joint_velocity_discontinuity\n"
  "bool cartesian_motion_generator_joint_acceleration_discontinuity\n"
  "bool cartesian_position_motion_generator_invalid_frame\n"
  "bool force_controller_desired_force_tolerance_violation\n"
  "bool controller_torque_discontinuity\n"
  "bool start_elbow_sign_inconsistent\n"
  "bool communication_constraints_violation\n"
  "bool power_limit_violation\n"
  "bool joint_p2p_insufficient_torque_for_planning\n"
  "bool tau_j_range_violation\n"
  "bool instability_detected\n"
  "bool joint_move_in_wrong_direction\n"
  "bool cartesian_spline_motion_generator_violation\n"
  "bool joint_via_motion_generator_planning_joint_limit_violation\n"
  "bool base_acceleration_initialization_timeout\n"
  "bool base_acceleration_invalid_reading";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
franka_msgs__msg__Errors__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {franka_msgs__msg__Errors__TYPE_NAME, 22, 22},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 1887, 1887},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
franka_msgs__msg__Errors__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *franka_msgs__msg__Errors__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
