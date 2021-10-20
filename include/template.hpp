#include <ros/ros.h>

#include <package_template/TemplateMessage.h>
#include <package_template/TemplateService.h>

ros::Subscriber subscriber;
ros::Publisher publisher;
ros::ServiceServer service;
ros::ServiceClient client;