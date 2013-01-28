"""autogenerated by genpy from C42_DynamicLocomotion/C42_CpgWlkGoal.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import geometry_msgs.msg

class C42_CpgWlkGoal(genpy.Message):
  _md5sum = "1401675520343c88fc779bbdd18e30b8"
  _type = "C42_DynamicLocomotion/C42_CpgWlkGoal"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======
#goal position and orientation
geometry_msgs/Pose2D goal_pos
float64 tol

================================================================================
MSG: geometry_msgs/Pose2D
# This expresses a position and orientation on a 2D manifold.

float64 x
float64 y
float64 theta
"""
  __slots__ = ['goal_pos','tol']
  _slot_types = ['geometry_msgs/Pose2D','float64']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       goal_pos,tol

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(C42_CpgWlkGoal, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.goal_pos is None:
        self.goal_pos = geometry_msgs.msg.Pose2D()
      if self.tol is None:
        self.tol = 0.
    else:
      self.goal_pos = geometry_msgs.msg.Pose2D()
      self.tol = 0.

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
      _x = self
      buff.write(_struct_4d.pack(_x.goal_pos.x, _x.goal_pos.y, _x.goal_pos.theta, _x.tol))
    except struct.error as se: self._check_types(se)
    except TypeError as te: self._check_types(te)

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.goal_pos is None:
        self.goal_pos = geometry_msgs.msg.Pose2D()
      end = 0
      _x = self
      start = end
      end += 32
      (_x.goal_pos.x, _x.goal_pos.y, _x.goal_pos.theta, _x.tol,) = _struct_4d.unpack(str[start:end])
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
      _x = self
      buff.write(_struct_4d.pack(_x.goal_pos.x, _x.goal_pos.y, _x.goal_pos.theta, _x.tol))
    except struct.error as se: self._check_types(se)
    except TypeError as te: self._check_types(te)

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.goal_pos is None:
        self.goal_pos = geometry_msgs.msg.Pose2D()
      end = 0
      _x = self
      start = end
      end += 32
      (_x.goal_pos.x, _x.goal_pos.y, _x.goal_pos.theta, _x.tol,) = _struct_4d.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_4d = struct.Struct("<4d")