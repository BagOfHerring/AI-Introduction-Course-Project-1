// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mujoco_ros_msgs:srv/RegisterSensorNoiseModels.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "mujoco_ros_msgs/srv/register_sensor_noise_models.h"


#ifndef MUJOCO_ROS_MSGS__SRV__DETAIL__REGISTER_SENSOR_NOISE_MODELS__STRUCT_H_
#define MUJOCO_ROS_MSGS__SRV__DETAIL__REGISTER_SENSOR_NOISE_MODELS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'noise_models'
#include "mujoco_ros_msgs/msg/detail/sensor_noise_model__struct.h"
// Member 'admin_hash'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/RegisterSensorNoiseModels in the package mujoco_ros_msgs.
typedef struct mujoco_ros_msgs__srv__RegisterSensorNoiseModels_Request
{
  mujoco_ros_msgs__msg__SensorNoiseModel__Sequence noise_models;
  rosidl_runtime_c__String admin_hash;
} mujoco_ros_msgs__srv__RegisterSensorNoiseModels_Request;

// Struct for a sequence of mujoco_ros_msgs__srv__RegisterSensorNoiseModels_Request.
typedef struct mujoco_ros_msgs__srv__RegisterSensorNoiseModels_Request__Sequence
{
  mujoco_ros_msgs__srv__RegisterSensorNoiseModels_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mujoco_ros_msgs__srv__RegisterSensorNoiseModels_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/RegisterSensorNoiseModels in the package mujoco_ros_msgs.
typedef struct mujoco_ros_msgs__srv__RegisterSensorNoiseModels_Response
{
  bool success;
} mujoco_ros_msgs__srv__RegisterSensorNoiseModels_Response;

// Struct for a sequence of mujoco_ros_msgs__srv__RegisterSensorNoiseModels_Response.
typedef struct mujoco_ros_msgs__srv__RegisterSensorNoiseModels_Response__Sequence
{
  mujoco_ros_msgs__srv__RegisterSensorNoiseModels_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mujoco_ros_msgs__srv__RegisterSensorNoiseModels_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  mujoco_ros_msgs__srv__RegisterSensorNoiseModels_Event__request__MAX_SIZE = 1
};
// response
enum
{
  mujoco_ros_msgs__srv__RegisterSensorNoiseModels_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/RegisterSensorNoiseModels in the package mujoco_ros_msgs.
typedef struct mujoco_ros_msgs__srv__RegisterSensorNoiseModels_Event
{
  service_msgs__msg__ServiceEventInfo info;
  mujoco_ros_msgs__srv__RegisterSensorNoiseModels_Request__Sequence request;
  mujoco_ros_msgs__srv__RegisterSensorNoiseModels_Response__Sequence response;
} mujoco_ros_msgs__srv__RegisterSensorNoiseModels_Event;

// Struct for a sequence of mujoco_ros_msgs__srv__RegisterSensorNoiseModels_Event.
typedef struct mujoco_ros_msgs__srv__RegisterSensorNoiseModels_Event__Sequence
{
  mujoco_ros_msgs__srv__RegisterSensorNoiseModels_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mujoco_ros_msgs__srv__RegisterSensorNoiseModels_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MUJOCO_ROS_MSGS__SRV__DETAIL__REGISTER_SENSOR_NOISE_MODELS__STRUCT_H_
