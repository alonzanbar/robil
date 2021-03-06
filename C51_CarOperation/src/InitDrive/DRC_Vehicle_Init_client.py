#!/usr/bin/env python
import roslib; roslib.load_manifest('C51_CarOperation')
import rospy
import actionlib
import C51_CarOperation.msg


def InitDrive_client():
    # Creates the SimpleActionClient, passing the type of the action
    # (FibonacciAction) to the constructor.
    client = actionlib.SimpleActionClient('InitDrive', C51_CarOperation.msg.DriveAction)

    # Waits until the action server has started up and started
    # listening for goals.
    client.wait_for_server()

    # Creates a goal to send to the action server.
    goal = C51_CarOperation.msg.DriveGoal(name='moshe',uid='5',parameters='xyz')

    # Sends the goal to the action server.
    client.send_goal(goal)

    # Waits for the server to finish performing the action.
    client.wait_for_result()

    # Prints out the result of executing the action
    return client.get_result()  

if __name__ == '__main__':
    try:
        # Initializes a rospy node so that the SimpleActionClient can
        # publish and subscribe over ROS.
        rospy.init_node('InitDrive_client')
        result =  InitDrive_client()
        if result:
            print 'Car is initialized and ready to go - hand brake released and brake pedal is pressed!'
    except rospy.ROSInterruptException:
        print "Initialization interrupted before completion"
