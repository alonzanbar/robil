; Auto-generated. Do not edit!


(cl:in-package C66_Grasp-msg)


;//! \htmlinclude C66_GraspAction.msg.html

(cl:defclass <C66_GraspAction> (roslisp-msg-protocol:ros-message)
  ((action_goal
    :reader action_goal
    :initarg :action_goal
    :type C66_Grasp-msg:C66_GraspActionGoal
    :initform (cl:make-instance 'C66_Grasp-msg:C66_GraspActionGoal))
   (action_result
    :reader action_result
    :initarg :action_result
    :type C66_Grasp-msg:C66_GraspActionResult
    :initform (cl:make-instance 'C66_Grasp-msg:C66_GraspActionResult))
   (action_feedback
    :reader action_feedback
    :initarg :action_feedback
    :type C66_Grasp-msg:C66_GraspActionFeedback
    :initform (cl:make-instance 'C66_Grasp-msg:C66_GraspActionFeedback)))
)

(cl:defclass C66_GraspAction (<C66_GraspAction>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <C66_GraspAction>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'C66_GraspAction)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name C66_Grasp-msg:<C66_GraspAction> is deprecated: use C66_Grasp-msg:C66_GraspAction instead.")))

(cl:ensure-generic-function 'action_goal-val :lambda-list '(m))
(cl:defmethod action_goal-val ((m <C66_GraspAction>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader C66_Grasp-msg:action_goal-val is deprecated.  Use C66_Grasp-msg:action_goal instead.")
  (action_goal m))

(cl:ensure-generic-function 'action_result-val :lambda-list '(m))
(cl:defmethod action_result-val ((m <C66_GraspAction>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader C66_Grasp-msg:action_result-val is deprecated.  Use C66_Grasp-msg:action_result instead.")
  (action_result m))

(cl:ensure-generic-function 'action_feedback-val :lambda-list '(m))
(cl:defmethod action_feedback-val ((m <C66_GraspAction>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader C66_Grasp-msg:action_feedback-val is deprecated.  Use C66_Grasp-msg:action_feedback instead.")
  (action_feedback m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <C66_GraspAction>) ostream)
  "Serializes a message object of type '<C66_GraspAction>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'action_goal) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'action_result) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'action_feedback) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <C66_GraspAction>) istream)
  "Deserializes a message object of type '<C66_GraspAction>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'action_goal) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'action_result) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'action_feedback) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<C66_GraspAction>)))
  "Returns string type for a message object of type '<C66_GraspAction>"
  "C66_Grasp/C66_GraspAction")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'C66_GraspAction)))
  "Returns string type for a message object of type 'C66_GraspAction"
  "C66_Grasp/C66_GraspAction")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<C66_GraspAction>)))
  "Returns md5sum for a message object of type '<C66_GraspAction>"
  "c29f3d2056fcd9404762cae3b12aba05")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'C66_GraspAction)))
  "Returns md5sum for a message object of type 'C66_GraspAction"
  "c29f3d2056fcd9404762cae3b12aba05")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<C66_GraspAction>)))
  "Returns full string definition for message of type '<C66_GraspAction>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%~%C66_GraspActionGoal action_goal~%C66_GraspActionResult action_result~%C66_GraspActionFeedback action_feedback~%~%================================================================================~%MSG: C66_Grasp/C66_GraspActionGoal~%# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%~%Header header~%actionlib_msgs/GoalID goal_id~%C66_GraspGoal goal~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: actionlib_msgs/GoalID~%# The stamp should store the time at which this goal was requested.~%# It is used by an action server when it tries to preempt all~%# goals that were requested before a certain time~%time stamp~%~%# The id provides a way to associate feedback and~%# result message with specific goal requests. The id~%# specified must be unique.~%string id~%~%~%================================================================================~%MSG: C66_Grasp/C66_GraspGoal~%# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#goal definition~%float32[2] location~%int32 max~%~%================================================================================~%MSG: C66_Grasp/C66_GraspActionResult~%# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%~%Header header~%actionlib_msgs/GoalStatus status~%C66_GraspResult result~%~%================================================================================~%MSG: actionlib_msgs/GoalStatus~%GoalID goal_id~%uint8 status~%uint8 PENDING         = 0   # The goal has yet to be processed by the action server~%uint8 ACTIVE          = 1   # The goal is currently being processed by the action server~%uint8 PREEMPTED       = 2   # The goal received a cancel request after it started executing~%                            #   and has since completed its execution (Terminal State)~%uint8 SUCCEEDED       = 3   # The goal was achieved successfully by the action server (Terminal State)~%uint8 ABORTED         = 4   # The goal was aborted during execution by the action server due~%                            #    to some failure (Terminal State)~%uint8 REJECTED        = 5   # The goal was rejected by the action server without being processed,~%                            #    because the goal was unattainable or invalid (Terminal State)~%uint8 PREEMPTING      = 6   # The goal received a cancel request after it started executing~%                            #    and has not yet completed execution~%uint8 RECALLING       = 7   # The goal received a cancel request before it started executing,~%                            #    but the action server has not yet confirmed that the goal is canceled~%uint8 RECALLED        = 8   # The goal received a cancel request before it started executing~%                            #    and was successfully cancelled (Terminal State)~%uint8 LOST            = 9   # An action client can determine that a goal is LOST. This should not be~%                            #    sent over the wire by an action server~%~%#Allow for the user to associate a string with GoalStatus for debugging~%string text~%~%~%================================================================================~%MSG: C66_Grasp/C66_GraspResult~%# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#result definition~%bool success~%~%================================================================================~%MSG: C66_Grasp/C66_GraspActionFeedback~%# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%~%Header header~%actionlib_msgs/GoalStatus status~%C66_GraspFeedback feedback~%~%================================================================================~%MSG: C66_Grasp/C66_GraspFeedback~%# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#feedback~%float32[2] location~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'C66_GraspAction)))
  "Returns full string definition for message of type 'C66_GraspAction"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%~%C66_GraspActionGoal action_goal~%C66_GraspActionResult action_result~%C66_GraspActionFeedback action_feedback~%~%================================================================================~%MSG: C66_Grasp/C66_GraspActionGoal~%# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%~%Header header~%actionlib_msgs/GoalID goal_id~%C66_GraspGoal goal~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: actionlib_msgs/GoalID~%# The stamp should store the time at which this goal was requested.~%# It is used by an action server when it tries to preempt all~%# goals that were requested before a certain time~%time stamp~%~%# The id provides a way to associate feedback and~%# result message with specific goal requests. The id~%# specified must be unique.~%string id~%~%~%================================================================================~%MSG: C66_Grasp/C66_GraspGoal~%# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#goal definition~%float32[2] location~%int32 max~%~%================================================================================~%MSG: C66_Grasp/C66_GraspActionResult~%# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%~%Header header~%actionlib_msgs/GoalStatus status~%C66_GraspResult result~%~%================================================================================~%MSG: actionlib_msgs/GoalStatus~%GoalID goal_id~%uint8 status~%uint8 PENDING         = 0   # The goal has yet to be processed by the action server~%uint8 ACTIVE          = 1   # The goal is currently being processed by the action server~%uint8 PREEMPTED       = 2   # The goal received a cancel request after it started executing~%                            #   and has since completed its execution (Terminal State)~%uint8 SUCCEEDED       = 3   # The goal was achieved successfully by the action server (Terminal State)~%uint8 ABORTED         = 4   # The goal was aborted during execution by the action server due~%                            #    to some failure (Terminal State)~%uint8 REJECTED        = 5   # The goal was rejected by the action server without being processed,~%                            #    because the goal was unattainable or invalid (Terminal State)~%uint8 PREEMPTING      = 6   # The goal received a cancel request after it started executing~%                            #    and has not yet completed execution~%uint8 RECALLING       = 7   # The goal received a cancel request before it started executing,~%                            #    but the action server has not yet confirmed that the goal is canceled~%uint8 RECALLED        = 8   # The goal received a cancel request before it started executing~%                            #    and was successfully cancelled (Terminal State)~%uint8 LOST            = 9   # An action client can determine that a goal is LOST. This should not be~%                            #    sent over the wire by an action server~%~%#Allow for the user to associate a string with GoalStatus for debugging~%string text~%~%~%================================================================================~%MSG: C66_Grasp/C66_GraspResult~%# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#result definition~%bool success~%~%================================================================================~%MSG: C66_Grasp/C66_GraspActionFeedback~%# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%~%Header header~%actionlib_msgs/GoalStatus status~%C66_GraspFeedback feedback~%~%================================================================================~%MSG: C66_Grasp/C66_GraspFeedback~%# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#feedback~%float32[2] location~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <C66_GraspAction>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'action_goal))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'action_result))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'action_feedback))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <C66_GraspAction>))
  "Converts a ROS message object to a list"
  (cl:list 'C66_GraspAction
    (cl:cons ':action_goal (action_goal msg))
    (cl:cons ':action_result (action_result msg))
    (cl:cons ':action_feedback (action_feedback msg))
))
