/* Auto-generated by genmsg_cpp for file /home/lab116/git2/robil/C45_PostureControl/msg/PostureControlFeedback.msg */
#ifndef C45_POSTURECONTROL_MESSAGE_POSTURECONTROLFEEDBACK_H
#define C45_POSTURECONTROL_MESSAGE_POSTURECONTROLFEEDBACK_H
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
struct PostureControlFeedback_ {
  typedef PostureControlFeedback_<ContainerAllocator> Type;

  PostureControlFeedback_()
  : PostureQuality()
  {
  }

  PostureControlFeedback_(const ContainerAllocator& _alloc)
  : PostureQuality(_alloc)
  {
  }

  typedef std::vector<int32_t, typename ContainerAllocator::template rebind<int32_t>::other >  _PostureQuality_type;
  std::vector<int32_t, typename ContainerAllocator::template rebind<int32_t>::other >  PostureQuality;


  typedef boost::shared_ptr< ::C45_PostureControl::PostureControlFeedback_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::C45_PostureControl::PostureControlFeedback_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct PostureControlFeedback
typedef  ::C45_PostureControl::PostureControlFeedback_<std::allocator<void> > PostureControlFeedback;

typedef boost::shared_ptr< ::C45_PostureControl::PostureControlFeedback> PostureControlFeedbackPtr;
typedef boost::shared_ptr< ::C45_PostureControl::PostureControlFeedback const> PostureControlFeedbackConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::C45_PostureControl::PostureControlFeedback_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::C45_PostureControl::PostureControlFeedback_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace C45_PostureControl

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::C45_PostureControl::PostureControlFeedback_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::C45_PostureControl::PostureControlFeedback_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::C45_PostureControl::PostureControlFeedback_<ContainerAllocator> > {
  static const char* value() 
  {
    return "4a0150643e522e09a805398bb01eedab";
  }

  static const char* value(const  ::C45_PostureControl::PostureControlFeedback_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x4a0150643e522e09ULL;
  static const uint64_t static_value2 = 0xa805398bb01eedabULL;
};

template<class ContainerAllocator>
struct DataType< ::C45_PostureControl::PostureControlFeedback_<ContainerAllocator> > {
  static const char* value() 
  {
    return "C45_PostureControl/PostureControlFeedback";
  }

  static const char* value(const  ::C45_PostureControl::PostureControlFeedback_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::C45_PostureControl::PostureControlFeedback_<ContainerAllocator> > {
  static const char* value() 
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
#feedback\n\
int32[] PostureQuality\n\
\n\
\n\
";
  }

  static const char* value(const  ::C45_PostureControl::PostureControlFeedback_<ContainerAllocator> &) { return value(); } 
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::C45_PostureControl::PostureControlFeedback_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.PostureQuality);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct PostureControlFeedback_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::C45_PostureControl::PostureControlFeedback_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::C45_PostureControl::PostureControlFeedback_<ContainerAllocator> & v) 
  {
    s << indent << "PostureQuality[]" << std::endl;
    for (size_t i = 0; i < v.PostureQuality.size(); ++i)
    {
      s << indent << "  PostureQuality[" << i << "]: ";
      Printer<int32_t>::stream(s, indent + "  ", v.PostureQuality[i]);
    }
  }
};


} // namespace message_operations
} // namespace ros

#endif // C45_POSTURECONTROL_MESSAGE_POSTURECONTROLFEEDBACK_H
