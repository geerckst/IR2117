#include  <iostream>

int main()
{
	std::cout << "Enter a number: ";
	int num;
	int sum = 0;
	std::cin >> num;
	for(int i=0; i<=num;i++){
		sum += i;
	}
	std::cout << "The sum from 1 to " << num << " is " << sum << std::endl;
	return 0;
}
