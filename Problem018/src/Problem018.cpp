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
std::vector<Row> convert(std::vector<std::vector<int> > triangle);
bool isWithinOne(int x, int y);
int findMaxRoute(std::vector<Row> triangle);
//int findBestPosInNext(int curPos, int curRow, std::vector<Row> triangle);

int main(int argc, char* argv[]) {
	std::vector<std::vector<int> > triangle = createTriangle();
	int max = 0;
	if (triangle.size() > 0) {
		max = findMaxRoute(convert(triangle));
	}
    std::cout << "The maximum sum of the triangle is " << max << std::endl;
    return 0;
}

int findMaxRoute(std::vector<Row> triangle) {
	int highest = 0;
	std::vector<Row>::iterator rows;
	int prevPos = 0;
	for (rows=triangle.begin(); rows!=triangle.end(); rows++) {
		Row row = *rows;
		std::vector<int> positions = row.getPositions();
		int bestVal = 0;
		int bestPos = 0;
		std::vector<int>::iterator it;
		for (it=positions.begin(); it!=positions.end(); it++) {
			int pos = *it;
			int valAtPos = row.getValueAt(pos);
			if (isWithinOne(pos, prevPos) && valAtPos > bestVal) {
				bestPos = pos;
				bestVal = valAtPos;
			}
		}
		std::cout << "pos:\t" << bestPos << "\tval:\t" << bestVal << std::endl;
		prevPos = bestPos;
		highest += bestVal;
	}

	return highest;
}

//int findBestPosInNext(int curPos, int curRow, std::vector<Row> triangle) {
//	int best = 0;
//	int highestSum = -1;
//	Row current = triangle.at(curRow);
//	for (int i=curPos-1; i<=curPos+1; i++) {
//		int sum = 0;
//		if (i>=0 && i<current.getPositions().size()) {
//			//see what possible sums from curRow+1(i) + curRow+2
//
//
//		}
//		if (sum > highestSum) {
//			best = i;
//		}
//	}
//	return best;
//}

bool isWithinOne(int x, int y) {
	return (x==y || x==y+1);
}

std::vector<Row> convert(std::vector<std::vector<int> > triangle) {
	std::vector<Row> tri;
	std::vector<std::vector<int> >::iterator rows;
	int rowNum = 0;
	for (rows=triangle.begin(); rows!=triangle.end(); rows++) {
		Row r(rowNum++);
		std::vector<int> row = *rows;
		std::vector<int>::iterator cols;
		int pos = 0;
		for (cols=row.begin(); cols!=row.end(); cols++) {
			int num = *cols;
			std::cout << num << " ";		//DELME
			r.addNumber(num, pos++);
		}
		std::cout << std::endl;		//DELME
		tri.push_back(r);
	}
	return tri;
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

