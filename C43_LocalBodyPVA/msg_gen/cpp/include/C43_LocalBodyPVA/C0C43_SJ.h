/* Auto-generated by genmsg_cpp for file /home/ariy/robil/C43_LocalBodyPVA/msg/C0C43_SJ.msg */
#ifndef C43_LOCALBODYPVA_MESSAGE_C0C43_SJ_H
#define C43_LOCALBODYPVA_MESSAGE_C0C43_SJ_H
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


namespace C43_LocalBodyPVA
{
template <class ContainerAllocator>
struct C0C43_SJ_ {
  typedef C0C43_SJ_<ContainerAllocator> Type;

  C0C43_SJ_()
  : Selected_Joint()
  {
  }

  C0C43_SJ_(const ContainerAllocator& _alloc)
  : Selected_Joint(_alloc)
  {
  }

  typedef std::vector<int32_t, typename ContainerAllocator::template rebind<int32_t>::other >  _Selected_Joint_type;
  std::vector<int32_t, typename ContainerAllocator::template rebind<int32_t>::other >  Selected_Joint;


  typedef boost::shared_ptr< ::C43_LocalBodyPVA::C0C43_SJ_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::C43_LocalBodyPVA::C0C43_SJ_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct C0C43_SJ
typedef  ::C43_LocalBodyPVA::C0C43_SJ_<std::allocator<void> > C0C43_SJ;

typedef boost::shared_ptr< ::C43_LocalBodyPVA::C0C43_SJ> C0C43_SJPtr;
typedef boost::shared_ptr< ::C43_LocalBodyPVA::C0C43_SJ const> C0C43_SJConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::C43_LocalBodyPVA::C0C43_SJ_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::C43_LocalBodyPVA::C0C43_SJ_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace C43_LocalBodyPVA

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::C43_LocalBodyPVA::C0C43_SJ_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::C43_LocalBodyPVA::C0C43_SJ_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::C43_LocalBodyPVA::C0C43_SJ_<ContainerAllocator> > {
  static const char* value() 
  {
    return "753b4c5f2595b51e063f633ee73a0454";
  }

  static const char* value(const  ::C43_LocalBodyPVA::C0C43_SJ_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x753b4c5f2595b51eULL;
  static const uint64_t static_value2 = 0x063f633ee73a0454ULL;
};

template<class ContainerAllocator>
struct DataType< ::C43_LocalBodyPVA::C0C43_SJ_<ContainerAllocator> > {
  static const char* value() 
  {
    return "C43_LocalBodyPVA/C0C43_SJ";
  }

  static const char* value(const  ::C43_LocalBodyPVA::C0C43_SJ_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::C43_LocalBodyPVA::C0C43_SJ_<ContainerAllocator> > {
  static const char* value() 
  {
    return "int32[] Selected_Joint\n\
\n\
";
  }

  static const char* value(const  ::C43_LocalBodyPVA::C0C43_SJ_<ContainerAllocator> &) { return value(); } 
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::C43_LocalBodyPVA::C0C43_SJ_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.Selected_Joint);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct C0C43_SJ_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::C43_LocalBodyPVA::C0C43_SJ_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::C43_LocalBodyPVA::C0C43_SJ_<ContainerAllocator> & v) 
  {
    s << indent << "Selected_Joint[]" << std::endl;
    for (size_t i = 0; i < v.Selected_Joint.size(); ++i)
    {
      s << indent << "  Selected_Joint[" << i << "]: ";
      Printer<int32_t>::stream(s, indent + "  ", v.Selected_Joint[i]);
    }
  }
};


} // namespace message_operations
} // namespace ros

#endif // C43_LOCALBODYPVA_MESSAGE_C0C43_SJ_H

