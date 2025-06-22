#include<stdio.h>
#include<conio.h>

void Pattern(int iRow, int iCol)
{
	int i=0, j=0;
	for(i=iRow; i>=1; i--)
	{
		for(j=i; j>=1; j--)
		{
			printf("*\t");
		}
	printf("\n");
	}
}

int main()

{
	int iRow=0, iCol=0;
	printf("Enter Row: ");
	scanf("%d", &iRow);
	printf("Enter Column: ");
	scanf("%d", &iCol);
	
	Pattern(iRow, iCol);
	
	return 0;
}