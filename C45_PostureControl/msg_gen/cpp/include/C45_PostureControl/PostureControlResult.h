/* Auto-generated by genmsg_cpp for file /home/lab116/git2/robil/C45_PostureControl/msg/PostureControlResult.msg */
#ifndef C45_POSTURECONTROL_MESSAGE_POSTURECONTROLRESULT_H
#define C45_POSTURECONTROL_MESSAGE_POSTURECONTROLRESULT_H
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


namespace C45_PostureControl
{
template <class ContainerAllocator>
struct PostureControlResult_ {
  typedef PostureControlResult_<ContainerAllocator> Type;

  PostureControlResult_()
  : success(false)
  {
  }

  PostureControlResult_(const ContainerAllocator& _alloc)
  : success(false)
  {
  }

  typedef uint8_t _success_type;
  uint8_t success;


  typedef boost::shared_ptr< ::C45_PostureControl::PostureControlResult_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::C45_PostureControl::PostureControlResult_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct PostureControlResult
typedef  ::C45_PostureControl::PostureControlResult_<std::allocator<void> > PostureControlResult;

typedef boost::shared_ptr< ::C45_PostureControl::PostureControlResult> PostureControlResultPtr;
typedef boost::shared_ptr< ::C45_PostureControl::PostureControlResult const> PostureControlResultConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::C45_PostureControl::PostureControlResult_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::C45_PostureControl::PostureControlResult_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace C45_PostureControl

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::C45_PostureControl::PostureControlResult_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::C45_PostureControl::PostureControlResult_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::C45_PostureControl::PostureControlResult_<ContainerAllocator> > {
  static const char* value() 
  {
    return "358e233cde0c8a8bcfea4ce193f8fc15";
  }

  static const char* value(const  ::C45_PostureControl::PostureControlResult_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x358e233cde0c8a8bULL;
  static const uint64_t static_value2 = 0xcfea4ce193f8fc15ULL;
};

template<class ContainerAllocator>
struct DataType< ::C45_PostureControl::PostureControlResult_<ContainerAllocator> > {
  static const char* value() 
  {
    return "C45_PostureControl/PostureControlResult";
  }

  static const char* value(const  ::C45_PostureControl::PostureControlResult_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::C45_PostureControl::PostureControlResult_<ContainerAllocator> > {
  static const char* value() 
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
#result definition\n\
bool success\n\
\n\
";
  }

  static const char* value(const  ::C45_PostureControl::PostureControlResult_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct IsFixedSize< ::C45_PostureControl::PostureControlResult_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::C45_PostureControl::PostureControlResult_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.success);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct PostureControlResult_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::C45_PostureControl::PostureControlResult_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::C45_PostureControl::PostureControlResult_<ContainerAllocator> & v) 
  {
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
  }
};


} // namespace message_operations
} // namespace ros

#endif // C45_POSTURECONTROL_MESSAGE_POSTURECONTROLRESULT_H
