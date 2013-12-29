//============================================================================
// Name        : Problem024.cpp
// Author      : Matthew Frost
// Description : millionth lexicographic permutation of 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
//============================================================================

#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>

std::set<std::vector<int>> fill(int pos, std::vector<int> digits);

int main(int argc, char* argv[]) {
	std::vector<int> digits = {0, 1, 2};
	std::set<std::vector<int>> permutations;
	for (int d : digits) {
		std::set<std::vector<int>> filled = fill(d, digits);
		permutations.insert(filled.begin(), filled.end());
	}
    std::cout << "Found " << permutations.size() << " permutations" << std::endl;
    return 0;
}

std::set<std::vector<int>> fill(int pos, std::vector<int> digits) {
	std::set<std::vector<int>> filled;
	std::unordered_map<int, int> valuesPositions;
	std::unordered_map<int, int> positionsValues;
	for (int d : digits) {
		auto initPair = std::pair<int, int>(d, d);
		valuesPositions.insert(initPair);
		positionsValues.insert(initPair);
	}
	for (unsigned int i = 0; i < digits.size(); i++) {
		int valAtPos = positionsValues.find(pos)->second;
		int prevPos = valuesPositions.find(i)->second;
		positionsValues.erase(pos);
		positionsValues.erase(prevPos);
		valuesPositions.erase(i);
		valuesPositions.erase(valAtPos);
		positionsValues.insert(std::pair<int, int>(pos, i));
		positionsValues.insert(std::pair<int, int>(prevPos, valAtPos));
		valuesPositions.insert(std::pair<int, int>(i, pos));
		valuesPositions.insert(std::pair<int, int>(valAtPos, prevPos));
		std::vector<int> filledPerm;
		std::cout << i << " / " << pos << " \t";	//DELME
		for (auto p : positionsValues) {
			std::cout << p.second;	//DELME
			filledPerm.push_back(p.second);
		}
		std::cout << std::endl;		//DELME
		filled.insert(filledPerm);
	}
	return filled;
}

