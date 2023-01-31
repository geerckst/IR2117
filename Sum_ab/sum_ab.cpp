#include <iostream>

int main(){
	
	int a, b;
	
	std::cout << "Enter a number >=1: ";
	std::cin >> a;
	
	while(a<1){
		std::cout << "Error, a is smaller than 1, try again!" << "\n";
		std::cout << "Enter a number >=1: ";
		std::cin >> a;
	}
	
	std::cout << "Enter b number >=1: ";
	std::cin >> b;
	
	int sum = 0;
	
	for(int i=a; i<=b; i++){
		sum+=i;
	}
	
	std::cout << "The sum from " << a << " to " << b << " is " << sum << "\n";
}	

