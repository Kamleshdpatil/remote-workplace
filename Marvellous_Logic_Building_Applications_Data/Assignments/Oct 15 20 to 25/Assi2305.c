#include<stdio.h>
#include<string.h>

int DisplayDigit(char *str)
{
	int iCnt=0;
	while(*str!='\0')
    {
    if(*str==' ')
    {
        iCnt++;
    }  
    str++;
    }
    return iCnt;
}

int main()
{
char arr[20];
int iRet=0;

printf("Enter string: ");
scanf("%[^'\n']s",arr);
iRet=DisplayDigit(arr);

printf("Space count are: %d",iRet);

return 0;
}