#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>



bool IsOnlyNumbers(std::string& str)
{
	return std::all_of(str.begin(), str.end(), std::isdigit);
}


bool IsAValidISBN(std::string& str)
{
	int size = str.length();
	std::vector<int> digits;

	int sum = 0;

	if (size == 10)
	{
		auto num = std::stoull(str);
		std::string num_str = std::to_string(num);

		while (num > 0)
		{
			digits.push_back(num % 10);
			num /= 10;
		}

		std::reverse(digits.begin(), digits.end());

		if (size > num_str.length())
		{
			for (int i = 0; i < size - num_str.length(); ++i)
			{
				digits.insert(digits.begin(), 0);
			}
		}

		int counter = 10;

		for (int i = 0; i < digits.size() - 1; ++i)
		{
			sum += digits[i] * counter;
			counter--;
		}

		sum = sum % 11;
		int check_digit = 11 - sum;

		std::cout << "check_digit: " << check_digit << std::endl;

		if (digits[9] == check_digit) { return true; }
	}
	else if (size == 13)
	{
		auto num = std::stoull(str);
		std::string num_str = std::to_string(num);

		while (num > 0)
		{
			digits.push_back(num % 10);
			num /= 10;
		}

		std::reverse(digits.begin(), digits.end());

		if (size > num_str.length())
		{
			for (int i = 0; i < size - num_str.length(); ++i)
			{
				digits.insert(digits.begin(), 0);
			}
		}

		int counter = 13;

		
		for (int i = 0; i < digits.size() - 1; ++i)
		{
			if (i % 2 == 0)
			{
				sum += digits[i] * 1;
			}
			else
			{
				sum += digits[i] * 3;
			}

			counter--;
		}

		sum = sum % 10;
		int check_digit = 10 - sum;

		std::cout << "check_digit: " << check_digit << std::endl;

		if (digits[12] == check_digit) { return true; }

	}
	
}



int main()
{
	
	std::vector<std::string> ISBN({ "0470371722","9781119247792","9780470124512","11190495550","1118105354","9781118737637",
			"0387372350","154875155X","9781548751555","978193981677" });
	std::vector<std::string> invalid;

	
	//valid code
	for (int i = 0; i < ISBN.size(); i++)
	{
		int digitLength = ISBN[i].length();
		bool checkIfOnlyNumber = IsOnlyNumbers(ISBN[i]);

		if (digitLength != 10 && digitLength != 13 || !checkIfOnlyNumber)
		{
			invalid.push_back(ISBN[i]);
		}
		else 
		{
			if (!IsAValidISBN(ISBN[i]))
			{
				invalid.push_back(ISBN[i]);
			}
		}
	}


	for (auto i = invalid.begin(); i != invalid.end(); ++i)
	{
		std::cout << *i << " ";
	}


	return 0;
}