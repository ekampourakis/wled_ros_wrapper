#include <template.hpp>

void topic_callback(const package_template::TemplateMessage::ConstPtr& msg) {
    ROS_INFO("%s", msg->Text.c_str());
}

bool service_callback(package_template::TemplateService::Request &req, package_template::TemplateService::Response &res) {
    ROS_INFO("%s", req.Request.c_str());
    res.Response = "Response from C++";
    return true;
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "package_template_cpp");

    ros::NodeHandle nh;

    subscriber = nh.subscribe("/cpp_subscriber", 1, topic_callback);
    publisher = nh.advertise<package_template::TemplateMessage>("/python_subscriber", 1);
    service = nh.advertiseService("/cpp_service", service_callback);
    client = nh.serviceClient<package_template::TemplateService>("/python_service");

    ros::Rate rate(10);  
    while (ros::ok()) {
        package_template::TemplateMessage msg;
        msg.Text = "Hello from C++";
        publisher.publish(msg);

        package_template::TemplateService srv;
        srv.request.Request = "Request from C++";
        client.call(srv);

        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}