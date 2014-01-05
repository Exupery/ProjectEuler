//============================================================================
// Name        : Problem024.cpp
// Author      : Matthew Frost
// Description : millionth lexicographic permutation of 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
//============================================================================

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

std::set<std::vector<int>> fill(std::vector<int> digits);

int main(int argc, char* argv[]) {
//	std::vector<int> digits {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::vector<int> digits {0, 1, 2};
	std::set<std::vector<int>> permutations = fill(digits);
    std::cout << "Found " << permutations.size() << " permutations" << std::endl;
    return 0;
}

std::set<std::vector<int>> fill(std::vector<int> digits) {
	std::set<std::vector<int>> filled;
	std::set<std::vector<int>> perms;
	for (auto d : digits) {
		std::vector<int> initial(d);
		perms.insert(initial);
	}
	for (auto perm : perms) {
		while (perm.size() != digits.size()) {
			for (auto d : digits) {
				if (std::find(std::begin(perm), std::end(perm), d) == perm.end()) {
					perm.push_back(d);
					std::cout << perm.size() << "\t" << d << std::endl;	//DELME
				}
			}
		}
		filled.insert(perm);
	}
	return filled;
}
