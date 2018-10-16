/*
 * Menu.cpp
 *
 *  Created on: Oct 15, 2018
 *      Author: Velzevoul
 */

#include <iostream>
#include <cmath>
#include "Menu.h"
#include "ComplexNumbers.h"

namespace complexnum {

Menu::Menu() {
}

void Menu::ShowMenu() {
	std::cout << "1. Addition.\n";
	std::cout << "2. Subtraction.\n";
	std::cout << "3. Multiplication.\n";
	std::cout << "4. Division.\n";
	std::cout << "5. Transformation.\n";
	std::cout << "Please enter you selection: ";
}

void Menu::TransSubMenu() {
	std::cout << "1. Transform from Rectangular to Polar.\n";
	std::cout << "2. Transform from Polar to Rectangular.\n";
}

void Menu::Addition() {
	double a, b, c, d;
	ComplexNumbers c1;
	ComplexNumbers c2;
	std::cout << "Enter the numbers you wish to add.\n";
	std::cout << "Enter Real: ";
	std::cin >> a;
	c1.setreal(a);
	std::cout << "Enter Imaginary: ";
	std::cin >> b;
	c1.setimaginary(b);
	std::cout << "First Number: " << c1;
	std::cout << "\n";
	std::cout << "Enter Real: ";
	std::cin >> c;
	c2.setreal(c);
	std::cout << "Enter Imaginary: ";
	std::cin >> d;
	c2.setimaginary(d);
	std::cout << "Second Number: " << c2;
	std::cout << "\n";
	ComplexNumbers sum = c1 + c2;
	std::cout << "Their sum is: " << sum <<"\n\n";
}

void Menu::Subtraction() {
	double a, b, c, d;
	ComplexNumbers c1;
	ComplexNumbers c2;
	std::cout << "Enter the numbers you wish to subtract.\n";
	std::cout << "Enter Real: ";
	std::cin >> a;
	c1.setreal(a);
	std::cout << "Enter Imaginary: ";
	std::cin >> b;
	c1.setimaginary(b);
	std::cout << "First Number: " << c1;
	std::cout << "\n";
	std::cout << "Enter Real: ";
	std::cin >> c;
	c2.setreal(c);
	std::cout << "Enter Imaginary: ";
	std::cin >> d;
	c2.setimaginary(d);
	std::cout << "Second Number: " << c2 << "\n";
	ComplexNumbers total = c1 - c2;
	std::cout << "Their total is: " << total <<"\n\n";
}

void Menu::Multiplication() {
	double a, b, c, d;
	ComplexNumbers c1;
	ComplexNumbers c2;
	std::cout << "Enter the numbers you wish to multiply.\n";
	std::cout << "Enter Real: ";
	std::cin >> a;
	c1.setreal(a);
	std::cout << "Enter Imaginary: ";
	std::cin >> b;
	c1.setimaginary(b);
	std::cout << "First Number: " << c1 << std::flush;
	std::cout << std::endl;
	std::cout << "Enter Real: ";
	std::cin >> c;
	c2.setreal(c);
	std::cout << "Enter Imaginary: ";
	std::cin >> d;
	c2.setimaginary(d);
	std::cout << "Second Number: " << c2 << std::flush;
	std::cout << std::endl;
	ComplexNumbers total = multiply(c1, c2);
	std::cout << "Their total is: " << total << "\n\n";
}

void Menu::Division() {
	double a, b, c, d;
	ComplexNumbers c1;
	ComplexNumbers c2;
	std::cout << "Enter the numbers you wish to multiply.\n";
	std::cout << "Enter Real: ";
	std::cin >> a;
	c1.setreal(a);
	std::cout << "Enter Imaginary: ";
	std::cin >> b;
	c1.setimaginary(b);
	std::cout << "First Number: " << c1 << std::flush;
	std::cout << std::endl;
	std::cout << "Enter Real: ";
	std::cin >> c;
	c2.setreal(c);
	std::cout << "Enter Imaginary: ";
	std::cin >> d;
	c2.setimaginary(d);
	std::cout << "Second Number: " << c2 << std::flush;
	std::cout << std::endl;
	ComplexNumbers total = divide(c1, c2);
	std::cout << "Their total is: " << total <<"\n\n";
}

void Menu::ConvToPol() {
	double a, b;
	ComplexNumbers c1;
	std::cout << "Enter the complex number you wish to convert to Polar form. ";
	std::cout << "E.g. (a+bj)\n";
	std::cout << "Real part: ";
	std::cin >> a;
	c1.setreal(a);
	std::cout << std::endl;
	std::cout << "Imaginary part: ";
	std::cin >> b;
	c1.setimaginary(b);
	std::cout << std::endl;
	std::cout << "The Polar equivalent is: ";
	ComplexNumbers c2 = convertpol(c1);
	c2.printpol();
	std::cout << "\n\n";
}

void Menu::ConvToRec() {
	double a, b;
	ComplexNumbers c1;
	std::cout << "Enter the complex number you wish to convert to Rectangular form. ";
	std::cout << "E.g. (a /_b)\n";
	std::cout << "Real part: ";
	std::cin >> a;
	c1.setreal(a);
	std::cout << "Imaginary part: ";
	std::cin >> b;
	c1.setimaginary(b);
	std::cout << "The Rectangular equivalent is: ";
	ComplexNumbers c2 = convertrec(c1);
	c2.printrect();
	std::cout << "\n\n";
}


Menu::~Menu() {

}

} /* namespace complexnum */
