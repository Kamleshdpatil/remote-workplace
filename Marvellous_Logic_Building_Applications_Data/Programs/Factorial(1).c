#include<conio.h>
#include<stdio.h>

typedef unsigned int UINT;

UINT Fact(int);

UINT Fact(int iNo)
{
	UINT iFact=1;
	int iCnt=0;
	if(iNo<0)
	{
		iNo=-iNo;
	}
	iCnt=1;
	while(iCnt<=iNo)
	{
		iFact= iFact * iCnt;
		iCnt++;
	}
	return iFact;
}

int main()
{
	int iValue=0;
	UINT iRet=0;
	printf("Enter Number: ");
	scanf("%d",&iValue);
	
	iRet=Fact(iValue);
	printf("\n Factorial is: %ld",iRet);
	return 0;	
}