#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include <cmath>


#include <iostream>

using namespace std::chrono_literals;

double x = 0.0;
double y = 0.0;
double angle = 0.0;
int i=0;

void odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg){
  while(i < 1){
    x = msg->pose.pose.position.x;
    y = msg->pose.pose.position.y;
    angle = msg->pose.pose.orientation.w;
    i++;
  }
    std::cout << "x: " << x << std::endl;
    std::cout << "y:  "<< y << std::endl;
    std::cout << "angle: " << acos(angle)*2 << std::endl;
  
}
  
int main(int argc, char * argv[]){
  
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("square_odom");
  auto subscription = node->create_subscription<nav_msgs::msg::Odometry>("odom", 10, odom_callback);
  auto publisher = node->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
  node->declare_parameter("linear_speed", 0.1);
  node->declare_parameter("angular_speed", M_PI / 20);
  geometry_msgs::msg::Twist message;
  rclcpp::WallRate loop_rate(10ms);
  
  double linear_speed = node->get_parameter("linear_speed").get_parameter_value().get<double>();
  double angular_speed = node->get_parameter("angular_speed").get_parameter_value().get<double>();

  
  double linear_iterations = 1 / (0.01 * linear_speed);
  double angular_iterations = (M_PI/2) / (0.01 * angular_speed);

  for(int j=0; j<4; j++){
  
    int i = 0, n=1000; 
    while (rclcpp::ok() && (i<n)) {
      message.linear.x = 0.1;
      message.angular.z = 0.0;
      publisher->publish(message);
      rclcpp::spin_some(node);
      loop_rate.sleep();
      i++;
    }  
  
    i=0, n=1571;
    while (rclcpp::ok() && (i<n)) {
      message.linear.x = 0.0;
      message.angular.z = 0.1;
      publisher->publish(message);
      rclcpp::spin_some(node);
      loop_rate.sleep();
      i++;
    }
      
  message.linear.x = 0;
  message.angular.z = 0;
  publisher->publish(message);
  rclcpp::shutdown();
  return 0;
  }
}

