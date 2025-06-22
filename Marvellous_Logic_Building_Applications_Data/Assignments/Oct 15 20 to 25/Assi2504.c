#include<stdio.h>
#include <string.h>

void StrCpyX(char *src, char *dest)
{
	while(*src != '\0')
	{
		if((*src>='a') && (*src<='z'))
		{
			*dest = *src;
			dest++;
		}
		src++;
	}*dest ='\0';
}
int main()
{
char arr[30] = "Marvellous Multi OS";
char brr[30]; // Empty string
StrCpyX(arr,brr);
printf("\nCopied String is : %s",brr); // Marvellous Multi OS
return 0;
}