#include <conio.h>
#include <stdio.h>

typedef unsigned long int UINT;

UINT Fact(int);
UINT Fact(int iNo)
{
	UINT iFact = 1;
	int iCnt = 0;
	if (iNo < 0)
	{
		iNo = -iNo;
	}
	for (iCnt = 1; iCnt <= iNo; iCnt++)
		iFact = iFact * iCnt;
	return iFact;
}

int main()
{
	int iValue = 0;
	UINT iRet = 0;
	printf("Enter Number: ");
	scanf("%ld", &iValue);

	iRet = Fact(iValue);
	printf("\n Factorial is: %ld", iRet);
	return 0;
}