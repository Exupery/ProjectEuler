//============================================================================
// Name        : Problem3.cpp
// Author      : Matthew Frost
// Description : largest prime factor of 600851475143
//============================================================================

#include <iostream>
#include <math.h>

double findLargestPrime(double num);
bool isPrime(double num);

int main(int argc, char* argv[]) {
	//const double num = 600851475143;
	const double num = 18;
	double largestPrime = findLargestPrime(num);
    std::cout << "Largest prime of " << num << " is " << largestPrime << std::endl;
    return 0;
}

double findLargestPrime(double num) {
	for (double d=num-1; d>0; d--) {
		//if (num%d==0 && isPrime(d)) {
		if (fmod(num, d)==0 && isPrime(d)) {
			return d;
		}
	}
	return 1;
}

bool isPrime(double num) {
	for (int i=2; (i*i)<num; i++) {
		//if (num % i == 0) {
		if (fmod(num, i) == 0) {
			return false;
		}
	}
	return true;
}



