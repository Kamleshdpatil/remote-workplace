#include<stdio.h>

int Display(int,int);

int main()
{
	int iValue=0, iValue2=0, iRet=0;
	printf("Enter first Number: ");
	scanf("%d",&iValue);
	
	printf("Enter second Number: ");
	scanf("%d",&iValue2);
	
	iRet=Display(iValue, iValue2);
	if(iRet>0)
	{
		printf("Sum of Range: %d",iRet);
	}
	return 0;
}

int Display(int iNo, int iNo2)
{
	int i=iNo, iSum=0;
	if(iNo2<0)
	{iNo2=-iNo2;}
	
	if(iNo>iNo2)
	{
		printf("Invalid Range\n");
	}
	else if(iNo<0)
	{
		printf("Invalid Range\n");
	}
	else
	{
		for(i;i<=iNo2;i++)
		{
			iSum=iSum+i;
		}
	}
	return iSum;
}