#include<iostream>
#include<vector>

using namespace std;

int sumOfAllDivisors(int n){
	// Write your code here.
	int sumAll = 0, sum = 0;
	for (int i = 1; i <= n; i++) {
		sum = 0;
		for (int j = 1; i <= i; j++) {
			if(i % j == 0)
			{
				sum+=sum;
			}
		}
		sumAll += sum;
	}

	return(sumAll);
}

int main(void)
{
	cout<<sumOfAllDivisors(5);
	return(0);
}
