/*
 * ComplexNumbers.cpp
 *
 *  Created on: Oct 8, 2018
 *      Author: Velzevoul
 */

#include <iostream>
#include "ComplexNumbers.h"

namespace complexnum {

ComplexNumbers::ComplexNumbers():real(0),imaginary(0){}	//Default constructor
ComplexNumbers::ComplexNumbers(double real,double imaginary):real(real),imaginary(imaginary){}	//Object constructor.
ComplexNumbers::ComplexNumbers(const ComplexNumbers& other) {	//copy constructor
	real = other.real;
	imaginary = other.imaginary;
}





void ComplexNumbers::setreal(double NewReal){	//Setter for real part.
	real =NewReal;
}
void ComplexNumbers::setimaginary(double NewImaginary){		//Setter for imaginary part.
	imaginary = NewImaginary;
}

void ComplexNumbers::print() const {						//Simple print function.
	std::cout <<"(" << real <<"," << imaginary << "j)";
}

const ComplexNumbers& ComplexNumbers::operator=(const ComplexNumbers& other){	//Copy constructor.
	*this = other;
	return other;
}






std::ostream& operator<<(std::ostream& output,const ComplexNumbers& other){		//Overloading the lest bit shift operator for printing.

	output <<"(" << other.getreal() <<"," << other.getimaginary() << "j)";
	return output;
}



ComplexNumbers operator+(const ComplexNumbers& complex1,const ComplexNumbers& complex2){ //Overloading the 'plus' operator for addition of complex numbers.
	return ComplexNumbers (complex1.getreal()+complex2.getreal(),complex1.getimaginary()+complex2.getimaginary());
}

ComplexNumbers operator+(const ComplexNumbers& complex, double number){	//Overloading the 'plus' operator for addition of a complex number and real number.
	return ComplexNumbers (complex.getreal()+number, complex.getimaginary());
}

ComplexNumbers operator+( double number,const ComplexNumbers& complex){	//Overloading the 'plus' operator for addition of a complex number and real number (real number is written first).
	return ComplexNumbers (complex.getreal()+number, complex.getimaginary());
}




ComplexNumbers operator-(const ComplexNumbers& complex1,const ComplexNumbers& complex2){	//Overloading the 'minus' operator for subtraction of complex numbers.
	return ComplexNumbers(complex1.getreal()-complex2.getreal(),complex1.getimaginary()-complex2.getimaginary());
}

ComplexNumbers operator-(const ComplexNumbers& complex,double number){ 	//Overloading the 'minus' operator for subtraction of a complex number and real number.
	return ComplexNumbers(complex.getreal()-number,complex.getimaginary());
}

ComplexNumbers operator-(double number,const ComplexNumbers& complex){ 	//Overloading the 'minus' operator for subtraction of a complex number and real number (real number is written first)
	return ComplexNumbers(complex.getreal()-number,complex.getimaginary());
}
ComplexNumbers::~ComplexNumbers() {}

} /* namespace complexnum */
