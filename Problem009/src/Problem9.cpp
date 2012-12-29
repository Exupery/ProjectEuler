//============================================================================
// Name        : Problem9.cpp
// Author      : Matthew Frost
// Description : Pythagorean triplet for which a + b + c = 1000
//============================================================================

#include <iostream>

int findProduct(int targetSum);

int main(int argc, char* argv[]) {
	int product = findProduct(1000);
    std::cout << "The product of a*b*c (where a+b+c=1000) is " << product << std::endl;
    return 0;
}

int findProduct(int targetSum) {
	for (int a=1; a<targetSum; a++) {
		for (int b=a+1; b<targetSum; b++) {
			for (int c=b+1; c<targetSum; c++) {
				if ((a+b+c)==targetSum && (a*a)+(b*b)==(c*c)) {
					return a*b*c;
				}
			}
		}
	}
	return 0;
}

