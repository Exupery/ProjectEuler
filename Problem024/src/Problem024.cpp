//============================================================================
// Name        : Problem024.cpp
// Author      : Matthew Frost
// Description : millionth lexicographic permutation of 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
//============================================================================

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

std::set<std::vector<int>> fill(std::vector<int> digits, std::set<std::vector<int>> perms);

int main(int argc, char* argv[]) {
//	std::vector<int> digits {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::vector<int> digits {0, 1, 2};
	std::set<std::vector<int>> initial {digits};
	std::set<std::vector<int>> permutations = fill(digits, initial);
    std::cout << "Found " << permutations.size() << " permutations" << std::endl;
    return 0;
}

std::set<std::vector<int>> fill(std::vector<int> digits, std::set<std::vector<int>> perms) {
	std::set<std::vector<int>> filled(perms);
	for (auto perm : perms) {
		for (auto digit : digits) {
			std::vector<int> p(perm);
			auto pos = std::find(std::begin(p), std::end(p), digit);
			p.erase(pos);
			if (pos == p.begin()) {
				int last = p.back();
				p.pop_back();
				p.push_back(digit);
				p.insert(pos, last);
			} else {
				p.insert(pos-1, digit);
			}
			filled.insert(p);
			std::vector<int> reversed;
			for (int i = p.size()-1; i >= 0; i--) {
					reversed.push_back(p.at(i));
			}
			if (p.size() == digits.size()) {
				filled.insert(reversed);
			}
		}
	}
	return (filled.size() == perms.size()) ? filled : fill(digits, filled);
}
