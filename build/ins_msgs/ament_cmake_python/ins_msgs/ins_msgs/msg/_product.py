# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ins_msgs:msg/Product.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'spec_value'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Product(type):
    """Metaclass of message 'Product'."""

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
            module = import_type_support('ins_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ins_msgs.msg.Product')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__product
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__product
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__product
            cls._TYPE_SUPPORT = module.type_support_msg__msg__product
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__product

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Product(metaclass=Metaclass_Product):
    """Message class 'Product'."""

    __slots__ = [
        '_client_id',
        '_name',
        '_desp',
        '_timestamp',
        '_spec_value',
    ]

    _fields_and_field_types = {
        'client_id': 'int64',
        'name': 'string<10>',
        'desp': 'string',
        'timestamp': 'int64',
        'spec_value': 'sequence<double>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BoundedString(10),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.client_id = kwargs.get('client_id', int())
        self.name = kwargs.get('name', str())
        self.desp = kwargs.get('desp', str())
        self.timestamp = kwargs.get('timestamp', int())
        self.spec_value = array.array('d', kwargs.get('spec_value', []))

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
        if self.client_id != other.client_id:
            return False
        if self.name != other.name:
            return False
        if self.desp != other.desp:
            return False
        if self.timestamp != other.timestamp:
            return False
        if self.spec_value != other.spec_value:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def client_id(self):
        """Message field 'client_id'."""
        return self._client_id

    @client_id.setter
    def client_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'client_id' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'client_id' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._client_id = value

    @builtins.property
    def name(self):
        """Message field 'name'."""
        return self._name

    @name.setter
    def name(self, value):
        if __debug__:
            from collections import UserString
            assert \
                (isinstance(value, (str, UserString)) and
                 len(value) <= 10), \
                "The 'name' field must be string value " \
                'not longer than 10'
        self._name = value

    @builtins.property
    def desp(self):
        """Message field 'desp'."""
        return self._desp

    @desp.setter
    def desp(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'desp' field must be of type 'str'"
        self._desp = value

    @builtins.property
    def timestamp(self):
        """Message field 'timestamp'."""
        return self._timestamp

    @timestamp.setter
    def timestamp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'timestamp' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'timestamp' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._timestamp = value

    @builtins.property
    def spec_value(self):
        """Message field 'spec_value'."""
        return self._spec_value

    @spec_value.setter
    def spec_value(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'spec_value' array.array() must have the type code of 'd'"
            self._spec_value = value
            return
        if __debug__:
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
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'spec_value' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._spec_value = array.array('d', value)
