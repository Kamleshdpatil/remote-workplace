#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define TRUE 1
#define FALSE 0

void Display(char *str)
{
	int i=0,len=0;
	len=strlen(str);
	
	for(i=len-1; i>=0;i--)
	{
		printf("%c",str[i]);
	}
}

int main()
{
	char arr[20];
	
	printf("Enter String: ");
	scanf("%[^'\n']s",arr);
	
	Display(arr);
	
	return 0;
}