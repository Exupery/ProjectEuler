//============================================================================
// Name        : Problem013.cpp
// Author      : Matthew Frost
// Description : first ten digits of the sum of one-hundred 50-digit numbers
//============================================================================

#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
	double sum = 0;
	std::ifstream numFile("numbers");
	if (numFile.is_open()) {
		while (numFile.good()) {
			std::string line;
			getline(numFile, line);
			//add line to sum
			std::cout << line << std::endl;
		}
		numFile.close();
	}

    std::cout << "The sum is " << sum << std::endl;
    return 0;
}

