#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <vector>


#include <image_transport/image_transport.h>
#include <message_filters/synchronizer.h>
#include <message_filters/subscriber.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <sensor_msgs/PointCloud2.h>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/locks.hpp>
#include <pcl/correspondence.h>
#include <pcl/point_cloud.h>
#include <pcl/common/common_headers.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <image_transport/subscriber_filter.h>
#include <pcl_ros/point_cloud.h>
#include <pcl/filters/passthrough.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl_ros/transforms.h>
#include <tf/tf.h>
#include <tf/transform_listener.h>
#include <math.h>

#include <C23_ObjectRecognition/C23C0_OD.h>
#include <C23_ObjectRecognition/C23C0_ODIM.h>
#include "C23_Detector.hpp"
Mat fromSensorMsg(const sensor_msgs::ImageConstPtr& msg)
{
  cv_bridge::CvImagePtr cv_ptr;
  try
  {
    cv_ptr = cv_bridge::toCvCopy(msg, enc::BGR16);
  }
  catch (cv_bridge::Exception& e)
  {
    ROS_ERROR("cv_bridge exception: %s", e.what());
    exit(1);
  }
  return cv_ptr->image;
}


	C23_Detector::C23_Detector(const char* left_cam, const char* right_cam, const char* pointc):
	it_(nh),
	left_image_sub_( it_, "/C21/left_camera/image", 1 ),
	pointcloud(nh,"/multisense_sl/camera/points2",1),
	sync( MySyncPolicy( 10 ), left_image_sub_,pointcloud)
	{
		sync.registerCallback( boost::bind( &C23_Detector::callback, this, _1, _2 ) ); //Specifying what to do with the data
		objectDetectedPublisher = nh.advertise<C23_ObjectRecognition::C23C0_OD>("C23/object_detected", 1);
    objectDeminsionsPublisher = nh.advertise<C23_ObjectRecognition::C23C0_ODIM>("C23/object_deminsions", 1);
		ROS_INFO("Started...");
	//	gates = new vector<Gate*>();
	}


  bool C23_Detector::detect(const string target) {
 //   ROS_INFO(target.c_str());
 namedWindow("Threshed",WINDOW_AUTOSIZE );
    if(!target.compare("Gate")) {
        _target = GATE;
        
      ROS_INFO("We are looking for a gate...");
    } else if (!target.compare("Car")) {
        _target = CAR;
      ROS_INFO("We are looking for a gate...");
    }
    return true;
  
  }
  void C23_Detector::publishMessage(bool isFound) {
    C23_ObjectRecognition::C23C0_OD msg;
    C23_ObjectRecognition::C23C0_ODIM msg2;
    string target;
    switch (_target) {
		  
		    case CAR:
		      target = "Car";
		      break;
	      case GATE:
	        target = "Gate";
	        break;
     }
    msg.ObjectDetected = isFound ? 1 : 0;
    msg2.x = x;
    msg2.y = y;
    msg2.width = width;
    msg2.height = height;
    msg2.Object = target;
    msg.Object = target;
    objectDeminsionsPublisher.publish(msg2);
    objectDetectedPublisher.publish(msg);

  
  }
	void C23_Detector::callback(const sensor_msgs::ImageConstPtr& msg,const sensor_msgs::PointCloud2::ConstPtr &cloud)
	{
		  Mat srcImg = fromSensorMsg(msg);
		  bool res;
		  switch (_target) {
		  
		    case CAR:
		      ROS_INFO("CAR");
		      break;
	      case GATE:
	    //    ROS_INFO("GATE");
	        
	        res = detectGate(srcImg,cloud);
	        if(res) {
	          publishMessage(true);
	        }
	        break;
     }
     srcImg.release();
			
	}
	
	bool C23_Detector::detectGate(Mat srcImg, const sensor_msgs::PointCloud2::ConstPtr &cloud) {
	  
	  pcl::PointCloud<pcl::PointXYZ>pclcloud;
		pcl::fromROSMsg<pcl::PointXYZ>(*cloud,pclcloud);
		static pcl::PointXYZ leftC;
		static pcl::PointXYZ rightC;
    bool res = false;

		IplImage* img = new IplImage(srcImg);
		IplImage* imgHSV = cvCreateImage(cvGetSize(img), 8, 3);

		cvCvtColor(img, imgHSV, CV_BGR2HSV);
		IplImage* imgThreshed = cvCreateImage(cvGetSize(img), 8, 1);
		cvInRangeS(imgHSV, cvScalar(0, 30, 30), cvScalar(20, 255, 255), imgThreshed); //filter red

		Mat threshMat(imgThreshed);
    
		//imshow("Threshed",threshMat);
  //  ROS_INFO("Gate!");


		//contoursR
		Mat bw,gray;


		////finding center mass of right column
		threshold(threshMat, bw, 10, 255, CV_THRESH_BINARY);
		vector<vector<cv::Point> > contoursR;
		findContours(bw, contoursR, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE);
		drawContours(srcImg, contoursR, -1, CV_RGB(255,0,0), 2);

		/// Get the moments and mass centers:
		  vector<Moments> muR(contoursR.size() );
		  vector<Point2f> mcR(contoursR.size() );
		  int biggstR=0;
		  for(unsigned int i = 0; i < contoursR.size(); i++ )
		  {
			  muR[i] = moments( contoursR[i], false );
			  mcR[i] = Point2f( muR[i].m10/muR[i].m00 , muR[i].m01/muR[i].m00 );
			  if (muR[biggstR].m00<=muR[i].m00)
				  biggstR=i;

		  }

		  circle( srcImg, mcR[biggstR], 16, 60, -1, 8, 0 );

		  if (pclcloud.at(mcR[biggstR].x,mcR[biggstR].y).x<50 && pclcloud.at(mcR[biggstR].x,mcR[biggstR].y).y <50 && pclcloud.at(mcR[biggstR].x,mcR[biggstR].y).x !=0)
		 {
			rightC=pclcloud.at(mcR[biggstR].x,mcR[biggstR].y);

		  }


		  /////finding center mass of left column
		  cvInRangeS(imgHSV, cvScalar(90, 130, 40), cvScalar(150, 255, 250), imgThreshed);//filter blue


		  Mat threshMatL(imgThreshed),bwL;
		  threshold(threshMatL, bwL, 10, 255, CV_THRESH_BINARY);
		  vector<vector<cv::Point> > contoursL;
	//	  cout<<"next2"<<endl;
		  findContours(bwL, contoursL, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE);
		  drawContours(srcImg, contoursL, -1, CV_RGB(0,0,255), 2);

		  vector<Moments> muL(contoursL.size() );
		  	  vector<Point2f> mcL(contoursL.size() );
		  	  int biggstL=0;
		  	  for(unsigned int i = 0; i < contoursL.size(); i++ )
		  	  {
		  		  muL[i] = moments( contoursL[i], false );
		  		  mcL[i] = Point2f( muL[i].m10/muL[i].m00 , muL[i].m01/muL[i].m00 );
		  		  if (muL[biggstL].m00<=muL[i].m00)
		  			  biggstL=i;

		  	  }

		  	  circle( srcImg, mcL[biggstL], 16, Scalar(0,0,255), -1, 8, 0 );




		  	 if (pclcloud.at(mcL[biggstL].x,mcL[biggstL].y).x<50 && pclcloud.at(mcL[biggstL].x,mcL[biggstL].y).y <50 && pclcloud.at(mcL[biggstL].x,mcL[biggstL].y).x !=0)
			 {
				leftC=pclcloud.at(mcL[biggstL].x,mcL[biggstL].y);
			  }

		  	line( srcImg,mcL[biggstL],mcR[biggstR],Scalar(0,0,0),5,8);

		  //	cout <<"\nleft :"<<leftC.x<<" ,"<<leftC.y<<endl;
		  //	cout<<"\nright :"<<rightC.x<<" ,"<<rightC.y<<endl;
		  	double gate =sqrt(pow((leftC.x-rightC.x),2)+pow((leftC.y-rightC.y),2));
		  //	cout<<gate<<endl;
		  	if (gate > 4.7 && gate < 5.2)
		  	{
		  		res = true;
		  	}

			//find lines
			Mat dst,cdst;
			Canny(threshMat, dst, 50, 200, 3);
			cvtColor(dst, cdst, CV_GRAY2BGR);

			//Probabilistic Hough Line Transform
			vector<Vec4i> lines;
			  HoughLinesP(dst, lines, 5, CV_PI/180, 50, 100, 10 );
			  for( size_t i = 0; i < lines.size(); i++ )
			  {
				Vec4i l = lines[i];
				line( cdst, cv::Point(l[0], l[1]), cv::Point(l[2], l[3]), Scalar(0,0,255), 3, CV_AA);
			  }


			//cout<<"left"<<mcL[biggstL]<<"right"<<mcR[biggstR]<<endl;
			x = (mcL[biggstL].x + mcR[biggstR].x)/2;
			y = (mcL[biggstL].y + mcR[biggstR].y)/2;

			Point2f a((float)x,(float)y);
			circle( srcImg, a, 16, Scalar(0,0,255), -1, 8, 0 );


		  return true;
	
	}


