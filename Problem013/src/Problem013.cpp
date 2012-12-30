//============================================================================
// Name        : Problem013.cpp
// Author      : Matthew Frost
// Description : first ten digits of the sum of one-hundred 50-digit numbers
//============================================================================

#include <iostream>
#include <fstream>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	double sum = 0;
	std::ifstream numFile("numbers");
	if (numFile.is_open()) {
		while (numFile.good()) {
			std::string line;
			getline(numFile, line);
			double num = strtod(line.c_str(), NULL);
			sum += num;
		}
		numFile.close();
	}

	std::cout.precision(11); //go an extra digit to confirm tenth digit is zero
    std::cout << "The sum is " << sum << std::endl;
    return 0;
}

