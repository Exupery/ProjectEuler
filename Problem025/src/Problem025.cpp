//============================================================================
// Name        : Problem025.cpp
// Author      : Matthew Frost
// Description : first 1000-digit Fibonacci number
//============================================================================

#include <iostream>
#include "bigint/BigIntegerLibrary.hh"

int fib(BigInteger a, BigInteger b, BigInteger max, int term);

int main(int argc, char* argv[]) {
	BigInteger goal = 10;
	for (int i=2; i<1000; i++) {
		goal *= 10;
	}
    std::cout << fib(1, 1, goal, 1) << std::endl;
    return 0;
}

int fib(BigInteger a, BigInteger b, BigInteger max, int term) {
	return (a > max) ? term : fib(b, a + b, max, term + 1);
}

