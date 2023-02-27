#include <iostream>
#include <vector>
#include <algorithm>
#include <Eigen/Dense>

using Eigen::VectorXd;

int main(){
    
  int element, n=0, m=0;
  std::vector<int> elements;
  std::cin >> element; 
  while(not std::cin.eof()){
    n+=1;
    elements.push_back(element);
    std::cin >> element;
  }
  
  VectorXd v;
  for (int i=0;i<elements.size();i++){
     v.conservativeResize(i+1);
     v[i] = elements[i];
  }
  
  std::sort(v.data(), v.data()+v.size());
  

  
  std::cout << v << std::endl;
  return 0;
}
