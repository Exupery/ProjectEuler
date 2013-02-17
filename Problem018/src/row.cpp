/*
 * row.cpp
 *
 *  Created on: Feb 16, 2013
 *      Author: frost
 */

#include "row.h"

Row::Row(int rowNumber) : rowNumber(rowNumber) {

}

Row::~Row() {

}

void Row::addNumber(int num, int pos) {
	numMap.insert(std::pair<int, int>(num, pos));
	positions.empty();
	std::map<int, int>::iterator it;
	for (it=numMap.begin(); it!=numMap.end(); it++) {
//		positions.push_back(it.operator ->()->second);
		positions.push_back(it->first);
	}
}

int Row::getRowNumber() {
	return rowNumber;
}

std::vector<int> Row::getPositions() {
	return positions;
}

