//============================================================================
// Name        : Problem4.cpp
// Author      : Matthew Frost
// Description : Find the largest palindrome made from the product of two 3-digit numbers
//============================================================================

#include <iostream>

bool isPalindrome(int num);

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
	return true;
}

