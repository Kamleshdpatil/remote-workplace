#include<stdio.h>
#include <string.h>

void StrCpyX(char *src, char *dest, int iRange)
{
	while((*src != '\0') && (iRange!=0))
	{
		*dest = *src;
		src++;
		dest++;
		iRange--;
	
	}*dest ='\0';
}
int main()
{
char arr[30] = "Marvellous Multi OS";
char brr[30]; // Empty string
int iRange=0;
printf("Enter range: ");
scanf("%d", &iRange);
StrCpyX(arr,brr, iRange);
printf("Copied String is : %s",brr); // Marvellous Multi OS
return 0;
}