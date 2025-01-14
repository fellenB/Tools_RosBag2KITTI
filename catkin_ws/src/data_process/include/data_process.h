#ifndef MAP_GENERATION_NODE
#define MAP_GENERATION_NODE

#include <ros/ros.h>
#include <pcl_ros/point_cloud.h>
#include <sensor_msgs/PointCloud2.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>


#include <pcl/io/pcd_io.h>
#include <pcl_ros/point_cloud.h>
#include <pcl/common/transforms.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/filters/filter.h>


class MapGenerationNode
{
public:
    MapGenerationNode();

    void lidarCallback(const sensor_msgs::PointCloud2::ConstPtr& lidar);

    void camera3Callback(const sensor_msgs::ImageConstPtr& camera);


private:

    ros::NodeHandle nh;

	pcl::PointCloud<pcl::PointXYZI> lidar_cloud;

	long long lidar_index;// todo 上限
	long long camera_index;
	bool camera_captured;// sampling
	bool lidar_captured;

	bool init_camera_time;
	bool init_lidar_time;
	
	long long camera_base_time;
	long long lidar_base_time;
	long long lidar_derta_time_gelobal;

    // subscriber
    ros::Subscriber sub_lidar;
	ros::Subscriber sub_camera200;
	ros::Subscriber sub_camera1;
	ros::Subscriber sub_camera2;
	ros::Subscriber sub_camera3;
	ros::Subscriber sub_camera4;
	image_transport::ImageTransport it;
	//publisher
	ros::Publisher image_publisher;

};


#endif
