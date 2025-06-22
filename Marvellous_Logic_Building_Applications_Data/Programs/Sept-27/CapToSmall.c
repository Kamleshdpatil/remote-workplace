#include<stdio.h>
#include<stdbool.h>

char SmallToCap(char ch)
{
	if((ch >='A') && (ch<='Z'))
		return ch+32;
}

int main()
{
	char ch ='\0';
	char cRet=false;
	printf("Enter character: ");
	scanf("%c", &ch);
	cRet=SmallToCap(ch);
	printf("Capital letter is: \n%c",cRet);
	return 0;
}