//============================================================================
// Name        : Buffer.cpp
// Author      : Me
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Ring.h"


int main() {

	Ring<std::string> buffer(5);

	buffer.add("One");
	buffer.add("Two");
	buffer.add("Three");
	buffer.add("Four");
	buffer.add("Five");
	buffer.add("Six");
	//buffer.add("Seven");

	for(int i=0; i < buffer.size(); i++ ){
		std::cout << buffer.get(i) << "\n";
	}

	return 0;
}
