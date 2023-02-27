#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
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
  
  std::unordered_map<int, int> map;
  for (int i = 0; i < elements.size(); i++){
     map[v[i]]++;
  }

  int mode = 0;
  int mode_freq = 0;
  for (auto itor = map.begin(); itor != map.end(); itor++){
    if (itor->second > mode_freq){
        mode = itor->first;
        mode_freq = itor->second;
    }
  }
  
  std::cout << "Mode: " << mode  << std::endl;
  return 0;
}
