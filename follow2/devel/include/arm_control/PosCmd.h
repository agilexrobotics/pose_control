// Generated by gencpp from file arm_control/PosCmd.msg
// DO NOT EDIT!


#ifndef ARM_CONTROL_MESSAGE_POSCMD_H
#define ARM_CONTROL_MESSAGE_POSCMD_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace arm_control
{
template <class ContainerAllocator>
struct PosCmd_
{
  typedef PosCmd_<ContainerAllocator> Type;

  PosCmd_()
    : x(0.0)
    , y(0.0)
    , z(0.0)
    , roll(0.0)
    , pitch(0.0)
    , yaw(0.0)
    , gripper(0.0)
    , mode1(0)
    , mode2(0)  {
    }
  PosCmd_(const ContainerAllocator& _alloc)
    : x(0.0)
    , y(0.0)
    , z(0.0)
    , roll(0.0)
    , pitch(0.0)
    , yaw(0.0)
    , gripper(0.0)
    , mode1(0)
    , mode2(0)  {
  (void)_alloc;
    }



   typedef double _x_type;
  _x_type x;

   typedef double _y_type;
  _y_type y;

   typedef double _z_type;
  _z_type z;

   typedef double _roll_type;
  _roll_type roll;

   typedef double _pitch_type;
  _pitch_type pitch;

   typedef double _yaw_type;
  _yaw_type yaw;

   typedef double _gripper_type;
  _gripper_type gripper;

   typedef int32_t _mode1_type;
  _mode1_type mode1;

   typedef int32_t _mode2_type;
  _mode2_type mode2;





  typedef boost::shared_ptr< ::arm_control::PosCmd_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::arm_control::PosCmd_<ContainerAllocator> const> ConstPtr;

}; // struct PosCmd_

typedef ::arm_control::PosCmd_<std::allocator<void> > PosCmd;

typedef boost::shared_ptr< ::arm_control::PosCmd > PosCmdPtr;
typedef boost::shared_ptr< ::arm_control::PosCmd const> PosCmdConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::arm_control::PosCmd_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::arm_control::PosCmd_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::arm_control::PosCmd_<ContainerAllocator1> & lhs, const ::arm_control::PosCmd_<ContainerAllocator2> & rhs)
{
  return lhs.x == rhs.x &&
    lhs.y == rhs.y &&
    lhs.z == rhs.z &&
    lhs.roll == rhs.roll &&
    lhs.pitch == rhs.pitch &&
    lhs.yaw == rhs.yaw &&
    lhs.gripper == rhs.gripper &&
    lhs.mode1 == rhs.mode1 &&
    lhs.mode2 == rhs.mode2;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::arm_control::PosCmd_<ContainerAllocator1> & lhs, const ::arm_control::PosCmd_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace arm_control

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::arm_control::PosCmd_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::arm_control::PosCmd_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::arm_control::PosCmd_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::arm_control::PosCmd_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::arm_control::PosCmd_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::arm_control::PosCmd_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::arm_control::PosCmd_<ContainerAllocator> >
{
  static const char* value()
  {
    return "1c57ab1c25d2c8b93367daa40ff13cae";
  }

  static const char* value(const ::arm_control::PosCmd_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x1c57ab1c25d2c8b9ULL;
  static const uint64_t static_value2 = 0x3367daa40ff13caeULL;
};

template<class ContainerAllocator>
struct DataType< ::arm_control::PosCmd_<ContainerAllocator> >
{
  static const char* value()
  {
    return "arm_control/PosCmd";
  }

  static const char* value(const ::arm_control::PosCmd_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::arm_control::PosCmd_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 x\n"
"float64 y\n"
"float64 z\n"
"float64 roll\n"
"float64 pitch\n"
"float64 yaw\n"
"float64 gripper\n"
"int32 mode1\n"
"int32 mode2\n"
;
  }

  static const char* value(const ::arm_control::PosCmd_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::arm_control::PosCmd_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.z);
      stream.next(m.roll);
      stream.next(m.pitch);
      stream.next(m.yaw);
      stream.next(m.gripper);
      stream.next(m.mode1);
      stream.next(m.mode2);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct PosCmd_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::arm_control::PosCmd_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::arm_control::PosCmd_<ContainerAllocator>& v)
  {
    s << indent << "x: ";
    Printer<double>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<double>::stream(s, indent + "  ", v.y);
    s << indent << "z: ";
    Printer<double>::stream(s, indent + "  ", v.z);
    s << indent << "roll: ";
    Printer<double>::stream(s, indent + "  ", v.roll);
    s << indent << "pitch: ";
    Printer<double>::stream(s, indent + "  ", v.pitch);
    s << indent << "yaw: ";
    Printer<double>::stream(s, indent + "  ", v.yaw);
    s << indent << "gripper: ";
    Printer<double>::stream(s, indent + "  ", v.gripper);
    s << indent << "mode1: ";
    Printer<int32_t>::stream(s, indent + "  ", v.mode1);
    s << indent << "mode2: ";
    Printer<int32_t>::stream(s, indent + "  ", v.mode2);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ARM_CONTROL_MESSAGE_POSCMD_H