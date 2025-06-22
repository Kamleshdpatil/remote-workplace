#include<stdio.h>

void Pattern(int iNo)
{
	int iCnt=0, temp=0;
	for(iCnt=1; iCnt<=iNo; iCnt++)
	{
		temp=temp + 2;
		printf("%d\t", temp);
		
	}
}

int main()

{
	int iValue;
	printf("Enter the number: ");
	scanf("%d", &iValue);
	
	Pattern(iValue);
	
	return 0;
}