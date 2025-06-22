#include<stdio.h>

int LastChar(char *str, char ch)
{
	int iCnt=0, flag=-1;
	while(str[iCnt]!='\0')
    {
	    if(str[iCnt]==ch)
	    {
	        flag=iCnt;
	    }
		iCnt++;
		  
    }str++;
    return flag;
}

int main()
{
char arr[20];
char cValue;
int iRet = 0;

printf("Enter string: ");
scanf("%[^'\n']s",arr);
printf("Enter the character: ");
scanf(" %c",&cValue);
iRet = LastChar(arr, cValue);

printf("Last Occurance: %d",iRet);

return 0;
}
