//============================================================================
// Name        : Problem018.cpp
// Author      : Matthew Frost
// Description : max sum in triangle
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::vector<int> > createTriangle();

int main(int argc, char* argv[]) {
	std::vector<std::vector<int> > triangle = createTriangle();

	int max = 0;
    std::cout << "The maximum sum of the triangle is " << max << std::endl;
    return 0;
}

std::vector<std::vector<int> > createTriangle() {
	std::vector<std::vector<int> > triangle;
	std::ifstream file("triangle");
	if (file.is_open()) {
		while (file.good()) {
			std::string line;
			getline(file, line);
			std::cout << line << std::endl;
		}
		file.close();
	}
	return triangle;
}

