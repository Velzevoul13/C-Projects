/*
 * ComplexNumbers.h
 *
 *  Created on: Oct 8, 2018
 *      Author: Velzevoul
 */

#ifndef COMPLEXNUMBERS_H_
#define COMPLEXNUMBERS_H_
#include <iostream>

namespace complexnum {

class ComplexNumbers {
private:

	double real;
	double imaginary;

public:
	ComplexNumbers();
	ComplexNumbers(double real,double imaginary);
	ComplexNumbers(const ComplexNumbers& other);	//Copy constructor.

public:

	double getreal() const{return real;};			//Getter for the real part.
	double getimaginary() const{return imaginary;};	//Getter for the imaginary part.
	void setreal(double);							//Setter for the real part.
	void setimaginary(double);						//Setter for the imaginary part.

	const ComplexNumbers& operator=(const ComplexNumbers&);	//Overloading the assignment operator to work with class objects.

	void print() const;

	virtual ~ComplexNumbers();
};

std::ostream& operator<<(std::ostream&,const ComplexNumbers&);	//Overloading the 'left bit shift' operator for printing.
ComplexNumbers operator+(const ComplexNumbers&,const ComplexNumbers&); //Overloading the 'plus' operator for addition of complex numbers.
ComplexNumbers operator+(const ComplexNumbers&,double number); 	//Overloading the 'plus' operator for addition of a complex number and real number.
ComplexNumbers operator+( double,const ComplexNumbers&); 	//Overloading the 'plus' operator for addition of a complex number and real number (real number is written first).


} /* namespace complexnum */

#endif /* COMPLEXNUMBERS_H_ */
