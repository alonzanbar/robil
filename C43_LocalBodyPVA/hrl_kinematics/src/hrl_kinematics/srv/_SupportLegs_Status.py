"""autogenerated by genpy from hrl_kinematics/SupportLegs_StatusRequest.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class SupportLegs_StatusRequest(genpy.Message):
  _md5sum = "64a69a181ef4f43cc29c2c2cd30d9424"
  _type = "hrl_kinematics/SupportLegs_StatusRequest"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """


















int8 FootSupport_CMD
int8 SUPPORT_DOUBLE=0
int8 SUPPORT_SINGLE_RIGHT=1
int8 SUPPORT_SINGLE_LEFT=2
int8 GET_SUPPORT_STATUS=3

"""
  # Pseudo-constants
  SUPPORT_DOUBLE = 0
  SUPPORT_SINGLE_RIGHT = 1
  SUPPORT_SINGLE_LEFT = 2
  GET_SUPPORT_STATUS = 3

  __slots__ = ['FootSupport_CMD']
  _slot_types = ['int8']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       FootSupport_CMD

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(SupportLegs_StatusRequest, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.FootSupport_CMD is None:
        self.FootSupport_CMD = 0
    else:
      self.FootSupport_CMD = 0

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      buff.write(_struct_b.pack(self.FootSupport_CMD))
    except struct.error as se: self._check_types(se)
    except TypeError as te: self._check_types(te)

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      start = end
      end += 1
      (self.FootSupport_CMD,) = _struct_b.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      buff.write(_struct_b.pack(self.FootSupport_CMD))
    except struct.error as se: self._check_types(se)
    except TypeError as te: self._check_types(te)

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      start = end
      end += 1
      (self.FootSupport_CMD,) = _struct_b.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_b = struct.Struct("<b")
"""autogenerated by genpy from hrl_kinematics/SupportLegs_StatusResponse.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class SupportLegs_StatusResponse(genpy.Message):
  _md5sum = "c12b8a4c6a2a72aae1a78605489ecd8f"
  _type = "hrl_kinematics/SupportLegs_StatusResponse"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """int32 FootSupport_Status



"""
  __slots__ = ['FootSupport_Status']
  _slot_types = ['int32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       FootSupport_Status

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(SupportLegs_StatusResponse, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.FootSupport_Status is None:
        self.FootSupport_Status = 0
    else:
      self.FootSupport_Status = 0

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      buff.write(_struct_i.pack(self.FootSupport_Status))
    except struct.error as se: self._check_types(se)
    except TypeError as te: self._check_types(te)

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      start = end
      end += 4
      (self.FootSupport_Status,) = _struct_i.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      buff.write(_struct_i.pack(self.FootSupport_Status))
    except struct.error as se: self._check_types(se)
    except TypeError as te: self._check_types(te)

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      start = end
      end += 4
      (self.FootSupport_Status,) = _struct_i.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_i = struct.Struct("<i")
class SupportLegs_Status(object):
  _type          = 'hrl_kinematics/SupportLegs_Status'
  _md5sum = 'ec7194f86cdbf88898be0a72e8be6e9f'
  _request_class  = SupportLegs_StatusRequest
  _response_class = SupportLegs_StatusResponse
