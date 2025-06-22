#include<stdio.h>
#include<stdbool.h>

#define TRUE 1
#define FALSE 0

bool ChkChar(char *str, char ch)
{
	bool flag=false;
	while(*str!='\0')
    {
	    if(*str==ch)
	    {
	        flag=true;
	        break;
	    }  
    str++;
    }
    return flag;
}

int main()
{
char arr[20];
char cValue;
bool bRet = FALSE;

printf("Enter string: ");
scanf("%[^'\n']s",arr);
printf("Enter the character: ");
scanf(" %c",&cValue);
bRet = ChkChar(arr, cValue);
	if(bRet == TRUE)
	{
		printf("\nCharacter found");
	}
	else
	{
	 	printf("\nCharacter not found");
	}
	
return 0;
}
