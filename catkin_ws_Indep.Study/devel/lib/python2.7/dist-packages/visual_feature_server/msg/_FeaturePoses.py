# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from visual_feature_server/FeaturePoses.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import visual_feature_server.msg
import geometry_msgs.msg
import genpy
import std_msgs.msg

class FeaturePoses(genpy.Message):
  _md5sum = "8329d4cd40eb21004182798fbd3b3cb5"
  _type = "visual_feature_server/FeaturePoses"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """time stamp

FeatureMsg[] features

================================================================================
MSG: visual_feature_server/FeatureMsg
uint8 CORNER=1
uint8 BLOB=2
uint8 EDGE=3
string CORNER_STR="corner"
string BLOB_STR="blob"
string EDGE_STR="edge"

string name
int32 type

float32 image_scale
float32 world_scale

BlobFeatureMsg blobFeature
CornerFeatureMsg cornerFeature
EdgeFeatureMsg edgeFeature

#recognition confidence
float32 confidence
int32 x_pixel
int32 y_pixel

================================================================================
MSG: visual_feature_server/BlobFeatureMsg
uint8 hHigh
uint8 sHigh
uint8 vHigh
uint8 hLow
uint8 sLow
uint8 vLow
#uint8 scale
uint8 threshold

#pose of the feature
geometry_msgs/PoseWithCovarianceStamped centroid
#geometry_msgs/PoseWithCovarianceStamped top_left
#geometry_msgs/PoseWithCovarianceStamped top_right
#geometry_msgs/PoseWithCovarianceStamped bottom_left
#geometry_msgs/PoseWithCovarianceStamped bottom_right

================================================================================
MSG: geometry_msgs/PoseWithCovarianceStamped
# This expresses an estimated pose with a reference coordinate frame and timestamp

Header header
PoseWithCovariance pose

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

================================================================================
MSG: geometry_msgs/PoseWithCovariance
# This represents a pose in free space with uncertainty.

Pose pose

# Row-major representation of the 6x6 covariance matrix
# The orientation parameters use a fixed-axis representation.
# In order, the parameters are:
# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)
float64[36] covariance

================================================================================
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of position and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w

================================================================================
MSG: visual_feature_server/CornerFeatureMsg
uint8 threshold
#uint8 scale

geometry_msgs/PoseWithCovarianceStamped centroid

================================================================================
MSG: visual_feature_server/EdgeFeatureMsg
uint8 threshold
#uint8 scale

# geometry_msgs/PoseWithCovarianceStamped p1
# geometry_msgs/PoseWithCovarianceStamped p2
geometry_msgs/PoseWithCovarianceStamped centroid
"""
  __slots__ = ['stamp','features']
  _slot_types = ['time','visual_feature_server/FeatureMsg[]']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       stamp,features

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(FeaturePoses, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.stamp is None:
        self.stamp = genpy.Time()
      if self.features is None:
        self.features = []
    else:
      self.stamp = genpy.Time()
      self.features = []

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
      buff.write(_get_struct_2I().pack(_x.stamp.secs, _x.stamp.nsecs))
      length = len(self.features)
      buff.write(_struct_I.pack(length))
      for val1 in self.features:
        _x = val1.name
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        _x = val1
        buff.write(_get_struct_i2f().pack(_x.type, _x.image_scale, _x.world_scale))
        _v1 = val1.blobFeature
        _x = _v1
        buff.write(_get_struct_7B().pack(_x.hHigh, _x.sHigh, _x.vHigh, _x.hLow, _x.sLow, _x.vLow, _x.threshold))
        _v2 = _v1.centroid
        _v3 = _v2.header
        buff.write(_get_struct_I().pack(_v3.seq))
        _v4 = _v3.stamp
        _x = _v4
        buff.write(_get_struct_2I().pack(_x.secs, _x.nsecs))
        _x = _v3.frame_id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        _v5 = _v2.pose
        _v6 = _v5.pose
        _v7 = _v6.position
        _x = _v7
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
        _v8 = _v6.orientation
        _x = _v8
        buff.write(_get_struct_4d().pack(_x.x, _x.y, _x.z, _x.w))
        buff.write(_get_struct_36d().pack(*_v5.covariance))
        _v9 = val1.cornerFeature
        buff.write(_get_struct_B().pack(_v9.threshold))
        _v10 = _v9.centroid
        _v11 = _v10.header
        buff.write(_get_struct_I().pack(_v11.seq))
        _v12 = _v11.stamp
        _x = _v12
        buff.write(_get_struct_2I().pack(_x.secs, _x.nsecs))
        _x = _v11.frame_id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        _v13 = _v10.pose
        _v14 = _v13.pose
        _v15 = _v14.position
        _x = _v15
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
        _v16 = _v14.orientation
        _x = _v16
        buff.write(_get_struct_4d().pack(_x.x, _x.y, _x.z, _x.w))
        buff.write(_get_struct_36d().pack(*_v13.covariance))
        _v17 = val1.edgeFeature
        buff.write(_get_struct_B().pack(_v17.threshold))
        _v18 = _v17.centroid
        _v19 = _v18.header
        buff.write(_get_struct_I().pack(_v19.seq))
        _v20 = _v19.stamp
        _x = _v20
        buff.write(_get_struct_2I().pack(_x.secs, _x.nsecs))
        _x = _v19.frame_id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        _v21 = _v18.pose
        _v22 = _v21.pose
        _v23 = _v22.position
        _x = _v23
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
        _v24 = _v22.orientation
        _x = _v24
        buff.write(_get_struct_4d().pack(_x.x, _x.y, _x.z, _x.w))
        buff.write(_get_struct_36d().pack(*_v21.covariance))
        _x = val1
        buff.write(_get_struct_f2i().pack(_x.confidence, _x.x_pixel, _x.y_pixel))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.stamp is None:
        self.stamp = genpy.Time()
      if self.features is None:
        self.features = None
      end = 0
      _x = self
      start = end
      end += 8
      (_x.stamp.secs, _x.stamp.nsecs,) = _get_struct_2I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.features = []
      for i in range(0, length):
        val1 = visual_feature_server.msg.FeatureMsg()
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.name = str[start:end].decode('utf-8')
        else:
          val1.name = str[start:end]
        _x = val1
        start = end
        end += 12
        (_x.type, _x.image_scale, _x.world_scale,) = _get_struct_i2f().unpack(str[start:end])
        _v25 = val1.blobFeature
        _x = _v25
        start = end
        end += 7
        (_x.hHigh, _x.sHigh, _x.vHigh, _x.hLow, _x.sLow, _x.vLow, _x.threshold,) = _get_struct_7B().unpack(str[start:end])
        _v26 = _v25.centroid
        _v27 = _v26.header
        start = end
        end += 4
        (_v27.seq,) = _get_struct_I().unpack(str[start:end])
        _v28 = _v27.stamp
        _x = _v28
        start = end
        end += 8
        (_x.secs, _x.nsecs,) = _get_struct_2I().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          _v27.frame_id = str[start:end].decode('utf-8')
        else:
          _v27.frame_id = str[start:end]
        _v29 = _v26.pose
        _v30 = _v29.pose
        _v31 = _v30.position
        _x = _v31
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        _v32 = _v30.orientation
        _x = _v32
        start = end
        end += 32
        (_x.x, _x.y, _x.z, _x.w,) = _get_struct_4d().unpack(str[start:end])
        start = end
        end += 288
        _v29.covariance = _get_struct_36d().unpack(str[start:end])
        _v33 = val1.cornerFeature
        start = end
        end += 1
        (_v33.threshold,) = _get_struct_B().unpack(str[start:end])
        _v34 = _v33.centroid
        _v35 = _v34.header
        start = end
        end += 4
        (_v35.seq,) = _get_struct_I().unpack(str[start:end])
        _v36 = _v35.stamp
        _x = _v36
        start = end
        end += 8
        (_x.secs, _x.nsecs,) = _get_struct_2I().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          _v35.frame_id = str[start:end].decode('utf-8')
        else:
          _v35.frame_id = str[start:end]
        _v37 = _v34.pose
        _v38 = _v37.pose
        _v39 = _v38.position
        _x = _v39
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        _v40 = _v38.orientation
        _x = _v40
        start = end
        end += 32
        (_x.x, _x.y, _x.z, _x.w,) = _get_struct_4d().unpack(str[start:end])
        start = end
        end += 288
        _v37.covariance = _get_struct_36d().unpack(str[start:end])
        _v41 = val1.edgeFeature
        start = end
        end += 1
        (_v41.threshold,) = _get_struct_B().unpack(str[start:end])
        _v42 = _v41.centroid
        _v43 = _v42.header
        start = end
        end += 4
        (_v43.seq,) = _get_struct_I().unpack(str[start:end])
        _v44 = _v43.stamp
        _x = _v44
        start = end
        end += 8
        (_x.secs, _x.nsecs,) = _get_struct_2I().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          _v43.frame_id = str[start:end].decode('utf-8')
        else:
          _v43.frame_id = str[start:end]
        _v45 = _v42.pose
        _v46 = _v45.pose
        _v47 = _v46.position
        _x = _v47
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        _v48 = _v46.orientation
        _x = _v48
        start = end
        end += 32
        (_x.x, _x.y, _x.z, _x.w,) = _get_struct_4d().unpack(str[start:end])
        start = end
        end += 288
        _v45.covariance = _get_struct_36d().unpack(str[start:end])
        _x = val1
        start = end
        end += 12
        (_x.confidence, _x.x_pixel, _x.y_pixel,) = _get_struct_f2i().unpack(str[start:end])
        self.features.append(val1)
      self.stamp.canon()
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
      buff.write(_get_struct_2I().pack(_x.stamp.secs, _x.stamp.nsecs))
      length = len(self.features)
      buff.write(_struct_I.pack(length))
      for val1 in self.features:
        _x = val1.name
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        _x = val1
        buff.write(_get_struct_i2f().pack(_x.type, _x.image_scale, _x.world_scale))
        _v49 = val1.blobFeature
        _x = _v49
        buff.write(_get_struct_7B().pack(_x.hHigh, _x.sHigh, _x.vHigh, _x.hLow, _x.sLow, _x.vLow, _x.threshold))
        _v50 = _v49.centroid
        _v51 = _v50.header
        buff.write(_get_struct_I().pack(_v51.seq))
        _v52 = _v51.stamp
        _x = _v52
        buff.write(_get_struct_2I().pack(_x.secs, _x.nsecs))
        _x = _v51.frame_id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        _v53 = _v50.pose
        _v54 = _v53.pose
        _v55 = _v54.position
        _x = _v55
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
        _v56 = _v54.orientation
        _x = _v56
        buff.write(_get_struct_4d().pack(_x.x, _x.y, _x.z, _x.w))
        buff.write(_v53.covariance.tostring())
        _v57 = val1.cornerFeature
        buff.write(_get_struct_B().pack(_v57.threshold))
        _v58 = _v57.centroid
        _v59 = _v58.header
        buff.write(_get_struct_I().pack(_v59.seq))
        _v60 = _v59.stamp
        _x = _v60
        buff.write(_get_struct_2I().pack(_x.secs, _x.nsecs))
        _x = _v59.frame_id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        _v61 = _v58.pose
        _v62 = _v61.pose
        _v63 = _v62.position
        _x = _v63
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
        _v64 = _v62.orientation
        _x = _v64
        buff.write(_get_struct_4d().pack(_x.x, _x.y, _x.z, _x.w))
        buff.write(_v61.covariance.tostring())
        _v65 = val1.edgeFeature
        buff.write(_get_struct_B().pack(_v65.threshold))
        _v66 = _v65.centroid
        _v67 = _v66.header
        buff.write(_get_struct_I().pack(_v67.seq))
        _v68 = _v67.stamp
        _x = _v68
        buff.write(_get_struct_2I().pack(_x.secs, _x.nsecs))
        _x = _v67.frame_id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        _v69 = _v66.pose
        _v70 = _v69.pose
        _v71 = _v70.position
        _x = _v71
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
        _v72 = _v70.orientation
        _x = _v72
        buff.write(_get_struct_4d().pack(_x.x, _x.y, _x.z, _x.w))
        buff.write(_v69.covariance.tostring())
        _x = val1
        buff.write(_get_struct_f2i().pack(_x.confidence, _x.x_pixel, _x.y_pixel))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.stamp is None:
        self.stamp = genpy.Time()
      if self.features is None:
        self.features = None
      end = 0
      _x = self
      start = end
      end += 8
      (_x.stamp.secs, _x.stamp.nsecs,) = _get_struct_2I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.features = []
      for i in range(0, length):
        val1 = visual_feature_server.msg.FeatureMsg()
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.name = str[start:end].decode('utf-8')
        else:
          val1.name = str[start:end]
        _x = val1
        start = end
        end += 12
        (_x.type, _x.image_scale, _x.world_scale,) = _get_struct_i2f().unpack(str[start:end])
        _v73 = val1.blobFeature
        _x = _v73
        start = end
        end += 7
        (_x.hHigh, _x.sHigh, _x.vHigh, _x.hLow, _x.sLow, _x.vLow, _x.threshold,) = _get_struct_7B().unpack(str[start:end])
        _v74 = _v73.centroid
        _v75 = _v74.header
        start = end
        end += 4
        (_v75.seq,) = _get_struct_I().unpack(str[start:end])
        _v76 = _v75.stamp
        _x = _v76
        start = end
        end += 8
        (_x.secs, _x.nsecs,) = _get_struct_2I().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          _v75.frame_id = str[start:end].decode('utf-8')
        else:
          _v75.frame_id = str[start:end]
        _v77 = _v74.pose
        _v78 = _v77.pose
        _v79 = _v78.position
        _x = _v79
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        _v80 = _v78.orientation
        _x = _v80
        start = end
        end += 32
        (_x.x, _x.y, _x.z, _x.w,) = _get_struct_4d().unpack(str[start:end])
        start = end
        end += 288
        _v77.covariance = numpy.frombuffer(str[start:end], dtype=numpy.float64, count=36)
        _v81 = val1.cornerFeature
        start = end
        end += 1
        (_v81.threshold,) = _get_struct_B().unpack(str[start:end])
        _v82 = _v81.centroid
        _v83 = _v82.header
        start = end
        end += 4
        (_v83.seq,) = _get_struct_I().unpack(str[start:end])
        _v84 = _v83.stamp
        _x = _v84
        start = end
        end += 8
        (_x.secs, _x.nsecs,) = _get_struct_2I().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          _v83.frame_id = str[start:end].decode('utf-8')
        else:
          _v83.frame_id = str[start:end]
        _v85 = _v82.pose
        _v86 = _v85.pose
        _v87 = _v86.position
        _x = _v87
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        _v88 = _v86.orientation
        _x = _v88
        start = end
        end += 32
        (_x.x, _x.y, _x.z, _x.w,) = _get_struct_4d().unpack(str[start:end])
        start = end
        end += 288
        _v85.covariance = numpy.frombuffer(str[start:end], dtype=numpy.float64, count=36)
        _v89 = val1.edgeFeature
        start = end
        end += 1
        (_v89.threshold,) = _get_struct_B().unpack(str[start:end])
        _v90 = _v89.centroid
        _v91 = _v90.header
        start = end
        end += 4
        (_v91.seq,) = _get_struct_I().unpack(str[start:end])
        _v92 = _v91.stamp
        _x = _v92
        start = end
        end += 8
        (_x.secs, _x.nsecs,) = _get_struct_2I().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          _v91.frame_id = str[start:end].decode('utf-8')
        else:
          _v91.frame_id = str[start:end]
        _v93 = _v90.pose
        _v94 = _v93.pose
        _v95 = _v94.position
        _x = _v95
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        _v96 = _v94.orientation
        _x = _v96
        start = end
        end += 32
        (_x.x, _x.y, _x.z, _x.w,) = _get_struct_4d().unpack(str[start:end])
        start = end
        end += 288
        _v93.covariance = numpy.frombuffer(str[start:end], dtype=numpy.float64, count=36)
        _x = val1
        start = end
        end += 12
        (_x.confidence, _x.x_pixel, _x.y_pixel,) = _get_struct_f2i().unpack(str[start:end])
        self.features.append(val1)
      self.stamp.canon()
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_B = None
def _get_struct_B():
    global _struct_B
    if _struct_B is None:
        _struct_B = struct.Struct("<B")
    return _struct_B
_struct_7B = None
def _get_struct_7B():
    global _struct_7B
    if _struct_7B is None:
        _struct_7B = struct.Struct("<7B")
    return _struct_7B
_struct_36d = None
def _get_struct_36d():
    global _struct_36d
    if _struct_36d is None:
        _struct_36d = struct.Struct("<36d")
    return _struct_36d
_struct_f2i = None
def _get_struct_f2i():
    global _struct_f2i
    if _struct_f2i is None:
        _struct_f2i = struct.Struct("<f2i")
    return _struct_f2i
_struct_4d = None
def _get_struct_4d():
    global _struct_4d
    if _struct_4d is None:
        _struct_4d = struct.Struct("<4d")
    return _struct_4d
_struct_2I = None
def _get_struct_2I():
    global _struct_2I
    if _struct_2I is None:
        _struct_2I = struct.Struct("<2I")
    return _struct_2I
_struct_i2f = None
def _get_struct_i2f():
    global _struct_i2f
    if _struct_i2f is None:
        _struct_i2f = struct.Struct("<i2f")
    return _struct_i2f
_struct_3d = None
def _get_struct_3d():
    global _struct_3d
    if _struct_3d is None:
        _struct_3d = struct.Struct("<3d")
    return _struct_3d
