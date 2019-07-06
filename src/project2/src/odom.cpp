#include "ros/ros.h"
#include <geometry_msgs/PointStamped.h>
#include <nav_msgs/Odometry.h>
#include <tf/transform_broadcaster.h>

#include <math.h>

#define BASELINE 1.30
#define FRONT_REAR_WHEELS_DISTANCE 1.765
#define STEERING_FACTOR 18

class odom_pub_sub
{

private:
  ros::NodeHandle n;
  ros::Subscriber sub;
  ros::Publisher pub;
  tf::TransformBroadcaster odom_broadcaster;
  geometry_msgs::TransformStamped odom_trans;
  double x_k;
  double y_k;
  double theta_k;
  double t_k;
  nav_msgs::Odometry odom_msg;

public:

odom_pub_sub()
{
  x_k = 0;
  y_k = 0;
  theta_k = 0;
  t_k = 0;
  sub = n.subscribe("/speedsteer",1000,&odom_pub_sub::odom_callback,this);
  pub = n.advertise<nav_msgs::Odometry>("/odom",1);
}

void odom_callback(const geometry_msgs::PointStamped::ConstPtr& msg)
{
  double w_k;
  double T_s = (msg->header.stamp.nsec - t_k) * pow(10,-9);
  double alpha = msg->point.x / 180 * M_PI / STEERING_FACTOR;
  double V_k = msg->point.y;

  if(T_s < 0)T_s += 1;
  w_k = V_k * tan(alpha) / FRONT_REAR_WHEELS_DISTANCE;

  x_k += V_k * cos(theta_k) * T_s;
  y_k += V_k * sin(theta_k) * T_s;
  theta_k += w_k * T_s;

  t_k = msg->header.stamp.nsec;

  std::cout << "x = " << x_k << "\ny = " << y_k << "\ntheta = " << theta_k << "\n";

  geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromYaw(theta_k);

  odom_trans.header.stamp = msg->header.stamp;
  odom_trans.header.frame_id = "odom";
  odom_trans.child_frame_id = "base_link";

  odom_trans.transform.translation.x = x_k;
  odom_trans.transform.translation.y = y_k;
  odom_trans.transform.translation.z = 0.0;
  odom_trans.transform.rotation = odom_quat;
  odom_broadcaster.sendTransform(odom_trans);


  odom_msg.pose.pose.position.x = x_k;
  odom_msg.pose.pose.position.y = y_k;
  odom_msg.pose.pose.position.z = 0.0;
  odom_msg.pose.pose.orientation = odom_quat;
  odom_msg.header = msg->header;
  odom_msg.header.frame_id = "odom";
  odom_msg.child_frame_id = "base_link";

  pub.publish(odom_msg);
}
};

int main(int argc, char** argv)
{
  ros::init(argc, argv, "main2");
  odom_pub_sub pub_sub;
  ros::spin();

  return 0;
}
