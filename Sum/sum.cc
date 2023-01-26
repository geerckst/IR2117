#include <iostream>

int suma(const int num)
{
	int sum=0;
	for(int i=0; i<=num;i++){
		sum+=i;
	}	
	return sum;
	
}

int main()
{
	std::cout << "Enter a number: " << std::endl;
	int num;
	std::cin >> num;
	int sum = suma(num);
	std::cout << sum << std::endl;
	return 0;
}
