#pragma once

#include <vector>
#include "XMLParser.h"

class SearchPrimes 
{

public:
	std::vector<int> RangePrime(const std::pair<int, int>&); //Setting the range to search for prime numbers, executing the algorithm
	
	bool IsPrime(int);	//The algorithm that checks if a number is prime
	bool IsOdd(int);	//Checking if a number if even or odd

};


