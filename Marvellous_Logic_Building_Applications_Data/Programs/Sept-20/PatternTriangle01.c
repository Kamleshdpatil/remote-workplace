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
	int i=0,j=0;
	for(i=1; i<=iNo; i++)
	{
		for(j=1; j<=i; j++)
	{
		printf("%d * ",j);
	}
		printf("\n");
	}
}