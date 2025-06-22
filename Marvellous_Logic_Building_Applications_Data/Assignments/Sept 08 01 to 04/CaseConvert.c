#include<stdio.h>

void DisplayConvert ( char CValue)
{
	if(CValue >='a' && CValue <='z')
	{	
		CValue=CValue-32;
		printf("%c",CValue);
	}
		else
	{
		printf("Already Capital..!!\n");
		printf("%c" ,CValue );
	}
}
int main()
{
	char cValue ='\0';
	printf("Enter character: ");
	scanf("%c",&cValue);
	DisplayConvert(cValue );
	return 0;
}