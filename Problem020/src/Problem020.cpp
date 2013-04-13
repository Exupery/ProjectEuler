//============================================================================
// Name        : Problem020.cpp
// Author      : Matthew Frost
// Description : Find the sum of the digits in the number 100!
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <sstream>

double calcFactorial(int num, double fct);
long sumOfDigits(double num);

int main(int argc, char* argv[]) {
	int num = 0;
	std::cout << "Enter a number: ";
	std::cin >> num;
	int factorial = calcFactorial(num, 0);
	int sum = sumOfDigits(factorial);
    std::cout << "The sum of the digits of " << num << "! (" << factorial << ") is " << sum << std::endl;
    return 0;
}

long sumOfDigits(double num) {
	long sum = 0;
	std::ostringstream ss;
	ss << num;
	std::string numStr = ss.str();
	for (unsigned int i=0; i< numStr.length(); i++) {
		std::string digit = numStr.substr(i, 1);
		sum += atoi(digit.c_str());
	}
	return sum;
}

double calcFactorial(int num, double fct) {
	std::cout << fct << std::endl;	//fct is way to big for a long :-(
	if (num == 0) {
		return fct;
	} else {
		fct = (fct==0) ? num : fct * num;
		return calcFactorial(num-1, fct);
	}
}

