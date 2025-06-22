#include<stdio.h>
#include<stdbool.h>

bool ckeckLetter(char ch)
{
	if((ch >='A') && (ch<='Z'))
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
		printf("It is Capital Letter..\n");
	else
		printf("It is not Capital..\n");
	return 0;
}