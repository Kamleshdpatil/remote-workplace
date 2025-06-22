#include<stdio.h>
#include<stdbool.h>

#define TRUE 1
#define FALSE 0

typedef int BOOL;

BOOL ChkAplha(char ch)
{
	if(ch>47 && ch<58)
	{
		return TRUE;
	}
	else{
		return FALSE;
	}
}

int main()
{
	char cValue='\0';
	BOOL bRet=false;
	
	printf("Enter the character ");
	scanf("%c",&cValue);
	
	bRet=ChkAplha(cValue);
	
	if(bRet==TRUE)
	{
		printf("It is Digit");
	}
	else
	{
		printf("It is not Digit");
	}
	
	return 0;
}