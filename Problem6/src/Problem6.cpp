//============================================================================
// Name        : Problem6.cpp
// Author      : Matthew Frost
// Description : difference between the sum of the squares of the first
//				 one hundred natural numbers and the square of the sum
//============================================================================

#include <iostream>
#include <cmath>

int sumOfSquares(int from, int to);
int squareOfSum(int from, int to);

int main(int argc, char* argv[]) {
	int from = 1;
	int to = 100;
	int diff = std::abs(squareOfSum(from, to) - sumOfSquares(from, to));
    std::cout << "Difference is " << diff << std::endl;
    return 0;
}

int sumOfSquares(int from, int to) {
	int sum = 0;
	for (int i=from; i<=to; i++) {
		sum += (i * i);
	}
	std::cout << "Sum of Squares is " << sum << std::endl;
	return sum;
}

int squareOfSum(int from, int to) {
	int sum = 0;
	int square = 0;
	for (int i=from; i<=to; i++) {
		sum += i;
	}
	square = (sum * sum);
	std::cout << "Square of Sum is " << square << std::endl;
	return square;
}

