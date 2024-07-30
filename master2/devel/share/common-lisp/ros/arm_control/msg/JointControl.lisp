; Auto-generated. Do not edit!


(cl:in-package arm_control-msg)


;//! \htmlinclude JointControl.msg.html

(cl:defclass <JointControl> (roslisp-msg-protocol:ros-message)
  ((joint_pos
    :reader joint_pos
    :initarg :joint_pos
    :type (cl:vector cl:float)
   :initform (cl:make-array 7 :element-type 'cl:float :initial-element 0.0))
   (joint_vel
    :reader joint_vel
    :initarg :joint_vel
    :type (cl:vector cl:float)
   :initform (cl:make-array 7 :element-type 'cl:float :initial-element 0.0))
   (joint_cur
    :reader joint_cur
    :initarg :joint_cur
    :type (cl:vector cl:float)
   :initform (cl:make-array 7 :element-type 'cl:float :initial-element 0.0))
   (mode
    :reader mode
    :initarg :mode
    :type cl:integer
    :initform 0))
)

(cl:defclass JointControl (<JointControl>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <JointControl>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'JointControl)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name arm_control-msg:<JointControl> is deprecated: use arm_control-msg:JointControl instead.")))

(cl:ensure-generic-function 'joint_pos-val :lambda-list '(m))
(cl:defmethod joint_pos-val ((m <JointControl>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader arm_control-msg:joint_pos-val is deprecated.  Use arm_control-msg:joint_pos instead.")
  (joint_pos m))

(cl:ensure-generic-function 'joint_vel-val :lambda-list '(m))
(cl:defmethod joint_vel-val ((m <JointControl>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader arm_control-msg:joint_vel-val is deprecated.  Use arm_control-msg:joint_vel instead.")
  (joint_vel m))

(cl:ensure-generic-function 'joint_cur-val :lambda-list '(m))
(cl:defmethod joint_cur-val ((m <JointControl>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader arm_control-msg:joint_cur-val is deprecated.  Use arm_control-msg:joint_cur instead.")
  (joint_cur m))

(cl:ensure-generic-function 'mode-val :lambda-list '(m))
(cl:defmethod mode-val ((m <JointControl>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader arm_control-msg:mode-val is deprecated.  Use arm_control-msg:mode instead.")
  (mode m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <JointControl>) ostream)
  "Serializes a message object of type '<JointControl>"
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'joint_pos))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'joint_vel))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'joint_cur))
  (cl:let* ((signed (cl:slot-value msg 'mode)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <JointControl>) istream)
  "Deserializes a message object of type '<JointControl>"
  (cl:setf (cl:slot-value msg 'joint_pos) (cl:make-array 7))
  (cl:let ((vals (cl:slot-value msg 'joint_pos)))
    (cl:dotimes (i 7)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
  (cl:setf (cl:slot-value msg 'joint_vel) (cl:make-array 7))
  (cl:let ((vals (cl:slot-value msg 'joint_vel)))
    (cl:dotimes (i 7)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
  (cl:setf (cl:slot-value msg 'joint_cur) (cl:make-array 7))
  (cl:let ((vals (cl:slot-value msg 'joint_cur)))
    (cl:dotimes (i 7)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'mode) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<JointControl>)))
  "Returns string type for a message object of type '<JointControl>"
  "arm_control/JointControl")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'JointControl)))
  "Returns string type for a message object of type 'JointControl"
  "arm_control/JointControl")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<JointControl>)))
  "Returns md5sum for a message object of type '<JointControl>"
  "86ad2a9a176a812901cac6f69b936f2e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'JointControl)))
  "Returns md5sum for a message object of type 'JointControl"
  "86ad2a9a176a812901cac6f69b936f2e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<JointControl>)))
  "Returns full string definition for message of type '<JointControl>"
  (cl:format cl:nil "float32[7] joint_pos~%float32[7] joint_vel~%float32[7] joint_cur~%int32 mode~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'JointControl)))
  "Returns full string definition for message of type 'JointControl"
  (cl:format cl:nil "float32[7] joint_pos~%float32[7] joint_vel~%float32[7] joint_cur~%int32 mode~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <JointControl>))
  (cl:+ 0
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'joint_pos) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'joint_vel) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'joint_cur) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <JointControl>))
  "Converts a ROS message object to a list"
  (cl:list 'JointControl
    (cl:cons ':joint_pos (joint_pos msg))
    (cl:cons ':joint_vel (joint_vel msg))
    (cl:cons ':joint_cur (joint_cur msg))
    (cl:cons ':mode (mode msg))
))
