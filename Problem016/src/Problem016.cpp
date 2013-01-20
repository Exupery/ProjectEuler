//============================================================================
// Name        : Problem016.cpp
// Author      : Matthew Frost
// Description : sum of the digits of the number 2^1000
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[]) {
	double num = pow(2, 1000);
//	printf("%lf\n", num);
	/* unable to find a way to calc 2^1000 and store it, but printf outputs the correct (full) value
	 * because C++ handles power of 2 differently than other nums in pow so the below is just copy & pasted from that */
	std::string numStr = "10715086071862673209484250490600018105614048117055336074437503883703510511249361224931983788156958581275946729175531468251871452856923140435984577574698574803934567774824230985421074605062371141877954182153046474983581941267398767559165543946077062914571196477686542167660429831652624386837205668069376";
	long sum = 0;
	for (unsigned int i=0; i< numStr.length(); i++) {
		std::string digit = numStr.substr(i, 1);
		sum += atoi(digit.c_str());
	}
    std::cout << "The sum of the digits of " << num << " is " << sum << std::endl;
    return 0;
}

