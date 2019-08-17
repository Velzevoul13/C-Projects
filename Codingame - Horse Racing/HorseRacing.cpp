#include <iostream>
#include <algorithm>
#include <vector>


int main() 
{
	std::vector<int> horses({ 11,1,3,4,2,5,12,5,7,12,44,32, });
	
	
	std::sort(horses.begin(), horses.end());

	int result = horses.back();

	for (int i = 0; i < horses.size() - 1; ++i)
	{
		int curr = horses[i];
		int next = horses[i + 1];

		int dif = abs(curr - next);

		if (dif < result)
		{
		
			result = dif;
		}
		
	}

	std::cout << result;
	

	return 0;
}