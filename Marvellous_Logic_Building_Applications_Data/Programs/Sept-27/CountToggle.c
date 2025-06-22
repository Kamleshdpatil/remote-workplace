#include<stdio.h>
#include<stdbool.h>

void CountSmall(char *ch)
{
	int sCnt=0, cCnt=0;
	while(*ch!='\0')
	{
		if((*ch >='A') && (*ch <='Z'))
			cCnt++;
		if((*ch >='a') && (*ch <='z'))
			sCnt++;
		ch++;
	}
	printf("Count of Small letters is: %d\n",sCnt);
	printf("Count of Capital letters is: %d",cCnt);
}

int main()
{
	char ch[20];
	
	printf("Enter String: ");
	scanf("%[^'\n']s", &ch);
	CountSmall(ch);
	return 0;
}