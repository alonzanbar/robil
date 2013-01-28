/* Auto-generated by genmsg_cpp for file /home/darpa/Projects/Robil/C42_DynamicLocomotion/hrl_kinematics/srv/SupportLegs_Status.srv */
#ifndef HRL_KINEMATICS_SERVICE_SUPPORTLEGS_STATUS_H
#define HRL_KINEMATICS_SERVICE_SUPPORTLEGS_STATUS_H
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

#include "ros/service_traits.h"




namespace hrl_kinematics
{
template <class ContainerAllocator>
struct SupportLegs_StatusRequest_ {
  typedef SupportLegs_StatusRequest_<ContainerAllocator> Type;

  SupportLegs_StatusRequest_()
  : FootSupport_CMD(0)
  {
  }

  SupportLegs_StatusRequest_(const ContainerAllocator& _alloc)
  : FootSupport_CMD(0)
  {
  }

  typedef int8_t _FootSupport_CMD_type;
  int8_t FootSupport_CMD;

  enum { SUPPORT_DOUBLE = 0 };
  enum { SUPPORT_SINGLE_RIGHT = 1 };
  enum { SUPPORT_SINGLE_LEFT = 2 };
  enum { GET_SUPPORT_STATUS = 3 };

  typedef boost::shared_ptr< ::hrl_kinematics::SupportLegs_StatusRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::hrl_kinematics::SupportLegs_StatusRequest_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct SupportLegs_StatusRequest
typedef  ::hrl_kinematics::SupportLegs_StatusRequest_<std::allocator<void> > SupportLegs_StatusRequest;

typedef boost::shared_ptr< ::hrl_kinematics::SupportLegs_StatusRequest> SupportLegs_StatusRequestPtr;
typedef boost::shared_ptr< ::hrl_kinematics::SupportLegs_StatusRequest const> SupportLegs_StatusRequestConstPtr;


template <class ContainerAllocator>
struct SupportLegs_StatusResponse_ {
  typedef SupportLegs_StatusResponse_<ContainerAllocator> Type;

  SupportLegs_StatusResponse_()
  : FootSupport_Status(0)
  {
  }

  SupportLegs_StatusResponse_(const ContainerAllocator& _alloc)
  : FootSupport_Status(0)
  {
  }

  typedef int32_t _FootSupport_Status_type;
  int32_t FootSupport_Status;


  typedef boost::shared_ptr< ::hrl_kinematics::SupportLegs_StatusResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::hrl_kinematics::SupportLegs_StatusResponse_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct SupportLegs_StatusResponse
typedef  ::hrl_kinematics::SupportLegs_StatusResponse_<std::allocator<void> > SupportLegs_StatusResponse;

typedef boost::shared_ptr< ::hrl_kinematics::SupportLegs_StatusResponse> SupportLegs_StatusResponsePtr;
typedef boost::shared_ptr< ::hrl_kinematics::SupportLegs_StatusResponse const> SupportLegs_StatusResponseConstPtr;

struct SupportLegs_Status
{

typedef SupportLegs_StatusRequest Request;
typedef SupportLegs_StatusResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;
}; // struct SupportLegs_Status
} // namespace hrl_kinematics

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::hrl_kinematics::SupportLegs_StatusRequest_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::hrl_kinematics::SupportLegs_StatusRequest_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::hrl_kinematics::SupportLegs_StatusRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "64a69a181ef4f43cc29c2c2cd30d9424";
  }

  static const char* value(const  ::hrl_kinematics::SupportLegs_StatusRequest_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x64a69a181ef4f43cULL;
  static const uint64_t static_value2 = 0xc29c2c2cd30d9424ULL;
};

template<class ContainerAllocator>
struct DataType< ::hrl_kinematics::SupportLegs_StatusRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "hrl_kinematics/SupportLegs_StatusRequest";
  }

  static const char* value(const  ::hrl_kinematics::SupportLegs_StatusRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::hrl_kinematics::SupportLegs_StatusRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "\n\
\n\
\n\
\n\
\n\
\n\
\n\
\n\
\n\
\n\
\n\
\n\
\n\
\n\
\n\
\n\
\n\
\n\
\n\
int8 FootSupport_CMD\n\
int8 SUPPORT_DOUBLE=0\n\
int8 SUPPORT_SINGLE_RIGHT=1\n\
int8 SUPPORT_SINGLE_LEFT=2\n\
int8 GET_SUPPORT_STATUS=3\n\
\n\
";
  }

  static const char* value(const  ::hrl_kinematics::SupportLegs_StatusRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct IsFixedSize< ::hrl_kinematics::SupportLegs_StatusRequest_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros


namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::hrl_kinematics::SupportLegs_StatusResponse_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::hrl_kinematics::SupportLegs_StatusResponse_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::hrl_kinematics::SupportLegs_StatusResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "c12b8a4c6a2a72aae1a78605489ecd8f";
  }

  static const char* value(const  ::hrl_kinematics::SupportLegs_StatusResponse_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xc12b8a4c6a2a72aaULL;
  static const uint64_t static_value2 = 0xe1a78605489ecd8fULL;
};

template<class ContainerAllocator>
struct DataType< ::hrl_kinematics::SupportLegs_StatusResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "hrl_kinematics/SupportLegs_StatusResponse";
  }

  static const char* value(const  ::hrl_kinematics::SupportLegs_StatusResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::hrl_kinematics::SupportLegs_StatusResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "int32 FootSupport_Status\n\
\n\
\n\
\n\
";
  }

  static const char* value(const  ::hrl_kinematics::SupportLegs_StatusResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct IsFixedSize< ::hrl_kinematics::SupportLegs_StatusResponse_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::hrl_kinematics::SupportLegs_StatusRequest_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.FootSupport_CMD);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct SupportLegs_StatusRequest_
} // namespace serialization
} // namespace ros


namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::hrl_kinematics::SupportLegs_StatusResponse_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.FootSupport_Status);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct SupportLegs_StatusResponse_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace service_traits
{
template<>
struct MD5Sum<hrl_kinematics::SupportLegs_Status> {
  static const char* value() 
  {
    return "ec7194f86cdbf88898be0a72e8be6e9f";
  }

  static const char* value(const hrl_kinematics::SupportLegs_Status&) { return value(); } 
};

template<>
struct DataType<hrl_kinematics::SupportLegs_Status> {
  static const char* value() 
  {
    return "hrl_kinematics/SupportLegs_Status";
  }

  static const char* value(const hrl_kinematics::SupportLegs_Status&) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<hrl_kinematics::SupportLegs_StatusRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "ec7194f86cdbf88898be0a72e8be6e9f";
  }

  static const char* value(const hrl_kinematics::SupportLegs_StatusRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<hrl_kinematics::SupportLegs_StatusRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "hrl_kinematics/SupportLegs_Status";
  }

  static const char* value(const hrl_kinematics::SupportLegs_StatusRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<hrl_kinematics::SupportLegs_StatusResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "ec7194f86cdbf88898be0a72e8be6e9f";
  }

  static const char* value(const hrl_kinematics::SupportLegs_StatusResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<hrl_kinematics::SupportLegs_StatusResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "hrl_kinematics/SupportLegs_Status";
  }

  static const char* value(const hrl_kinematics::SupportLegs_StatusResponse_<ContainerAllocator> &) { return value(); } 
};

} // namespace service_traits
} // namespace ros

#endif // HRL_KINEMATICS_SERVICE_SUPPORTLEGS_STATUS_H

