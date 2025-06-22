#include<stdio.h>

void Display(char Brr[])
{
	printf("Name Is: %s",Brr);
}

int main()
{
	char Arr[20];
	
	printf("Enter your name: ");
	scanf("%[^'\n']s", Arr);
	
	Display(Arr);
	
	return 0;
}