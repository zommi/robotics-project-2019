// Generated by gencpp from file project/floatStamped.msg
// DO NOT EDIT!


#ifndef PROJECT_MESSAGE_FLOATSTAMPED_H
#define PROJECT_MESSAGE_FLOATSTAMPED_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace project
{
template <class ContainerAllocator>
struct floatStamped_
{
  typedef floatStamped_<ContainerAllocator> Type;

  floatStamped_()
    : header()
    , data(0.0)  {
    }
  floatStamped_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , data(0.0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef double _data_type;
  _data_type data;





  typedef boost::shared_ptr< ::project::floatStamped_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::project::floatStamped_<ContainerAllocator> const> ConstPtr;

}; // struct floatStamped_

typedef ::project::floatStamped_<std::allocator<void> > floatStamped;

typedef boost::shared_ptr< ::project::floatStamped > floatStampedPtr;
typedef boost::shared_ptr< ::project::floatStamped const> floatStampedConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::project::floatStamped_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::project::floatStamped_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace project

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'project': ['/home/zommi/Desktop/robotics-project-2019/src/project/msg'], 'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::project::floatStamped_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::project::floatStamped_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::project::floatStamped_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::project::floatStamped_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::project::floatStamped_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::project::floatStamped_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::project::floatStamped_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e6c99c37e6f9fe98e071d524cc164e65";
  }

  static const char* value(const ::project::floatStamped_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe6c99c37e6f9fe98ULL;
  static const uint64_t static_value2 = 0xe071d524cc164e65ULL;
};

template<class ContainerAllocator>
struct DataType< ::project::floatStamped_<ContainerAllocator> >
{
  static const char* value()
  {
    return "project/floatStamped";
  }

  static const char* value(const ::project::floatStamped_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::project::floatStamped_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n"
"float64 data\n"
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
;
  }

  static const char* value(const ::project::floatStamped_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::project::floatStamped_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.data);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct floatStamped_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::project::floatStamped_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::project::floatStamped_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "data: ";
    Printer<double>::stream(s, indent + "  ", v.data);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PROJECT_MESSAGE_FLOATSTAMPED_H
