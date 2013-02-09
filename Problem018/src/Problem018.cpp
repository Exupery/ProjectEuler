//============================================================================
// Name        : Problem018.cpp
// Author      : Matthew Frost
// Description : max sum in triangle
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>

std::vector<std::vector<int> > createTriangle();
std::vector<int> tokenize(std::string str);

int main(int argc, char* argv[]) {
	std::vector<std::vector<int> > triangle = createTriangle();
	std::cout << triangle.size() << std::endl;	//DELME
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
			if (line.length() > 0) {
				triangle.push_back(tokenize(line));
				std::cout << triangle.size() << std::endl;
			}
		}
		std::cout << "near" << std::endl;
		file.close();
		std::cout << "far" << std::endl;
	}
	std::cout << triangle.size() << std::endl;
	return triangle;
}

std::vector<int> tokenize(std::string str) {
	std::vector<int> v;
	for (unsigned int i=0; i<=str.length(); i++) {
		if (i==str.length() || !std::isdigit(str[i])) {
			int num = ((str[i-2]-48) * 10) + (str[i-1]-48);
			v.push_back(num);
		}
	}
//	std::cout << v.size() << std::endl;
	return v;
}

