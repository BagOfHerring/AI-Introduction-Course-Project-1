// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from franka_msgs:srv/SetCartesianStiffness.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "franka_msgs/srv/set_cartesian_stiffness.h"


#ifndef FRANKA_MSGS__SRV__DETAIL__SET_CARTESIAN_STIFFNESS__FUNCTIONS_H_
#define FRANKA_MSGS__SRV__DETAIL__SET_CARTESIAN_STIFFNESS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "franka_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "franka_msgs/srv/detail/set_cartesian_stiffness__struct.h"

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
const rosidl_type_hash_t *
franka_msgs__srv__SetCartesianStiffness__get_type_hash(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
const rosidl_runtime_c__type_description__TypeDescription *
franka_msgs__srv__SetCartesianStiffness__get_type_description(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
const rosidl_runtime_c__type_description__TypeSource *
franka_msgs__srv__SetCartesianStiffness__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
const rosidl_runtime_c__type_description__TypeSource__Sequence *
franka_msgs__srv__SetCartesianStiffness__get_type_description_sources(
  const rosidl_service_type_support_t * type_support);

/// Initialize srv/SetCartesianStiffness message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * franka_msgs__srv__SetCartesianStiffness_Request
 * )) before or use
 * franka_msgs__srv__SetCartesianStiffness_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
bool
franka_msgs__srv__SetCartesianStiffness_Request__init(franka_msgs__srv__SetCartesianStiffness_Request * msg);

/// Finalize srv/SetCartesianStiffness message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
void
franka_msgs__srv__SetCartesianStiffness_Request__fini(franka_msgs__srv__SetCartesianStiffness_Request * msg);

/// Create srv/SetCartesianStiffness message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * franka_msgs__srv__SetCartesianStiffness_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
franka_msgs__srv__SetCartesianStiffness_Request *
franka_msgs__srv__SetCartesianStiffness_Request__create(void);

