#ifndef _ROS_agv_mcu_pose_h
#define _ROS_agv_mcu_pose_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose2D.h"

namespace agv
{

  class mcu_pose : public ros::Msg
  {
    public:
      typedef float _linear_type;
      _linear_type linear;
      typedef float _angular_type;
      _angular_type angular;
      typedef geometry_msgs::Pose2D _pose_type;
      _pose_type pose;

    mcu_pose():
      linear(0),
      angular(0),
      pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->linear);
      offset += serializeAvrFloat64(outbuffer + offset, this->angular);
      offset += this->pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->linear));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->angular));
      offset += this->pose.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "agv/mcu_pose"; };
    virtual const char * getMD5() override { return "aa6a4d99c88b96da9f6c03f000974f35"; };

  };

}
#endif
