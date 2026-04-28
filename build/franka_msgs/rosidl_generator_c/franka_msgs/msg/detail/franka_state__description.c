// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from franka_msgs:msg/FrankaState.idl
// generated code does not contain a copyright notice

#include "franka_msgs/msg/detail/franka_state__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
const rosidl_type_hash_t *
franka_msgs__msg__FrankaState__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x59, 0xaa, 0x1b, 0xb0, 0x64, 0xa7, 0x6d, 0x6a,
      0x23, 0x05, 0xe4, 0x83, 0x8b, 0x8a, 0x9d, 0xaa,
      0x81, 0xb8, 0x91, 0x9b, 0x9c, 0xb4, 0x5d, 0x23,
      0x61, 0x54, 0x46, 0xcc, 0x35, 0x04, 0x21, 0x6d,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "std_msgs/msg/detail/header__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "franka_msgs/msg/detail/errors__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t franka_msgs__msg__Errors__EXPECTED_HASH = {1, {
    0xe9, 0x8b, 0xbe, 0x02, 0x75, 0x43, 0x2f, 0x4d,
    0x9b, 0x5b, 0x74, 0xc1, 0x1d, 0x4c, 0xda, 0x27,
    0x7d, 0x7d, 0x2b, 0xcf, 0x85, 0x93, 0xd8, 0x99,
    0x60, 0x70, 0x94, 0x35, 0x74, 0x02, 0x59, 0x76,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
#endif

static char franka_msgs__msg__FrankaState__TYPE_NAME[] = "franka_msgs/msg/FrankaState";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char franka_msgs__msg__Errors__TYPE_NAME[] = "franka_msgs/msg/Errors";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";

// Define type names, field names, and default values
static char franka_msgs__msg__FrankaState__FIELD_NAME__header[] = "header";
static char franka_msgs__msg__FrankaState__FIELD_NAME__cartesian_collision[] = "cartesian_collision";
static char franka_msgs__msg__FrankaState__FIELD_NAME__cartesian_contact[] = "cartesian_contact";
static char franka_msgs__msg__FrankaState__FIELD_NAME__q[] = "q";
static char franka_msgs__msg__FrankaState__FIELD_NAME__q_d[] = "q_d";
static char franka_msgs__msg__FrankaState__FIELD_NAME__dq[] = "dq";
static char franka_msgs__msg__FrankaState__FIELD_NAME__dq_d[] = "dq_d";
static char franka_msgs__msg__FrankaState__FIELD_NAME__ddq_d[] = "ddq_d";
static char franka_msgs__msg__FrankaState__FIELD_NAME__theta[] = "theta";
static char franka_msgs__msg__FrankaState__FIELD_NAME__dtheta[] = "dtheta";
static char franka_msgs__msg__FrankaState__FIELD_NAME__tau_j[] = "tau_j";
static char franka_msgs__msg__FrankaState__FIELD_NAME__dtau_j[] = "dtau_j";
static char franka_msgs__msg__FrankaState__FIELD_NAME__tau_j_d[] = "tau_j_d";
static char franka_msgs__msg__FrankaState__FIELD_NAME__k_f_ext_hat_k[] = "k_f_ext_hat_k";
static char franka_msgs__msg__FrankaState__FIELD_NAME__elbow[] = "elbow";
static char franka_msgs__msg__FrankaState__FIELD_NAME__elbow_d[] = "elbow_d";
static char franka_msgs__msg__FrankaState__FIELD_NAME__elbow_c[] = "elbow_c";
static char franka_msgs__msg__FrankaState__FIELD_NAME__delbow_c[] = "delbow_c";
static char franka_msgs__msg__FrankaState__FIELD_NAME__ddelbow_c[] = "ddelbow_c";
static char franka_msgs__msg__FrankaState__FIELD_NAME__joint_collision[] = "joint_collision";
static char franka_msgs__msg__FrankaState__FIELD_NAME__joint_contact[] = "joint_contact";
static char franka_msgs__msg__FrankaState__FIELD_NAME__o_f_ext_hat_k[] = "o_f_ext_hat_k";
static char franka_msgs__msg__FrankaState__FIELD_NAME__o_dp_ee_d[] = "o_dp_ee_d";
static char franka_msgs__msg__FrankaState__FIELD_NAME__o_ddp_o[] = "o_ddp_o";
static char franka_msgs__msg__FrankaState__FIELD_NAME__o_dp_ee_c[] = "o_dp_ee_c";
static char franka_msgs__msg__FrankaState__FIELD_NAME__o_ddp_ee_c[] = "o_ddp_ee_c";
static char franka_msgs__msg__FrankaState__FIELD_NAME__tau_ext_hat_filtered[] = "tau_ext_hat_filtered";
static char franka_msgs__msg__FrankaState__FIELD_NAME__m_ee[] = "m_ee";
static char franka_msgs__msg__FrankaState__FIELD_NAME__f_x_cee[] = "f_x_cee";
static char franka_msgs__msg__FrankaState__FIELD_NAME__i_ee[] = "i_ee";
static char franka_msgs__msg__FrankaState__FIELD_NAME__m_load[] = "m_load";
static char franka_msgs__msg__FrankaState__FIELD_NAME__f_x_cload[] = "f_x_cload";
static char franka_msgs__msg__FrankaState__FIELD_NAME__i_load[] = "i_load";
static char franka_msgs__msg__FrankaState__FIELD_NAME__m_total[] = "m_total";
static char franka_msgs__msg__FrankaState__FIELD_NAME__f_x_ctotal[] = "f_x_ctotal";
static char franka_msgs__msg__FrankaState__FIELD_NAME__i_total[] = "i_total";
static char franka_msgs__msg__FrankaState__FIELD_NAME__o_t_ee[] = "o_t_ee";
static char franka_msgs__msg__FrankaState__FIELD_NAME__o_t_ee_d[] = "o_t_ee_d";
static char franka_msgs__msg__FrankaState__FIELD_NAME__o_t_ee_c[] = "o_t_ee_c";
static char franka_msgs__msg__FrankaState__FIELD_NAME__f_t_ee[] = "f_t_ee";
static char franka_msgs__msg__FrankaState__FIELD_NAME__f_t_ne[] = "f_t_ne";
static char franka_msgs__msg__FrankaState__FIELD_NAME__ne_t_ee[] = "ne_t_ee";
static char franka_msgs__msg__FrankaState__FIELD_NAME__ee_t_k[] = "ee_t_k";
static char franka_msgs__msg__FrankaState__FIELD_NAME__time[] = "time";
static char franka_msgs__msg__FrankaState__FIELD_NAME__control_command_success_rate[] = "control_command_success_rate";
static char franka_msgs__msg__FrankaState__FIELD_NAME__robot_mode[] = "robot_mode";
static char franka_msgs__msg__FrankaState__FIELD_NAME__current_errors[] = "current_errors";
static char franka_msgs__msg__FrankaState__FIELD_NAME__last_motion_errors[] = "last_motion_errors";

static rosidl_runtime_c__type_description__Field franka_msgs__msg__FrankaState__FIELDS[] = {
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__header, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__cartesian_collision, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      6,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__cartesian_contact, 17, 17},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      6,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__q, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      7,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__q_d, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      7,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__dq, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      7,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__dq_d, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      7,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__ddq_d, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      7,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__theta, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      7,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__dtheta, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      7,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__tau_j, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      7,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__dtau_j, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      7,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__tau_j_d, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      7,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__k_f_ext_hat_k, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      6,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__elbow, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      2,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__elbow_d, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      2,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__elbow_c, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      2,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__delbow_c, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      2,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__ddelbow_c, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      2,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__joint_collision, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      7,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__joint_contact, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      7,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__o_f_ext_hat_k, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      6,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__o_dp_ee_d, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      6,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__o_ddp_o, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      3,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__o_dp_ee_c, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      6,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__o_ddp_ee_c, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      6,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__tau_ext_hat_filtered, 20, 20},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      7,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__m_ee, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__f_x_cee, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      3,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__i_ee, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      9,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__m_load, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__f_x_cload, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      3,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__i_load, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      9,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__m_total, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__f_x_ctotal, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      3,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__i_total, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      9,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__o_t_ee, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      16,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__o_t_ee_d, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      16,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__o_t_ee_c, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      16,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__f_t_ee, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      16,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__f_t_ne, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      16,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__ne_t_ee, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      16,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__ee_t_k, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      16,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__time, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__control_command_success_rate, 28, 28},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__robot_mode, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__current_errors, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {franka_msgs__msg__Errors__TYPE_NAME, 22, 22},
    },
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__FrankaState__FIELD_NAME__last_motion_errors, 18, 18},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {franka_msgs__msg__Errors__TYPE_NAME, 22, 22},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription franka_msgs__msg__FrankaState__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {franka_msgs__msg__Errors__TYPE_NAME, 22, 22},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
franka_msgs__msg__FrankaState__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {franka_msgs__msg__FrankaState__TYPE_NAME, 27, 27},
      {franka_msgs__msg__FrankaState__FIELDS, 48, 48},
    },
    {franka_msgs__msg__FrankaState__REFERENCED_TYPE_DESCRIPTIONS, 3, 3},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&franka_msgs__msg__Errors__EXPECTED_HASH, franka_msgs__msg__Errors__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = franka_msgs__msg__Errors__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "std_msgs/Header header\n"
  "float64[6] cartesian_collision\n"
  "float64[6] cartesian_contact\n"
  "float64[7] q\n"
  "float64[7] q_d\n"
  "float64[7] dq\n"
  "float64[7] dq_d\n"
  "float64[7] ddq_d\n"
  "float64[7] theta\n"
  "float64[7] dtheta\n"
  "float64[7] tau_j\n"
  "float64[7] dtau_j\n"
  "float64[7] tau_j_d\n"
  "float64[6] k_f_ext_hat_k\n"
  "float64[2] elbow\n"
  "float64[2] elbow_d\n"
  "float64[2] elbow_c\n"
  "float64[2] delbow_c\n"
  "float64[2] ddelbow_c\n"
  "float64[7] joint_collision\n"
  "float64[7] joint_contact\n"
  "float64[6] o_f_ext_hat_k\n"
  "float64[6] o_dp_ee_d\n"
  "float64[3] o_ddp_o\n"
  "float64[6] o_dp_ee_c\n"
  "float64[6] o_ddp_ee_c\n"
  "float64[7] tau_ext_hat_filtered\n"
  "float64 m_ee\n"
  "float64[3] f_x_cee\n"
  "float64[9] i_ee\n"
  "float64 m_load\n"
  "float64[3] f_x_cload\n"
  "float64[9] i_load\n"
  "float64 m_total\n"
  "float64[3] f_x_ctotal\n"
  "float64[9] i_total\n"
  "float64[16] o_t_ee\n"
  "float64[16] o_t_ee_d\n"
  "float64[16] o_t_ee_c\n"
  "float64[16] f_t_ee\n"
  "float64[16] f_t_ne\n"
  "float64[16] ne_t_ee\n"
  "float64[16] ee_t_k\n"
  "float64 time\n"
  "float64 control_command_success_rate\n"
  "uint8 ROBOT_MODE_OTHER=0\n"
  "uint8 ROBOT_MODE_IDLE=1\n"
  "uint8 ROBOT_MODE_MOVE=2\n"
  "uint8 ROBOT_MODE_GUIDING=3\n"
  "uint8 ROBOT_MODE_REFLEX=4\n"
  "uint8 ROBOT_MODE_USER_STOPPED=5\n"
  "uint8 ROBOT_MODE_AUTOMATIC_ERROR_RECOVERY=6\n"
  "uint8 robot_mode\n"
  "franka_msgs/Errors current_errors\n"
  "franka_msgs/Errors last_motion_errors";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
franka_msgs__msg__FrankaState__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {franka_msgs__msg__FrankaState__TYPE_NAME, 27, 27},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 1198, 1198},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
franka_msgs__msg__FrankaState__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[4];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 4, 4};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *franka_msgs__msg__FrankaState__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *franka_msgs__msg__Errors__get_individual_type_description_source(NULL);
    sources[3] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
