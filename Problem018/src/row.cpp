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
	positionValues.insert(std::pair<int, int>(pos, num));
	positions.clear();
	std::map<int, int>::iterator it;
	for (it=numMap.begin(); it!=numMap.end(); it++) {
		positions.push_back(it->second);
	}
}

int Row::getValueAt(int pos) {
	return positionValues.at(pos);
}

int Row::getRowNumber() {
	return rowNumber;
}

std::vector<int> Row::getPositions() {
	return positions;
}

