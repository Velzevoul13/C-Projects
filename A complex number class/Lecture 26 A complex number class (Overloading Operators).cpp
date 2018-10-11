//============================================================================
// Name        : Lecture.cpp
// Author      : Me
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include "ComplexNumbers.h"

using namespace complexnum;

int main() {

	ComplexNumbers number1(3,5);
	number1.print();
	std::cout << "\n";
	std::cout << number1;

	ComplexNumbers number2;
	number2.setreal(6);
	number2.setimaginary(-3);
	number2.print();
	std::cout << "\n";
	std::cout << number2;
	std::cout << "\n";

	ComplexNumbers number3(7,-23.5);
	ComplexNumbers number4 = number1+number1;
	ComplexNumbers number5 = number4 + number3;
	std::cout << number5 << "\n";
	number5.print();
	std::cout << "\n";

	std::cout << number5 - number3 << "\n";
	std::cout << "\n";

	comparison(number4, number5);
	std::cout << "\n";
	ComplexNumbers number6 = multiply(number4,number5);
	std::cout << number6 << "\n";
	std::cout << number2*4 << "\n";
	std::cout << 3*number2+number5 << "\n";


	return 0;
}
