/*
 * row.h
 *
 *  Created on: Feb 16, 2013
 *      Author: frost
 */

#include <map>
#include <algorithm>

#ifndef ROW_H_
#define ROW_H_

class Row {
private:
	int rowNumber;
	std::map<int, int, std::greater<int>() > numMap;

public:
	Row(int rowNumber);
	virtual ~Row();
	int getRowNumber();
	void addNumber(int num, int pos);
};

#endif /* ROW_H_ */
