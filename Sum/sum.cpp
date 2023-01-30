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
	int sum=0;
	int num;
	std::cin >> num;
	if(num>=1){
		int sum = fsum(num);
		std::cout << "The sum from 1 to " << num << " is " << sum << std::endl;
		return 0;
	} else {
		std::cout << "Error, entered number is smaller than 1!" << std::endl;
		return 0;
	}

	}
	
