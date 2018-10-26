//============================================================================
// Name        : Task.cpp
// Author      : Me
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>



int solution(std::vector<int>&);

int main() {

	std::vector<int> A = {0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1};

	solution(A);

	return 0;
}


int solution(std::vector<int>& A){
	int n = A.size();
	int i = n-1;
	int result = 0;
	int k = 0;
	int maximal = 0;
	while(i>0){
		if(A[i]==1){
			k = k+1;
			if(k >= maximal){
				maximal = k;
				result = i;
			}
		} else {
			k = -1;
		}
		i = i-1;
	}
	if((A[i]==0) && (k+1 >= maximal)){
		result = -1;
	}
	std::cout << result;
	return result;
}
