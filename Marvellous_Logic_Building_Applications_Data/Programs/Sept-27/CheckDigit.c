#include<stdio.h>
#include<stdbool.h>

bool ckeckLetter(char ch)
{
	if((ch >='0') && (ch<='9'))
		return true;
	else
		return false;
}

int main()
{
	char ch ='\0';
	bool bRet=false;
	printf("Enter character: ");
	scanf("%c", &ch);
	bRet=ckeckLetter(ch);
	
	if(bRet==true)
		printf("It is digit..\n");
	else
		printf("It is not digit..\n");
	return 0;
}