# generated from rosidl_generator_py/resource/_idl.py.em
# with input from mujoco_ros_msgs:srv/SetBodyState.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SetBodyState_Request(type):
    """Metaclass of message 'SetBodyState_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('mujoco_ros_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'mujoco_ros_msgs.srv.SetBodyState_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__set_body_state__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__set_body_state__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__set_body_state__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__set_body_state__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__set_body_state__request

            from mujoco_ros_msgs.msg import BodyState
            if BodyState.__class__._TYPE_SUPPORT is None:
                BodyState.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetBodyState_Request(metaclass=Metaclass_SetBodyState_Request):
    """Message class 'SetBodyState_Request'."""

    __slots__ = [
        '_state',
        '_set_pose',
        '_set_twist',
        '_set_mass',
        '_reset_qpos',
        '_admin_hash',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'state': 'mujoco_ros_msgs/BodyState',
        'set_pose': 'boolean',
        'set_twist': 'boolean',
        'set_mass': 'boolean',
        'reset_qpos': 'boolean',
        'admin_hash': 'string',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['mujoco_ros_msgs', 'msg'], 'BodyState'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from mujoco_ros_msgs.msg import BodyState
        self.state = kwargs.get('state', BodyState())
        self.set_pose = kwargs.get('set_pose', bool())
        self.set_twist = kwargs.get('set_twist', bool())
        self.set_mass = kwargs.get('set_mass', bool())
        self.reset_qpos = kwargs.get('reset_qpos', bool())
        self.admin_hash = kwargs.get('admin_hash', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.state != other.state:
            return False
        if self.set_pose != other.set_pose:
            return False
        if self.set_twist != other.set_twist:
            return False
        if self.set_mass != other.set_mass:
            return False
        if self.reset_qpos != other.reset_qpos:
            return False
        if self.admin_hash != other.admin_hash:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def state(self):
        """Message field 'state'."""
        return self._state

    @state.setter
    def state(self, value):
        if self._check_fields:
            from mujoco_ros_msgs.msg import BodyState
            assert \
                isinstance(value, BodyState), \
                "The 'state' field must be a sub message of type 'BodyState'"
        self._state = value

    @builtins.property
    def set_pose(self):
        """Message field 'set_pose'."""
        return self._set_pose

    @set_pose.setter
    def set_pose(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'set_pose' field must be of type 'bool'"
        self._set_pose = value

    @builtins.property
    def set_twist(self):
        """Message field 'set_twist'."""
        return self._set_twist

    @set_twist.setter
    def set_twist(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'set_twist' field must be of type 'bool'"
        self._set_twist = value

    @builtins.property
    def set_mass(self):
        """Message field 'set_mass'."""
        return self._set_mass

    @set_mass.setter
    def set_mass(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'set_mass' field must be of type 'bool'"
        self._set_mass = value

    @builtins.property
    def reset_qpos(self):
        """Message field 'reset_qpos'."""
        return self._reset_qpos

    @reset_qpos.setter
    def reset_qpos(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'reset_qpos' field must be of type 'bool'"
        self._reset_qpos = value

    @builtins.property
    def admin_hash(self):
        """Message field 'admin_hash'."""
        return self._admin_hash

    @admin_hash.setter
    def admin_hash(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'admin_hash' field must be of type 'str'"
        self._admin_hash = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SetBodyState_Response(type):
    """Metaclass of message 'SetBodyState_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('mujoco_ros_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'mujoco_ros_msgs.srv.SetBodyState_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__set_body_state__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__set_body_state__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__set_body_state__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__set_body_state__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__set_body_state__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetBodyState_Response(metaclass=Metaclass_SetBodyState_Response):
    """Message class 'SetBodyState_Response'."""

    __slots__ = [
        '_success',
        '_status_message',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'status_message': 'string',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())
        self.status_message = kwargs.get('status_message', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.success != other.success:
            return False
        if self.status_message != other.status_message:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value

    @builtins.property
    def status_message(self):
        """Message field 'status_message'."""
        return self._status_message

    @status_message.setter
    def status_message(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'status_message' field must be of type 'str'"
        self._status_message = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SetBodyState_Event(type):
    """Metaclass of message 'SetBodyState_Event'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('mujoco_ros_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'mujoco_ros_msgs.srv.SetBodyState_Event')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__set_body_state__event
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__set_body_state__event
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__set_body_state__event
            cls._TYPE_SUPPORT = module.type_support_msg__srv__set_body_state__event
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__set_body_state__event

            from service_msgs.msg import ServiceEventInfo
            if ServiceEventInfo.__class__._TYPE_SUPPORT is None:
                ServiceEventInfo.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetBodyState_Event(metaclass=Metaclass_SetBodyState_Event):
    """Message class 'SetBodyState_Event'."""

    __slots__ = [
        '_info',
        '_request',
        '_response',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'info': 'service_msgs/ServiceEventInfo',
        'request': 'sequence<mujoco_ros_msgs/SetBodyState_Request, 1>',
        'response': 'sequence<mujoco_ros_msgs/SetBodyState_Response, 1>',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['service_msgs', 'msg'], 'ServiceEventInfo'),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.NamespacedType(['mujoco_ros_msgs', 'srv'], 'SetBodyState_Request'), 1),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.NamespacedType(['mujoco_ros_msgs', 'srv'], 'SetBodyState_Response'), 1),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from service_msgs.msg import ServiceEventInfo
        self.info = kwargs.get('info', ServiceEventInfo())
        self.request = kwargs.get('request', [])
        self.response = kwargs.get('response', [])

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.info != other.info:
            return False
        if self.request != other.request:
            return False
        if self.response != other.response:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def info(self):
        """Message field 'info'."""
        return self._info

    @info.setter
    def info(self, value):
        if self._check_fields:
            from service_msgs.msg import ServiceEventInfo
            assert \
                isinstance(value, ServiceEventInfo), \
                "The 'info' field must be a sub message of type 'ServiceEventInfo'"
        self._info = value

    @builtins.property
    def request(self):
        """Message field 'request'."""
        return self._request

    @request.setter
    def request(self, value):
        if self._check_fields:
            from mujoco_ros_msgs.srv import SetBodyState_Request
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) <= 1 and
                 all(isinstance(v, SetBodyState_Request) for v in value) and
                 True), \
                "The 'request' field must be a set or sequence with length <= 1 and each value of type 'SetBodyState_Request'"
        self._request = value

    @builtins.property
    def response(self):
        """Message field 'response'."""
        return self._response

    @response.setter
    def response(self, value):
        if self._check_fields:
            from mujoco_ros_msgs.srv import SetBodyState_Response
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) <= 1 and
                 all(isinstance(v, SetBodyState_Response) for v in value) and
                 True), \
                "The 'response' field must be a set or sequence with length <= 1 and each value of type 'SetBodyState_Response'"
        self._response = value


class Metaclass_SetBodyState(type):
    """Metaclass of service 'SetBodyState'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('mujoco_ros_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'mujoco_ros_msgs.srv.SetBodyState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__set_body_state

            from mujoco_ros_msgs.srv import _set_body_state
            if _set_body_state.Metaclass_SetBodyState_Request._TYPE_SUPPORT is None:
                _set_body_state.Metaclass_SetBodyState_Request.__import_type_support__()
            if _set_body_state.Metaclass_SetBodyState_Response._TYPE_SUPPORT is None:
                _set_body_state.Metaclass_SetBodyState_Response.__import_type_support__()
            if _set_body_state.Metaclass_SetBodyState_Event._TYPE_SUPPORT is None:
                _set_body_state.Metaclass_SetBodyState_Event.__import_type_support__()


class SetBodyState(metaclass=Metaclass_SetBodyState):
    from mujoco_ros_msgs.srv._set_body_state import SetBodyState_Request as Request
    from mujoco_ros_msgs.srv._set_body_state import SetBodyState_Response as Response
    from mujoco_ros_msgs.srv._set_body_state import SetBodyState_Event as Event

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
