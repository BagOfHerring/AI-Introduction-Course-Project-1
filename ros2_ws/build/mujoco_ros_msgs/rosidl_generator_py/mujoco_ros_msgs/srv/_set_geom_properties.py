# generated from rosidl_generator_py/resource/_idl.py.em
# with input from mujoco_ros_msgs:srv/SetGeomProperties.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SetGeomProperties_Request(type):
    """Metaclass of message 'SetGeomProperties_Request'."""

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
                'mujoco_ros_msgs.srv.SetGeomProperties_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__set_geom_properties__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__set_geom_properties__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__set_geom_properties__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__set_geom_properties__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__set_geom_properties__request

            from mujoco_ros_msgs.msg import GeomProperties
            if GeomProperties.__class__._TYPE_SUPPORT is None:
                GeomProperties.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetGeomProperties_Request(metaclass=Metaclass_SetGeomProperties_Request):
    """Message class 'SetGeomProperties_Request'."""

    __slots__ = [
        '_properties',
        '_set_type',
        '_set_mass',
        '_set_friction',
        '_set_size',
        '_admin_hash',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'properties': 'mujoco_ros_msgs/GeomProperties',
        'set_type': 'boolean',
        'set_mass': 'boolean',
        'set_friction': 'boolean',
        'set_size': 'boolean',
        'admin_hash': 'string',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['mujoco_ros_msgs', 'msg'], 'GeomProperties'),  # noqa: E501
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
        from mujoco_ros_msgs.msg import GeomProperties
        self.properties = kwargs.get('properties', GeomProperties())
        self.set_type = kwargs.get('set_type', bool())
        self.set_mass = kwargs.get('set_mass', bool())
        self.set_friction = kwargs.get('set_friction', bool())
        self.set_size = kwargs.get('set_size', bool())
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
        if self.properties != other.properties:
            return False
        if self.set_type != other.set_type:
            return False
        if self.set_mass != other.set_mass:
            return False
        if self.set_friction != other.set_friction:
            return False
        if self.set_size != other.set_size:
            return False
        if self.admin_hash != other.admin_hash:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def properties(self):
        """Message field 'properties'."""
        return self._properties

    @properties.setter
    def properties(self, value):
        if self._check_fields:
            from mujoco_ros_msgs.msg import GeomProperties
            assert \
                isinstance(value, GeomProperties), \
                "The 'properties' field must be a sub message of type 'GeomProperties'"
        self._properties = value

    @builtins.property
    def set_type(self):
        """Message field 'set_type'."""
        return self._set_type

    @set_type.setter
    def set_type(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'set_type' field must be of type 'bool'"
        self._set_type = value

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
    def set_friction(self):
        """Message field 'set_friction'."""
        return self._set_friction

    @set_friction.setter
    def set_friction(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'set_friction' field must be of type 'bool'"
        self._set_friction = value

    @builtins.property
    def set_size(self):
        """Message field 'set_size'."""
        return self._set_size

    @set_size.setter
    def set_size(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'set_size' field must be of type 'bool'"
        self._set_size = value

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


class Metaclass_SetGeomProperties_Response(type):
    """Metaclass of message 'SetGeomProperties_Response'."""

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
                'mujoco_ros_msgs.srv.SetGeomProperties_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__set_geom_properties__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__set_geom_properties__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__set_geom_properties__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__set_geom_properties__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__set_geom_properties__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetGeomProperties_Response(metaclass=Metaclass_SetGeomProperties_Response):
    """Message class 'SetGeomProperties_Response'."""

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


class Metaclass_SetGeomProperties_Event(type):
    """Metaclass of message 'SetGeomProperties_Event'."""

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
                'mujoco_ros_msgs.srv.SetGeomProperties_Event')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__set_geom_properties__event
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__set_geom_properties__event
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__set_geom_properties__event
            cls._TYPE_SUPPORT = module.type_support_msg__srv__set_geom_properties__event
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__set_geom_properties__event

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


class SetGeomProperties_Event(metaclass=Metaclass_SetGeomProperties_Event):
    """Message class 'SetGeomProperties_Event'."""

    __slots__ = [
        '_info',
        '_request',
        '_response',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'info': 'service_msgs/ServiceEventInfo',
        'request': 'sequence<mujoco_ros_msgs/SetGeomProperties_Request, 1>',
        'response': 'sequence<mujoco_ros_msgs/SetGeomProperties_Response, 1>',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['service_msgs', 'msg'], 'ServiceEventInfo'),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.NamespacedType(['mujoco_ros_msgs', 'srv'], 'SetGeomProperties_Request'), 1),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.NamespacedType(['mujoco_ros_msgs', 'srv'], 'SetGeomProperties_Response'), 1),  # noqa: E501
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
            from mujoco_ros_msgs.srv import SetGeomProperties_Request
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
                 all(isinstance(v, SetGeomProperties_Request) for v in value) and
                 True), \
                "The 'request' field must be a set or sequence with length <= 1 and each value of type 'SetGeomProperties_Request'"
        self._request = value

    @builtins.property
    def response(self):
        """Message field 'response'."""
        return self._response

    @response.setter
    def response(self, value):
        if self._check_fields:
            from mujoco_ros_msgs.srv import SetGeomProperties_Response
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
                 all(isinstance(v, SetGeomProperties_Response) for v in value) and
                 True), \
                "The 'response' field must be a set or sequence with length <= 1 and each value of type 'SetGeomProperties_Response'"
        self._response = value


class Metaclass_SetGeomProperties(type):
    """Metaclass of service 'SetGeomProperties'."""

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
                'mujoco_ros_msgs.srv.SetGeomProperties')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__set_geom_properties

            from mujoco_ros_msgs.srv import _set_geom_properties
            if _set_geom_properties.Metaclass_SetGeomProperties_Request._TYPE_SUPPORT is None:
                _set_geom_properties.Metaclass_SetGeomProperties_Request.__import_type_support__()
            if _set_geom_properties.Metaclass_SetGeomProperties_Response._TYPE_SUPPORT is None:
                _set_geom_properties.Metaclass_SetGeomProperties_Response.__import_type_support__()
            if _set_geom_properties.Metaclass_SetGeomProperties_Event._TYPE_SUPPORT is None:
                _set_geom_properties.Metaclass_SetGeomProperties_Event.__import_type_support__()


class SetGeomProperties(metaclass=Metaclass_SetGeomProperties):
    from mujoco_ros_msgs.srv._set_geom_properties import SetGeomProperties_Request as Request
    from mujoco_ros_msgs.srv._set_geom_properties import SetGeomProperties_Response as Response
    from mujoco_ros_msgs.srv._set_geom_properties import SetGeomProperties_Event as Event

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
