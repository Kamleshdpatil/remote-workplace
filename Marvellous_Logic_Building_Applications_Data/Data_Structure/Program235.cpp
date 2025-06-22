#include<iostream>
#include<stdlib.h>
using namespace std;

int FactI(int iNo)
{
	int iFact=1;
	
	while(iNo !=0)
	{
		iFact = iFact * iNo;
		iNo--;
	}
	return iFact;
}

int FactR(int iNo)
{
	static int iFact=1;
	
	if(iNo !=0)
	{
		iFact = iFact * iNo;
		iNo--;
		FactR(iNo);
	}
	return iFact;
}


int main()
{
	int x=0, iRet=0;
	
	cout<<"Enter Number: "<<endl;
	cin>>x;

	
	iRet= FactR(x);
	
	cout<<"Factorial of number is: "<<iRet<<"\n";
	
	return 0;
}