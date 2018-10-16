/*
 * Menu.h
 *
 *  Created on: Oct 15, 2018
 *      Author: Velzevoul
 */

#ifndef MENU_H_
#define MENU_H_

namespace complexnum {

class Menu {
public:
	Menu();
	virtual ~Menu();

public:

	void ShowMenu();
	void TransSubMenu();
	void Addition();
	void Subtraction();
	void Multiplication();
	void Division();
	void ConvToPol();
	void ConvToRec();

};

} /* namespace complexnum */

#endif /* MENU_H_ */
