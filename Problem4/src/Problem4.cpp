//============================================================================
// Name        : Problem4.cpp
// Author      : Matthew Frost
// Description : Find the largest palindrome made from the product of two 3-digit numbers
//============================================================================

#include <iostream>

bool isPalindrome(int num);
int countDigits(int num);

int main(int argc, char* argv[]) {
	int highest = 0;
	for (int i=1; i<105; i++) {
		for (int j=10; j<105; j++) {
			int product = i*j;
			if (isPalindrome(product) && product>highest) {
				highest = product;
			}
		}
	}
    std::cout << "The largest palindrome made from two 3-digit numbers is " << highest << std::endl;
    return 0;
}

bool isPalindrome(int num) {
	if (num < 10) {
		return num >= 0;
	}
	int digits = countDigits(num);
	std::cout << num << "\t" << digits << std::endl;
	return true;
}

int countDigits(int num) {
	int digits = 0;
	while (num > 0) {
		num /= 10;
		digits++;
	}

	return digits;
}
