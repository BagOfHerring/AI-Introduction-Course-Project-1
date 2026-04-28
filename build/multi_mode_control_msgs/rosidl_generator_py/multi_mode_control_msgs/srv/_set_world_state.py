# generated from rosidl_generator_py/resource/_idl.py.em
# with input from multi_mode_control_msgs:srv/SetWorldState.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

# Member 'items'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SetWorldState_Request(type):
    """Metaclass of message 'SetWorldState_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'HUMAN_PRESENT': 0,
        'OBJECT_IN_HAND': 1,
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('multi_mode_control_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'multi_mode_control_msgs.srv.SetWorldState_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__set_world_state__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__set_world_state__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__set_world_state__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__set_world_state__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__set_world_state__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'HUMAN_PRESENT': cls.__constants['HUMAN_PRESENT'],
            'OBJECT_IN_HAND': cls.__constants['OBJECT_IN_HAND'],
        }

    @property
    def HUMAN_PRESENT(self):
        """Message constant 'HUMAN_PRESENT'."""
        return Metaclass_SetWorldState_Request.__constants['HUMAN_PRESENT']

    @property
    def OBJECT_IN_HAND(self):
        """Message constant 'OBJECT_IN_HAND'."""
        return Metaclass_SetWorldState_Request.__constants['OBJECT_IN_HAND']


class SetWorldState_Request(metaclass=Metaclass_SetWorldState_Request):
    """
    Message class 'SetWorldState_Request'.

    Constants:
      HUMAN_PRESENT
      OBJECT_IN_HAND
    """

    __slots__ = [
        '_items',
        '_values',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'items': 'sequence<int32>',
        'values': 'sequence<boolean>',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('int32')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('boolean')),  # noqa: E501
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
        self.items = array.array('i', kwargs.get('items', []))
        self.values = kwargs.get('values', [])

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
        if self.items != other.items:
            return False
        if self.values != other.values:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def items(self):
        """Message field 'items'."""
        return self._items

    @items.setter
    def items(self, value):
        if self._check_fields:
            if isinstance(value, array.array):
                assert value.typecode == 'i', \
                    "The 'items' array.array() must have the type code of 'i'"
                self._items = value
                return
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
                 all(isinstance(v, int) for v in value) and
                 all(val >= -2147483648 and val < 2147483648 for val in value)), \
                "The 'items' field must be a set or sequence and each value of type 'int' and each integer in [-2147483648, 2147483647]"
        self._items = array.array('i', value)

    @builtins.property
    def values(self):
        """Message field 'values'."""
        return self._values

    @values.setter
    def values(self, value):
        if self._check_fields:
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
                 all(isinstance(v, bool) for v in value) and
                 True), \
                "The 'values' field must be a set or sequence and each value of type 'bool'"
        self._values = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_SetWorldState_Response(type):
    """Metaclass of message 'SetWorldState_Response'."""

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
            module = import_type_support('multi_mode_control_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'multi_mode_control_msgs.srv.SetWorldState_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__set_world_state__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__set_world_state__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__set_world_state__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__set_world_state__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__set_world_state__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetWorldState_Response(metaclass=Metaclass_SetWorldState_Response):
    """Message class 'SetWorldState_Response'."""

    __slots__ = [
        '_check_fields',
    ]

    _fields_and_field_types = {
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
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
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SetWorldState_Event(type):
    """Metaclass of message 'SetWorldState_Event'."""

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
            module = import_type_support('multi_mode_control_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'multi_mode_control_msgs.srv.SetWorldState_Event')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__set_world_state__event
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__set_world_state__event
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__set_world_state__event
            cls._TYPE_SUPPORT = module.type_support_msg__srv__set_world_state__event
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__set_world_state__event

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


class SetWorldState_Event(metaclass=Metaclass_SetWorldState_Event):
    """Message class 'SetWorldState_Event'."""

    __slots__ = [
        '_info',
        '_request',
        '_response',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'info': 'service_msgs/ServiceEventInfo',
        'request': 'sequence<multi_mode_control_msgs/SetWorldState_Request, 1>',
        'response': 'sequence<multi_mode_control_msgs/SetWorldState_Response, 1>',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['service_msgs', 'msg'], 'ServiceEventInfo'),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.NamespacedType(['multi_mode_control_msgs', 'srv'], 'SetWorldState_Request'), 1),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.NamespacedType(['multi_mode_control_msgs', 'srv'], 'SetWorldState_Response'), 1),  # noqa: E501
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
            from multi_mode_control_msgs.srv import SetWorldState_Request
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
                 all(isinstance(v, SetWorldState_Request) for v in value) and
                 True), \
                "The 'request' field must be a set or sequence with length <= 1 and each value of type 'SetWorldState_Request'"
        self._request = value

    @builtins.property
    def response(self):
        """Message field 'response'."""
        return self._response

    @response.setter
    def response(self, value):
        if self._check_fields:
            from multi_mode_control_msgs.srv import SetWorldState_Response
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
                 all(isinstance(v, SetWorldState_Response) for v in value) and
                 True), \
                "The 'response' field must be a set or sequence with length <= 1 and each value of type 'SetWorldState_Response'"
        self._response = value


class Metaclass_SetWorldState(type):
    """Metaclass of service 'SetWorldState'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('multi_mode_control_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'multi_mode_control_msgs.srv.SetWorldState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__set_world_state

            from multi_mode_control_msgs.srv import _set_world_state
            if _set_world_state.Metaclass_SetWorldState_Request._TYPE_SUPPORT is None:
                _set_world_state.Metaclass_SetWorldState_Request.__import_type_support__()
            if _set_world_state.Metaclass_SetWorldState_Response._TYPE_SUPPORT is None:
                _set_world_state.Metaclass_SetWorldState_Response.__import_type_support__()
            if _set_world_state.Metaclass_SetWorldState_Event._TYPE_SUPPORT is None:
                _set_world_state.Metaclass_SetWorldState_Event.__import_type_support__()


class SetWorldState(metaclass=Metaclass_SetWorldState):
    from multi_mode_control_msgs.srv._set_world_state import SetWorldState_Request as Request
    from multi_mode_control_msgs.srv._set_world_state import SetWorldState_Response as Response
    from multi_mode_control_msgs.srv._set_world_state import SetWorldState_Event as Event

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
