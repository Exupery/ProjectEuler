//============================================================================
// Name        : Problem012.cpp
// Author      : Matthew Frost
// Description : Value of the first triangle number to have over 500 divisors
//============================================================================

#include <iostream>
#include <limits>

int findTriangle(int targetDivisors);
int numDivisors(int num);

int main(int argc, char* argv[]) {
	std::cout << "First triangle number with over 500 divisors is " << findTriangle(500) << std::endl;
    return 0;
}

int findTriangle(int targetDivisors) {
	const int MAX = std::numeric_limits<int>::max();
	int curTriangle = 1;
	for (int i=2; curTriangle<MAX; i++) {
		int div = numDivisors(curTriangle);
		if (div > 500) {
			return curTriangle;
		}
		curTriangle += i;
	}
	return 0;
}

int numDivisors(int num) {
	int divisors = 0;
	for (int i=1; i<=num; i++) {
		if (num % i == 0) {
			divisors++;
		}
	}
	return divisors;
}

