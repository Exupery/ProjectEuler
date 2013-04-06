//============================================================================
// Name        : Problem019.cpp
// Author      : Matthew Frost
// Description : How many Sundays fell on the first of the month during the
//				 twentieth century (1 Jan 1901 to 31 Dec 2000)
//============================================================================

#include <iostream>

int findSundays(int beginMonth, int beginYear, int endMonth, int endYear);
bool isLeapYear(int year);
int getDaysInMonth(int month, int year);

int main(int argc, char* argv[]) {
	int numSundays = findSundays(1, 1901, 12, 2000);
    std::cout << numSundays << " Sundays fell on the first day of the month in the 20th century" << std::endl;
    return 0;
}

int findSundays(int beginMonth, int beginYear, int endMonth, int endYear) {
	int sundays = 0;

	return sundays;
}

bool isLeapYear(int year) {
	if (year % 100 == 0) {
		return year % 400 == 0;
	} else {
		return year % 4 == 0;
	}
}

int getDaysInMonth(int month, int year) {
	int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month==2 && isLeapYear(year)) {
		return 29;
	} else {
		return daysInMonth[month-1];
	}
}

