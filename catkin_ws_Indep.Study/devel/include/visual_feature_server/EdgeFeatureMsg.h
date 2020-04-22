// Generated by gencpp from file visual_feature_server/EdgeFeatureMsg.msg
// DO NOT EDIT!


#ifndef VISUAL_FEATURE_SERVER_MESSAGE_EDGEFEATUREMSG_H
#define VISUAL_FEATURE_SERVER_MESSAGE_EDGEFEATUREMSG_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/PoseWithCovarianceStamped.h>

namespace visual_feature_server
{
template <class ContainerAllocator>
struct EdgeFeatureMsg_
{
  typedef EdgeFeatureMsg_<ContainerAllocator> Type;

  EdgeFeatureMsg_()
    : threshold(0)
    , centroid()  {
    }
  EdgeFeatureMsg_(const ContainerAllocator& _alloc)
    : threshold(0)
    , centroid(_alloc)  {
  (void)_alloc;
    }



   typedef uint8_t _threshold_type;
  _threshold_type threshold;

   typedef  ::geometry_msgs::PoseWithCovarianceStamped_<ContainerAllocator>  _centroid_type;
  _centroid_type centroid;





  typedef boost::shared_ptr< ::visual_feature_server::EdgeFeatureMsg_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::visual_feature_server::EdgeFeatureMsg_<ContainerAllocator> const> ConstPtr;

}; // struct EdgeFeatureMsg_

typedef ::visual_feature_server::EdgeFeatureMsg_<std::allocator<void> > EdgeFeatureMsg;

typedef boost::shared_ptr< ::visual_feature_server::EdgeFeatureMsg > EdgeFeatureMsgPtr;
typedef boost::shared_ptr< ::visual_feature_server::EdgeFeatureMsg const> EdgeFeatureMsgConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::visual_feature_server::EdgeFeatureMsg_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::visual_feature_server::EdgeFeatureMsg_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::visual_feature_server::EdgeFeatureMsg_<ContainerAllocator1> & lhs, const ::visual_feature_server::EdgeFeatureMsg_<ContainerAllocator2> & rhs)
{
  return lhs.threshold == rhs.threshold &&
    lhs.centroid == rhs.centroid;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::visual_feature_server::EdgeFeatureMsg_<ContainerAllocator1> & lhs, const ::visual_feature_server::EdgeFeatureMsg_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace visual_feature_server

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::visual_feature_server::EdgeFeatureMsg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::visual_feature_server::EdgeFeatureMsg_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::visual_feature_server::EdgeFeatureMsg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::visual_feature_server::EdgeFeatureMsg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::visual_feature_server::EdgeFeatureMsg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::visual_feature_server::EdgeFeatureMsg_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::visual_feature_server::EdgeFeatureMsg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "f86d11aa7264d820fbf8de0199829dfe";
  }

  static const char* value(const ::visual_feature_server::EdgeFeatureMsg_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf86d11aa7264d820ULL;
  static const uint64_t static_value2 = 0xfbf8de0199829dfeULL;
};

template<class ContainerAllocator>
struct DataType< ::visual_feature_server::EdgeFeatureMsg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "visual_feature_server/EdgeFeatureMsg";
  }

  static const char* value(const ::visual_feature_server::EdgeFeatureMsg_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::visual_feature_server::EdgeFeatureMsg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint8 threshold\n"
"#uint8 scale\n"
"\n"
"# geometry_msgs/PoseWithCovarianceStamped p1\n"
"# geometry_msgs/PoseWithCovarianceStamped p2\n"
"geometry_msgs/PoseWithCovarianceStamped centroid\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/PoseWithCovarianceStamped\n"
"# This expresses an estimated pose with a reference coordinate frame and timestamp\n"
"\n"
"Header header\n"
"PoseWithCovariance pose\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/PoseWithCovariance\n"
"# This represents a pose in free space with uncertainty.\n"
"\n"
"Pose pose\n"
"\n"
"# Row-major representation of the 6x6 covariance matrix\n"
"# The orientation parameters use a fixed-axis representation.\n"
"# In order, the parameters are:\n"
"# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)\n"
"float64[36] covariance\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Pose\n"
"# A representation of pose in free space, composed of position and orientation. \n"
"Point position\n"
"Quaternion orientation\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Point\n"
"# This contains the position of a point in free space\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Quaternion\n"
"# This represents an orientation in free space in quaternion form.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"float64 w\n"
;
  }

  static const char* value(const ::visual_feature_server::EdgeFeatureMsg_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::visual_feature_server::EdgeFeatureMsg_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.threshold);
      stream.next(m.centroid);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct EdgeFeatureMsg_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::visual_feature_server::EdgeFeatureMsg_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::visual_feature_server::EdgeFeatureMsg_<ContainerAllocator>& v)
  {
    s << indent << "threshold: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.threshold);
    s << indent << "centroid: ";
    s << std::endl;
    Printer< ::geometry_msgs::PoseWithCovarianceStamped_<ContainerAllocator> >::stream(s, indent + "  ", v.centroid);
  }
};

} // namespace message_operations
} // namespace ros

#endif // VISUAL_FEATURE_SERVER_MESSAGE_EDGEFEATUREMSG_H
