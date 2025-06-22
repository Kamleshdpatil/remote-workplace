#include<stdio.h>

void Pattern(int iNo)
{
	int iCnt=0;
	for(iCnt=iNo; iCnt>=1; iCnt--)
	{
		printf("%d  #  ",iCnt);
		
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