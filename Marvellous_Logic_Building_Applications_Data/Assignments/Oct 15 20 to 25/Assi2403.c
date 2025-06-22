#include<stdio.h>

int FirstChar(char *str, char ch)
{
	int iCnt=0, flag=0;
	while(str[iCnt]!='\0')
    {
	    if(ch==str[iCnt])
	    {
	        flag=iCnt;
	        break;
	    }
	    else
		{return -1;}
		iCnt++;
		  
    }str++;
    return iCnt;
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
iRet = FirstChar(arr, cValue);

printf("First Occurance: %d",iRet);

return 0;
}
