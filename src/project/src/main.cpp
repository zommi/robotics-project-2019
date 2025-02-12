#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>

#include <math.h>

#include <nav_msgs/Odometry.h>
#include <tf/transform_broadcaster.h>

#include "project/odom.h"
#include "project/floatStamped.h"
#include <dynamic_reconfigure/server.h>
#include <project/parametersConfig.h>

#define BASELINE 1.30
#define FRONT_REAR_WHEELS_DISTANCE 1.765
#define STEERING_FACTOR 18
#define PI 3.14159
#define approx 10e-6

using namespace message_filters;

typedef message_filters::sync_policies::ApproximateTime<project::floatStamped,
                                                        project::floatStamped,
                                                        project::floatStamped> myPolicy;

bool diff_not_ack;

double x_k = 0;

double y_k = 0;

double theta_k = 0;

double t_k = 0;

ros::Publisher pub;
ros::Publisher custom_pub;

/*cambia il valore del booleano diff_not_ack. Se vale vero, l'odometria verra calcolata
in maniera differenziale, se falso invece secondo ackermann
 */
void param_callback(project::parametersConfig &config, uint32_t level)
{
  ROS_INFO("Reconfigure Request: diff_not_ack = %s, reset = %s, x_enable = %s, y_enable = %s, xy_enable = %s, x = %f, y = %f",
                                config.diff_not_ack?"True":"False",
                                config.reset?"True":"False",
                                config.x_enable?"True":"False",
                                config.y_enable?"True":"False",
                                config.xy_enable?"True":"False",
                                config.x,
                                config.y
                                      );
  diff_not_ack = config.diff_not_ack;

  if(config.reset){
      x_k = 0;
      y_k = 0;
  }
  else {
      if(config.xy_enable){
          x_k = config.x;
          y_k = config.y;
      }
      else {
          if (config.x_enable) {
              x_k = config.x;
          }
          if (config.y_enable) {
              y_k = config.y;
          }
      }
  }
  ROS_INFO("diff_not_ack %s", diff_not_ack?"True": "False" );
}


void odom_callback(const project::floatStamped::ConstPtr& r_vel,
                    const project::floatStamped::ConstPtr& l_vel,
                    const project::floatStamped::ConstPtr& steer)
{
  double V_k = (r_vel->data + l_vel->data)/2;
  double w_k;
  double T_s = (r_vel->header.stamp.nsec - t_k) * pow(10,-9);
  double alpha = steer->data * PI / 180 / STEERING_FACTOR;
  nav_msgs::Odometry msg;
  project::odom custom_msg;
  tf::TransformBroadcaster odom_broadcaster;

  if(T_s < 0)T_s += 1;

  if(diff_not_ack)
  { //DIFFERENTIAL
    w_k = (r_vel->data - l_vel->data)/BASELINE;

    x_k += V_k * T_s * cos(theta_k + (w_k * T_s) / 2);
    y_k += V_k * T_s * sin(theta_k + (w_k * T_s) / 2);
    theta_k += w_k * T_s;
  }
  else { //ACKERMANN
    w_k = V_k * tan(alpha) / FRONT_REAR_WHEELS_DISTANCE;

    x_k += V_k * cos(theta_k) * T_s;
    y_k += V_k * sin(theta_k) * T_s;
    theta_k += w_k * T_s;
  }

  t_k = r_vel->header.stamp.nsec;

  geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromYaw(theta_k);

  geometry_msgs::TransformStamped odom_trans;
  odom_trans.header.stamp = r_vel->header.stamp;
  odom_trans.header.frame_id = "odom";
  odom_trans.child_frame_id = "base_link";

  odom_trans.transform.translation.x = x_k;
  odom_trans.transform.translation.y = y_k;
  odom_trans.transform.translation.z = 0.0;
  odom_trans.transform.rotation = odom_quat;
  odom_broadcaster.sendTransform(odom_trans);


  msg.pose.pose.position.x = x_k;
  msg.pose.pose.position.y = y_k;
  msg.pose.pose.position.z = 0.0;
  msg.pose.pose.orientation = odom_quat;
  msg.header = r_vel->header;
  msg.header.frame_id = "odom";
  msg.child_frame_id = "base_link";

  //custom message creation
  custom_msg.x_value = x_k;
  custom_msg.y_value = y_k;
  custom_msg.theta = theta_k;
  custom_msg.odom_type = diff_not_ack ? "Differential drive" : "Ackermann";

  pub.publish(msg);
  custom_pub.publish(custom_msg);
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "main");

  //linee di codice per la dynamic reconfigure
  dynamic_reconfigure::Server<project::parametersConfig> server;
  dynamic_reconfigure::Server<project::parametersConfig>::CallbackType f;
  //bindo la funzione che aggiorna i parametri
  f = boost::bind(&param_callback, _1, _2);
  // setto la funzione di callback nel server
  server.setCallback(f);

  ros::NodeHandle n;

  pub = n.advertise<nav_msgs::Odometry>("odom",1000);
  custom_pub = n.advertise<project::odom>("customOdom",1000);
  tf::TransformBroadcaster odom_broadcaster;

  message_filters::Subscriber<project::floatStamped> sub_r_vel(n, "speedR_stamped", 1);
  message_filters::Subscriber<project::floatStamped> sub_l_vel(n, "speedL_stamped", 1);
  message_filters::Subscriber<project::floatStamped> sub_steer(n, "steer_stamped", 1);
  message_filters::Synchronizer<myPolicy> sync(myPolicy(10), sub_r_vel,sub_l_vel,sub_steer);
  sync.registerCallback(boost::bind(&odom_callback, _1, _2, _3));

  ros::spin();

  return 0;
}
