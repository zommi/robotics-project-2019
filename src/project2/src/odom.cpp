#include "ros/ros.h"
#include <geometry_msgs/PointStamped.h>
#include <math.h>

#define BASELINE 1.30
#define FRONT_REAR_WHEELS_DISTANCE 1.765
#define STEERING_FACTOR 18

double x_k = 0;

double y_k = 0;

double theta_k = 0;

double t_k = 0;

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
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "odom");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("/speedsteer",1000,odom_callback);

  ros::spin();

  return 0;
}
