#include<stdio.h>
void strlwrx(char *str)
{
//    int i=0;
//    while(*str!='\0')
//    {
//        if((*str>='A')&&(*str<='Z'))
//        {
//            *str=*str+32;
//        }
//        str++;
//    }
	int iCnt=0;
	for(iCnt;str[iCnt];iCnt++)
	{
		if((str[iCnt] >= 65)&& (str[iCnt]<=90))
		str[iCnt]+=32;
	}
}

int main()
{
char arr[20];

printf("Enter string ");
scanf("%[^'\n']s",arr);

strlwrx(arr);

printf("Modified string is %s",arr);

return 0;
}