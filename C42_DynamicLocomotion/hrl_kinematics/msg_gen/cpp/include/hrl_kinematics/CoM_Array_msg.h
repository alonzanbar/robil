/* Auto-generated by genmsg_cpp for file /home/darpa/Projects/Robil/C42_DynamicLocomotion/hrl_kinematics/msg/CoM_Array_msg.msg */
#ifndef HRL_KINEMATICS_MESSAGE_COM_ARRAY_MSG_H
#define HRL_KINEMATICS_MESSAGE_COM_ARRAY_MSG_H
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

namespace hrl_kinematics
{
template <class ContainerAllocator>
struct CoM_Array_msg_ {
  typedef CoM_Array_msg_<ContainerAllocator> Type;

  CoM_Array_msg_()
  : header()
  , x()
  , y()
  , z()
  {
    x.assign(0.0);
    y.assign(0.0);
    z.assign(0.0);
  }

  CoM_Array_msg_(const ContainerAllocator& _alloc)
  : header(_alloc)
  , x()
  , y()
  , z()
  {
    x.assign(0.0);
    y.assign(0.0);
    z.assign(0.0);
  }

  typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
   ::std_msgs::Header_<ContainerAllocator>  header;

  typedef boost::array<double, 3>  _x_type;
  boost::array<double, 3>  x;

  typedef boost::array<double, 3>  _y_type;
  boost::array<double, 3>  y;

  typedef boost::array<double, 3>  _z_type;
  boost::array<double, 3>  z;


  typedef boost::shared_ptr< ::hrl_kinematics::CoM_Array_msg_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::hrl_kinematics::CoM_Array_msg_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct CoM_Array_msg
typedef  ::hrl_kinematics::CoM_Array_msg_<std::allocator<void> > CoM_Array_msg;

typedef boost::shared_ptr< ::hrl_kinematics::CoM_Array_msg> CoM_Array_msgPtr;
typedef boost::shared_ptr< ::hrl_kinematics::CoM_Array_msg const> CoM_Array_msgConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::hrl_kinematics::CoM_Array_msg_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::hrl_kinematics::CoM_Array_msg_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace hrl_kinematics

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::hrl_kinematics::CoM_Array_msg_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::hrl_kinematics::CoM_Array_msg_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::hrl_kinematics::CoM_Array_msg_<ContainerAllocator> > {
  static const char* value() 
  {
    return "458d6ca638eb99402ee2d03fb6bc79ba";
  }

  static const char* value(const  ::hrl_kinematics::CoM_Array_msg_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x458d6ca638eb9940ULL;
  static const uint64_t static_value2 = 0x2ee2d03fb6bc79baULL;
};

template<class ContainerAllocator>
struct DataType< ::hrl_kinematics::CoM_Array_msg_<ContainerAllocator> > {
  static const char* value() 
  {
    return "hrl_kinematics/CoM_Array_msg";
  }

  static const char* value(const  ::hrl_kinematics::CoM_Array_msg_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::hrl_kinematics::CoM_Array_msg_<ContainerAllocator> > {
  static const char* value() 
  {
    return "# This contains the position of 3 points that indicate the position\n\
# of the Center of Mass in three different frames of coordinates:\n\
# The first (num. 0) gives the CoM position in the root frame (\"pelvis\").\n\
# The second (num. 1) gives the CoM position in the right foot frame (\"r_foot\"). \n\
# The third (num. 2) gives the CoM position in the left foot frame (\"l_foot\").\n\
\n\
# geometry_msgs/Point root\n\
# geometry_msgs/Point Rfoot\n\
# geometry_msgs/Point Lfoot\n\
\n\
Header header\n\
\n\
float64[3] x \n\
float64[3] y\n\
float64[3] z\n\
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
# * stamp.secs: seconds (stamp_secs) since epoch\n\
# * stamp.nsecs: nanoseconds since stamp_secs\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
";
  }

  static const char* value(const  ::hrl_kinematics::CoM_Array_msg_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct HasHeader< ::hrl_kinematics::CoM_Array_msg_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct HasHeader< const ::hrl_kinematics::CoM_Array_msg_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::hrl_kinematics::CoM_Array_msg_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.header);
    stream.next(m.x);
    stream.next(m.y);
    stream.next(m.z);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct CoM_Array_msg_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::hrl_kinematics::CoM_Array_msg_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::hrl_kinematics::CoM_Array_msg_<ContainerAllocator> & v) 
  {
    s << indent << "header: ";
s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "x[]" << std::endl;
    for (size_t i = 0; i < v.x.size(); ++i)
    {
      s << indent << "  x[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.x[i]);
    }
    s << indent << "y[]" << std::endl;
    for (size_t i = 0; i < v.y.size(); ++i)
    {
      s << indent << "  y[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.y[i]);
    }
    s << indent << "z[]" << std::endl;
    for (size_t i = 0; i < v.z.size(); ++i)
    {
      s << indent << "  z[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.z[i]);
    }
  }
};


} // namespace message_operations
} // namespace ros

#endif // HRL_KINEMATICS_MESSAGE_COM_ARRAY_MSG_H

