#include<stdio.h>
void Display(int);

int main()
{
	int iValue=0;
	printf("Enter a Number: ");
	scanf("%d", &iValue);
	Display(iValue);
	return 0;
}

void Display(int iNo)
{
	int iCnt=0;
	for(iCnt=1; iCnt<=iNo; iCnt++)
	{
		if(iCnt %2==0)
		{
			printf(" # ");
		}
		else
		{
			printf(" * ");
		}
	}
}