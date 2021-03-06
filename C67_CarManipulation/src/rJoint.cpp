/*
 * Copyright 2012 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
#include <math.h>
#include <ros/ros.h>
#include <ros/subscribe_options.h>
#include <boost/thread.hpp>
#include <boost/algorithm/string.hpp>
#include <atlas_msgs/AtlasState.h>
#include <atlas_msgs/AtlasCommand.h>
#include "std_msgs/String.h"
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <boost/lexical_cast.hpp>
#include <C67_CarManipulation/FK.h>
#include <C67_CarManipulation/IK.h>
#include <C67_CarManipulation/Path.h>

ros::Publisher pubAtlasCommand;
atlas_msgs::AtlasCommand ac;
atlas_msgs::AtlasState as;
boost::mutex mutex;
ros::Time t0;
const unsigned int numJoints = 28;


int	 callback_called = 0;
RPY argTarget;
bool use_arg = false;
bool callBackRun = false;

void SetAtlasState(const atlas_msgs::AtlasState::ConstPtr &_as)
{
	
	if (callBackRun == false)
	{
		callBackRun = true;

		static ros::Time startTime = ros::Time::now();
			t0 = startTime;

		// lock to copy incoming AtlasState
		{
			boost::mutex::scoped_lock lock(mutex);
			as = *_as;
		}

		ac.header.stamp = as.header.stamp;
		// set cout presentation	
		std::cout.precision(6);
		std::cout.setf (std::ios::fixed , std::ios::floatfield ); 
		// print current state
		std::cout << "Current Position:\n";
		IkSolution IkCurrent = IkSolution(as.position[q4r],as.position[q5r],
			as.position[q6r],	as.position[q7r], as.position[q8r], as.position[q9r]);
		IkCurrent.Print();	
		RPY rCurrent = rPose(as.position[q1], as.position[q2],as.position[q3],IkCurrent);
		rCurrent.Print();
	}


  // uncomment to simulate state filtering
  // usleep(1000);
}



int main(int argc, char** argv)
{
	int pointsNum;
	double seconds;
	int angleNum = 0;
	double angleVal = 0;

	if (argc == 5)
	{

		angleNum = boost::lexical_cast<int>(argv[1]);
		angleVal = boost::lexical_cast<double>(argv[2]);

		seconds =  boost::lexical_cast<double>(argv[3]);
		pointsNum = boost::lexical_cast<int>(argv[4]);
		if ((angleNum >= 4)&&(angleNum <= 9)) use_arg = true;
	}
   
  ros::init(argc, argv, "pub_joint_command_rhand");

  ros::NodeHandle* rosnode = new ros::NodeHandle();

  ros::Time last_ros_time_;
  bool wait = true;
  while (wait)
  {
    last_ros_time_ = ros::Time::now();
    if (last_ros_time_.toSec() > 0)
      wait = false;
  }

	unsigned int n = numJoints;
	ac.position.resize(n);
	ac.k_effort.resize(n);
	ac.velocity.resize(n);
	ac.effort.resize(n);
	ac.kp_position.resize(n);
	ac.ki_position.resize(n);
	ac.kd_position.resize(n);
	ac.kp_velocity.resize(n);
	ac.i_effort_min.resize(n);
	ac.i_effort_max.resize(n);

	// ros topic subscribtions
	ros::SubscribeOptions atlasStateSo =
		ros::SubscribeOptions::create <atlas_msgs::AtlasState> (
		"/atlas/atlas_state", 100, SetAtlasState,
		ros::VoidPtr(), rosnode->getCallbackQueue());


  atlasStateSo.transport_hints = ros::TransportHints().reliable().tcpNoDelay(true);
  ros::Subscriber subAtlasState = rosnode->subscribe(atlasStateSo);

  // ros topic publisher
    pubAtlasCommand = rosnode->advertise<atlas_msgs::AtlasCommand>(
      "/atlas/atlas_command", 1, true);
	
	while (ros::ok())
	{
		ros::spinOnce();
		/*if (callback_called == 1)
		{
			subJointStates.~Subscriber();
			callback_called++;
			break;
		}*/
		if (callBackRun)
		{

			// check if no arguments
			if (!use_arg) break;

			for (unsigned int i = 0; i < n; i++)
			{
				ac.kp_position[i] = as.kp_position[i];
				ac.ki_position[i] = as.ki_position[i];
				ac.kd_position[i] = as.kd_position[i];
				ac.i_effort_min[i] = as.i_effort_min[i];
				ac.i_effort_max[i] = as.i_effort_max[i];

				ac.velocity[i] = 0;
				ac.effort[i] = 0;
				ac.kp_velocity[i] = 0;

			}
						
			IkSolution IkCurrent = IkSolution(as.position[q4r], as.position[q5r], as.position[q6r], as.position[q7r],
				as.position[q8r], as.position[q9r]);
			IkSolution IkNext;

			switch (angleNum)
			{
			case 4:
				angleVal = (angleVal > q4rMax? q4rMax: angleVal);
				angleVal = (angleVal < q4rMin? q4rMin: angleVal);
				std::cout<< "angle q4: " << angleVal << " Limits("<< q4rMin << ", "<<
						q4rMax << ")\n";
				IkNext = IkSolution(angleVal, as.position[q5r], as.position[q6r], as.position[q7r],
						as.position[q8r], as.position[q9r]);
				break;

			case 5:
				angleVal = (angleVal > q5rMax? q5rMax: angleVal);
				angleVal = (angleVal < q5rMin? q5rMin: angleVal);
				std::cout<< "angle q5: " << angleVal << " Limits("<< q5rMin << ", "<<
						q5rMax << ")\n";
				IkNext = IkSolution(as.position[q4r], angleVal, as.position[q6r], as.position[q7r],
						as.position[q8r], as.position[q9r]);
				break;

			case 6:
				angleVal = (angleVal > q6rMax? q6rMax: angleVal);
				angleVal = (angleVal < q6rMin? q6rMin: angleVal);
				std::cout<< "angle q6: " << angleVal << " Limits("<< q6rMin << ", "<<
						q6rMax << ")\n";
				IkNext = IkSolution(as.position[q4r], as.position[q5r], angleVal, as.position[q7r],
						as.position[q8r], as.position[q9r]);
				break;

			case 7:
				angleVal = (angleVal > q7rMax? q7rMax: angleVal);
				angleVal = (angleVal < q7rMin? q7rMin: angleVal);
				std::cout<< "angle q7: " << angleVal << " Limits("<< q7rMin << ", "<<
						q7rMax << ")\n";
				IkNext = IkSolution(as.position[q4r], as.position[q5r], as.position[q6r], angleVal,
						as.position[q8r], as.position[q9r]);
				break;

			case 8:
				angleVal = (angleVal > q8rMax? q8rMax: angleVal);
				angleVal = (angleVal < q8rMin? q8rMin: angleVal);
				std::cout<< "angle q8: " << angleVal << " Limits("<< q8rMin << ", "<<
						q8rMax << ")\n";
				IkNext = IkSolution(as.position[q4r], as.position[q5r], as.position[q6r], as.position[q7r],
						angleVal, as.position[q9r]);
				break;

			case 9:
				angleVal = (angleVal > q9rMax? q9rMax: angleVal);
				angleVal = (angleVal < q9rMin? q9rMin: angleVal);
				std::cout<< "angle q9: " << angleVal << " Limits("<< q9rMin << ", "<<
						q9rMax << ")\n";
				IkNext = IkSolution(as.position[q4r], as.position[q5r], as.position[q6r], as.position[q7r],
						as.position[q8r], angleVal);
				break;
			}

			IkNext.Print();
			RPY r = rPose(as.position[q1], as.position[q2], as.position[q3], IkNext);
			r.Print();
			
			
			pPathPoints points = pPathPoints(IkCurrent, IkNext, pointsNum);

			ac.k_effort[q4l]  = 255;
			ac.k_effort[q5l]  = 255;
			ac.k_effort[q6l]  = 255;
			ac.k_effort[q7l]  = 255;
			ac.k_effort[q8l]  = 255;
			ac.k_effort[q9l]  = 255;
			ac.k_effort[q4r]  = 255;
			ac.k_effort[q5r]  = 255;
			ac.k_effort[q6r]  = 255;
			ac.k_effort[q7r]  = 255;
			ac.k_effort[q8r]  = 255;
			ac.k_effort[q9r]  = 255;
			
			for (unsigned int i=0; i < numJoints; i++)
			{
				ac.position[i] = as.position[i];
				ac.k_effort[i]  = 255;
				//std::cout << state[j] << " ";
			}

			for (int i=0; i < pointsNum; i++)
			{
				// ros::spinOnce();
				// assign current joint angles 


				ac.position[q4r] = points.pArray[i]._q4;
				ac.position[q5r] = points.pArray[i]._q5;
				ac.position[q6r] = points.pArray[i]._q6;
				ac.position[q7r] = points.pArray[i]._q7;
				ac.position[q8r] = points.pArray[i]._q8;
				ac.position[q9r] = points.pArray[i]._q9;
				
				//ROS_INFO("");
				//std::cout << i <<": ";				
				//points.Array[i].Print();
				//std::cout << "q8 = "<< ac.position[q8r] << "\n";
				//ac.desired_controller_period_ms = 5;

				pubAtlasCommand.publish(ac);
					
				ros::Duration(seconds/pointsNum).sleep();
			}
			break;
		}
		ros::Duration(0.1).sleep();
	}

  return 0;
}
