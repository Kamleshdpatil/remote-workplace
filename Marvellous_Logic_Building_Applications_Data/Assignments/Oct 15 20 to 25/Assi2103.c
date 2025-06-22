#include<stdio.h>

void Display(char ch)
{
	if(ch>64 && ch<91)
	{
		while(ch==90)
		{
			printf("%c\t",ch);
			ch++;
		}
	}
	else if(ch>96 && ch<123)
	{
		while(ch==97)
		{
			printf("%c\t",ch);
			ch--;
		}
	}
}


int main()
{
	char cValue='\0';
	
	printf("Enter the character ");
	scanf("%c",&cValue);
	
	Display(cValue);
	
	return 0;
}