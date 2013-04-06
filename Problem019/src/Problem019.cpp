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
//	char daysOfWeek[7] = {'s', 'm', 't', 'w', 'h', 'f', 'a'};
	//starting on 1/1/1900 because we are told that is a Monday
	int daysElapsed = 1;
	for (int year=1900; year<=endYear; year++) {
		for (int month=1; month<=12; month++) {
//			std::cout << month << "\t" << year << "\t" << daysOfWeek[daysElapsed%7] << std::endl;
			bool isSunday = daysElapsed%7==0;
			if (isSunday &&
					(	(year>beginYear && year<endYear) ||
						(year==beginYear && month>=beginMonth) ||
						(year==endYear && month<=endMonth))
					) {
						sundays++;
			}
			daysElapsed += getDaysInMonth(month, year);
		}
	}
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

