//
//



#include <iostream>
#include <vector>

int solution(std::vector<int>&);

int main()
{

	std::vector<int> A = { 1,4,-1,3,2 };

	solution(A);



}

int solution(std::vector<int>& A) {
	int i = 0;
	int count = 0;
	while (i != -1) {
		i = A[i];
		count++;
	}

	std::cout << "Count is: " << count;
	return count;
}


