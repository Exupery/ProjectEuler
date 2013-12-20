//============================================================================
// Name        : Problem023.cpp
// Author      : Matthew Frost
// Description : sum of all positive integers which cannot be written as
//				 the sum of two abundant numbers
//============================================================================

#include <iostream>
#include <vector>

bool isAbundant(int num);
std::vector<int> findAbundants(int max);

int main(int argc, char* argv[]) {
	std::vector<int> abundants = findAbundants(28123);
    std::cout << abundants.size() << std::endl;	//DELME
    return 0;
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

