//============================================================================
// Name        : Problem020.cpp
// Author      : Matthew Frost
// Description : Find the sum of the digits in the number 100!
//============================================================================

#include <iostream>

int calcFactorial(int num);

int main(int argc, char* argv[]) {
	int num = 0;
	std::cout << "Enter a number: ";
	std::cin >> num;
	int factorial = calcFactorial(num);
	int sum = 0;
    std::cout << "The sum of the digits of " << num << "! (" << factorial << ") is " << sum << std::endl;
    return 0;
}

int calcFactorial(int num) {
	return num;
}

