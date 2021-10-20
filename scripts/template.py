#!/usr/bin/env python

import rospy

from package_template.msg import TemplateMessage
from package_template.srv import TemplateService, TemplateServiceResponse

def service_callback(req):
    rospy.loginfo(req.Request)
    return TemplateServiceResponse(Response="Response from Python")

def topic_callback(msg):
    rospy.loginfo(msg.Text)

def main():
    rospy.init_node('package_template_python')

    subscriber = rospy.Subscriber("/python_subscriber", TemplateMessage, topic_callback)
    publisher = rospy.Publisher('/cpp_subscriber', TemplateMessage, queue_size=10)
    server = rospy.Service('/python_service', TemplateService, service_callback)
    client = rospy.ServiceProxy('/cpp_service', TemplateService)

    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        message = TemplateMessage()
        message.Text = "Hello from Python"
        publisher.publish(message)

        rospy.wait_for_service('/cpp_service')
        response = client("Request from Python")

        rate.sleep()

if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass