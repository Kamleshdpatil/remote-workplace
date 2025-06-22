#include<stdio.h>
#include <string.h>

void RevStr(char *str)
{
//	int i=0,len=0;
//	len=strlen(str);
//	
//	for(i=len-1; i>=0;i--)
//	{
//		printf("%c",str[i]);
//	}
//a b c d 
    char *end = str;
    char temp;
    
    while(*end != '\0')
    {
        end++;
    }
    end--;
    
    while(str < end)
    {
        temp = *str;
        *str = *end;
        *end = temp;
        str++;
        end--;
    }
}

int main()
{
char arr[20];
char cValue;

printf("Enter string: ");
scanf("%[^'\n']s",arr);

RevStr(arr);
printf("Modified string is: %s",arr);
return 0;
}