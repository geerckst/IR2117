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
	if (num >= 1){
		std::cout << suma(num) << std::endl;
		return 0;
	}else{
		std::cout << "Error" << std::endl;
		return 1;	
	}

	
	
}
