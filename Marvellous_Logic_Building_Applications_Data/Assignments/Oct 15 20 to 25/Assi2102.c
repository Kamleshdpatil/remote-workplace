#include<stdio.h>

void ChkAplha(char ch)
{
	if(ch>64)
	{
		ch+=32;
		printf("%c",ch);
	}
	else if(ch>96)
	{
		ch-=32;
		printf("%c",ch);
	}
}


int main()
{
	char cValue='\0';
	
	printf("Enter the character ");
	scanf("%c",&cValue);
	
	ChkAplha(cValue);
	
	return 0;
}