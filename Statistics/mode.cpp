#include <iostream>
#include <vector>
#include <algorithm>
int main(int argc, char** argv){
    double m=0, s=0;
    int n=0, element;
    std::vector<int> elements;
    std::cin >> element;
    while(not std::cin.eof()){
        elements.push_back(element);
        n+=1;
        std::cin >> element;
    }
    int count[n], max=0;
    if ( count[n] == 0) {
        m = max;
    }
    std::cout << "Mode: : " << m << std::endl;
    return 0;
}
