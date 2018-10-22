/*
 * Ring.h
 *
 *  Created on: Oct 22, 2018
 *      Author: Velzevoul
 */

#ifndef RING_H_
#define RING_H_
#include <iostream>

class Ring {
private:
	int _pos;
	int _size;
	double *_values;

public:
	Ring(int size):_pos(0), _size(size),_values(NULL){
		_values = new double [size];
	}

	virtual ~Ring(){
		delete [] _values;
	}


	int size() {return _size;}

	void add(double value);

	double& get(int pos);

};

#endif /* RING_H_ */
