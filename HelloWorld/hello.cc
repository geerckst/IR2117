#include <iostream>
#include<string>

int main()
{
	std::cout << "Whats your name?" << std::endl;
	std::string nombre;
	std::cin >> nombre;
	std::cout << "Hello " << nombre << "!" << std::endl;
	return 0;
}	
