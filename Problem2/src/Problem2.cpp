//============================================================================
// Name        : Problem2.cpp
// Author      : Matthew Frost
// Description : Even Fibonacci numbers
//============================================================================

#include <iostream>

int fib(int a, int b, int sum, int max);

int main(int argc, char* argv[]) {
	//const int MAX = 4000000;
	const int MAX = 1000;
	int sum = fib(1, 2, 0, MAX);
    std::cout << sum << std::endl;
    return 0;
}

int fib(int a, int b, int sum, int max) {
	std::cout << a << "\t" << b << std::endl;
	if (a>max) {
		return sum;
	}
	if (a%2==0) {
		sum += a;
	}
	int temp = a+b;
	a = b;
	b = temp;
	return fib(a, b, sum, max);
}

