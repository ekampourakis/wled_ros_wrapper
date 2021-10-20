#include <ros/ros.h>

#include <wled_ros_wrapper/WLED.h>

ros::Subscriber subscriber;

void topic_callback(const wled_ros_wrapper::WLED::ConstPtr& msg);