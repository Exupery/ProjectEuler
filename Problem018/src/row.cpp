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
}

int Row::getRowNumber() {
	return rowNumber;
}

