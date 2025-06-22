#include<stdio.h>

void Display(char ch)
{
	printf("%d\t%o\t%x\t",ch);
}


int main()
{
	char cValue='\0';
	
	printf("Enter the character ");
	scanf("%c",&cValue);
	
	Display(cValue);
	
	return 0;
}