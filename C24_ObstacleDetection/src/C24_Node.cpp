/**************************************************************************************
 * This is a template for the C24_ObstacleDetection module for the robil project
 * The C24_ObstacleDetection module goal is to provide an obstacle detection on demand
 *
 * There is no actual input/output at this time, this goes according to the current milestone
 * set at the robil managment meeting
 * 
 **************************************************************************************/

#include "ros/ros.h"
#include "C24_ObstacleDetection/C24.h"
#include <image_transport/image_transport.h>
#include <message_filters/synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <sensor_msgs/image_encodings.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <image_transport/subscriber_filter.h>

namespace enc=sensor_msgs::image_encodings;

/**
 * this class represent the C24_Node,
 * it subscribe to two camera/image topics and provide the path
 **/
class C24_Node{

public:

	/**
	 * constructor, initializes the ROS node, subscribe it to the given topics and instruct it to provide the service
	 * @param left_camera the left camera image topic
	 * @param right_camera the right camera image topic
	 */
	  C24_Node(std::string left_camera,std::string right_camera) :
		it_(nh_),
		//the purpose of the following 3 lines is to synchronize the data from the cameras using a message filter
		//more on filters and how to use them can be found on http://www.ros.org/wiki/message_filters
		left_image_sub_( it_, left_camera, 1 ),
		right_image_sub_( it_, right_camera, 1 ),
		sync( MySyncPolicy( 10 ), left_image_sub_, right_image_sub_ )
	  {
		ROS_INFO("finished subscribing\n");
		sync.registerCallback( boost::bind( &C24_Node::callback, this, _1, _2 ) );  //Specifying what to do with the data
		service = nh_.advertiseService("C24", &C24_Node::proccess, this); //Specifying what to do when a reconstructed 3d scene is requested
		ROS_INFO("service on\n");
	  }


	  /**
	   * The call back function executed when a service is requested
	   * it must return true in order to work properly
	   * @param req the request message, generated by the node requesting the service
	   * @param res the response message, generated by the service node when a service is requested
	   */
	  bool proccess(C24_ObstacleDetection::C24::Request  &req,
			C24_ObstacleDetection::C24::Response &res )
	  {
		  ROS_INFO("recived request, tying to fetch data\n");

		  return true;
	  }


	  /**
	   * The call back function executed when a data is available
	   * @param left_msg ROS mesage with image data from the left camera topic
	   * @param right_msg ROS mesage with image data from the right camera topic
	   */
	  void callback(const sensor_msgs::ImageConstPtr& left_msg,const sensor_msgs::ImageConstPtr& right_msg){
		 cv_bridge::CvImagePtr left;
		 cv_bridge::CvImagePtr right;

		try
		{
		  left = cv_bridge::toCvCopy(left_msg,enc::RGB8);
		  right =cv_bridge::toCvCopy(right_msg,enc::RGB8);
		}
		catch (cv_bridge::Exception& e)
		{
		  ROS_ERROR("cv_bridge exception: %s", e.what());
		  return;
		}
	  }

private:
  ros::NodeHandle nh_;
  image_transport::ImageTransport it_;
  typedef image_transport::SubscriberFilter ImageSubscriber;
  ImageSubscriber left_image_sub_;
  ImageSubscriber right_image_sub_;
  ros::ServiceServer service;
  typedef message_filters::sync_policies::ApproximateTime<sensor_msgs::Image, sensor_msgs::Image> MySyncPolicy;
  message_filters::Synchronizer< MySyncPolicy > sync;
};

int main(int argc, char **argv)
{
  ros::init(argc, argv, "C24_ObstacleDetection");
  if(argc!=3){
	  printf("usage: C24_module <left camera topic> <right camera topic>");
  }
  C24_Node my_node(argv[1],argv[2]);
  ROS_INFO("made topic at %s %s \n",argv[1],argv[2]);
  while(ros::ok()){
	  ros::spin();
  }
  return 0;
}

