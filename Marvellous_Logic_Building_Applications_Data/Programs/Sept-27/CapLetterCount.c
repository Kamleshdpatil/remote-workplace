#include<stdio.h>
#include<stdbool.h>

int CountSmall(char *ch)
{
	int iCnt=0;
	while(*ch!='\0')
	{
		if((*ch >='A') && (*ch <='Z'))
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
	Count=CountSmall(ch);
	printf("Count of Capital is: %d",Count);
	return 0;
}