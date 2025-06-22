#include<stdio.h>
#include <string.h>

void StrCatX(char *src, char *dest)
{
	while(*src != '\0')
	{
		src++;
	}
	while(*dest != '\0')
	{
		*src = *dest;
		dest++;
		src++;
	}
	*src ='\0';
}
int main()
{
char arr[30] = "Marvellous Infosystems";
char brr[30]= " Logic Building";
StrCatX(arr,brr);
printf("Copied String is : %s",arr); // Marvellous Multi OS
return 0;
}