//============================================================================
// Name        : Problem7.cpp
// Author      : Matthew Frost
// Description : find 10001st prime number
//============================================================================

#include <iostream>
#include <limits>

int findPrime(int find);
bool isPrime(int num);

int main(int argc, char* argv[]) {
	int find = 10001;
	int prime = findPrime(find);
    std::cout << "Prime #" << find << " is " << prime << std::endl;
    return 0;
}

int findPrime(int find) {
	int prime = 0;
	int primesFound = 1;	//start at 1 because 2 will be skipped
	const int MAX = std::numeric_limits<int>::max();
	//we know after 2 all primes are odd so skip even nums
	for (int i=3; i<MAX; i+=2) {
		if (isPrime(i)) {
			primesFound++;
			prime = i;
			if (primesFound >= find) {
				break;
			}
		}
	}
	return prime;
}

bool isPrime(int num) {
	for (int i=2; (i*i)<=num; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}
