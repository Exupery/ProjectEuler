//============================================================================
// Name        : Problem021.cpp
// Author      : Matthew Frost
// Description : Evaluate the sum of all the amicable numbers under 10000
//============================================================================

#include <iostream>

int calcSum(int target);
int sumOfDivisors(int num);

int main(int argc, char* argv[]) {
	int target = 100;
//	std::cout << "Target number: ";
//	std::cin >> target;
	int sum = calcSum(target);
    std::cout << "The sum of all the amicable numbers under " << target << " is " << sum << std::endl;
    return 0;
}

int calcSum(int target) {
	int sum = 0;
	for (int i=0; i<target; i++) {
		int divSum = sumOfDivisors(i);
		std::cout << "sum of divisors of " << i << " is " << divSum << std::endl;
	}
	return sum;
}

int sumOfDivisors(int num) {
	int sum = 0;
	for (int i=1; i<num; i++) {
		if (num % i == 0) {
			sum += i;
		}
	}
	return sum;
}

