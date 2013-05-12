//============================================================================
// Name        : Problem021.cpp
// Author      : Matthew Frost
// Description : Evaluate the sum of all the amicable numbers under 10000
//============================================================================

#include <iostream>
#include <set>

long calcSum(int target);
int sumOfDivisors(int num);

int main(int argc, char* argv[]) {
	int target = 10000;
	std::cout << "Target number: ";
	std::cin >> target;
	long sum = calcSum(target);
    std::cout << "The sum of all the amicable numbers under " << target << " is " << sum << std::endl;
    return 0;
}

long calcSum(int target) {
	long sum = 0;
	std::set<int> amicable;

	for (int i=0; i<target; i++) {
		int divSum = sumOfDivisors(i);
		if (i == sumOfDivisors(divSum) && i != divSum) {
			amicable.insert(i);
			amicable.insert(divSum);
		}
	}

	std::set<int>::iterator iter;
	for (iter=amicable.begin(); iter!=amicable.end(); iter++) {
		sum += *iter;
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

