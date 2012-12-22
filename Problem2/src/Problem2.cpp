//============================================================================
// Name        : Problem2.cpp
// Author      : Matthew Frost
// Description : Even Fibonacci numbers
//============================================================================

#include <iostream>

int fib(int a, int b, int max);

int main(int argc, char* argv[]) {
	//const int MAX = 4000000;
	const int MAX = 100;
	int sum = fib(1, 2, MAX);
    std::cout << sum << std::endl;
    return 0;
}

int fib(int a, int b, int max) {
	std::cout << a << "\t" << b << std::endl;
	if (a>max) {
		return a;
	}
	int temp = a+b;
	a = b;
	b = temp;
	return fib(a, b, max);
}

