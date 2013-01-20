//============================================================================
// Name        : Problem015.cpp
// Author      : Matthew Frost
// Description : lattice paths in 20x20 grid
//============================================================================

#include <iostream>

long countPaths(long x, long y);

int main(int argc, char* argv[]) {
	int paths = countPaths(4, 4);
    std::cout << "Number of paths in a 20x20 grid is " << paths << std::endl;
    return 0;
}

long countPaths(long x, long y) {
	long count = 0;
	if (x==0 && y==0) {
		return 1;
	}

	if (x > 0) {
		count += countPaths(x-1, y);
	}
	if (y > 0) {
		count += countPaths(x, y-1);
	}

	return count;
}

