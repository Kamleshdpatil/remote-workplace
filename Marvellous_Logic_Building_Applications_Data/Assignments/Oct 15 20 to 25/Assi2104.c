#include<stdio.h>
#include<stdbool.h>

#define TRUE 1
#define FALSE 0

bool ChkSpecial(char ch)
{
//	if(ch<=64 || ch<=33)
//	{
//		return TRUE;
//	}
	if((ch>='!') && ch<='@')
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}


int main()
{
	char cValue='\0';
	bool bRet=false;
	
	printf("Enter the character ");
	scanf("%c",&cValue);
	
	bRet = ChkSpecial(cValue);
	if(bRet == TRUE)
		{
			printf("It is special Character");
		}
	else
		{
			printf("It is not a special Character");
		}
		
	return 0;
}