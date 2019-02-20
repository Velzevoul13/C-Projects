// Primes.cpp :This program finds all prime numbers within set intervals, read from .xml files. Each interval runs in its own thread
//			   and all found prime numbers are stored in a vector, then exported to a .xml file.

#include "pch.h"


#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <chrono>
#include <algorithm>
#include <thread>
#include <stdexcept>


#include "SearchPrimes.h"
#include "WriteFiles.h"





std::vector<int> CalcPrimeForInterval(const std::pair<int, int>& inInterval)
{
	SearchPrimes primes;
	return primes.RangePrime(inInterval);
	
	 
}

void calcPrimesThreadFunc(int inIndex, const std::pair<int, int>& inInterval, std::vector<std::vector<int> >& sharedAnswers)
{
	auto prime = CalcPrimeForInterval(inInterval);
	
	sharedAnswers[inIndex] = prime;
	
}

std::vector<std::pair<int, int> >  ParseXML()
{

	XMLParser file;

	std::vector<std::pair<int,int> > myvec = file.stringsToInts();

	return myvec;
}

int main(int argc, const char * argv[])
{

	const auto intervals = ParseXML();

	
	const auto numTasks = intervals.size();

	std::vector<std::vector<int>> sharedAnswerVec(numTasks);

	std::vector<std::thread> threads(numTasks);

	//spawn all thread
	for (int i = 0; i < numTasks; i++)
	{
		threads[i] = std::thread(calcPrimesThreadFunc, i, std::cref(intervals[i]), std::ref(sharedAnswerVec));
	}

	//join all threads
	for (unsigned int i = 0; i < numTasks; i++)
	{
		threads[i].join();
	}

	std::cout << "Prime numbers found in the intervals" << std::endl << std::endl;
	
	for (auto row = 0; row < sharedAnswerVec.size(); row++) {
		for (auto col = 0; col < sharedAnswerVec[row].size(); col++) {
			std::cout << sharedAnswerVec[row][col] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	//Removing the double primes before writing the file 
	std::set<int> unique_primes;
	for (const auto& v : sharedAnswerVec)
	{
		for (auto i : v)
		{
			unique_primes.insert(i);
		}
	}

	std::cout << "Unique prime numbers to be written in the .xml file" << std::endl << std::endl;

	for (auto i : unique_primes)
	{
		std::cout << i << " ";
	}

	std::cout << std::endl;

	//Writing the .xml fime
	WriteFiles outFile;
	std::ofstream file;
	outFile.WriteToFile(file, unique_primes);


	return 0;
}






