;; Auto-generated. Do not edit!


(when (boundp 'project::odom)
  (if (not (find-package "PROJECT"))
    (make-package "PROJECT"))
  (shadow 'odom (find-package "PROJECT")))
(unless (find-package "PROJECT::ODOM")
  (make-package "PROJECT::ODOM"))

(in-package "ROS")
;;//! \htmlinclude odom.msg.html


(defclass project::odom
  :super ros::object
  :slots (_x_value _y_value _theta ))

(defmethod project::odom
  (:init
   (&key
    ((:x_value __x_value) 0.0)
    ((:y_value __y_value) 0.0)
    ((:theta __theta) 0.0)
    )
   (send-super :init)
   (setq _x_value (float __x_value))
   (setq _y_value (float __y_value))
   (setq _theta (float __theta))
   self)
  (:x_value
   (&optional __x_value)
   (if __x_value (setq _x_value __x_value)) _x_value)
  (:y_value
   (&optional __y_value)
   (if __y_value (setq _y_value __y_value)) _y_value)
  (:theta
   (&optional __theta)
   (if __theta (setq _theta __theta)) _theta)
  (:serialization-length
   ()
   (+
    ;; float64 _x_value
    8
    ;; float64 _y_value
    8
    ;; float64 _theta
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _x_value
       (sys::poke _x_value (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _y_value
       (sys::poke _y_value (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _theta
       (sys::poke _theta (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _x_value
     (setq _x_value (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _y_value
     (setq _y_value (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _theta
     (setq _theta (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get project::odom :md5sum-) "8759f9f7c1bf1b646c210b6a32c081e4")
(setf (get project::odom :datatype-) "project/odom")
(setf (get project::odom :definition-)
      "float64 x_value
float64 y_value
float64 theta

")



(provide :project/odom "8759f9f7c1bf1b646c210b6a32c081e4")


