/*
 * ComplexNumbers.cpp
 *
 *  Created on: Oct 8, 2018
 *      Author: Velzevoul
 */

#include <iostream>
#include <cmath>
#include "ComplexNumbers.h"



namespace complexnum {

ComplexNumbers::ComplexNumbers():real(0),imaginary(0){}	//Default constructor
ComplexNumbers::ComplexNumbers(double real,double imaginary):real(real),imaginary(imaginary){}	//Object constructor.
ComplexNumbers::ComplexNumbers(const ComplexNumbers& other) {	//Copy constructor
	real = other.real;
	imaginary = other.imaginary;
}


/******************************************************************************/

//Setter for real part.
void ComplexNumbers::setreal(double NewReal){
	real=NewReal;
}

//Setter for imaginary part.
void ComplexNumbers::setimaginary(double NewImaginary){
	imaginary=NewImaginary;
}


/****************************************************************************************/

//Printing in rectangular form.
void ComplexNumbers::printrect() const {
	std::cout <<"(" << real <<"," << imaginary << "j)";
}

//Printing in polar form.
void ComplexNumbers::printpol() const{
	std::cout << real << " /_ " << imaginary;
}

//Overloading the '=' operator to work with class objects
const ComplexNumbers& ComplexNumbers::operator=(const ComplexNumbers& other){
	*this = other;
	return other;
}

//Overloading the '==' operator to work with class objects.
bool ComplexNumbers::operator==(const ComplexNumbers& other)const{
	return (real == other.real)&&(imaginary==other.imaginary);
}

//Overloading the '!=' operator to work with class objects.
bool ComplexNumbers::operator!=(const ComplexNumbers& other)const{
return !(*this == other);
}



/***************************************************************************************************************/


//Overloading the left bit shift operator for printing.
std::ostream& operator<<(std::ostream& output,const ComplexNumbers& other){
	output <<"(" << other.getreal() <<"," << other.getimaginary() << "j)";
	return output;
}



/************************************************************************************************************************/

//Overloading the 'plus' operator for addition of complex numbers.
ComplexNumbers operator+(const ComplexNumbers& c1,const ComplexNumbers& c2){
	return ComplexNumbers (c1.getreal()+c2.getreal(),c1.getimaginary()+c2.getimaginary());
}


//Overloading the 'plus' operator for addition of a complex number and real number.
ComplexNumbers operator+(const ComplexNumbers& c, double d){
	return ComplexNumbers (c.getreal()+d, c.getimaginary());
}

//Overloading the 'plus' operator for addition of a complex number and real number (real number is written first).
ComplexNumbers operator+( double d,const ComplexNumbers& c){
	return ComplexNumbers (c.getreal()+d, c.getimaginary());
}


/*****************************************************************************************************************************/


//Overloading the 'minus' operator for subtraction of complex numbers.
ComplexNumbers operator-(const ComplexNumbers& c1,const ComplexNumbers& c2){
	return ComplexNumbers(c1.getreal()-c2.getreal(),c1.getimaginary()-c2.getimaginary());
}

//Overloading the 'minus' operator for subtraction of a complex number and real number.
ComplexNumbers operator-(const ComplexNumbers& c,double d){
	return ComplexNumbers(c.getreal()-d,c.getimaginary());
}

//Overloading the 'minus' operator for subtraction of a complex number and real number (real number is written first)
ComplexNumbers operator-(double d,const ComplexNumbers& c){
	return ComplexNumbers(c.getreal()-d,c.getimaginary());
}



/****************************************************************************************************************/

//Multiplication of two complex numbers.
ComplexNumbers multiply (const ComplexNumbers& c1, const ComplexNumbers& c2){
	ComplexNumbers temp;
	temp.real = c1.real*c2.real - c1.imaginary - c2.imaginary;
	temp.imaginary = c1.real*c2.imaginary + c1.imaginary*c2.real;
	return temp;
}

//Overloading the 'multiply' operator for multiplication of R*C.
ComplexNumbers operator*(const ComplexNumbers& c,double d){
	return ComplexNumbers (c.getreal()* d,c.getimaginary()*d);
}


//Overloading the 'multiply' operator for multiplication of C*R.
ComplexNumbers operator*(double d,const ComplexNumbers& c){
	return ComplexNumbers (c.getreal()* d,c.getimaginary()*d);
}

/******************************************************************************************************/

//Division of two complex numbers.
ComplexNumbers divide (const ComplexNumbers& c1, const ComplexNumbers& c2){
	ComplexNumbers temp;
	temp.real = (((c1.real*c2.real)) + (c1.imaginary*c2.imaginary))/(pow(c2.real,2)+pow(c2.imaginary,2));
	temp.imaginary = (((c2.real)*(c1.imaginary))-((c1.real)*(c2.imaginary)))/(pow(c2.real,2)+pow(c2.imaginary,2));
	return temp;
}

ComplexNumbers operator/(const ComplexNumbers& c,double d){
	return ComplexNumbers (c.getreal()/d,c.getimaginary()/d);
}


ComplexNumbers operator/(double d,const ComplexNumbers& c){
	return ComplexNumbers (c.getreal()/d,c.getimaginary()/d);
}

/*****************************************************************************************************************/

//Conversion of a complex number to the polar form.
ComplexNumbers convertpol(const ComplexNumbers& c){
	ComplexNumbers temp;
	double PI = 3.14159265;
	temp.real = sqrt(c.real+c.imaginary);
	temp.imaginary = atan2(c.imaginary,c.real)*180 / PI;

	return temp;
}

//Conversion of a complex number to the rectangular form.
ComplexNumbers convertrec(const ComplexNumbers& c){
	double PI = 3.14159265;
	ComplexNumbers temp;
	temp.real = c.real * (cos (c.imaginary*PI/180));
	temp.imaginary = c.real * (sin(c.imaginary*PI/180));
	return temp;
}


/**********************************************************************************************************************/


//Equality comparison between two complex numbers
void comparison(const ComplexNumbers& c1,const ComplexNumbers& c2){
	if(c1==c2){
		std::cout << "The complex numbers are equal.";
	} else {
		std::cout <<"The complex numbers are not equal.";
	}

}



ComplexNumbers::~ComplexNumbers() {}

} /* namespace complexnum */
