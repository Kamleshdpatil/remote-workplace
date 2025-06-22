#include<stdio.h>

void Display(char *Brr)
{
	int i=0;
	while(*Brr!='\0')
	{
		printf("%c\n", *Brr);
		Brr++;
	}
	
}

int main()
{
	char Arr[10];
//	int n=0;
//	printf("Enter String Size: ");
//	scanf("%d",&n);
//	Arr[n];
	
	printf("Enter your name: ");
	scanf("%[^'\n']s", Arr);
	
	Display(Arr);
	
	return 0;
}