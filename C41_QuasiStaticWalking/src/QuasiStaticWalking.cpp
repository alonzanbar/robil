#include <ros/ros.h>
#include <C0_RobilTask/RobilTaskAction.h>
#include <C0_RobilTask/RobilTask.h>
#include <C31_PathPlanner/C31_GetPath.h>
#include <move_pelvis/move_pelvis.h>
#include <pelvis_leg_target/pelvis_leg_target.h>
#include <actionlib/server/simple_action_server.h>
#include <pr2_controllers_msgs/JointControllerState.h>
#include <actionlib/client/simple_action_client.h>
#include <std_msgs/Float64.h>
#include <math.h>
#include <boost/bind.hpp>
#include <string>
#include <sensor_msgs/JointState.h>
#include <sensor_msgs/Imu.h>
#include <osrf_msgs/JointCommands.h>

class QuasiStaticWalking{
private:
	ros::NodeHandle nh_, nh2_, nh3_, nh4_;
	ros::NodeHandle* rosnode;
	ros::ServiceClient move_pelvis_cli_, pelvis_leg_target_cli_, getPath_cli_;
	actionlib::SimpleActionServer<C0_RobilTask::RobilTaskAction> as_; // NodeHandle instance must be created before this line.
	C0_RobilTask::RobilTaskFeedback feedback_;
	C0_RobilTask::RobilTaskResult result_;
	ros::Publisher turn_angle;
	std::string action_name_;
	std_msgs::Float64 float64_msg;
	ros::Time clock;
	ros::Publisher pub_joint_commands_;
	ros::Subscriber imu_sub_;
	double yaw_from_imu;

public:
	QuasiStaticWalking(std::string name)
	:as_(nh_, name, false), action_name_(name){

		move_pelvis_cli_ = nh_.serviceClient<move_pelvis::move_pelvis>("move_pelvis");
		pelvis_leg_target_cli_ = nh_.serviceClient<pelvis_leg_target::pelvis_leg_target>("pelvis_leg_target");
		getPath_cli_ = nh_.serviceClient<C31_PathPlanner::C31_GetPath>("/C31_GlobalPathPlanner/getPath");
		imu_sub_ = nh_.subscribe("/atlas/imu",100,&QuasiStaticWalking::imu_CB,this);

		while(!move_pelvis_cli_.waitForExistence(ros::Duration(0.1))){
			ROS_INFO("Waiting for the move_pelvis server");
		}
		while(!pelvis_leg_target_cli_.waitForExistence(ros::Duration(0.1))){
			ROS_INFO("Waiting for the pelvis_leg_target server");
		}
		while(!getPath_cli_.waitForExistence(ros::Duration(0.1))){
			ROS_INFO("Waiting for the /C31_GlobalPathPlanner/getPath server");
		}

		//Set callback functions
		as_.registerGoalCallback(boost::bind(&QuasiStaticWalking::goalCB, this));
		as_.registerPreemptCallback(boost::bind(&QuasiStaticWalking::preemptCB, this));

		ROS_INFO("starting");
		as_.start();
		ROS_INFO("started");
	}
	~QuasiStaticWalking(){}


	void imu_CB(const sensor_msgs::Imu::ConstPtr& imu){
		yaw_from_imu = atan2((2*(imu->orientation.w*imu->orientation.z + imu->orientation.y*imu->orientation.x)),
								(1-2*(pow(imu->orientation.y,2)+pow(imu->orientation.z,2))));
		return;
	}

	void turnToWaypoint(double angle){

	}

