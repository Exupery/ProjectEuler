//============================================================================
// Name        : Problem3.cpp
// Author      : Matthew Frost
// Description : largest prime factor of 600851475143
//============================================================================

#include <iostream>

double findLargestPrime(double num);
bool isPrime(double num);

int main(int argc, char* argv[]) {
	//const double num = 600851475143;
	const double num = 18;

    std::cout << "" << std::endl;
    return 0;
}

double findLargestPrime(double num) {
	double lp = 0;
	for (double d=num; d>0; d--) {

	}
	return lp;
}

bool isPrime(double num) {
	for (int i=2; i<num; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}



