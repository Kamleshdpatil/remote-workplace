#include<stdio.h>

void DisplayTable()
{
	int i=0;
	printf("***********************ASCII TABLE***********************\n");
	printf("Decimal characters: \n");
	
	for(i=0; i<=127; i++)
	{
		printf("%d\t%x\t%o\t%c\n",i,i,i,i);
	}
}

int main()
{
	DisplayTable();
	return 0;
}