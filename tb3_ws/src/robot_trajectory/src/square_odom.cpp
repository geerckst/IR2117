#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "nav_msgs/msg/odometry.hpp"


#include <iostream>

using namespace std::chrono_literals;

double x = 0.0;
double y = 0.0;

void odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg)
{
  std::cout << msg << std::endl;
  x = msg->pose.pose.position.x;
  y = msg->pose.pose.position.y;
  std::cout << x << std::endl;
  std::cout << y << std::endl;
}

int main(int argc, char * argv[])
{
  
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("square_odom");
  auto subscription = node->create_subscription<nav_msgs::msg::Odometry>("odom", 10, odom_callback);
  auto publisher = node->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
  node->declare_parameter("linear_speed", 0.1);
  node->declare_parameter("angular_speed", 3.1416 / 20);
  geometry_msgs::msg::Twist message;
  rclcpp::WallRate loop_rate(10ms);
  
  double linear_speed = node->get_parameter("linear_speed").get_parameter_value().get<double>();
  double angular_speed = node->get_parameter("angular_speed").get_parameter_value().get<double>();
  //double square_length = node->get_parameter("square_length").get_parameter_value().get<double>();
  
  double linear_iterations = 1 / (0.01 * linear_speed);
  double angular_iterations = (3.1416/2) / (0.01 * angular_speed);
  //double square_length = ();
  
  for(int j=0; j<4; j++){
    int i = 0, n=linear_iterations; 
  while (rclcpp::ok() && (i<n)) {
    message.linear.x = linear_speed;
    message.angular.z = 0.0;
    publisher->publish(message);
    rclcpp::spin_some(node);
    loop_rate.sleep();
    i++;
  }  
  
  i=0, n=angular_iterations;
  while (rclcpp::ok() && (i<n)) {
    message.linear.x = 0;
    message.angular.z = angular_speed;
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

