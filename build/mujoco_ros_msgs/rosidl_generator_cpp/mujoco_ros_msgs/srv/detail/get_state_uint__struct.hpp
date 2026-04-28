// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from mujoco_ros_msgs:srv/GetStateUint.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "mujoco_ros_msgs/srv/get_state_uint.hpp"


#ifndef MUJOCO_ROS_MSGS__SRV__DETAIL__GET_STATE_UINT__STRUCT_HPP_
#define MUJOCO_ROS_MSGS__SRV__DETAIL__GET_STATE_UINT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__mujoco_ros_msgs__srv__GetStateUint_Request __attribute__((deprecated))
#else
# define DEPRECATED__mujoco_ros_msgs__srv__GetStateUint_Request __declspec(deprecated)
#endif

namespace mujoco_ros_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetStateUint_Request_
{
  using Type = GetStateUint_Request_<ContainerAllocator>;

  explicit GetStateUint_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit GetStateUint_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    mujoco_ros_msgs::srv::GetStateUint_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const mujoco_ros_msgs::srv::GetStateUint_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mujoco_ros_msgs::srv::GetStateUint_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mujoco_ros_msgs::srv::GetStateUint_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mujoco_ros_msgs::srv::GetStateUint_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mujoco_ros_msgs::srv::GetStateUint_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mujoco_ros_msgs::srv::GetStateUint_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mujoco_ros_msgs::srv::GetStateUint_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mujoco_ros_msgs::srv::GetStateUint_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mujoco_ros_msgs::srv::GetStateUint_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mujoco_ros_msgs__srv__GetStateUint_Request
    std::shared_ptr<mujoco_ros_msgs::srv::GetStateUint_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mujoco_ros_msgs__srv__GetStateUint_Request
    std::shared_ptr<mujoco_ros_msgs::srv::GetStateUint_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetStateUint_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetStateUint_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetStateUint_Request_

// alias to use template instance with default allocator
using GetStateUint_Request =
  mujoco_ros_msgs::srv::GetStateUint_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace mujoco_ros_msgs


// Include directives for member types
// Member 'state'
#include "mujoco_ros_msgs/msg/detail/state_uint__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__mujoco_ros_msgs__srv__GetStateUint_Response __attribute__((deprecated))
#else
# define DEPRECATED__mujoco_ros_msgs__srv__GetStateUint_Response __declspec(deprecated)
#endif

namespace mujoco_ros_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetStateUint_Response_
{
  using Type = GetStateUint_Response_<ContainerAllocator>;

  explicit GetStateUint_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : state(_init)
  {
    (void)_init;
  }

  explicit GetStateUint_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : state(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _state_type =
    mujoco_ros_msgs::msg::StateUint_<ContainerAllocator>;
  _state_type state;

  // setters for named parameter idiom
  Type & set__state(
    const mujoco_ros_msgs::msg::StateUint_<ContainerAllocator> & _arg)
  {
    this->state = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mujoco_ros_msgs::srv::GetStateUint_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const mujoco_ros_msgs::srv::GetStateUint_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mujoco_ros_msgs::srv::GetStateUint_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mujoco_ros_msgs::srv::GetStateUint_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mujoco_ros_msgs::srv::GetStateUint_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mujoco_ros_msgs::srv::GetStateUint_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mujoco_ros_msgs::srv::GetStateUint_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mujoco_ros_msgs::srv::GetStateUint_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mujoco_ros_msgs::srv::GetStateUint_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mujoco_ros_msgs::srv::GetStateUint_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mujoco_ros_msgs__srv__GetStateUint_Response
    std::shared_ptr<mujoco_ros_msgs::srv::GetStateUint_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mujoco_ros_msgs__srv__GetStateUint_Response
    std::shared_ptr<mujoco_ros_msgs::srv::GetStateUint_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetStateUint_Response_ & other) const
  {
    if (this->state != other.state) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetStateUint_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetStateUint_Response_

// alias to use template instance with default allocator
using GetStateUint_Response =
  mujoco_ros_msgs::srv::GetStateUint_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace mujoco_ros_msgs


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__mujoco_ros_msgs__srv__GetStateUint_Event __attribute__((deprecated))
#else
# define DEPRECATED__mujoco_ros_msgs__srv__GetStateUint_Event __declspec(deprecated)
#endif

namespace mujoco_ros_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetStateUint_Event_
{
  using Type = GetStateUint_Event_<ContainerAllocator>;

  explicit GetStateUint_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit GetStateUint_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<mujoco_ros_msgs::srv::GetStateUint_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<mujoco_ros_msgs::srv::GetStateUint_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<mujoco_ros_msgs::srv::GetStateUint_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<mujoco_ros_msgs::srv::GetStateUint_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<mujoco_ros_msgs::srv::GetStateUint_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<mujoco_ros_msgs::srv::GetStateUint_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<mujoco_ros_msgs::srv::GetStateUint_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<mujoco_ros_msgs::srv::GetStateUint_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mujoco_ros_msgs::srv::GetStateUint_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const mujoco_ros_msgs::srv::GetStateUint_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mujoco_ros_msgs::srv::GetStateUint_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mujoco_ros_msgs::srv::GetStateUint_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mujoco_ros_msgs::srv::GetStateUint_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mujoco_ros_msgs::srv::GetStateUint_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mujoco_ros_msgs::srv::GetStateUint_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mujoco_ros_msgs::srv::GetStateUint_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mujoco_ros_msgs::srv::GetStateUint_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mujoco_ros_msgs::srv::GetStateUint_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mujoco_ros_msgs__srv__GetStateUint_Event
    std::shared_ptr<mujoco_ros_msgs::srv::GetStateUint_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mujoco_ros_msgs__srv__GetStateUint_Event
    std::shared_ptr<mujoco_ros_msgs::srv::GetStateUint_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetStateUint_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetStateUint_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetStateUint_Event_

// alias to use template instance with default allocator
using GetStateUint_Event =
  mujoco_ros_msgs::srv::GetStateUint_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace mujoco_ros_msgs

namespace mujoco_ros_msgs
{

namespace srv
{

struct GetStateUint
{
  using Request = mujoco_ros_msgs::srv::GetStateUint_Request;
  using Response = mujoco_ros_msgs::srv::GetStateUint_Response;
  using Event = mujoco_ros_msgs::srv::GetStateUint_Event;
};

}  // namespace srv

}  // namespace mujoco_ros_msgs

#endif  // MUJOCO_ROS_MSGS__SRV__DETAIL__GET_STATE_UINT__STRUCT_HPP_
