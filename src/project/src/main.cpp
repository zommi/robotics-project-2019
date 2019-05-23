#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>

#include <math.h>

#include "project/odom.h"
#include "project/floatStamped.h"
#include <dynamic_reconfigure/server.h>
#include <project/parametersConfig.h>

#define BASELINE 1.30
#define FRONT_REAL_WHEELS_DISTANCE 1.765
#define STEERING_FACTOR 18
#define PI 3.14159

bool diff_not_ack = true;

/*cambia il valore del booleano diff_not_ack. Se vale vero, l'odometria verra calcolata
in maniera differenziale, se falso invece secondo ackerman
 */
void paramCallback(project::parametersConfig &config, uint32_t level) {
  ROS_INFO("Reconfigure Request: %s", config.diff_not_ack?"True":"False");
  diff_not_ack = config.diff_not_ack;
}

typedef message_filters::sync_policies::ApproximateTime<project::floatStamped,
                                      project::floatStamped,
                                      project::floatStamped> myPolicy;


using namespace message_filters;

double x_k = 0;
double y_k = 0;
double theta_k = 0;
double t_k = 0;


void callback(const project::floatStamped::ConstPtr& r_vel,
              const project::floatStamped::ConstPtr& l_vel,
              const project::floatStamped::ConstPtr& steer)
{
  //ROS_INFO("I heard: [%f] - [%f] - [%f]", r_vel->header.stamp.sec, l_vel->header.stamp.sec, steer->header.stamp.sec);

  double V_k = (r_vel->data + l_vel->data)/2;
  double w_k = (r_vel->data - l_vel->data)/BASELINE;
  double T_s = (r_vel->header.stamp.nsec - t_k) * pow(10,-9);



  x_k = x_k + V_k * T_s * cos(theta_k + (w_k * T_s) / 2);
  y_k = y_k + V_k * T_s * sin(theta_k + (w_k * T_s) / 2);
  theta_k = theta_k + w_k * T_s;

  ROS_INFO("Current odometry: x:[%f] - y:[%f] - theta(rad):[%f]", x_k, y_k, theta_k);
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "main");

  //linee di codice per la dynamic configuration
  dynamic_reconfigure::Server<project::parametersConfig> server;
  dynamic_reconfigure::Server<project::parametersConfig>::CallbackType f;
  //bindo la funzione che aggiorna i parametri
  f = boost::bind(&paramCallback, _1, _2);
  // setto la funzione di collback nel server
  server.setCallback(f);

  ros::NodeHandle n;

  ros::Publisher p;

  message_filters::Subscriber<project::floatStamped> sub_r_vel(n, "speedR_stamped", 1);
  message_filters::Subscriber<project::floatStamped> sub_l_vel(n, "speedL_stamped", 1);
  message_filters::Subscriber<project::floatStamped> sub_steer(n, "steer_stamped", 1);
  message_filters::Synchronizer<myPolicy> sync(myPolicy(10), sub_r_vel,sub_l_vel,sub_steer);
  sync.registerCallback(boost::bind(&callback, _1, _2, _3));

  ros::spin();

  return 0;
}
