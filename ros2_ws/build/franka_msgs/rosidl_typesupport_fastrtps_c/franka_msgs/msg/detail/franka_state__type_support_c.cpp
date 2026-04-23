// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from franka_msgs:msg/FrankaState.idl
// generated code does not contain a copyright notice
#include "franka_msgs/msg/detail/franka_state__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "franka_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "franka_msgs/msg/detail/franka_state__struct.h"
#include "franka_msgs/msg/detail/franka_state__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "franka_msgs/msg/detail/errors__functions.h"  // current_errors, last_motion_errors
#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions

bool cdr_serialize_franka_msgs__msg__Errors(
  const franka_msgs__msg__Errors * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_franka_msgs__msg__Errors(
  eprosima::fastcdr::Cdr & cdr,
  franka_msgs__msg__Errors * ros_message);

size_t get_serialized_size_franka_msgs__msg__Errors(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_franka_msgs__msg__Errors(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_franka_msgs__msg__Errors(
  const franka_msgs__msg__Errors * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_franka_msgs__msg__Errors(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_franka_msgs__msg__Errors(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, franka_msgs, msg, Errors)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
bool cdr_serialize_std_msgs__msg__Header(
  const std_msgs__msg__Header * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
bool cdr_deserialize_std_msgs__msg__Header(
  eprosima::fastcdr::Cdr & cdr,
  std_msgs__msg__Header * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
bool cdr_serialize_key_std_msgs__msg__Header(
  const std_msgs__msg__Header * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t get_serialized_size_key_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t max_serialized_size_key_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _FrankaState__ros_msg_type = franka_msgs__msg__FrankaState;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_franka_msgs
bool cdr_serialize_franka_msgs__msg__FrankaState(
  const franka_msgs__msg__FrankaState * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    cdr_serialize_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: cartesian_collision
  {
    size_t size = 6;
    auto array_ptr = ros_message->cartesian_collision;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: cartesian_contact
  {
    size_t size = 6;
    auto array_ptr = ros_message->cartesian_contact;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: q
  {
    size_t size = 7;
    auto array_ptr = ros_message->q;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: q_d
  {
    size_t size = 7;
    auto array_ptr = ros_message->q_d;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: dq
  {
    size_t size = 7;
    auto array_ptr = ros_message->dq;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: dq_d
  {
    size_t size = 7;
    auto array_ptr = ros_message->dq_d;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: ddq_d
  {
    size_t size = 7;
    auto array_ptr = ros_message->ddq_d;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: theta
  {
    size_t size = 7;
    auto array_ptr = ros_message->theta;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: dtheta
  {
    size_t size = 7;
    auto array_ptr = ros_message->dtheta;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: tau_j
  {
    size_t size = 7;
    auto array_ptr = ros_message->tau_j;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: dtau_j
  {
    size_t size = 7;
    auto array_ptr = ros_message->dtau_j;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: tau_j_d
  {
    size_t size = 7;
    auto array_ptr = ros_message->tau_j_d;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: k_f_ext_hat_k
  {
    size_t size = 6;
    auto array_ptr = ros_message->k_f_ext_hat_k;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: elbow
  {
    size_t size = 2;
    auto array_ptr = ros_message->elbow;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: elbow_d
  {
    size_t size = 2;
    auto array_ptr = ros_message->elbow_d;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: elbow_c
  {
    size_t size = 2;
    auto array_ptr = ros_message->elbow_c;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: delbow_c
  {
    size_t size = 2;
    auto array_ptr = ros_message->delbow_c;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: ddelbow_c
  {
    size_t size = 2;
    auto array_ptr = ros_message->ddelbow_c;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: joint_collision
  {
    size_t size = 7;
    auto array_ptr = ros_message->joint_collision;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: joint_contact
  {
    size_t size = 7;
    auto array_ptr = ros_message->joint_contact;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: o_f_ext_hat_k
  {
    size_t size = 6;
    auto array_ptr = ros_message->o_f_ext_hat_k;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: o_dp_ee_d
  {
    size_t size = 6;
    auto array_ptr = ros_message->o_dp_ee_d;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: o_ddp_o
  {
    size_t size = 3;
    auto array_ptr = ros_message->o_ddp_o;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: o_dp_ee_c
  {
    size_t size = 6;
    auto array_ptr = ros_message->o_dp_ee_c;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: o_ddp_ee_c
  {
    size_t size = 6;
    auto array_ptr = ros_message->o_ddp_ee_c;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: tau_ext_hat_filtered
  {
    size_t size = 7;
    auto array_ptr = ros_message->tau_ext_hat_filtered;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: m_ee
  {
    cdr << ros_message->m_ee;
  }

  // Field name: f_x_cee
  {
    size_t size = 3;
    auto array_ptr = ros_message->f_x_cee;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: i_ee
  {
    size_t size = 9;
    auto array_ptr = ros_message->i_ee;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: m_load
  {
    cdr << ros_message->m_load;
  }

  // Field name: f_x_cload
  {
    size_t size = 3;
    auto array_ptr = ros_message->f_x_cload;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: i_load
  {
    size_t size = 9;
    auto array_ptr = ros_message->i_load;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: m_total
  {
    cdr << ros_message->m_total;
  }

  // Field name: f_x_ctotal
  {
    size_t size = 3;
    auto array_ptr = ros_message->f_x_ctotal;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: i_total
  {
    size_t size = 9;
    auto array_ptr = ros_message->i_total;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: o_t_ee
  {
    size_t size = 16;
    auto array_ptr = ros_message->o_t_ee;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: o_t_ee_d
  {
    size_t size = 16;
    auto array_ptr = ros_message->o_t_ee_d;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: o_t_ee_c
  {
    size_t size = 16;
    auto array_ptr = ros_message->o_t_ee_c;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: f_t_ee
  {
    size_t size = 16;
    auto array_ptr = ros_message->f_t_ee;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: f_t_ne
  {
    size_t size = 16;
    auto array_ptr = ros_message->f_t_ne;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: ne_t_ee
  {
    size_t size = 16;
    auto array_ptr = ros_message->ne_t_ee;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: ee_t_k
  {
    size_t size = 16;
    auto array_ptr = ros_message->ee_t_k;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: time
  {
    cdr << ros_message->time;
  }

  // Field name: control_command_success_rate
  {
    cdr << ros_message->control_command_success_rate;
  }

  // Field name: robot_mode
  {
    cdr << ros_message->robot_mode;
  }

  // Field name: current_errors
  {
    cdr_serialize_franka_msgs__msg__Errors(
      &ros_message->current_errors, cdr);
  }

  // Field name: last_motion_errors
  {
    cdr_serialize_franka_msgs__msg__Errors(
      &ros_message->last_motion_errors, cdr);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_franka_msgs
bool cdr_deserialize_franka_msgs__msg__FrankaState(
  eprosima::fastcdr::Cdr & cdr,
  franka_msgs__msg__FrankaState * ros_message)
{
  // Field name: header
  {
    cdr_deserialize_std_msgs__msg__Header(cdr, &ros_message->header);
  }

  // Field name: cartesian_collision
  {
    size_t size = 6;
    auto array_ptr = ros_message->cartesian_collision;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: cartesian_contact
  {
    size_t size = 6;
    auto array_ptr = ros_message->cartesian_contact;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: q
  {
    size_t size = 7;
    auto array_ptr = ros_message->q;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: q_d
  {
    size_t size = 7;
    auto array_ptr = ros_message->q_d;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: dq
  {
    size_t size = 7;
    auto array_ptr = ros_message->dq;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: dq_d
  {
    size_t size = 7;
    auto array_ptr = ros_message->dq_d;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: ddq_d
  {
    size_t size = 7;
    auto array_ptr = ros_message->ddq_d;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: theta
  {
    size_t size = 7;
    auto array_ptr = ros_message->theta;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: dtheta
  {
    size_t size = 7;
    auto array_ptr = ros_message->dtheta;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: tau_j
  {
    size_t size = 7;
    auto array_ptr = ros_message->tau_j;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: dtau_j
  {
    size_t size = 7;
    auto array_ptr = ros_message->dtau_j;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: tau_j_d
  {
    size_t size = 7;
    auto array_ptr = ros_message->tau_j_d;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: k_f_ext_hat_k
  {
    size_t size = 6;
    auto array_ptr = ros_message->k_f_ext_hat_k;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: elbow
  {
    size_t size = 2;
    auto array_ptr = ros_message->elbow;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: elbow_d
  {
    size_t size = 2;
    auto array_ptr = ros_message->elbow_d;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: elbow_c
  {
    size_t size = 2;
    auto array_ptr = ros_message->elbow_c;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: delbow_c
  {
    size_t size = 2;
    auto array_ptr = ros_message->delbow_c;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: ddelbow_c
  {
    size_t size = 2;
    auto array_ptr = ros_message->ddelbow_c;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: joint_collision
  {
    size_t size = 7;
    auto array_ptr = ros_message->joint_collision;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: joint_contact
  {
    size_t size = 7;
    auto array_ptr = ros_message->joint_contact;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: o_f_ext_hat_k
  {
    size_t size = 6;
    auto array_ptr = ros_message->o_f_ext_hat_k;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: o_dp_ee_d
  {
    size_t size = 6;
    auto array_ptr = ros_message->o_dp_ee_d;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: o_ddp_o
  {
    size_t size = 3;
    auto array_ptr = ros_message->o_ddp_o;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: o_dp_ee_c
  {
    size_t size = 6;
    auto array_ptr = ros_message->o_dp_ee_c;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: o_ddp_ee_c
  {
    size_t size = 6;
    auto array_ptr = ros_message->o_ddp_ee_c;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: tau_ext_hat_filtered
  {
    size_t size = 7;
    auto array_ptr = ros_message->tau_ext_hat_filtered;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: m_ee
  {
    cdr >> ros_message->m_ee;
  }

  // Field name: f_x_cee
  {
    size_t size = 3;
    auto array_ptr = ros_message->f_x_cee;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: i_ee
  {
    size_t size = 9;
    auto array_ptr = ros_message->i_ee;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: m_load
  {
    cdr >> ros_message->m_load;
  }

  // Field name: f_x_cload
  {
    size_t size = 3;
    auto array_ptr = ros_message->f_x_cload;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: i_load
  {
    size_t size = 9;
    auto array_ptr = ros_message->i_load;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: m_total
  {
    cdr >> ros_message->m_total;
  }

  // Field name: f_x_ctotal
  {
    size_t size = 3;
    auto array_ptr = ros_message->f_x_ctotal;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: i_total
  {
    size_t size = 9;
    auto array_ptr = ros_message->i_total;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: o_t_ee
  {
    size_t size = 16;
    auto array_ptr = ros_message->o_t_ee;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: o_t_ee_d
  {
    size_t size = 16;
    auto array_ptr = ros_message->o_t_ee_d;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: o_t_ee_c
  {
    size_t size = 16;
    auto array_ptr = ros_message->o_t_ee_c;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: f_t_ee
  {
    size_t size = 16;
    auto array_ptr = ros_message->f_t_ee;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: f_t_ne
  {
    size_t size = 16;
    auto array_ptr = ros_message->f_t_ne;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: ne_t_ee
  {
    size_t size = 16;
    auto array_ptr = ros_message->ne_t_ee;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: ee_t_k
  {
    size_t size = 16;
    auto array_ptr = ros_message->ee_t_k;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: time
  {
    cdr >> ros_message->time;
  }

  // Field name: control_command_success_rate
  {
    cdr >> ros_message->control_command_success_rate;
  }

  // Field name: robot_mode
  {
    cdr >> ros_message->robot_mode;
  }

  // Field name: current_errors
  {
    cdr_deserialize_franka_msgs__msg__Errors(cdr, &ros_message->current_errors);
  }

  // Field name: last_motion_errors
  {
    cdr_deserialize_franka_msgs__msg__Errors(cdr, &ros_message->last_motion_errors);
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_franka_msgs
size_t get_serialized_size_franka_msgs__msg__FrankaState(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _FrankaState__ros_msg_type * ros_message = static_cast<const _FrankaState__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: cartesian_collision
  {
    size_t array_size = 6;
    auto array_ptr = ros_message->cartesian_collision;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: cartesian_contact
  {
    size_t array_size = 6;
    auto array_ptr = ros_message->cartesian_contact;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: q
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->q;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: q_d
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->q_d;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: dq
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->dq;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: dq_d
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->dq_d;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: ddq_d
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->ddq_d;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: theta
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->theta;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: dtheta
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->dtheta;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: tau_j
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->tau_j;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: dtau_j
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->dtau_j;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: tau_j_d
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->tau_j_d;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: k_f_ext_hat_k
  {
    size_t array_size = 6;
    auto array_ptr = ros_message->k_f_ext_hat_k;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: elbow
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->elbow;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: elbow_d
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->elbow_d;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: elbow_c
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->elbow_c;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: delbow_c
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->delbow_c;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: ddelbow_c
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->ddelbow_c;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: joint_collision
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->joint_collision;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: joint_contact
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->joint_contact;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: o_f_ext_hat_k
  {
    size_t array_size = 6;
    auto array_ptr = ros_message->o_f_ext_hat_k;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: o_dp_ee_d
  {
    size_t array_size = 6;
    auto array_ptr = ros_message->o_dp_ee_d;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: o_ddp_o
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->o_ddp_o;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: o_dp_ee_c
  {
    size_t array_size = 6;
    auto array_ptr = ros_message->o_dp_ee_c;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: o_ddp_ee_c
  {
    size_t array_size = 6;
    auto array_ptr = ros_message->o_ddp_ee_c;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: tau_ext_hat_filtered
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->tau_ext_hat_filtered;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: m_ee
  {
    size_t item_size = sizeof(ros_message->m_ee);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: f_x_cee
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->f_x_cee;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: i_ee
  {
    size_t array_size = 9;
    auto array_ptr = ros_message->i_ee;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: m_load
  {
    size_t item_size = sizeof(ros_message->m_load);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: f_x_cload
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->f_x_cload;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: i_load
  {
    size_t array_size = 9;
    auto array_ptr = ros_message->i_load;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: m_total
  {
    size_t item_size = sizeof(ros_message->m_total);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: f_x_ctotal
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->f_x_ctotal;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: i_total
  {
    size_t array_size = 9;
    auto array_ptr = ros_message->i_total;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: o_t_ee
  {
    size_t array_size = 16;
    auto array_ptr = ros_message->o_t_ee;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: o_t_ee_d
  {
    size_t array_size = 16;
    auto array_ptr = ros_message->o_t_ee_d;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: o_t_ee_c
  {
    size_t array_size = 16;
    auto array_ptr = ros_message->o_t_ee_c;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: f_t_ee
  {
    size_t array_size = 16;
    auto array_ptr = ros_message->f_t_ee;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: f_t_ne
  {
    size_t array_size = 16;
    auto array_ptr = ros_message->f_t_ne;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: ne_t_ee
  {
    size_t array_size = 16;
    auto array_ptr = ros_message->ne_t_ee;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: ee_t_k
  {
    size_t array_size = 16;
    auto array_ptr = ros_message->ee_t_k;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: time
  {
    size_t item_size = sizeof(ros_message->time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: control_command_success_rate
  {
    size_t item_size = sizeof(ros_message->control_command_success_rate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: robot_mode
  {
    size_t item_size = sizeof(ros_message->robot_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: current_errors
  current_alignment += get_serialized_size_franka_msgs__msg__Errors(
    &(ros_message->current_errors), current_alignment);

  // Field name: last_motion_errors
  current_alignment += get_serialized_size_franka_msgs__msg__Errors(
    &(ros_message->last_motion_errors), current_alignment);

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_franka_msgs
size_t max_serialized_size_franka_msgs__msg__FrankaState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: header
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: cartesian_collision
  {
    size_t array_size = 6;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: cartesian_contact
  {
    size_t array_size = 6;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: q
  {
    size_t array_size = 7;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: q_d
  {
    size_t array_size = 7;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: dq
  {
    size_t array_size = 7;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: dq_d
  {
    size_t array_size = 7;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: ddq_d
  {
    size_t array_size = 7;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: theta
  {
    size_t array_size = 7;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: dtheta
  {
    size_t array_size = 7;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: tau_j
  {
    size_t array_size = 7;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: dtau_j
  {
    size_t array_size = 7;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: tau_j_d
  {
    size_t array_size = 7;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: k_f_ext_hat_k
  {
    size_t array_size = 6;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: elbow
  {
    size_t array_size = 2;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: elbow_d
  {
    size_t array_size = 2;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: elbow_c
  {
    size_t array_size = 2;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: delbow_c
  {
    size_t array_size = 2;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: ddelbow_c
  {
    size_t array_size = 2;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: joint_collision
  {
    size_t array_size = 7;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: joint_contact
  {
    size_t array_size = 7;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: o_f_ext_hat_k
  {
    size_t array_size = 6;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: o_dp_ee_d
  {
    size_t array_size = 6;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: o_ddp_o
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: o_dp_ee_c
  {
    size_t array_size = 6;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: o_ddp_ee_c
  {
    size_t array_size = 6;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: tau_ext_hat_filtered
  {
    size_t array_size = 7;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: m_ee
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: f_x_cee
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: i_ee
  {
    size_t array_size = 9;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: m_load
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: f_x_cload
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: i_load
  {
    size_t array_size = 9;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: m_total
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: f_x_ctotal
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: i_total
  {
    size_t array_size = 9;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: o_t_ee
  {
    size_t array_size = 16;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: o_t_ee_d
  {
    size_t array_size = 16;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: o_t_ee_c
  {
    size_t array_size = 16;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: f_t_ee
  {
    size_t array_size = 16;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: f_t_ne
  {
    size_t array_size = 16;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: ne_t_ee
  {
    size_t array_size = 16;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: ee_t_k
  {
    size_t array_size = 16;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: time
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: control_command_success_rate
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: robot_mode
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: current_errors
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_franka_msgs__msg__Errors(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: last_motion_errors
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_franka_msgs__msg__Errors(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = franka_msgs__msg__FrankaState;
    is_plain =
      (
      offsetof(DataType, last_motion_errors) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_franka_msgs
bool cdr_serialize_key_franka_msgs__msg__FrankaState(
  const franka_msgs__msg__FrankaState * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: header
  {
    cdr_serialize_key_std_msgs__msg__Header(
      &ros_message->header, cdr);
  }

  // Field name: cartesian_collision
  {
    size_t size = 6;
    auto array_ptr = ros_message->cartesian_collision;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: cartesian_contact
  {
    size_t size = 6;
    auto array_ptr = ros_message->cartesian_contact;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: q
  {
    size_t size = 7;
    auto array_ptr = ros_message->q;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: q_d
  {
    size_t size = 7;
    auto array_ptr = ros_message->q_d;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: dq
  {
    size_t size = 7;
    auto array_ptr = ros_message->dq;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: dq_d
  {
    size_t size = 7;
    auto array_ptr = ros_message->dq_d;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: ddq_d
  {
    size_t size = 7;
    auto array_ptr = ros_message->ddq_d;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: theta
  {
    size_t size = 7;
    auto array_ptr = ros_message->theta;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: dtheta
  {
    size_t size = 7;
    auto array_ptr = ros_message->dtheta;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: tau_j
  {
    size_t size = 7;
    auto array_ptr = ros_message->tau_j;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: dtau_j
  {
    size_t size = 7;
    auto array_ptr = ros_message->dtau_j;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: tau_j_d
  {
    size_t size = 7;
    auto array_ptr = ros_message->tau_j_d;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: k_f_ext_hat_k
  {
    size_t size = 6;
    auto array_ptr = ros_message->k_f_ext_hat_k;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: elbow
  {
    size_t size = 2;
    auto array_ptr = ros_message->elbow;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: elbow_d
  {
    size_t size = 2;
    auto array_ptr = ros_message->elbow_d;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: elbow_c
  {
    size_t size = 2;
    auto array_ptr = ros_message->elbow_c;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: delbow_c
  {
    size_t size = 2;
    auto array_ptr = ros_message->delbow_c;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: ddelbow_c
  {
    size_t size = 2;
    auto array_ptr = ros_message->ddelbow_c;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: joint_collision
  {
    size_t size = 7;
    auto array_ptr = ros_message->joint_collision;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: joint_contact
  {
    size_t size = 7;
    auto array_ptr = ros_message->joint_contact;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: o_f_ext_hat_k
  {
    size_t size = 6;
    auto array_ptr = ros_message->o_f_ext_hat_k;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: o_dp_ee_d
  {
    size_t size = 6;
    auto array_ptr = ros_message->o_dp_ee_d;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: o_ddp_o
  {
    size_t size = 3;
    auto array_ptr = ros_message->o_ddp_o;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: o_dp_ee_c
  {
    size_t size = 6;
    auto array_ptr = ros_message->o_dp_ee_c;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: o_ddp_ee_c
  {
    size_t size = 6;
    auto array_ptr = ros_message->o_ddp_ee_c;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: tau_ext_hat_filtered
  {
    size_t size = 7;
    auto array_ptr = ros_message->tau_ext_hat_filtered;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: m_ee
  {
    cdr << ros_message->m_ee;
  }

  // Field name: f_x_cee
  {
    size_t size = 3;
    auto array_ptr = ros_message->f_x_cee;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: i_ee
  {
    size_t size = 9;
    auto array_ptr = ros_message->i_ee;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: m_load
  {
    cdr << ros_message->m_load;
  }

  // Field name: f_x_cload
  {
    size_t size = 3;
    auto array_ptr = ros_message->f_x_cload;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: i_load
  {
    size_t size = 9;
    auto array_ptr = ros_message->i_load;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: m_total
  {
    cdr << ros_message->m_total;
  }

  // Field name: f_x_ctotal
  {
    size_t size = 3;
    auto array_ptr = ros_message->f_x_ctotal;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: i_total
  {
    size_t size = 9;
    auto array_ptr = ros_message->i_total;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: o_t_ee
  {
    size_t size = 16;
    auto array_ptr = ros_message->o_t_ee;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: o_t_ee_d
  {
    size_t size = 16;
    auto array_ptr = ros_message->o_t_ee_d;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: o_t_ee_c
  {
    size_t size = 16;
    auto array_ptr = ros_message->o_t_ee_c;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: f_t_ee
  {
    size_t size = 16;
    auto array_ptr = ros_message->f_t_ee;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: f_t_ne
  {
    size_t size = 16;
    auto array_ptr = ros_message->f_t_ne;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: ne_t_ee
  {
    size_t size = 16;
    auto array_ptr = ros_message->ne_t_ee;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: ee_t_k
  {
    size_t size = 16;
    auto array_ptr = ros_message->ee_t_k;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: time
  {
    cdr << ros_message->time;
  }

  // Field name: control_command_success_rate
  {
    cdr << ros_message->control_command_success_rate;
  }

  // Field name: robot_mode
  {
    cdr << ros_message->robot_mode;
  }

  // Field name: current_errors
  {
    cdr_serialize_key_franka_msgs__msg__Errors(
      &ros_message->current_errors, cdr);
  }

  // Field name: last_motion_errors
  {
    cdr_serialize_key_franka_msgs__msg__Errors(
      &ros_message->last_motion_errors, cdr);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_franka_msgs
size_t get_serialized_size_key_franka_msgs__msg__FrankaState(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _FrankaState__ros_msg_type * ros_message = static_cast<const _FrankaState__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: header
  current_alignment += get_serialized_size_key_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);

  // Field name: cartesian_collision
  {
    size_t array_size = 6;
    auto array_ptr = ros_message->cartesian_collision;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: cartesian_contact
  {
    size_t array_size = 6;
    auto array_ptr = ros_message->cartesian_contact;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: q
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->q;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: q_d
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->q_d;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: dq
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->dq;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: dq_d
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->dq_d;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: ddq_d
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->ddq_d;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: theta
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->theta;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: dtheta
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->dtheta;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: tau_j
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->tau_j;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: dtau_j
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->dtau_j;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: tau_j_d
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->tau_j_d;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: k_f_ext_hat_k
  {
    size_t array_size = 6;
    auto array_ptr = ros_message->k_f_ext_hat_k;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: elbow
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->elbow;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: elbow_d
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->elbow_d;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: elbow_c
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->elbow_c;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: delbow_c
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->delbow_c;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: ddelbow_c
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->ddelbow_c;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: joint_collision
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->joint_collision;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: joint_contact
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->joint_contact;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: o_f_ext_hat_k
  {
    size_t array_size = 6;
    auto array_ptr = ros_message->o_f_ext_hat_k;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: o_dp_ee_d
  {
    size_t array_size = 6;
    auto array_ptr = ros_message->o_dp_ee_d;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: o_ddp_o
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->o_ddp_o;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: o_dp_ee_c
  {
    size_t array_size = 6;
    auto array_ptr = ros_message->o_dp_ee_c;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: o_ddp_ee_c
  {
    size_t array_size = 6;
    auto array_ptr = ros_message->o_ddp_ee_c;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: tau_ext_hat_filtered
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->tau_ext_hat_filtered;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: m_ee
  {
    size_t item_size = sizeof(ros_message->m_ee);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: f_x_cee
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->f_x_cee;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: i_ee
  {
    size_t array_size = 9;
    auto array_ptr = ros_message->i_ee;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: m_load
  {
    size_t item_size = sizeof(ros_message->m_load);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: f_x_cload
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->f_x_cload;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: i_load
  {
    size_t array_size = 9;
    auto array_ptr = ros_message->i_load;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: m_total
  {
    size_t item_size = sizeof(ros_message->m_total);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: f_x_ctotal
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->f_x_ctotal;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: i_total
  {
    size_t array_size = 9;
    auto array_ptr = ros_message->i_total;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: o_t_ee
  {
    size_t array_size = 16;
    auto array_ptr = ros_message->o_t_ee;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: o_t_ee_d
  {
    size_t array_size = 16;
    auto array_ptr = ros_message->o_t_ee_d;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: o_t_ee_c
  {
    size_t array_size = 16;
    auto array_ptr = ros_message->o_t_ee_c;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: f_t_ee
  {
    size_t array_size = 16;
    auto array_ptr = ros_message->f_t_ee;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: f_t_ne
  {
    size_t array_size = 16;
    auto array_ptr = ros_message->f_t_ne;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: ne_t_ee
  {
    size_t array_size = 16;
    auto array_ptr = ros_message->ne_t_ee;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: ee_t_k
  {
    size_t array_size = 16;
    auto array_ptr = ros_message->ee_t_k;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: time
  {
    size_t item_size = sizeof(ros_message->time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: control_command_success_rate
  {
    size_t item_size = sizeof(ros_message->control_command_success_rate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: robot_mode
  {
    size_t item_size = sizeof(ros_message->robot_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: current_errors
  current_alignment += get_serialized_size_key_franka_msgs__msg__Errors(
    &(ros_message->current_errors), current_alignment);

  // Field name: last_motion_errors
  current_alignment += get_serialized_size_key_franka_msgs__msg__Errors(
    &(ros_message->last_motion_errors), current_alignment);

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_franka_msgs
size_t max_serialized_size_key_franka_msgs__msg__FrankaState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: header
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: cartesian_collision
  {
    size_t array_size = 6;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: cartesian_contact
  {
    size_t array_size = 6;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: q
  {
    size_t array_size = 7;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: q_d
  {
    size_t array_size = 7;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: dq
  {
    size_t array_size = 7;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: dq_d
  {
    size_t array_size = 7;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: ddq_d
  {
    size_t array_size = 7;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: theta
  {
    size_t array_size = 7;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: dtheta
  {
    size_t array_size = 7;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: tau_j
  {
    size_t array_size = 7;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: dtau_j
  {
    size_t array_size = 7;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: tau_j_d
  {
    size_t array_size = 7;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: k_f_ext_hat_k
  {
    size_t array_size = 6;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: elbow
  {
    size_t array_size = 2;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: elbow_d
  {
    size_t array_size = 2;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: elbow_c
  {
    size_t array_size = 2;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: delbow_c
  {
    size_t array_size = 2;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: ddelbow_c
  {
    size_t array_size = 2;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: joint_collision
  {
    size_t array_size = 7;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: joint_contact
  {
    size_t array_size = 7;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: o_f_ext_hat_k
  {
    size_t array_size = 6;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: o_dp_ee_d
  {
    size_t array_size = 6;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: o_ddp_o
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: o_dp_ee_c
  {
    size_t array_size = 6;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: o_ddp_ee_c
  {
    size_t array_size = 6;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: tau_ext_hat_filtered
  {
    size_t array_size = 7;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: m_ee
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: f_x_cee
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: i_ee
  {
    size_t array_size = 9;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: m_load
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: f_x_cload
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: i_load
  {
    size_t array_size = 9;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: m_total
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: f_x_ctotal
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: i_total
  {
    size_t array_size = 9;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: o_t_ee
  {
    size_t array_size = 16;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: o_t_ee_d
  {
    size_t array_size = 16;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: o_t_ee_c
  {
    size_t array_size = 16;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: f_t_ee
  {
    size_t array_size = 16;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: f_t_ne
  {
    size_t array_size = 16;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: ne_t_ee
  {
    size_t array_size = 16;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: ee_t_k
  {
    size_t array_size = 16;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: time
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: control_command_success_rate
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: robot_mode
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: current_errors
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_franka_msgs__msg__Errors(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: last_motion_errors
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_franka_msgs__msg__Errors(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = franka_msgs__msg__FrankaState;
    is_plain =
      (
      offsetof(DataType, last_motion_errors) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _FrankaState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const franka_msgs__msg__FrankaState * ros_message = static_cast<const franka_msgs__msg__FrankaState *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_franka_msgs__msg__FrankaState(ros_message, cdr);
}

static bool _FrankaState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  franka_msgs__msg__FrankaState * ros_message = static_cast<franka_msgs__msg__FrankaState *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_franka_msgs__msg__FrankaState(cdr, ros_message);
}

static uint32_t _FrankaState__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_franka_msgs__msg__FrankaState(
      untyped_ros_message, 0));
}

static size_t _FrankaState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_franka_msgs__msg__FrankaState(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_FrankaState = {
  "franka_msgs::msg",
  "FrankaState",
  _FrankaState__cdr_serialize,
  _FrankaState__cdr_deserialize,
  _FrankaState__get_serialized_size,
  _FrankaState__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _FrankaState__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_FrankaState,
  get_message_typesupport_handle_function,
  &franka_msgs__msg__FrankaState__get_type_hash,
  &franka_msgs__msg__FrankaState__get_type_description,
  &franka_msgs__msg__FrankaState__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, franka_msgs, msg, FrankaState)() {
  return &_FrankaState__type_support;
}

#if defined(__cplusplus)
}
#endif
