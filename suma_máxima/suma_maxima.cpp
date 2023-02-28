#include <iostream>
#include <vector>
#include <Eigen/Dense>

//using Eigen::VectorXd;
using Eigen::MatrixXd;

int main (){
  int rows;
  int sumamax = 0;
  
  std::cout << "Enter quadratic matrix size: " << std::endl;
  std::cin >> rows;
  
  MatrixXd m(rows, rows);
  
  while(m.rows() != m.cols() && (m.rows()+m.cols()) == m.size()){
      
    std::cout << "That matrix isn't quadratic! " << std::endl;
    std::cout << "What is the size of the quadratic  matrix? (enter number of rows): " << std::endl;
    std::cin >> rows;    
  }

  m << 1, 2, 3,
       4, 5, 6,
       7, 8, 9;
  
  double sumamaxfilas=0.0, sumamaxcolumnas=0.0, sumamaxdiag1=0.0, sumamaxdiag2=0.0;

  std::cout << "The matrix is: \n"  << m << std::endl;
  std::cout << "La suma maxima de las filas es: " << m.rowwise().sum().maxCoeff() << std::endl;
  std::cout << "La suma maxima de las columnas es: " << m.colwise().sum().maxCoeff() << std::endl;
  
  if(m.diagonal().sum() > m.colwise().reverse().diagonal().sum()){
    std::cout << "La suma maxima de la diagonal es: " << m.diagonal().sum() << std::endl;  
  } else {
    std::cout << "La suma maxima de la diagonal es: " << m.colwise().reverse().diagonal().sum() << std::endl;  
  }

  return 0;  
}
