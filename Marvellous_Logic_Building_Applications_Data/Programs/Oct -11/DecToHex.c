#include<stdio.h>

int main()
{
	int iValue=0;
	
	printf("Enter Number ");
	scanf("%d",&iValue);
	
	printf("Decimal format is %d\n",iValue);
	printf("Octal format is %o\n",iValue);
	printf("Hexadecimal format is %x\n",iValue);
	
	return 0;
	
}