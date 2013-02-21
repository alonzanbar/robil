/**************************************************************************************
 * This is a template for the C23_ObjectRecognition module for the robil project
 * The C23_ObjectRecognition module goal is to provide a recognition of the object searched in the given frame
 *
 * There is no actual input/output at this time, this goes according to the current milestone
 * set at the robil managment meeting
 * 
 **************************************************************************************/
#include "C23_Node.hpp"




static const char WINDOW[] = "Image window";


static const char *models[] = {
"car_polaris_driver_side.mdl",
"car_polaris_passenger_side.mdl",
"car_polaris_front.mdl",
"car_polaris_behind.mdl"};

C23_Node::C23_Node(std::string left_camera,std::string right_camera) :
		it_(nh_),
		tldh_(NULL),
		x(-1), y(-1), width(-1), height(-1),
		left_image_sub_( it_, left_camera, 1 ),
		right_image_sub_( it_, right_camera, 1 ),
		sync( MySyncPolicy( 10 ), left_image_sub_, right_image_sub_ ),
		ready(false)
	  {
	    //ready=false;
		sync.registerCallback( boost::bind( &C23_Node::callback, this, _1, _2 ) );  //Specifying what to do with the data
		//service = nh_.advertiseService("C23", &C23_Node::proccess, this); //Specifying what to do when a reconstructed 3d scene is requested
		ROS_INFO("service on\n");
		
	  }
/**
* The call back function executed when a service is requested
* it must return true in order to work properly
* @param req the request message, generated by the node requesting the service
* @param res the response message, generated by the service node when a service is requested
*/
/*
bool proccess(C23_ObjectRecognition::C23::Request  &req,
	C23_ObjectRecognition::C23::Response &res )
{
  ROS_INFO("recived request, tying to fetch data\n");

  return true;
}
*/

/**
* The call back function executed when a data is available
* @param left_msg ROS mesage with image data from the left camera topic
* @param right_msg ROS mesage with image data from the right camera topic
*/
	   
bool C23_Node::detectAndTrack(MODELS model) {
    ROS_INFO("C23_Node::detectAndTrack\n");
    if(tldh_ != NULL) {
        free(tldh_);
        tldh_ = NULL;
        currentModel_ = NONE;
    }
    currentModel_ = model;
    ROS_INFO("Now detecting and tracking model 2: ");
    ROS_INFO(models[model]);
    ROS_INFO("\n");
    ready=true;
    return true;

}

	
void C23_Node::callback(const sensor_msgs::ImageConstPtr& left_msg,const sensor_msgs::ImageConstPtr& right_msg){
 
 cv_bridge::CvImagePtr cv_ptr;
    ROS_INFO("C23_Node::callBack\n");
 if(ready) {
    ready = false;
    ROS_INFO("I'm ready\n");
    try {
        cv_ptr = cv_bridge::toCvCopy(left_msg,enc::BGR8);
    }
    
    catch (cv_bridge::Exception& e)
    {
      ROS_ERROR("cv_bridge exception: %s", e.what());
      return;
    }

    IplImage tosave=cv_ptr->image;
    int percent = 30;
    IplImage *destination = cvCreateImage
    ( cvSize((int)((tosave.width*percent)/100) , (int)((tosave.height*percent)/100) ),
                             tosave.depth, tosave.nChannels );
    
    //use cvResize to resize source to a destination image
    cvResize(&tosave, destination);
    ROS_INFO("Received image");
    if(tldh_ == NULL) {
        ROS_INFO("Now reading model..");
        char buf[10000];
        sprintf(buf,"models/%s%c",models[currentModel_],'\0');
        ROS_INFO("Done reading");
        ROS_INFO("Now building... %s\n",buf);
        tldh_ = new C23_Node_TLD_Handler(TRACKING, "models/car_polaris_passenger_side.mdl");
        ROS_INFO("Now init..\n");
        tldh_->init(destination);
    } else {
        ROS_INFO("Now processing..\n");
        
        tldh_->processFrame(destination, &x, &y, &width, &height, &confident);
        char buff[100];
        sprintf(buff,"BB: %d %d %d %d, Confident: %lf \n",x,y,width,height,confident);
        ROS_INFO(buff);
    }
    ready = true;
   }
}
void C23_Node::startDetection() {
    ROS_INFO("C23_Node::startDetection\n");
  //  ready=false;
}
void C23_Node::stopDetection() {
    ROS_INFO("C23_Node::stopDetection\n");
    if(tldh_ != NULL) {
        free(tldh_);
        tldh_ = NULL;
    }
    ready=false;
}
	  



