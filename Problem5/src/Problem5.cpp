//============================================================================
// Name        : Problem5.cpp
// Author      : Matthew Frost
// Description : smallest positive number that is evenly divisible by all of the numbers from 1 to 20
//============================================================================

#include <iostream>
#include <limits>

bool isDivisible(int num);

int main(int argc, char* argv[]) {
	const int MAX = std::numeric_limits<int>::max();
	int num = 0;
	//answer cannot be less than 2520 since that's the smallest number divisible by 1 through 10
	for (int i=2520; i<MAX; i++) {
		if (isDivisible(i)) {
			num = i;
			break;
		}
	}

    std::cout << "Smallest number divisible by 1 through 20 is: " << num << std::endl;
    return 0;
}

bool isDivisible(int num) {
	//start at 20 and work down because less things are divisible by the larger numbers
	//stop at 2 because everything is divisible by 1
	for (int i=20; i>1; i--) {
		if (num % i != 0) {
			return false;
		}
	}
	return true;
}