/// Destroy srv/SetCartesianStiffness message.
/**
 * It calls
 * franka_msgs__srv__SetCartesianStiffness_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
void
franka_msgs__srv__SetCartesianStiffness_Request__destroy(franka_msgs__srv__SetCartesianStiffness_Request * msg);

/// Check for srv/SetCartesianStiffness message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
bool
franka_msgs__srv__SetCartesianStiffness_Request__are_equal(const franka_msgs__srv__SetCartesianStiffness_Request * lhs, const franka_msgs__srv__SetCartesianStiffness_Request * rhs);

/// Copy a srv/SetCartesianStiffness message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
bool
franka_msgs__srv__SetCartesianStiffness_Request__copy(
  const franka_msgs__srv__SetCartesianStiffness_Request * input,
  franka_msgs__srv__SetCartesianStiffness_Request * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
const rosidl_type_hash_t *
franka_msgs__srv__SetCartesianStiffness_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
const rosidl_runtime_c__type_description__TypeDescription *
franka_msgs__srv__SetCartesianStiffness_Request__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
const rosidl_runtime_c__type_description__TypeSource *
franka_msgs__srv__SetCartesianStiffness_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
const rosidl_runtime_c__type_description__TypeSource__Sequence *
franka_msgs__srv__SetCartesianStiffness_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of srv/SetCartesianStiffness messages.
/**
 * It allocates the memory for the number of elements and calls
 * franka_msgs__srv__SetCartesianStiffness_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
bool
franka_msgs__srv__SetCartesianStiffness_Request__Sequence__init(franka_msgs__srv__SetCartesianStiffness_Request__Sequence * array, size_t size);

/// Finalize array of srv/SetCartesianStiffness messages.
/**
 * It calls
 * franka_msgs__srv__SetCartesianStiffness_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
void
franka_msgs__srv__SetCartesianStiffness_Request__Sequence__fini(franka_msgs__srv__SetCartesianStiffness_Request__Sequence * array);

/// Create array of srv/SetCartesianStiffness messages.
/**
 * It allocates the memory for the array and calls
 * franka_msgs__srv__SetCartesianStiffness_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
franka_msgs__srv__SetCartesianStiffness_Request__Sequence *
franka_msgs__srv__SetCartesianStiffness_Request__Sequence__create(size_t size);

/// Destroy array of srv/SetCartesianStiffness messages.
/**
 * It calls
 * franka_msgs__srv__SetCartesianStiffness_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
void
franka_msgs__srv__SetCartesianStiffness_Request__Sequence__destroy(franka_msgs__srv__SetCartesianStiffness_Request__Sequence * array);

/// Check for srv/SetCartesianStiffness message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
bool
franka_msgs__srv__SetCartesianStiffness_Request__Sequence__are_equal(const franka_msgs__srv__SetCartesianStiffness_Request__Sequence * lhs, const franka_msgs__srv__SetCartesianStiffness_Request__Sequence * rhs);

/// Copy an array of srv/SetCartesianStiffness messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
bool
franka_msgs__srv__SetCartesianStiffness_Request__Sequence__copy(
  const franka_msgs__srv__SetCartesianStiffness_Request__Sequence * input,
  franka_msgs__srv__SetCartesianStiffness_Request__Sequence * output);

/// Initialize srv/SetCartesianStiffness message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * franka_msgs__srv__SetCartesianStiffness_Response
 * )) before or use
 * franka_msgs__srv__SetCartesianStiffness_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
bool
franka_msgs__srv__SetCartesianStiffness_Response__init(franka_msgs__srv__SetCartesianStiffness_Response * msg);

/// Finalize srv/SetCartesianStiffness message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
void
franka_msgs__srv__SetCartesianStiffness_Response__fini(franka_msgs__srv__SetCartesianStiffness_Response * msg);

/// Create srv/SetCartesianStiffness message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * franka_msgs__srv__SetCartesianStiffness_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
franka_msgs__srv__SetCartesianStiffness_Response *
franka_msgs__srv__SetCartesianStiffness_Response__create(void);

/// Destroy srv/SetCartesianStiffness message.
/**
 * It calls
 * franka_msgs__srv__SetCartesianStiffness_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
void
franka_msgs__srv__SetCartesianStiffness_Response__destroy(franka_msgs__srv__SetCartesianStiffness_Response * msg);

/// Check for srv/SetCartesianStiffness message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
bool
franka_msgs__srv__SetCartesianStiffness_Response__are_equal(const franka_msgs__srv__SetCartesianStiffness_Response * lhs, const franka_msgs__srv__SetCartesianStiffness_Response * rhs);

/// Copy a srv/SetCartesianStiffness message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
bool
franka_msgs__srv__SetCartesianStiffness_Response__copy(
  const franka_msgs__srv__SetCartesianStiffness_Response * input,
  franka_msgs__srv__SetCartesianStiffness_Response * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
const rosidl_type_hash_t *
franka_msgs__srv__SetCartesianStiffness_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
const rosidl_runtime_c__type_description__TypeDescription *
franka_msgs__srv__SetCartesianStiffness_Response__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
const rosidl_runtime_c__type_description__TypeSource *
franka_msgs__srv__SetCartesianStiffness_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
const rosidl_runtime_c__type_description__TypeSource__Sequence *
franka_msgs__srv__SetCartesianStiffness_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of srv/SetCartesianStiffness messages.
/**
 * It allocates the memory for the number of elements and calls
 * franka_msgs__srv__SetCartesianStiffness_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
bool
franka_msgs__srv__SetCartesianStiffness_Response__Sequence__init(franka_msgs__srv__SetCartesianStiffness_Response__Sequence * array, size_t size);

/// Finalize array of srv/SetCartesianStiffness messages.
/**
 * It calls
 * franka_msgs__srv__SetCartesianStiffness_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
void
franka_msgs__srv__SetCartesianStiffness_Response__Sequence__fini(franka_msgs__srv__SetCartesianStiffness_Response__Sequence * array);

/// Create array of srv/SetCartesianStiffness messages.
/**
 * It allocates the memory for the array and calls
 * franka_msgs__srv__SetCartesianStiffness_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
franka_msgs__srv__SetCartesianStiffness_Response__Sequence *
franka_msgs__srv__SetCartesianStiffness_Response__Sequence__create(size_t size);

/// Destroy array of srv/SetCartesianStiffness messages.
/**
 * It calls
 * franka_msgs__srv__SetCartesianStiffness_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
void
franka_msgs__srv__SetCartesianStiffness_Response__Sequence__destroy(franka_msgs__srv__SetCartesianStiffness_Response__Sequence * array);

/// Check for srv/SetCartesianStiffness message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
bool
franka_msgs__srv__SetCartesianStiffness_Response__Sequence__are_equal(const franka_msgs__srv__SetCartesianStiffness_Response__Sequence * lhs, const franka_msgs__srv__SetCartesianStiffness_Response__Sequence * rhs);

/// Copy an array of srv/SetCartesianStiffness messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
bool
franka_msgs__srv__SetCartesianStiffness_Response__Sequence__copy(
  const franka_msgs__srv__SetCartesianStiffness_Response__Sequence * input,
  franka_msgs__srv__SetCartesianStiffness_Response__Sequence * output);

/// Initialize srv/SetCartesianStiffness message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * franka_msgs__srv__SetCartesianStiffness_Event
 * )) before or use
 * franka_msgs__srv__SetCartesianStiffness_Event__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
bool
franka_msgs__srv__SetCartesianStiffness_Event__init(franka_msgs__srv__SetCartesianStiffness_Event * msg);

/// Finalize srv/SetCartesianStiffness message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
void
franka_msgs__srv__SetCartesianStiffness_Event__fini(franka_msgs__srv__SetCartesianStiffness_Event * msg);

/// Create srv/SetCartesianStiffness message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * franka_msgs__srv__SetCartesianStiffness_Event__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
franka_msgs__srv__SetCartesianStiffness_Event *
franka_msgs__srv__SetCartesianStiffness_Event__create(void);

/// Destroy srv/SetCartesianStiffness message.
/**
 * It calls
 * franka_msgs__srv__SetCartesianStiffness_Event__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
void
franka_msgs__srv__SetCartesianStiffness_Event__destroy(franka_msgs__srv__SetCartesianStiffness_Event * msg);

/// Check for srv/SetCartesianStiffness message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
bool
franka_msgs__srv__SetCartesianStiffness_Event__are_equal(const franka_msgs__srv__SetCartesianStiffness_Event * lhs, const franka_msgs__srv__SetCartesianStiffness_Event * rhs);

/// Copy a srv/SetCartesianStiffness message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
bool
franka_msgs__srv__SetCartesianStiffness_Event__copy(
  const franka_msgs__srv__SetCartesianStiffness_Event * input,
  franka_msgs__srv__SetCartesianStiffness_Event * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
const rosidl_type_hash_t *
franka_msgs__srv__SetCartesianStiffness_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
const rosidl_runtime_c__type_description__TypeDescription *
franka_msgs__srv__SetCartesianStiffness_Event__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
const rosidl_runtime_c__type_description__TypeSource *
franka_msgs__srv__SetCartesianStiffness_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
const rosidl_runtime_c__type_description__TypeSource__Sequence *
franka_msgs__srv__SetCartesianStiffness_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of srv/SetCartesianStiffness messages.
/**
 * It allocates the memory for the number of elements and calls
 * franka_msgs__srv__SetCartesianStiffness_Event__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
bool
franka_msgs__srv__SetCartesianStiffness_Event__Sequence__init(franka_msgs__srv__SetCartesianStiffness_Event__Sequence * array, size_t size);

/// Finalize array of srv/SetCartesianStiffness messages.
/**
 * It calls
 * franka_msgs__srv__SetCartesianStiffness_Event__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
void
franka_msgs__srv__SetCartesianStiffness_Event__Sequence__fini(franka_msgs__srv__SetCartesianStiffness_Event__Sequence * array);

/// Create array of srv/SetCartesianStiffness messages.
/**
 * It allocates the memory for the array and calls
 * franka_msgs__srv__SetCartesianStiffness_Event__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
franka_msgs__srv__SetCartesianStiffness_Event__Sequence *
franka_msgs__srv__SetCartesianStiffness_Event__Sequence__create(size_t size);

/// Destroy array of srv/SetCartesianStiffness messages.
/**
 * It calls
 * franka_msgs__srv__SetCartesianStiffness_Event__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
void
franka_msgs__srv__SetCartesianStiffness_Event__Sequence__destroy(franka_msgs__srv__SetCartesianStiffness_Event__Sequence * array);

/// Check for srv/SetCartesianStiffness message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
bool
franka_msgs__srv__SetCartesianStiffness_Event__Sequence__are_equal(const franka_msgs__srv__SetCartesianStiffness_Event__Sequence * lhs, const franka_msgs__srv__SetCartesianStiffness_Event__Sequence * rhs);

/// Copy an array of srv/SetCartesianStiffness messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_franka_msgs
bool
franka_msgs__srv__SetCartesianStiffness_Event__Sequence__copy(
  const franka_msgs__srv__SetCartesianStiffness_Event__Sequence * input,
  franka_msgs__srv__SetCartesianStiffness_Event__Sequence * output);
#ifdef __cplusplus
}
#endif

#endif  // FRANKA_MSGS__SRV__DETAIL__SET_CARTESIAN_STIFFNESS__FUNCTIONS_H_
