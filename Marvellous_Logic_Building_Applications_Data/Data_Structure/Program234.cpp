#include<iostream>
#include<stdlib.h>
using namespace std;


int SumI(int iNo)
{
	int iSum=0;
	
	while(iNo != 0)
	{
		iSum = iSum +(iNo % 10);
		iNo= iNo/10;
	}
	
	return iSum;
}

int SumR(int iNo)
{
	static int iSum=0;
	
	if(iNo != 0)
	{
		iSum = iSum +(iNo % 10);
		iNo= iNo/10;
		
		SumR(iNo);
	}
	
	return iSum;
}


int main()
{
	int x=0, iRet=0;
	
	cout<<"Enter Number: "<<endl;
	cin>>x;
	
//	iRet= SumI(x);
//	
//	cout<<"Summation of Digits: "<<iRet<<"\n";
	
	iRet= SumR(x);
	
	cout<<"Summation of Digits: "<<iRet<<"\n";
	
	return 0;
}