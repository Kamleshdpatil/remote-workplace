#include<stdio.h>

void Display(int,int);

int main()
{
	int iValue=0, iValue2=0;
	printf("Enter Number: ");
	scanf("%d",&iValue);
	
	printf("Enter Number: ");
	scanf("%d",&iValue2);
	
	Display(iValue, iValue2);
	return 0;
}

void Display(int iNo, int iNo2)
{
    int i=0;
	if(iNo>iNo2)
	{
		printf("Invalid Range\n");
	} 
	else
	{
		for(i=iNo2; i>=iNo; i--)
		{
			printf("%d\t", i);
		}
	}
}