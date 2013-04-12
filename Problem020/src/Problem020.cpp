//============================================================================
// Name        : Problem020.cpp
// Author      : Matthew Frost
// Description : Find the sum of the digits in the number 100!
//============================================================================

#include <iostream>

int calcFactorial(int num, int sum);

int main(int argc, char* argv[]) {
	int num = 0;
	std::cout << "Enter a number: ";
	std::cin >> num;
	int factorial = calcFactorial(num, 0);
	int sum = 0;
    std::cout << "The sum of the digits of " << num << "! (" << factorial << ") is " << sum << std::endl;
    return 0;
}

int calcFactorial(int num, int fct) {
	if (num == 0) {
		return fct;
	} else {
		fct = (fct==0) ? num : fct * num;
		return calcFactorial(num-1, fct);
	}
}

