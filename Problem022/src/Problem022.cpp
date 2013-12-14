//============================================================================
// Name        : Problem022.cpp
// Author      : Matthew Frost
// Description : total of name scores in a file
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

std::vector<std::string> readNames(std::string filename);
long totalScore(std::vector<std::string> names);

int main(int argc, char* argv[]) {
	std::vector<std::string> names = readNames("names.txt");
    std::cout << "Found " << names.size() << " names" << std::endl;
    long total = totalScore(names);
    std::cout << "Total score: " << total << std::endl;
    return 0;
}

long totalScore(std::vector<std::string> names) {
	std::sort(names.begin(), names.end());
	long total = 0;
	int pos = 1;
	for (auto name : names) {
		int val = 0;
		for (auto n : name) {
			val += (int)n - 64;
		}
		total += (val * pos);
		pos++;
	}
	return total;
}

std::vector<std::string> readNames(std::string filename) {
	std::vector<std::string> names;
	std::ifstream file(filename.c_str());
	if (file.is_open()) {
		while (file.good()) {
			std::string line;
			getline(file, line, ',');
			if (line.length() > 0) {
				line.erase(0, 1);
				line.erase(line.end()-1, line.end());
				names.push_back(line);
			}
		}
		file.close();
	}
	return names;
}
