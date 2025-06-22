#include<stdio.h>

int RevNumber(int);

int main()
{
	int iValue=0, iDigit=0, iRev=0;
	printf("Enter Number:" );
	scanf("%d",&iValue);
	
	iRev=RevNumber(iValue);
	printf("Ohh your reversed number is ready: %d",iRev);
	
	return 0;
}

int RevNumber(int iNo)
{
	int iDigit=0, iRev=0;
	
	while(iNo!=0)
	{
		iDigit= iNo % 10;
		//printf("%d\n",iDigit);
		iRev=((iRev *10) + iDigit);
		//printf("%d\n",iRev);
		iNo=iNo/10;
	}
	return iRev;
}