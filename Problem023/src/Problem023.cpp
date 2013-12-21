//============================================================================
// Name        : Problem023.cpp
// Author      : Matthew Frost
// Description : sum of all positive integers which cannot be written as
//				 the sum of two abundant numbers
//============================================================================

#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

bool isAbundant(int num);
std::vector<int> findAbundants(int max);
std::set<int> hasSumOfAbundant(int max);

int main(int argc, char* argv[]) {
	int max = 28123;
	std::set<int> hasSums = hasSumOfAbundant(max);
	int sum = 0;
	for (int i = 0; i < max; i++) {
		if (hasSums.count(i) == 0) {
			sum += i;
		}
	}
    std::cout << sum << std::endl;
    return 0;
}

std::set<int> hasSumOfAbundant(int max) {
	std::set<int> hasSums;
	std::vector<int> abundants = findAbundants(max);
	std::sort(abundants.begin(), abundants.end());
	for (auto i : abundants) {
		for (auto j : abundants) {
			int sum = i + j;
			if (sum < max) {
				hasSums.insert(sum);
			} else {
				break;
			}

		}
	}
	return hasSums;
}

std::vector<int> findAbundants(int max) {
	std::vector<int> abundants;
	for (int i = 0; i < max; i++) {
		if (isAbundant(i)) {
			abundants.push_back(i);
		}
	}
	return abundants;
}

bool isAbundant(int num) {
	int sum = 0;
	for (int i = 1; i < num; i++) {
		if (num % i == 0) {
			sum += i;
		}
	}
	return sum > num;
}

