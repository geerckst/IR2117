#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("square");
  auto publisher = node->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
  node->declare_parameter("linear_speed", 0.1);
  node->declare_parameter("angular_speed", 3.1416 / 20);
  geometry_msgs::msg::Twist message;
  rclcpp::WallRate loop_rate(10ms);
  
  double linear_speed = node->get_parameter("linear_speed").get_parameter_value().get<double>();
  double angular_speed = node->get_parameter("angular_speed").get_parameter_value().get<double>();
  
  double linear_iterations = 1 / (0.01 * linear_speed);
  double angular_iterations = (3.1416/2) / (0.01 * angular_speed);
  
  
  
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

