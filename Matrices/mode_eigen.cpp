#include <iostream>
#include <vector>
#include <Eigen/Dense>

using Eigen::MatrixXd;
using Eigen::VectorXd;

int main(){
  int n=0, element;
  std::vector<int> elements;
  std::cin >> element;
  while(not std::cin.eof()){
    elements.push_back(element);
    n+=1;
    std::cin >> element;
  }
  VectorXd v(elements.size());
  for(int i=1; i<elements.size(); i++){
    v << elements[i];    
  }
    
  std::cout << v << std::endl;

}
