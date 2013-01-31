"""autogenerated by genpy from C31_PathPlanner/C31_Constraints.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import C31_PathPlanner.msg

class C31_Constraints(genpy.Message):
  _md5sum = "644055951022a4ce9d1bc139bc4b5e01"
  _type = "C31_PathPlanner/C31_Constraints"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """C31_PathPlanner/C31_RobotDimension robot
C31_PathPlanner/C31_Waypoints transits
C31_PathPlanner/C31_Charge[] attractors
C31_PathPlanner/C31_Charge[] repulsors
C31_PathPlanner/C31_Corridor corridor

================================================================================
MSG: C31_PathPlanner/C31_RobotDimension
float64 size
================================================================================
MSG: C31_PathPlanner/C31_Waypoints
C31_PathPlanner/C31_Location[] points
================================================================================
MSG: C31_PathPlanner/C31_Location
float64 x
float64 y
================================================================================
MSG: C31_PathPlanner/C31_Charge
C31_PathPlanner/C31_Location location
float64 power
uint32 type

================================================================================
MSG: C31_PathPlanner/C31_Corridor
float64 width
C31_PathPlanner/C31_Waypoints path
"""
  __slots__ = ['robot','transits','attractors','repulsors','corridor']
  _slot_types = ['C31_PathPlanner/C31_RobotDimension','C31_PathPlanner/C31_Waypoints','C31_PathPlanner/C31_Charge[]','C31_PathPlanner/C31_Charge[]','C31_PathPlanner/C31_Corridor']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       robot,transits,attractors,repulsors,corridor

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(C31_Constraints, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.robot is None:
        self.robot = C31_PathPlanner.msg.C31_RobotDimension()
      if self.transits is None:
        self.transits = C31_PathPlanner.msg.C31_Waypoints()
      if self.attractors is None:
        self.attractors = []
      if self.repulsors is None:
        self.repulsors = []
      if self.corridor is None:
        self.corridor = C31_PathPlanner.msg.C31_Corridor()
    else:
      self.robot = C31_PathPlanner.msg.C31_RobotDimension()
      self.transits = C31_PathPlanner.msg.C31_Waypoints()
      self.attractors = []
      self.repulsors = []
      self.corridor = C31_PathPlanner.msg.C31_Corridor()

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
      buff.write(_struct_d.pack(self.robot.size))
      length = len(self.transits.points)
      buff.write(_struct_I.pack(length))
      for val1 in self.transits.points:
        _x = val1
        buff.write(_struct_2d.pack(_x.x, _x.y))
      length = len(self.attractors)
      buff.write(_struct_I.pack(length))
      for val1 in self.attractors:
        _v1 = val1.location
        _x = _v1
        buff.write(_struct_2d.pack(_x.x, _x.y))
        _x = val1
        buff.write(_struct_dI.pack(_x.power, _x.type))
      length = len(self.repulsors)
      buff.write(_struct_I.pack(length))
      for val1 in self.repulsors:
        _v2 = val1.location
        _x = _v2
        buff.write(_struct_2d.pack(_x.x, _x.y))
        _x = val1
        buff.write(_struct_dI.pack(_x.power, _x.type))
      buff.write(_struct_d.pack(self.corridor.width))
      length = len(self.corridor.path.points)
      buff.write(_struct_I.pack(length))
      for val1 in self.corridor.path.points:
        _x = val1
        buff.write(_struct_2d.pack(_x.x, _x.y))
    except struct.error as se: self._check_types(se)
    except TypeError as te: self._check_types(te)

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.robot is None:
        self.robot = C31_PathPlanner.msg.C31_RobotDimension()
      if self.transits is None:
        self.transits = C31_PathPlanner.msg.C31_Waypoints()
      if self.attractors is None:
        self.attractors = None
      if self.repulsors is None:
        self.repulsors = None
      if self.corridor is None:
        self.corridor = C31_PathPlanner.msg.C31_Corridor()
      end = 0
      start = end
      end += 8
      (self.robot.size,) = _struct_d.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.transits.points = []
      for i in range(0, length):
        val1 = C31_PathPlanner.msg.C31_Location()
        _x = val1
        start = end
        end += 16
        (_x.x, _x.y,) = _struct_2d.unpack(str[start:end])
        self.transits.points.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.attractors = []
      for i in range(0, length):
        val1 = C31_PathPlanner.msg.C31_Charge()
        _v3 = val1.location
        _x = _v3
        start = end
        end += 16
        (_x.x, _x.y,) = _struct_2d.unpack(str[start:end])
        _x = val1
        start = end
        end += 12
        (_x.power, _x.type,) = _struct_dI.unpack(str[start:end])
        self.attractors.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.repulsors = []
      for i in range(0, length):
        val1 = C31_PathPlanner.msg.C31_Charge()
        _v4 = val1.location
        _x = _v4
        start = end
        end += 16
        (_x.x, _x.y,) = _struct_2d.unpack(str[start:end])
        _x = val1
        start = end
        end += 12
        (_x.power, _x.type,) = _struct_dI.unpack(str[start:end])
        self.repulsors.append(val1)
      start = end
      end += 8
      (self.corridor.width,) = _struct_d.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.corridor.path.points = []
      for i in range(0, length):
        val1 = C31_PathPlanner.msg.C31_Location()
        _x = val1
        start = end
        end += 16
        (_x.x, _x.y,) = _struct_2d.unpack(str[start:end])
        self.corridor.path.points.append(val1)
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
      buff.write(_struct_d.pack(self.robot.size))
      length = len(self.transits.points)
      buff.write(_struct_I.pack(length))
      for val1 in self.transits.points:
        _x = val1
        buff.write(_struct_2d.pack(_x.x, _x.y))
      length = len(self.attractors)
      buff.write(_struct_I.pack(length))
      for val1 in self.attractors:
        _v5 = val1.location
        _x = _v5
        buff.write(_struct_2d.pack(_x.x, _x.y))
        _x = val1
        buff.write(_struct_dI.pack(_x.power, _x.type))
      length = len(self.repulsors)
      buff.write(_struct_I.pack(length))
      for val1 in self.repulsors:
        _v6 = val1.location
        _x = _v6
        buff.write(_struct_2d.pack(_x.x, _x.y))
        _x = val1
        buff.write(_struct_dI.pack(_x.power, _x.type))
      buff.write(_struct_d.pack(self.corridor.width))
      length = len(self.corridor.path.points)
      buff.write(_struct_I.pack(length))
      for val1 in self.corridor.path.points:
        _x = val1
        buff.write(_struct_2d.pack(_x.x, _x.y))
    except struct.error as se: self._check_types(se)
    except TypeError as te: self._check_types(te)

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.robot is None:
        self.robot = C31_PathPlanner.msg.C31_RobotDimension()
      if self.transits is None:
        self.transits = C31_PathPlanner.msg.C31_Waypoints()
      if self.attractors is None:
        self.attractors = None
      if self.repulsors is None:
        self.repulsors = None
      if self.corridor is None:
        self.corridor = C31_PathPlanner.msg.C31_Corridor()
      end = 0
      start = end
      end += 8
      (self.robot.size,) = _struct_d.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.transits.points = []
      for i in range(0, length):
        val1 = C31_PathPlanner.msg.C31_Location()
        _x = val1
        start = end
        end += 16
        (_x.x, _x.y,) = _struct_2d.unpack(str[start:end])
        self.transits.points.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.attractors = []
      for i in range(0, length):
        val1 = C31_PathPlanner.msg.C31_Charge()
        _v7 = val1.location
        _x = _v7
        start = end
        end += 16
        (_x.x, _x.y,) = _struct_2d.unpack(str[start:end])
        _x = val1
        start = end
        end += 12
        (_x.power, _x.type,) = _struct_dI.unpack(str[start:end])
        self.attractors.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.repulsors = []
      for i in range(0, length):
        val1 = C31_PathPlanner.msg.C31_Charge()
        _v8 = val1.location
        _x = _v8
        start = end
        end += 16
        (_x.x, _x.y,) = _struct_2d.unpack(str[start:end])
        _x = val1
        start = end
        end += 12
        (_x.power, _x.type,) = _struct_dI.unpack(str[start:end])
        self.repulsors.append(val1)
      start = end
      end += 8
      (self.corridor.width,) = _struct_d.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.corridor.path.points = []
      for i in range(0, length):
        val1 = C31_PathPlanner.msg.C31_Location()
        _x = val1
        start = end
        end += 16
        (_x.x, _x.y,) = _struct_2d.unpack(str[start:end])
        self.corridor.path.points.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_2d = struct.Struct("<2d")
_struct_d = struct.Struct("<d")
_struct_dI = struct.Struct("<dI")