	void goalCB(){

		clock = ros::Time::now();
		ROS_INFO("Start time: %f", ros::Time::now().toSec());

		std::string g = as_.acceptNewGoal()->parameters;

		C31_PathPlanner::C31_GetPath getpath;
		if(!getPath_cli_.call(getpath)){
			C0_RobilTask::RobilTaskResult _res;
			_res.success = C0_RobilTask::RobilTask::FAULT;
			as_.setSucceeded(_res);
			return;
		}

		//TODO: turn to waypoint

		pelvis_leg_target::pelvis_leg_target leg_target;
		move_pelvis::move_pelvis move_pelvis;
		while(1){

			if (as_.isPreemptRequested() || !ros::ok())
			{
				ROS_ERROR("%s: Preempted", action_name_.c_str());
				// set the action state to preempted
				as_.setPreempted();
			}

			leg_target.request.leg = "r_foot";
			ROS_INFO("Moving to right leg");
			if(!pelvis_leg_target_cli_.call(leg_target)){
				ROS_ERROR("Could not move to right leg");
				C0_RobilTask::RobilTaskResult _res;
				_res.success = C0_RobilTask::RobilTask::FAULT;
				as_.setSucceeded(_res);
				return;
			}

			leg_target.request.leg = "r_foot";
			if(!pelvis_leg_target_cli_.call(leg_target)){
				ROS_ERROR("Could not move to right leg");
				C0_RobilTask::RobilTaskResult _res;
				_res.success = C0_RobilTask::RobilTask::FAULT;
				as_.setSucceeded(_res);
				return;
			}

			leg_target.request.leg = "r_foot";
			if(!pelvis_leg_target_cli_.call(leg_target)){
				ROS_ERROR("Could not move to right leg");
				C0_RobilTask::RobilTaskResult _res;
				_res.success = C0_RobilTask::RobilTask::FAULT;
				as_.setSucceeded(_res);
				return;
			}

			move_pelvis.request.PositionDestination.x = 0.0;
			move_pelvis.request.PositionDestination.y = 0.0;
			move_pelvis.request.PositionDestination.z = -0.1;
			move_pelvis.request.AngleDestination.x = 0.0;
			move_pelvis.request.AngleDestination.y = 0.0;
			move_pelvis.request.AngleDestination.z = 0.0;
			move_pelvis.request.LinkToMove = "l_leg";
			ROS_INFO("Moving left leg up");
			if(!move_pelvis_cli_.call(move_pelvis)){
				ROS_ERROR("Could not move left leg up");
				C0_RobilTask::RobilTaskResult _res;
				_res.success = C0_RobilTask::RobilTask::FAULT;
				as_.setSucceeded(_res);
				return;
			}

			move_pelvis.request.PositionDestination.x = -0.1;
			move_pelvis.request.PositionDestination.y = -0.0;
			move_pelvis.request.PositionDestination.z = 0.08;
			move_pelvis.request.AngleDestination.x = 0.0;
			move_pelvis.request.AngleDestination.y = 0.0;
			move_pelvis.request.AngleDestination.z = 0.0;
			move_pelvis.request.LinkToMove = "l_leg";
			ROS_INFO("Moving left leg forward");
			if(!move_pelvis_cli_.call(move_pelvis)){
				ROS_ERROR("Could not move left leg forward");
				C0_RobilTask::RobilTaskResult _res;
				_res.success = C0_RobilTask::RobilTask::FAULT;
				as_.setSucceeded(_res);
				return;
			}

			leg_target.request.leg = "l_foot";
			ROS_INFO("Moving to left leg");
			if(!pelvis_leg_target_cli_.call(leg_target)){
				ROS_ERROR("Could not move to left leg");
				C0_RobilTask::RobilTaskResult _res;
				_res.success = C0_RobilTask::RobilTask::FAULT;
				as_.setSucceeded(_res);
				return;
			}
			leg_target.request.leg = "l_foot";
			if(!pelvis_leg_target_cli_.call(leg_target)){
				ROS_ERROR("Could not move to left leg");
				C0_RobilTask::RobilTaskResult _res;
				_res.success = C0_RobilTask::RobilTask::FAULT;
				as_.setSucceeded(_res);
				return;
			}
			leg_target.request.leg = "l_foot";
			if(!pelvis_leg_target_cli_.call(leg_target)){
				ROS_ERROR("Could not move to left leg");
				C0_RobilTask::RobilTaskResult _res;
				_res.success = C0_RobilTask::RobilTask::FAULT;
				as_.setSucceeded(_res);
				return;
			}

			move_pelvis.request.PositionDestination.x = 0.0;
			move_pelvis.request.PositionDestination.y = 0.0;
			move_pelvis.request.PositionDestination.z = -0.1;
			move_pelvis.request.AngleDestination.x = 0.0;
			move_pelvis.request.AngleDestination.y = 0.0;
			move_pelvis.request.AngleDestination.z = 0.0;
			move_pelvis.request.LinkToMove = "r_leg";
			ROS_INFO("Moving right leg up");
			if(!move_pelvis_cli_.call(move_pelvis)){
				ROS_ERROR("Could not move left leg up");
				C0_RobilTask::RobilTaskResult _res;
				_res.success = C0_RobilTask::RobilTask::FAULT;
				as_.setSucceeded(_res);
				return;
			}

			move_pelvis.request.PositionDestination.x = -0.1;
			move_pelvis.request.PositionDestination.y = -0.0;
			move_pelvis.request.PositionDestination.z = 0.08;
			move_pelvis.request.AngleDestination.x = 0.0;
			move_pelvis.request.AngleDestination.y = 0.0;
			move_pelvis.request.AngleDestination.z = 0.0;
			move_pelvis.request.LinkToMove = "r_leg";
			ROS_INFO("Moving right leg forward");
			if(!move_pelvis_cli_.call(move_pelvis)){
				ROS_ERROR("Could not move left leg forward");
				C0_RobilTask::RobilTaskResult _res;
				_res.success = C0_RobilTask::RobilTask::FAULT;
				as_.setSucceeded(_res);
				return;
			}
		}




		if (as_.isPreemptRequested() || !ros::ok())
		{
			ROS_ERROR("%s: Preempted", action_name_.c_str());
			// set the action state to preempted
			as_.setPreempted();
		}

		C0_RobilTask::RobilTaskResult _res;
		_res.success = C0_RobilTask::RobilTask::SUCCESS;
		as_.setSucceeded(_res);
		ROS_INFO("End time: %f", ros::Time::now().toSec());
		return;
	}

	void preemptCB()
	{
		ROS_ERROR("%s: Preempted", action_name_.c_str());
		as_.setPreempted();
	}
};

int main(int argc, char **argv) {
	ros::init(argc, argv, "C41_QuasiStaticWalking");

	QuasiStaticWalking* QuasiStaticWalker = new QuasiStaticWalking("QuasiStaticWalking");
	ROS_INFO("Running QuasiStaticWalking action");
	ros::spin();

	return 0;
}