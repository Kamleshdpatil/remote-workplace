#include<stdio.h>

int main()
{
	int num1=0, num2=0, total=0;
	
	printf("Enter first Number: ");
	scanf("%d", &num1);
	
	printf("Enter second Number: ");
	scanf("%d", &num2);
	
	total=num1 + num2;
	printf("Total is: %d",total);
	
	return 0;
}