#include <iostream>
#include <string>
#include <vector>
#include <algorithm>





int main()
{
	const int N = 3;
	int L = 3;

	std::string input{};
	
	int map[N][N]{ 0 };
	int luminance[N][N]{ 0 };

	std::cout << "now:" << std::endl;

	

	for (int i = 0; i < N; ++i)
	{
		std::getline(std::cin, input);
		//removing white spaces from input
		input.erase(std::remove_if(input.begin(), input.end(), [](const char c) {return std::isspace(c); }) );
		
		//for every letter in the input string
		for (int k = 0; k < N; ++k)
		{
			//place each letter in the map array
			map[i][k] = input[k];
		}
		
	}
	

	for(int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			
			if (map[i][j] == 'C')
			{
				
				int col = j;
				int row = i;

				for (int k = 0; k < N; ++k)
				{
					for (int l = 0; l < N; ++l)
					{
						if (luminance[k][l] == 0)
						{
							int distance = std::max(std::abs(k - row), std::abs(l - col));
							luminance[k][l] = std::max(L - distance, 0);
						}
					}
				}
							
			}
			
		}
	}

	int counter{ 0 };

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			std::cout << luminance[i][j];
			if (luminance[i][j] == 0) { counter++; }
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;

	std::cout << "counter = " << counter;
	

	return 0;
}