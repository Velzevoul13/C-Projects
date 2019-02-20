#pragma once

#include <iostream>
#include <vector>


class XMLParser
{

public:

	void removeTags(std::string&);	//Removing the brackets of the tags of the .xml


	std::string openFile(std::string);	//Opening a file
	std::vector<std::string> readFile(const std::string&, std::string); //Getting the text from the .xml file to a vector

	std::vector<std::pair<int, int> > stringsToInts();	//Finding the values of the tags that contain the ranges
													    //and converting the string numbers to a vector<int>
};
