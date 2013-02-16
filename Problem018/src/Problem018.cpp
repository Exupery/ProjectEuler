//============================================================================
// Name        : Problem018.cpp
// Author      : Matthew Frost
// Description : max sum in triangle
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "row.h"

std::vector<std::vector<int> > createTriangle();
std::vector<int> tokenize(std::string str);
int findMaxRoute(std::vector<std::vector<int> > triangle);

int main(int argc, char* argv[]) {
	std::vector<std::vector<int> > triangle = createTriangle();
	int max = 0;
	if (triangle.size() > 0) {
		max = findMaxRoute(triangle);
	}
    std::cout << "The maximum sum of the triangle is " << max << std::endl;
    return 0;
}

int findMaxRoute(std::vector<std::vector<int> > triangle) {
	int highest = 0;
	std::vector<std::vector<int> >::iterator rows;
	for (rows=triangle.begin(); rows!=triangle.end(); rows++) {
		std::vector<int> row = *rows;
		std::vector<int>::iterator cols;
		for (cols=row.begin(); cols!=row.end(); cols++) {
			int num = *cols;
			std::cout << num;
		}
		std::cout << std::endl;
	}
	return highest;
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
			}
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
			v.push_back(num);
		}
	}
	return v;
}

