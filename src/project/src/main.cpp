#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>

#include "project/odom.h"
#include "project/floatStamped.h"

typedef message_filters::sync_policies::ApproximateTime<project::floatStamped,
                                      project::floatStamped,
                                      project::floatStamped> myPolicy;


using namespace message_filters;

void callback(const project::floatStamped::ConstPtr& r_vel,
              const project::floatStamped::ConstPtr& l_vel,
              const project::floatStamped::ConstPtr& steer)
{
  ROS_INFO("I heard: [%f] - [%f] - [%f]", r_vel->data, l_vel->data, steer->data);
  //ROS_INFO("I l_vel: [%d]", l_vel->data);
  //ROS_INFO("I theta: [%d]", theta->data);
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "main");

  ros::NodeHandle n;

  message_filters::Subscriber<project::floatStamped> sub_r_vel(n, "speedR_stamped", 1);
  message_filters::Subscriber<project::floatStamped> sub_l_vel(n, "speedL_stamped", 1);
  message_filters::Subscriber<project::floatStamped> sub_steer(n, "steer_stamped", 1);
  message_filters::Synchronizer<myPolicy> sync(myPolicy(10), sub_r_vel,sub_l_vel,sub_steer);
  sync.registerCallback(boost::bind(&callback, _1, _2, _3));

  ros::spin();

  return 0;
}


