/* Auto-generated by genmsg_cpp for file /home/samer/code_release/hitl-slam/vector_slam_msgs/msg/GuiMouseMoveEvent.msg */
#ifndef VECTOR_SLAM_MSGS_MESSAGE_GUIMOUSEMOVEEVENT_H
#define VECTOR_SLAM_MSGS_MESSAGE_GUIMOUSEMOVEEVENT_H
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/time.h"

#include "ros/macros.h"

#include "ros/assert.h"

#include "std_msgs/Header.h"
#include "geometry_msgs/Point32.h"

namespace vector_slam_msgs
{
template <class ContainerAllocator>
struct GuiMouseMoveEvent_ {
  typedef GuiMouseMoveEvent_<ContainerAllocator> Type;

  GuiMouseMoveEvent_()
  : header()
  , location()
  , buttons(0)
  , modifiers(0)
  {
  }

  GuiMouseMoveEvent_(const ContainerAllocator& _alloc)
  : header(_alloc)
  , location(_alloc)
  , buttons(0)
  , modifiers(0)
  {
  }

  typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
   ::std_msgs::Header_<ContainerAllocator>  header;

  typedef  ::geometry_msgs::Point32_<ContainerAllocator>  _location_type;
   ::geometry_msgs::Point32_<ContainerAllocator>  location;

  typedef uint32_t _buttons_type;
  uint32_t buttons;

  typedef uint32_t _modifiers_type;
  uint32_t modifiers;


  typedef boost::shared_ptr< ::vector_slam_msgs::GuiMouseMoveEvent_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::vector_slam_msgs::GuiMouseMoveEvent_<ContainerAllocator>  const> ConstPtr;
}; // struct GuiMouseMoveEvent
typedef  ::vector_slam_msgs::GuiMouseMoveEvent_<std::allocator<void> > GuiMouseMoveEvent;

typedef boost::shared_ptr< ::vector_slam_msgs::GuiMouseMoveEvent> GuiMouseMoveEventPtr;
typedef boost::shared_ptr< ::vector_slam_msgs::GuiMouseMoveEvent const> GuiMouseMoveEventConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::vector_slam_msgs::GuiMouseMoveEvent_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::vector_slam_msgs::GuiMouseMoveEvent_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace vector_slam_msgs

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::vector_slam_msgs::GuiMouseMoveEvent_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::vector_slam_msgs::GuiMouseMoveEvent_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::vector_slam_msgs::GuiMouseMoveEvent_<ContainerAllocator> > {
  static const char* value() 
  {
    return "53a26cd1bb23d1ed61768f55e50f7f84";
  }

  static const char* value(const  ::vector_slam_msgs::GuiMouseMoveEvent_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x53a26cd1bb23d1edULL;
  static const uint64_t static_value2 = 0x61768f55e50f7f84ULL;
};

template<class ContainerAllocator>
struct DataType< ::vector_slam_msgs::GuiMouseMoveEvent_<ContainerAllocator> > {
  static const char* value() 
  {
    return "vector_slam_msgs/GuiMouseMoveEvent";
  }

  static const char* value(const  ::vector_slam_msgs::GuiMouseMoveEvent_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::vector_slam_msgs::GuiMouseMoveEvent_<ContainerAllocator> > {
  static const char* value() 
  {
    return "# Feedback in terms of mouse clicks on the localization GUI.\n\
#\n\
\n\
# Standard header. The frame should normally be \"map\", since the localization\n\
# GUI reports coordinates in the world (map) frame.\n\
std_msgs/Header header\n\
\n\
# The 2D location where the mouse pointer was moved to. The z coordinate of the\n\
# Point32 should be set to 0 by publishers, and ignored by subscribers.\n\
geometry_msgs/Point32 location\n\
\n\
# Binary mask of mouse buttons that were depressed, as enumerated by the\n\
# Qt::MouseButton enumerator. Comon values are:\n\
# 0x00 = No button\n\
# 0x01 = Left button\n\
# 0x02 = Right button\n\
# 0x04 = Middle button\n\
uint32 buttons\n\
\n\
# Binary mask of keyboard modifiers that were active when the mouse event occurred.\n\
# 0x01 = Alt key  modifier\n\
# 0x02 = Ctrl key modifier\n\
# 0x04 = Shift key modifier\n\
uint32 modifiers\n\
\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point32\n\
# This contains the position of a point in free space(with 32 bits of precision).\n\
# It is recommeded to use Point wherever possible instead of Point32.  \n\
# \n\
# This recommendation is to promote interoperability.  \n\
#\n\
# This message is designed to take up less space when sending\n\
# lots of points at once, as in the case of a PointCloud.  \n\
\n\
float32 x\n\
float32 y\n\
float32 z\n\
";
  }

  static const char* value(const  ::vector_slam_msgs::GuiMouseMoveEvent_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct HasHeader< ::vector_slam_msgs::GuiMouseMoveEvent_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct HasHeader< const ::vector_slam_msgs::GuiMouseMoveEvent_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::vector_slam_msgs::GuiMouseMoveEvent_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.header);
    stream.next(m.location);
    stream.next(m.buttons);
    stream.next(m.modifiers);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct GuiMouseMoveEvent_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::vector_slam_msgs::GuiMouseMoveEvent_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::vector_slam_msgs::GuiMouseMoveEvent_<ContainerAllocator> & v) 
  {
    s << indent << "header: ";
s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "location: ";
s << std::endl;
    Printer< ::geometry_msgs::Point32_<ContainerAllocator> >::stream(s, indent + "  ", v.location);
    s << indent << "buttons: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.buttons);
    s << indent << "modifiers: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.modifiers);
  }
};


} // namespace message_operations
} // namespace ros

#endif // VECTOR_SLAM_MSGS_MESSAGE_GUIMOUSEMOVEEVENT_H
