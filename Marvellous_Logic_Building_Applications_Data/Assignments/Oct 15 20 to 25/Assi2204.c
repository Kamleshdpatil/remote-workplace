#include<stdio.h>
#include<stdbool.h>
#define TRUE 1
#define FALSE 0

bool ChkVowel(char *str)
{
	bool flag=false;
	while(*str!='\0')
	{
		if(*str=='a' || *str=='e' || *str=='i' || *str=='o'|| *str=='u' || *str=='A' || *str=='E' || *str=='I' || *str=='O'|| *str=='U')
		{
			flag=true;
			break;
		} 
		else
		{
			flag=false;
		}
		str++;
	}
	return flag;
}

int main()
{
	char arr[20];
	bool bRet=false;
	
	printf("Enter String: ");
	scanf("%[^'\n']s",arr);
	
	bRet = ChkVowel(arr);
	if(bRet == TRUE)
	{
		printf("Contains Vowel");
	}
	else
	{
		printf("There is no Vowel");
	}
return 0;
}