#include<stdio.h>
#include<stdbool.h>

int CountSpace(char *ch)
{
	int iCnt=0;
	while(*ch!='\0')
	{
		if(*ch ==' ')
			iCnt++;
		ch++;
	}
	return iCnt;	
}

int main()
{
	char ch[20];
	int Count=0;
	
	printf("Enter String: ");
	scanf("%[^'\n']s", &ch);
	Count=CountSpace(ch);
	printf("Count of spaces is: %d",Count);
	return 0;
}