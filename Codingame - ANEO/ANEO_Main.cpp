#include <iostream>
#include <vector>
#include <utility>


bool IsRed(int speed, int distance, int time) 
{
	if ((18 * distance) % (10 * speed * time) >= (5 * speed * time)) {  return true; }

	return false;
}


int main()
{
	std::vector<std::pair<int, int> > DistanceTime = { { 200,10 } };
	int maxSpeed = 50;
	int traficLights = 31;

	for (int i = 0; i < traficLights; i++)
	{
		for (auto j = DistanceTime.begin(); j != DistanceTime.end(); ++j)
		{
			int distance = j->first;
			int time = j->second;
			if (IsRed(maxSpeed, distance, time))
			{
				maxSpeed--;
				i = 0;
				j = DistanceTime.begin();
				
			}

			
		}

		
	}

	std::cout <<  maxSpeed << std::endl;

	return 0;
}
