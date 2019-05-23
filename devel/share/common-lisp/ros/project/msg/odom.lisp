; Auto-generated. Do not edit!


(cl:in-package project-msg)


;//! \htmlinclude odom.msg.html

(cl:defclass <odom> (roslisp-msg-protocol:ros-message)
  ((x_value
    :reader x_value
    :initarg :x_value
    :type cl:float
    :initform 0.0)
   (y_value
    :reader y_value
    :initarg :y_value
    :type cl:float
    :initform 0.0)
   (theta
    :reader theta
    :initarg :theta
    :type cl:float
    :initform 0.0))
)

(cl:defclass odom (<odom>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <odom>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'odom)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name project-msg:<odom> is deprecated: use project-msg:odom instead.")))

(cl:ensure-generic-function 'x_value-val :lambda-list '(m))
(cl:defmethod x_value-val ((m <odom>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project-msg:x_value-val is deprecated.  Use project-msg:x_value instead.")
  (x_value m))

(cl:ensure-generic-function 'y_value-val :lambda-list '(m))
(cl:defmethod y_value-val ((m <odom>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project-msg:y_value-val is deprecated.  Use project-msg:y_value instead.")
  (y_value m))

(cl:ensure-generic-function 'theta-val :lambda-list '(m))
(cl:defmethod theta-val ((m <odom>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader project-msg:theta-val is deprecated.  Use project-msg:theta instead.")
  (theta m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <odom>) ostream)
  "Serializes a message object of type '<odom>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'x_value))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'y_value))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'theta))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <odom>) istream)
  "Deserializes a message object of type '<odom>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'x_value) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'y_value) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'theta) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<odom>)))
  "Returns string type for a message object of type '<odom>"
  "project/odom")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'odom)))
  "Returns string type for a message object of type 'odom"
  "project/odom")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<odom>)))
  "Returns md5sum for a message object of type '<odom>"
  "8759f9f7c1bf1b646c210b6a32c081e4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'odom)))
  "Returns md5sum for a message object of type 'odom"
  "8759f9f7c1bf1b646c210b6a32c081e4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<odom>)))
  "Returns full string definition for message of type '<odom>"
  (cl:format cl:nil "float64 x_value~%float64 y_value~%float64 theta~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'odom)))
  "Returns full string definition for message of type 'odom"
  (cl:format cl:nil "float64 x_value~%float64 y_value~%float64 theta~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <odom>))
  (cl:+ 0
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <odom>))
  "Converts a ROS message object to a list"
  (cl:list 'odom
    (cl:cons ':x_value (x_value msg))
    (cl:cons ':y_value (y_value msg))
    (cl:cons ':theta (theta msg))
))
