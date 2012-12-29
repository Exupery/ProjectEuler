//============================================================================
// Name        : Problem10.cpp
// Author      : Matthew Frost
// Description : Find the sum of all the primes below two million
//============================================================================

#include <iostream>

bool isPrime(int num);

int main(int argc, char* argv[]) {
	long sum = 0;
	for (int i=2; i<2000000; i++) {
		if (isPrime(i)) {
			sum += i;
		}
	}
    std::cout << "The sum of all primes below 2 million is " << sum << std::endl;
    return 0;
}

bool isPrime(int num) {
	for (int i=2; (i*i)<=num; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

