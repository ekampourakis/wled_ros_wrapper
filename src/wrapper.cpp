#include <wrapper.hpp>

int main(int argc, char** argv) {
    ros::init(argc, argv, "wled_ros_wrapper");
    ros::NodeHandle nh("wled_ros_wrapper");
    nh_ptr = &nh;

    // Set the ROS logging level (for better debugging)
    if (ros::console::set_logger_level(ROSCONSOLE_DEFAULT_NAME, ros::console::levels::Debug)) {
        ros::console::notifyLoggerLevelsChanged();
    }

    subscriber = nh.subscribe("set", 1, topic_callback);

    ros::spin();
    return 0;
}

void topic_callback(const wled_ros_wrapper::WLED::ConstPtr& msg) {
    try {
        // Load the address parameter from the ROS parameter server
        std::string address;
        nh_ptr->param<std::string>("address", address, "wled.local");

        // Create the base link of the request
        std::string request = "http://" + address + "/win";

        // Populate the request's fields
        if (msg->state) {
            request += "&T=1";
            request += "&A=" + std::to_string(msg->brightness);
            request += "&R=" + std::to_string(msg->r);
            request += "&G=" + std::to_string(msg->g);
            request += "&B=" + std::to_string(msg->b);
            request += "&W=" + std::to_string(msg->a);
            request += "&FX=" + std::to_string(msg->effect.type);
            request += "&SX=" + std::to_string(msg->effect.speed);
            request += "&IX=" + std::to_string(msg->effect.intensity);
        } else {
            request += "&T=0";
        }

        // Send the GET request
        http::Request get{request};
        get.send("GET");
    } catch (const std::exception& e) {
        ROS_ERROR("Request failed, error: %s", e.what());
    }
}