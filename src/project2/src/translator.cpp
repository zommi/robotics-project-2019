#include "ros/ros.h"
#include <sensor_msgs/Imu.h>
class translator
{

private:
	ros::NodeHandle n;
	ros::Subscriber sub;
	ros::Publisher pub;

public:

translator()
{
	sub = n.subscribe("/swiftnav/rear/imu",1000,&translator::translator_callback,this);
	pub = n.advertise<sensor_msgs::Imu>("/imu",1);
}
void translator_callback(const sensor_msgs::Imu::ConstPtr& msg)
{
	pub.publish(msg);
}

};

int main(int argc, char **argv){
	ros::init(argc, argv, "translator");
	translator translator;
  	ros::spin();

  	return 0;
}