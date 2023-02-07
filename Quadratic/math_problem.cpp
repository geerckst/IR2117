#include <iostream>
#include <cmath>

int main(){
    double a, b, c, x1, x2;
    std::cout << "Enter a: ";
    std::cin >> a;
    std::cout << "Enter b: ";
    std::cin >> b;
    std::cout << "Enter c: ";
    std::cin >> c;
    double discriminant = b*b - 4*a*c;
    x1 = (-b + sqrt(discriminant))/(2*a);
    x2 = (-b - sqrt(discriminant))/(2*a);	
    std::cout << "x1 = " << x1 << std::endl;
    std::cout << "x2 = " << x2 << std::endl;
    
}
