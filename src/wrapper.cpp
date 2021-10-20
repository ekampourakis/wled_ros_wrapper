#include <wrapper.hpp>

int main(int argc, char** argv) {
    ros::init(argc, argv, "wled_ros_wrapper");
    ros::NodeHandle nh("wled_ros_wrapper");
    nh_ptr = &nh;

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
        request += "&T=" + msg->state ? "1" : "0";
        request += "&A=" + std::to_string(msg->brightness);
        request += "&R=" + std::to_string(std::clamp<char>(msg->color.r, 0, 255));
        request += "&G=" + std::to_string(std::clamp<char>(msg->color.g, 0, 255));
        request += "&B=" + std::to_string(std::clamp<char>(msg->color.b, 0, 255));
        request += "&W=" + std::to_string(std::clamp<char>(msg->color.a, 0, 255));
        request += "&FX=" + std::to_string(msg->effect.type);
        request += "&SX=" + std::to_string(msg->effect.speed);
        request += "&IX=" + std::to_string(msg->effect.intensity);

        // Send the GET request
        http::Request get{request};
        get.send("GET");
    } catch (const std::exception& e) {
        ROS_ERROR("Request failed, error: %s", e.what());
    }
}