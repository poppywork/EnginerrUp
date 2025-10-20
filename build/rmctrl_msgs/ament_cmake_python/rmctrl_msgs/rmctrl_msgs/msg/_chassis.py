# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rmctrl_msgs:msg/Chassis.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Chassis(type):
    """Metaclass of message 'Chassis'."""

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
            module = import_type_support('rmctrl_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'rmctrl_msgs.msg.Chassis')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__chassis
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__chassis
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__chassis
            cls._TYPE_SUPPORT = module.type_support_msg__msg__chassis
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__chassis

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Chassis(metaclass=Metaclass_Chassis):
    """Message class 'Chassis'."""

    __slots__ = [
        '_chassis_target_linear_x',
        '_chassis_target_linear_y',
        '_chassis_target_linear_z',
        '_chassis_target_angular_x',
        '_chassis_target_angular_y',
        '_chassis_target_angular_z',
    ]

    _fields_and_field_types = {
        'chassis_target_linear_x': 'double',
        'chassis_target_linear_y': 'double',
        'chassis_target_linear_z': 'double',
        'chassis_target_angular_x': 'double',
        'chassis_target_angular_y': 'double',
        'chassis_target_angular_z': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.chassis_target_linear_x = kwargs.get('chassis_target_linear_x', float())
        self.chassis_target_linear_y = kwargs.get('chassis_target_linear_y', float())
        self.chassis_target_linear_z = kwargs.get('chassis_target_linear_z', float())
        self.chassis_target_angular_x = kwargs.get('chassis_target_angular_x', float())
        self.chassis_target_angular_y = kwargs.get('chassis_target_angular_y', float())
        self.chassis_target_angular_z = kwargs.get('chassis_target_angular_z', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
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
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.chassis_target_linear_x != other.chassis_target_linear_x:
            return False
        if self.chassis_target_linear_y != other.chassis_target_linear_y:
            return False
        if self.chassis_target_linear_z != other.chassis_target_linear_z:
            return False
        if self.chassis_target_angular_x != other.chassis_target_angular_x:
            return False
        if self.chassis_target_angular_y != other.chassis_target_angular_y:
            return False
        if self.chassis_target_angular_z != other.chassis_target_angular_z:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def chassis_target_linear_x(self):
        """Message field 'chassis_target_linear_x'."""
        return self._chassis_target_linear_x

    @chassis_target_linear_x.setter
    def chassis_target_linear_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'chassis_target_linear_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'chassis_target_linear_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._chassis_target_linear_x = value

    @builtins.property
    def chassis_target_linear_y(self):
        """Message field 'chassis_target_linear_y'."""
        return self._chassis_target_linear_y

    @chassis_target_linear_y.setter
    def chassis_target_linear_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'chassis_target_linear_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'chassis_target_linear_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._chassis_target_linear_y = value

    @builtins.property
    def chassis_target_linear_z(self):
        """Message field 'chassis_target_linear_z'."""
        return self._chassis_target_linear_z

    @chassis_target_linear_z.setter
    def chassis_target_linear_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'chassis_target_linear_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'chassis_target_linear_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._chassis_target_linear_z = value

    @builtins.property
    def chassis_target_angular_x(self):
        """Message field 'chassis_target_angular_x'."""
        return self._chassis_target_angular_x

    @chassis_target_angular_x.setter
    def chassis_target_angular_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'chassis_target_angular_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'chassis_target_angular_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._chassis_target_angular_x = value

    @builtins.property
    def chassis_target_angular_y(self):
        """Message field 'chassis_target_angular_y'."""
        return self._chassis_target_angular_y

    @chassis_target_angular_y.setter
    def chassis_target_angular_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'chassis_target_angular_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'chassis_target_angular_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._chassis_target_angular_y = value

    @builtins.property
    def chassis_target_angular_z(self):
        """Message field 'chassis_target_angular_z'."""
        return self._chassis_target_angular_z

    @chassis_target_angular_z.setter
    def chassis_target_angular_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'chassis_target_angular_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'chassis_target_angular_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._chassis_target_angular_z = value
