//============================================================================
// Name        : Problem017.cpp
// Author      : Matthew Frost
// Description : If all the numbers from 1 to 1000 (one thousand) inclusive
//				 were written out in words, how many letters would be used?
//============================================================================

#include <iostream>

int countDigits(int num);
int* convertToArray(int digits, int num);
int* getLengths(std::string* strings, int size);

int main(int argc, char* argv[]) {
	std::string numbers[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	std::string teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	std::string tens[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	int* numberLengths = getLengths(numbers, sizeof(numbers) / sizeof(std::string));
	int* teenLengths = getLengths(teens, sizeof(teens) / sizeof(std::string));
	int* tenLengths = getLengths(tens, sizeof(tens) / sizeof(std::string));
	int hundredLength = std::string("hundred").length() + std::string("and").length();
	int thousandLength = std::string("thousand").length();

	int total = 0;
	for (int i=1; i<100; i++) {
		int iLength = 0;
		int numDigits = countDigits(i);
		int* num = convertToArray(numDigits, i);
		if (i < 10) {
			iLength += numberLengths[i-1];
		} else if (i >= 10 && i < 20) {
			iLength += teenLengths[i-10];
		} else {
			for (int j=0; j<numDigits; j++) {
				if (j == numDigits-1) {

				} else if (j == numDigits-2) {

				} else {

				}
			}
		}

		std::cout << i << "\t" << iLength << std::endl;
		total += iLength;
	}

    std::cout << "Total letters used is " << total << std::endl;
    return 0;
}

int* getLengths(std::string* strings, int size) {
	int* lengths = new int[size];
	for (int i=0; i<size; i++) {
		lengths[i] = strings[i].length();
	}
	return lengths;
}

int countDigits(int num) {
	int digits = 0;
	while (num > 0) {
		num /= 10;
		digits++;
	}
	return digits;
}

int* convertToArray(int digits, int num) {
	int* array = new int[digits];
	for (int i=digits-1; i>=0; i--) {
		array[i] = num % 10;
		num /= 10;
	}
	return array;
}

