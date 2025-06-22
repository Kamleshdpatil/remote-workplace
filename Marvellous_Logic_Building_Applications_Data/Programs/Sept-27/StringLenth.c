#include<stdio.h>

int Display(char *Brr)
{
	int i=0;
	while(*Brr!='\0')
	{
		printf("%c\n", *Brr);
		Brr++;
		i++;
	}
	return i;
}

int main()
{
	char Arr[10];
	int Count;
//	int n=0;
//	printf("Enter String Size: ");
//	scanf("%d",&n);
//	Arr[n];
	
	printf("Enter your name: ");
	scanf("%[^'\n']s", Arr);
	
	Count=Display(Arr);
	printf("Size of String is: %d", Count);
	return 0;
}