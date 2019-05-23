// Generated by gencpp from file project/odom.msg
// DO NOT EDIT!


#ifndef PROJECT_MESSAGE_ODOM_H
#define PROJECT_MESSAGE_ODOM_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace project
{
template <class ContainerAllocator>
struct odom_
{
  typedef odom_<ContainerAllocator> Type;

  odom_()
    : x_value(0.0)
    , y_value(0.0)
    , theta(0.0)  {
    }
  odom_(const ContainerAllocator& _alloc)
    : x_value(0.0)
    , y_value(0.0)
    , theta(0.0)  {
  (void)_alloc;
    }



   typedef double _x_value_type;
  _x_value_type x_value;

   typedef double _y_value_type;
  _y_value_type y_value;

   typedef double _theta_type;
  _theta_type theta;





  typedef boost::shared_ptr< ::project::odom_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::project::odom_<ContainerAllocator> const> ConstPtr;

}; // struct odom_

typedef ::project::odom_<std::allocator<void> > odom;

typedef boost::shared_ptr< ::project::odom > odomPtr;
typedef boost::shared_ptr< ::project::odom const> odomConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::project::odom_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::project::odom_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace project

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'project': ['/home/zommi/Desktop/robotics-project-2019/src/project/msg'], 'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::project::odom_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::project::odom_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::project::odom_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::project::odom_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::project::odom_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::project::odom_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::project::odom_<ContainerAllocator> >
{
  static const char* value()
  {
    return "8759f9f7c1bf1b646c210b6a32c081e4";
  }

  static const char* value(const ::project::odom_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x8759f9f7c1bf1b64ULL;
  static const uint64_t static_value2 = 0x6c210b6a32c081e4ULL;
};

template<class ContainerAllocator>
struct DataType< ::project::odom_<ContainerAllocator> >
{
  static const char* value()
  {
    return "project/odom";
  }

  static const char* value(const ::project::odom_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::project::odom_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 x_value\n"
"float64 y_value\n"
"float64 theta\n"
;
  }

  static const char* value(const ::project::odom_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::project::odom_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.x_value);
      stream.next(m.y_value);
      stream.next(m.theta);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct odom_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::project::odom_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::project::odom_<ContainerAllocator>& v)
  {
    s << indent << "x_value: ";
    Printer<double>::stream(s, indent + "  ", v.x_value);
    s << indent << "y_value: ";
    Printer<double>::stream(s, indent + "  ", v.y_value);
    s << indent << "theta: ";
    Printer<double>::stream(s, indent + "  ", v.theta);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PROJECT_MESSAGE_ODOM_H