//============================================================================
// Name        : Problem014.cpp
// Author      : Matthew Frost
// Description : Which starting Collatz sequence number, under one million, produces the longest chain
//============================================================================

#include <iostream>

int findLength(long num, int sum);
long evenSequence(long num);
long oddSequence(long num);

int main(int argc, char* argv[]) {
	const int MAX = 1000000;
	long longest = 0;
	int longestLength = 0;
	for (long i=1L; i<MAX; i++) {
		int length = findLength(i, 0);
		if (length > longestLength) {
			longest = i;
			longestLength = length;
		}
	}
    std::cout << "The longest sequence begins with " << longest << " and has " << longestLength << " terms" << std::endl;
    return 0;
}

int findLength(long num, int terms) {
	terms++;
	if (num == 1) {
		return terms;
	}
	long newNum;
	if ((num&1)==0) {
		newNum = evenSequence(num);
	} else {
		newNum = oddSequence(num);
	}
	return findLength(newNum, terms);
}

long evenSequence(long num) {
	return num/2;
}

long oddSequence(long num) {
	return (3*num)+1;
}

