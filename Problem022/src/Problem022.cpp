//============================================================================
// Name        : Problem022.cpp
// Author      : Matthew Frost
// Description : total of name scores in a file
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::string> readNames(std::string filename);

int main(int argc, char* argv[]) {
	std::vector<std::string> names = readNames("names.txt");
    std::cout << "Found " << names.size() << " names" << std::endl;
    return 0;
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



