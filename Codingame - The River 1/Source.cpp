#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int GetSum(int number);


int main()
{

	int seed1 = 57;
	int seed2 = 78;

	while (seed1 != seed2)
	{
		if (seed1 < seed2) { seed1 += GetSum(seed1); }
		else if (seed1 > seed2) { seed2 += GetSum(seed2); }
		if (seed1 == seed2) { std::cout << seed1; }
	}
	
	
	return 0;
}

int GetSum(int number)
{
	int temp{ 0 };
	int sum{ 0 };
	while (number != 0)
	{
		temp = number % 10;
		sum += temp;
		number = number / 10;
	}
	return sum;
}