/*
 * Factorial.cpp
 */

#include "Factorial.h"

int factorialRecurs(int n)
{
	if(n==1)
		return 1;
	else{
		return n*factorialRecurs(n-1);
	}

}

int factorialDinam(int n)
{
	static vector<int> answers = {1 , 1};
	if (n >= answers.size()){
			for (int i=answers.size() ; i<=n ; i++){
				answers.push_back(i*answers.at(i-1));
			}
	}
	return answers.at(n);
}
