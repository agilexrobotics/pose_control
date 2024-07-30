;; Auto-generated. Do not edit!


(when (boundp 'arm_control::JointInformation)
  (if (not (find-package "ARM_CONTROL"))
    (make-package "ARM_CONTROL"))
  (shadow 'JointInformation (find-package "ARM_CONTROL")))
(unless (find-package "ARM_CONTROL::JOINTINFORMATION")
  (make-package "ARM_CONTROL::JOINTINFORMATION"))

(in-package "ROS")
;;//! \htmlinclude JointInformation.msg.html


(defclass arm_control::JointInformation
  :super ros::object
  :slots (_joint_pos _joint_vel _joint_cur _mode ))

(defmethod arm_control::JointInformation
  (:init
   (&key
    ((:joint_pos __joint_pos) (make-array 7 :initial-element 0.0 :element-type :float))
    ((:joint_vel __joint_vel) (make-array 7 :initial-element 0.0 :element-type :float))
    ((:joint_cur __joint_cur) (make-array 7 :initial-element 0.0 :element-type :float))
    ((:mode __mode) 0)
    )
   (send-super :init)
   (setq _joint_pos __joint_pos)
   (setq _joint_vel __joint_vel)
   (setq _joint_cur __joint_cur)
   (setq _mode (round __mode))
   self)
  (:joint_pos
   (&optional __joint_pos)
   (if __joint_pos (setq _joint_pos __joint_pos)) _joint_pos)
  (:joint_vel
   (&optional __joint_vel)
   (if __joint_vel (setq _joint_vel __joint_vel)) _joint_vel)
  (:joint_cur
   (&optional __joint_cur)
   (if __joint_cur (setq _joint_cur __joint_cur)) _joint_cur)
  (:mode
   (&optional __mode)
   (if __mode (setq _mode __mode)) _mode)
  (:serialization-length
   ()
   (+
    ;; float32[7] _joint_pos
    (* 4    7)
    ;; float32[7] _joint_vel
    (* 4    7)
    ;; float32[7] _joint_cur
    (* 4    7)
    ;; int32 _mode
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32[7] _joint_pos
     (dotimes (i 7)
       (sys::poke (elt _joint_pos i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[7] _joint_vel
     (dotimes (i 7)
       (sys::poke (elt _joint_vel i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[7] _joint_cur
     (dotimes (i 7)
       (sys::poke (elt _joint_cur i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; int32 _mode
       (write-long _mode s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32[7] _joint_pos
   (dotimes (i (length _joint_pos))
     (setf (elt _joint_pos i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;; float32[7] _joint_vel
   (dotimes (i (length _joint_vel))
     (setf (elt _joint_vel i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;; float32[7] _joint_cur
   (dotimes (i (length _joint_cur))
     (setf (elt _joint_cur i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;; int32 _mode
     (setq _mode (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get arm_control::JointInformation :md5sum-) "86ad2a9a176a812901cac6f69b936f2e")
(setf (get arm_control::JointInformation :datatype-) "arm_control/JointInformation")
(setf (get arm_control::JointInformation :definition-)
      "float32[7] joint_pos
float32[7] joint_vel
float32[7] joint_cur
int32 mode
")



(provide :arm_control/JointInformation "86ad2a9a176a812901cac6f69b936f2e")


