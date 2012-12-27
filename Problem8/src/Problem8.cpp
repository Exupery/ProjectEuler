//============================================================================
// Name        : Problem8.cpp
// Author      : Matthew Frost
// Description : Find the greatest product of five consecutive digits in the 1000-digit number
//============================================================================

#include <iostream>

int* convertToIntArray(std::string num);

int main(int argc, char* argv[]) {
	std::string num = "123456789123456";
	convertToIntArray(num);
    std::cout << "" << std::endl;
    return 0;
}

int* convertToIntArray(std::string num) {
	int size = num.length();
	int* array = new int[size];
	for (int i=0; i<size; i++) {
		array[i] = (int)num[i] - 48;
		std::cout << num[i] << "\t" << array[i] << std::endl;
	}
	return array;
}

