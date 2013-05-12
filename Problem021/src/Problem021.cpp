//============================================================================
// Name        : Problem021.cpp
// Author      : Matthew Frost
// Description : Evaluate the sum of all the amicable numbers under 10000
//============================================================================

#include <iostream>
#include <map>
#include <set>

long calcSum(int target);
int sumOfDivisors(int num);

int main(int argc, char* argv[]) {
	int target = 10000;
//	std::cout << "Target number: ";
//	std::cin >> target;
	long sum = calcSum(target);
    std::cout << "The sum of all the amicable numbers under " << target << " is " << sum << std::endl;
    return 0;
}

long calcSum(int target) {
	long sum = 0;
	std::map<int, int> allDivSums;
	std::set<int> paired;
	for (int i=0; i<target; i++) {
		int divSum = sumOfDivisors(i);
		allDivSums.insert(std::make_pair(i, divSum));
	}

	std::map<int, int>::iterator iter;
	for (iter=allDivSums.begin(); iter!=allDivSums.end(); iter++) {
		if (iter->second < target) {
			paired.insert(iter->first);
			paired.insert(iter->second);
		}
	}

	std::set<int>::iterator sumIter;
	for (sumIter=paired.begin(); sumIter!=paired.end(); sumIter++) {
		sum += *sumIter;
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

