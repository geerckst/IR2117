#include <iostream>
#include <vector>
#include <Eigen/Dense>

using Eigen::VectorXd;
using Eigen::MatrixXd;

int main (){
  int rows;
  int sumamax = 0;
  
  std::cout << "What is the size of the quadratic  matrix? (enter number of rows) " << std::endl;
  std::cin >> rows;
  
  MatrixXd m (rows, rows);
  
  return 0;  
}
