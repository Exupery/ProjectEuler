/*
 * row.h
 *
 *  Created on: Feb 16, 2013
 *      Author: frost
 */

#include <map>
#include <vector>
#include <algorithm>

#ifndef ROW_H_
#define ROW_H_

class Row {
private:
	int rowNumber;
	std::vector<int> positions;
	std::map<int, int> positionValues;
	std::map<int, int, std::greater<int> > numMap;

public:
	Row(int rowNumber);
	virtual ~Row();
	int getRowNumber();
	int getValueAt(int pos);
	void addNumber(int num, int pos);
	std::vector<int> getPositions();
};

#endif /* ROW_H_ */
