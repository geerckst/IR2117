#include <iostream>

int main()
{
	std::cout << "Enter a number: " << std::endl;
	int num;
	int sum =0;
	std::cin >> num;
	for(int i=0; i<=num;i++){
		sum+=i;
	}
	std::cout << sum << std::endl;
	return 0;
}
