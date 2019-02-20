#include "pch.h"
#include "XMLParser.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdio>
#include <iterator>
#include <utility>
#include <algorithm>




std::string XMLParser::openFile(std::string file) //Opening a file
{
	std::string line;
	char c;

	std::ifstream fileContents(file);
	if (!fileContents) {
		std::cout << file << " not found." << std::endl;
	}

	while (fileContents.get(c)) {
		line += c;
	}

	fileContents.close();

	return line;
}


//Getting the all the text from the .xml file and storing it to a vector
std::vector<std::string> XMLParser::readFile(const std::string &text, std::string tag)
{
	std::vector<std::string> myVec;
	unsigned int pos = 0, start;

	while (true) 
	{
		start = text.find("<" + tag, pos);

		if (start == std::string::npos) 
		{
			return myVec;
		}

		start = text.find(">", start);
		start++;

		pos = text.find("</" + tag, start);
		if (pos == std::string::npos) {
			return myVec;
		}

		myVec.push_back(text.substr(start, pos - start));
	}
}


//Removing the brackets of the tags of the .xml
void XMLParser::removeTags(std::string& text)
{
	unsigned int start = 0, pos;

	while (start < text.size()) 
	{
		start = text.find("<", start);

		if (start == std::string::npos) 
		{
			break;
		}

		pos = text.find(">", start);

		if (pos == std::string::npos) 
		{
			break;
		}

		text.erase(start, pos - start + 1);
	}
}


// Finding the values of the tags that contain the ranges
// and converting the string numbers to a vector<int>
std::vector<std::pair<int, int> > XMLParser::stringsToInts()
{
	XMLParser file;
	std::string filename = "find_primes.xml"; //File to be openned 
	std::string tag1 = "low";
	std::string tag2 = "high";
	bool stripTags = true;

	std::string text = file.openFile(filename);

	std::vector<std::string> vec1 = file.readFile(text, tag1); //vector that contains the begining value of the range
	for (std::string &line : vec1) 
	{
		if (stripTags) 
		{
			file.removeTags(line);
		}

	}

	std::vector<std::string> vec2 = file.readFile(text, tag2); //vector that contains the end value of the range
	for (std::string &line : vec2) 
	{
		if (stripTags) 
		{
			file.removeTags(line);
		}

	}


	std::vector<int> vec1Int;
	std::vector<int> vec2Int;

	//Converting the strings into ints
	std::transform(vec1.begin(), vec1.end(), std::back_inserter(vec1Int),
		[](const std::string& str) {return std::stoi(str); });

	//Debug code
	/*for (auto it = vec1Int.begin(); it != vec1Int.end(); ++it)
	{
		std::cout << *it << " ";
	}*/

	std::transform(vec2.begin(), vec2.end(), std::back_inserter(vec2Int),
		[](const std::string& str) {return std::stoi(str); });
	
	
	//Debug line
	//std::cout << std::endl;

	//Debug code
	/*for (auto it = vec2Int.begin(); it != vec2Int.end(); ++it)
	{
		std::cout << *it << " ";
	}*/


	std::vector<std::pair <int, int>> vecAll;
	vecAll.reserve(vec1Int.size());
	std::transform(vec1Int.begin(), vec1Int.end(), vec2Int.begin(), std::back_inserter(vecAll),
		[](int a, int b) { return std::make_pair(a, b); });


	std::cout << "Intervals to search for primes:" << std::endl << std::endl;

	for (size_t x = 0; x < vecAll.size(); ++x) 
	{
		std::cout << vecAll[x].first << "," << vecAll[x].second << std::endl;
	}

	std::cout << std::endl;

	return vecAll;
}