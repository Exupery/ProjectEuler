//============================================================================
// Name        : Problem017.cpp
// Author      : Matthew Frost
// Description : If all the numbers from 1 to 1000 (one thousand) inclusive
//				 were written out in words, how many letters would be used?
//============================================================================

#include <iostream>

int getLength(std::string* strings, int size);

int main(int argc, char* argv[]) {
	std::string ones[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	std::string teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	std::string tens[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	const int onesLength = getLength(ones, sizeof(ones) / sizeof(std::string));
	const int teensLength = getLength(teens, sizeof(teens) / sizeof(std::string));
	const int tensLength = getLength(tens, sizeof(tens) / sizeof(std::string));
	const int hundredLength = std::string("hundred").length();
	const int andLength = std::string("and").length();

	int total = 0;

	//one thousand
	total += ((std::string("one thousand")).length()-1);
	//hundreds in 1000 - handle "hundred" in "one hundred"
	int numHundreds = 1000 - 100;
	int combinedHundredLengths = numHundreds * hundredLength;
	total += combinedHundredLengths;
	//hundreds in 1000 - handle "xyz" in "xyz hundred"
	total += onesLength * 100;
	//tens in 1000
	int numTens = 10 * 10;
	int combinedTensLengths = numTens * tensLength;
	total += combinedTensLengths;
	//ones in 1000
	int numOnes = 10 * 9; //9 instead of 10 because not used by teens
	int combinedOnesLengths = numOnes * onesLength;
	total += combinedOnesLengths;
	//teens in 1000
	int numTeens = 10;
	int combinedTeensLengths = numTeens * teensLength;
	total += combinedTeensLengths;
	//ands in 1000
	int numAnds = numHundreds - 9; //only x00 won't have "and"
	int combinedAndLengths = numAnds * andLength;
	total += combinedAndLengths;

    std::cout << "Total letters used is " << total << std::endl;
    return 0;
}

int getLength(std::string* strings, int size) {
	int length = 0;
	for (int i=0; i<size; i++) {
		length += strings[i].length();
	}
	return length;
}

