//============================================================================
// Name        : Problem018.cpp
// Author      : Matthew Frost
// Description : max sum in triangle
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
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
			std::cout << line << std::endl;	//DELME
			triangle.push_back(tokenize(line));
		}
		file.close();
	}
	return triangle;
}

std::vector<int> tokenize(std::string str) {
	std::vector<int> v;
	for (unsigned int i=0; i<=str.length(); i++) {
		if (i==str.length() || !std::isdigit(str[i])) {
			int num = ((str[i-2]-48) * 10) + (str[i-1]-48);
			std::cout << num;	//DELME
			v.push_back(num);
		}
	}
	std::cout << std::endl;	//DELME
	return v;

}

