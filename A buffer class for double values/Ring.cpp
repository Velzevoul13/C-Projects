/*
 * Ring.cpp
 *
 *  Created on: Oct 22, 2018
 *      Author: Velzevoul
 */

#include "Ring.h"

void Ring::add(double value){
	_values[_pos++] = value;
	if(_pos==_size){
		_pos=0;
	}
}

double& Ring::get(int pos){
	return _values[pos];
}




