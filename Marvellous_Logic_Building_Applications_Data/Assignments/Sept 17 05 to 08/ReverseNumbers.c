#include<stdio.h>

void ReverseNumber(int);

int main()
{
	int iValue=0;
	printf("Enter Number: ");
	scanf("%d", &iValue);
	
	ReverseNumber(iValue);
	
	return 0;	
}

void ReverseNumber(int iNo)
{
	int iDigit=0;
	if(iNo<0){
		iNo=-iNo;
	}
	while(iNo!=0){
		iDigit=iNo%10;
		printf("%d\n",iDigit);
		iNo=iNo/10;
	}
}

