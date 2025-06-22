#include<stdio.h>

void Display(int,int);

int main()
{
	int iValue=0, iValue2=0;
	printf("Enter first Number: ");
	scanf("%d",&iValue);
	
	printf("Enter second Number: ");
	scanf("%d",&iValue2);
	
	Display(iValue, iValue2);
	return 0;
}

void Display(int iNo, int iNo2)
{
	int i=iNo;
	if(iNo>iNo2)
	{
		printf("Invalid Range\n");
	} 
	else
	{
		for(i;i<=iNo2;i++)
		{
			if(i%2==0){
			printf("%d  ",i);
		}
		}
	}
}