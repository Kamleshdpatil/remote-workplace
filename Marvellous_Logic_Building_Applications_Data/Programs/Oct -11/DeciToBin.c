#include<stdio.h>

void DisplayBin(int iNo)
{
	int iDigit=0;
	
	while(iNo!= 0)
	{
		iDigit=iNo % 2;
		printf("%d\t",iDigit);
		iNo=iNo/2;
	}
}

int main()
{
	int iValue=0;
	
	printf("Enter Number");
	scanf("%d",&iValue);
	
	DisplayBin(iValue);
	
	return 0;
}