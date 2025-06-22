#include<stdio.h>
#include<stdbool.h>

#define TRUE 1
#define FALSE 0

typedef int BOOL;

BOOL ChkAplha(char ch)
{
	if(ch>90)
	{
		ch=ch-32;
	}
	if(ch==65)
	{
		printf("Your exam at 7 AM");
	}
	else if(ch==66)
	{
		printf("Your exam at 8.30 AM");;
	}
	else if(ch==67)
	{
		printf("Your exam at 9.20 AM");;
	}
	else if(ch==68)
	{
		printf("Your exam at 10.30 AM");;
	}else{
		printf("\nIvalid input");
	}
}

int main()
{
	char cValue='\0';
	BOOL bRet=false;
	
	printf("Enter the character ");
	scanf("%c",&cValue);
	
	ChkAplha(cValue);
	
	return 0;
}