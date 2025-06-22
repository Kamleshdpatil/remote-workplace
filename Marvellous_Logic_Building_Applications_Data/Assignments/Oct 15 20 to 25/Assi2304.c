#include<stdio.h>
#include<string.h>

void DisplayDigit(char *str)
{
	int iCnt=0;
//    while(str[iCnt]!='\0')
//    {
//    	if((str[iCnt]>='0')&&(str[iCnt]<='9'))
//        {
//            printf("%c",str[iCnt]);
//        }  
//        iCnt++;
//    }
		while(*str!='\0')
    	{
    	if((*str>='0')&&(*str<='9'))
        {
            printf("%c",*str);
        }  
        str++;
    	}
}

int main()
{
char arr[20];

printf("Enter string: ");
scanf("%[^'\n']s",arr);
DisplayDigit(arr);

return 0;
}