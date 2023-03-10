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
    std::sort(elements.begin(), elements.end());
    int middle = elements.size()/2;
    if (elements.size()%2!=0){
        m = elements[middle];
    } else {
        m = double((elements[middle]+elements[middle+1])/2);
    }
    std::cout << "Median: : " << m << std::endl;
    return 0;
}
