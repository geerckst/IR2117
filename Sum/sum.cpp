#include <iostream>

int fsum(int fnum){	
	int fsum=0;
	for(int i=0; i<=fnum;i++){
		fsum+=i;
	}
	return fsum;
}
	
int main(){
	std::cout << "Enter a number: ";
	int num;
	std::cin >> num;
	int sum = fsum(num);
	std::cout << "The sum from 1 to " << num << " is " << sum << std::endl;
	return 0;
	}
	
