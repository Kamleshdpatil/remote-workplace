#include<stdio.h>

void Pattern(int iNo)
{
	int iCnt=0;
	for(iCnt=0; iCnt<=iNo; iCnt++)
	{
		printf("%d  *  ",iCnt);
		
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