//============================================================================
// Name        : Problem4.cpp
// Author      : Matthew Frost
// Description : Find the largest palindrome made from the product of two 3-digit numbers
//============================================================================

#include <iostream>

bool isPalindrome(int num);
int countDigits(int num);
int* convertToArray(int digits, int num);
int* convertToBackwardsArray(int digits, int num);

int main(int argc, char* argv[]) {
	int highest = 0;
	for (int i=100; i<1000; i++) {
		for (int j=100; j<1000; j++) {
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
	int* numArray = convertToArray(digits, num);
	int* numBackwards = convertToBackwardsArray(digits, num);
	//discard any numbers with a leading or trailing zero
	if (numArray[0]==0 || numBackwards[0]==0) {
		return false;
	}
	for (int i=0; i<digits; i++) {
		if (numArray[i] != numBackwards[i]) {
			return false;
		}
	}
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

int* convertToArray(int digits, int num) {
	int* array = new int[digits];
	for (int i=digits-1; i>=0; i--) {
		array[i] = num % 10;
		num /= 10;
	}
	return array;
}

int* convertToBackwardsArray(int digits, int num) {
	int* array = new int[digits];
	for (int i=0; i<digits; i++) {
		array[i] = num % 10;
		num /= 10;
	}
	return array;
}
