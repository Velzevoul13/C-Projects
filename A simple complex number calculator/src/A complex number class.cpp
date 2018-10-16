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
#include "Menu.h"

using namespace complexnum;

void ShowIntro();

int main() {

	int choice = 0;
	int done = 0;
	while (!done) {
		ShowIntro();
		Menu menu;
		menu.ShowMenu();
		std::cin >> choice;
		switch (choice) {
		case 1:
			if (choice == 1) {
				menu.Addition();
			}
			break;
		case 2:
			if (choice == 2) {
				menu.Subtraction();
			}
			break;
		case 3:
			if (choice == 3) {
				menu.Multiplication();
			}
			break;
		case 4:
			if (choice == 4) {
				menu.Division();
			}
			break;
		case 5:
			if (choice == 5) {
				menu.TransSubMenu();
				int i = 0;
				std::cin >> i;
				if (i == 1) {
					menu.ConvToPol();
				} else if (i == 2) {
					menu.ConvToRec();
				} else {
					std::cout << "Wrong input please select option 1 or 2.\n";
					menu.TransSubMenu();
					std::cin >> i;
					if (i == 1) {
						menu.ConvToPol();
					} else if (i == 2) {
						menu.ConvToRec();
					}

				}
			}
			break;
		default:
			std::cout << "Invalid choice.\n";
		}
	}

	return 0;
}

void ShowIntro() {
	std::cout << "This is a simple complex number calculator.\n";
	std::cout
			<< "It can handle addition, subtraction, multiplication and division \nbetween "
					"complex numbers and real numbers.\n";
	std::cout
			<< "It can transform a complex number, from the rectangular form, \n"
					"to the polar form and vice versa.";
	std::cout << "\n";
	std::cout
			<< "**********************************************************************\n";
}
