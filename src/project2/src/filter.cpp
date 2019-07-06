#include "imu_complementary_filter/complementary_filter_ros.h"


int main (int argc, char **argv)
{
	ros::init (argc, argv, "filter");
	ros::NodeHandle n;
	ros::NodeHandle nh("~");
	imu_tools::ComplementaryFilterROS filter(n,nh);
	ros::spin();
	return 0;
}