; Auto-generated. Do not edit!


(cl:in-package C22_GroundRecognitionAndMapping-msg)


;//! \htmlinclude C0C22_AZI.msg.html

(cl:defclass <C0C22_AZI> (roslisp-msg-protocol:ros-message)
  ((azimuth
    :reader azimuth
    :initarg :azimuth
    :type cl:float
    :initform 0.0))
)

(cl:defclass C0C22_AZI (<C0C22_AZI>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <C0C22_AZI>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'C0C22_AZI)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name C22_GroundRecognitionAndMapping-msg:<C0C22_AZI> is deprecated: use C22_GroundRecognitionAndMapping-msg:C0C22_AZI instead.")))

(cl:ensure-generic-function 'azimuth-val :lambda-list '(m))
(cl:defmethod azimuth-val ((m <C0C22_AZI>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader C22_GroundRecognitionAndMapping-msg:azimuth-val is deprecated.  Use C22_GroundRecognitionAndMapping-msg:azimuth instead.")
  (azimuth m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <C0C22_AZI>) ostream)
  "Serializes a message object of type '<C0C22_AZI>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'azimuth))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <C0C22_AZI>) istream)
  "Deserializes a message object of type '<C0C22_AZI>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'azimuth) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<C0C22_AZI>)))
  "Returns string type for a message object of type '<C0C22_AZI>"
  "C22_GroundRecognitionAndMapping/C0C22_AZI")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'C0C22_AZI)))
  "Returns string type for a message object of type 'C0C22_AZI"
  "C22_GroundRecognitionAndMapping/C0C22_AZI")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<C0C22_AZI>)))
  "Returns md5sum for a message object of type '<C0C22_AZI>"
  "1ad4832faa8759062b7c12092a041b10")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'C0C22_AZI)))
  "Returns md5sum for a message object of type 'C0C22_AZI"
  "1ad4832faa8759062b7c12092a041b10")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<C0C22_AZI>)))
  "Returns full string definition for message of type '<C0C22_AZI>"
  (cl:format cl:nil "float32 azimuth~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'C0C22_AZI)))
  "Returns full string definition for message of type 'C0C22_AZI"
  (cl:format cl:nil "float32 azimuth~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <C0C22_AZI>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <C0C22_AZI>))
  "Converts a ROS message object to a list"
  (cl:list 'C0C22_AZI
    (cl:cons ':azimuth (azimuth msg))
))
