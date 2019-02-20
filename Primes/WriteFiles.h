#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <thread>


class WriteFiles
{
public:

	void WriteToFile(std::ofstream& file, std::set<int> unique_primes)
	{

		std::string fileName = "CurrentOutput.xml";
		file.open(fileName);
		if (file.is_open())
		{
			file << "<?xml version=" << "\"1.0\"" << " encoding=" << "\"utf-8\"" << "?>" << "\n";
			file << "<root>\n";
			file << "\t<primes>";

			for (auto i : unique_primes)
			{
				file << i << " ";
			
			}
			
			file << "</primes>\n";
			file << "</root>";
			file.close();
		}

		else
		{
			std::cout << "Cannot open file " << std::endl;

		}
	}

};

