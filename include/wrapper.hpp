#include <algorithm>

#include <HTTPRequest.hpp>

#include <ros/ros.h>
#include <wled_ros_wrapper/WLED.h>

ros::NodeHandle* nh_ptr;
ros::Subscriber subscriber;

void topic_callback(const wled_ros_wrapper::WLED::ConstPtr& msg);