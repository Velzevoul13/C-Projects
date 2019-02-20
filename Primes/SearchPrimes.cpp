//This method is slow for big numbers, but works very well for ranges.
//If very big numbers are involved, a better approach would be a sieve.


#include "pch.h"
#include <iostream>

#include "SearchPrimes.h"

//Checking if a number is odd
bool SearchPrimes::IsOdd(int val) 
{
	return ((val % 2 != 0) ? true : false);
}

//Algorithm that checks if a number is prime
bool SearchPrimes::IsPrime(int val) 
{
	if (val == 2)
	{
		return true;
	}


	if (val < 2) 
	{
		return false;
	}


	if (IsOdd(val)) 
	{
		for (int i = 3; i <= (val / 3); i += 2) 
		{
			if (val % i == 0)
				return false;
		}
		return true;
	} 


	else 
	{
		return false; // even numbers(excluding 2) are composite
	}
}

//Seting the range in which the search for primes will be conducted and
//writing all primes to a vector.
std::vector<int> SearchPrimes::RangePrime(const std::pair<int, int>& inIterval) {
	std::vector<int> vec;
	int low { 0 }, high { 0 };

	{
		low = inIterval.first;
		high = inIterval.second;

		for (int j = low; j != high + 1; ++j)
		{
			bool isPrime = IsPrime(j);
			if (isPrime) 
			{
				vec.push_back(j);
			}
		}
	}

	return vec;

}





