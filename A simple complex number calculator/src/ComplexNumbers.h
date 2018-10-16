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

	void setreal(double);						//Setter for real part.
	void setimaginary(double);					//Setter for imaginary part

public:

	const ComplexNumbers& operator=(const ComplexNumbers&);	//Overloading the assignment operator to work with class objects.


	void printrect() const;		//Print for rectangular form;
	void printpol() const;		//Print for polar form



	friend ComplexNumbers convertpol(const ComplexNumbers&);		//Conversion of a complex number to the polar form.
	friend ComplexNumbers convertrec(const ComplexNumbers&);		//Conversion of a complex number to the rectangular form.

	friend void comparison(const ComplexNumbers&,const ComplexNumbers&); //Equality comparison between two complex numbers
	friend ComplexNumbers multiply (const ComplexNumbers&, const ComplexNumbers&);	//Multiplication of two complex numbers.
	friend ComplexNumbers divide (const ComplexNumbers&, const ComplexNumbers&);	//Division of two complex numbers.


	bool operator==(const ComplexNumbers&)const;	//Overloading the '==' operator to work with class objects.
	bool operator!=(const ComplexNumbers&)const;	//Overloading the '!=' operator to work with class objects.

	virtual ~ComplexNumbers();
};

/********************************************************************************************/


std::ostream& operator<<(std::ostream&,const ComplexNumbers&);	//Overloading the 'left bit shift' operator for printing.


/*********************************************************************************************************************************/

ComplexNumbers operator+(const ComplexNumbers&,const ComplexNumbers&); //Overloading the 'plus' operator for addition of complex numbers.
ComplexNumbers operator+(const ComplexNumbers&,double); 	//Overloading the 'plus' operator for addition of a complex number and real number.
ComplexNumbers operator+(double,const ComplexNumbers&); 	//Overloading the 'plus' operator for addition of a complex number and real number (real number is written first).

/*********************************************************************************************************************************/

ComplexNumbers operator-(const ComplexNumbers&,const ComplexNumbers&); //Overloading the 'minus' operator for subtraction of complex numbers.
ComplexNumbers operator-(const ComplexNumbers&,double); 	//Overloading the 'minus' operator for subtraction of a complex number and real number.
ComplexNumbers operator+(double,const ComplexNumbers&); 	//Overloading the 'minus' operator for subtraction of a complex number and real number (real number is written first).


/*******************************************************************************************************************/


ComplexNumbers operator*(const ComplexNumbers&,double);	//Overloading the 'multiply' operator for multiplication of R*C.
ComplexNumbers operator*(double,const ComplexNumbers&); //Overloading the 'multiply' operator for multiplication of C*R.


/*******************************************************************************************************************/


ComplexNumbers operator/(const ComplexNumbers&,double);	//Overloading the 'divide by' operator for division of of R/C.
ComplexNumbers operator/(double,const ComplexNumbers&);	//Overloading the 'divide by' operator for division of of C/R.

} /* namespace complexnum */


#endif /* COMPLEXNUMBERS_H_ */
