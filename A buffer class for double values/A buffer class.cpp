//============================================================================
// Name        : A Buffer class.cpp
// Author      : Me
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Ring.h"


int main() {

	Ring buffer(5);

	buffer.add(5.3);
	buffer.add(3.14);
	buffer.add(4.67);
	buffer.add(9.4);
	buffer.add(5.54);
	buffer.add(11.3);

	for(int i=0; i<buffer.size();i++){
		std::cout << buffer.get(i) << "\n";
	}

	return 0;
}
