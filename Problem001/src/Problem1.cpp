//============================================================================
// Name        : Problem1.cpp
// Author      : Matthew Frost
// Description : Find the sum of all the multiples of 3 or 5 below 1000
//============================================================================

#include <iostream>

int main(int argc, char* argv[]) {
	int sum = 0;
	for (int i=0; i<1000; i++) {
		if (i%3==0 || i%5==0) {
			sum += i;
		}
	}
	std::cout << sum << std::endl;
	return 0;
}
