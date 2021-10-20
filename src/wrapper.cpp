#include <wrapper.hpp>

int main(int argc, char** argv) {
    ros::init(argc, argv, "wled_ros_wrapper");

    ros::NodeHandle nh;

    subscriber = nh.subscribe("set", 1, topic_callback);

    ros::spin();

    return 0;
}

void topic_callback(const wled_ros_wrapper::WLED::ConstPtr& msg) {
    ROS_INFO("Got a new request");
}