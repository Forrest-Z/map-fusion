/* Auto-generated by genmsg_cpp for file /home/samer/code_release/hitl-slam/vector_slam_msgs/msg/LocalizationMsg.msg */
#ifndef VECTOR_SLAM_MSGS_MESSAGE_LOCALIZATIONMSG_H
#define VECTOR_SLAM_MSGS_MESSAGE_LOCALIZATIONMSG_H
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

#include "geometry_msgs/Vector3.h"

namespace vector_slam_msgs
{
template <class ContainerAllocator>
struct LocalizationMsg_ {
  typedef LocalizationMsg_<ContainerAllocator> Type;

  LocalizationMsg_()
  : map_name()
  , location()
  , angle(0.0)
  {
  }

  LocalizationMsg_(const ContainerAllocator& _alloc)
  : map_name(_alloc)
  , location(_alloc)
  , angle(0.0)
  {
  }

  typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _map_name_type;
  std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  map_name;

  typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _location_type;
   ::geometry_msgs::Vector3_<ContainerAllocator>  location;

  typedef float _angle_type;
  float angle;


  typedef boost::shared_ptr< ::vector_slam_msgs::LocalizationMsg_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::vector_slam_msgs::LocalizationMsg_<ContainerAllocator>  const> ConstPtr;
}; // struct LocalizationMsg
typedef  ::vector_slam_msgs::LocalizationMsg_<std::allocator<void> > LocalizationMsg;

typedef boost::shared_ptr< ::vector_slam_msgs::LocalizationMsg> LocalizationMsgPtr;
typedef boost::shared_ptr< ::vector_slam_msgs::LocalizationMsg const> LocalizationMsgConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::vector_slam_msgs::LocalizationMsg_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::vector_slam_msgs::LocalizationMsg_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace vector_slam_msgs

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::vector_slam_msgs::LocalizationMsg_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::vector_slam_msgs::LocalizationMsg_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::vector_slam_msgs::LocalizationMsg_<ContainerAllocator> > {
  static const char* value() 
  {
    return "d97acce230cd4cd8961fb0e1730022b9";
  }

  static const char* value(const  ::vector_slam_msgs::LocalizationMsg_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xd97acce230cd4cd8ULL;
  static const uint64_t static_value2 = 0x961fb0e1730022b9ULL;
};

template<class ContainerAllocator>
struct DataType< ::vector_slam_msgs::LocalizationMsg_<ContainerAllocator> > {
  static const char* value() 
  {
    return "vector_slam_msgs/LocalizationMsg";
  }

  static const char* value(const  ::vector_slam_msgs::LocalizationMsg_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::vector_slam_msgs::LocalizationMsg_<ContainerAllocator> > {
  static const char* value() 
  {
    return "string map_name\n\
geometry_msgs/Vector3 location\n\
float32 angle\n\
\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Vector3\n\
# This represents a vector in free space. \n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
";
  }

  static const char* value(const  ::vector_slam_msgs::LocalizationMsg_<ContainerAllocator> &) { return value(); } 
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::vector_slam_msgs::LocalizationMsg_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.map_name);
    stream.next(m.location);
    stream.next(m.angle);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct LocalizationMsg_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::vector_slam_msgs::LocalizationMsg_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::vector_slam_msgs::LocalizationMsg_<ContainerAllocator> & v) 
  {
    s << indent << "map_name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.map_name);
    s << indent << "location: ";
s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.location);
    s << indent << "angle: ";
    Printer<float>::stream(s, indent + "  ", v.angle);
  }
};


} // namespace message_operations
} // namespace ros

#endif // VECTOR_SLAM_MSGS_MESSAGE_LOCALIZATIONMSG_H
