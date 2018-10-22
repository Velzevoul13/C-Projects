/*
 * Ring.h
 *
 *  Created on: Oct 22, 2018
 *      Author: Velzevoul
 */

#ifndef RING_H_
#define RING_H_
#include <iostream>


template <typename T>
class Ring{
private:
	int _pos;
	int _size;
	T *_values;

public:

	Ring(int size):_pos(0),_size(size),_values(NULL){
		_values = new T[size];
	}

	~Ring(){
		delete [] _values;
	}


	int size(){
		return _size;
	}

	void add(T value){
		_values[_pos++] = value;

		if(_pos == _size){
			_pos = 0;
		}
	}

	T& get(int pos){
		return _values[pos];
	}



};




#endif /* RING_H_ */
