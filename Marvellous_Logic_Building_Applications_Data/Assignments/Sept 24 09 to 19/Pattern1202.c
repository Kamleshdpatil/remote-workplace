#include<stdio.h>
#include<conio.h>

void Pattern(int iRow, int iCol)
{
	int i=0, j=0;
	
	for(j=1; j<=iRow; j++)
	{
		for(i=iRow; i>=j; i--)
		{
			printf("  *  ");
		}
		for(i=2; i<=j;i++)
		{
			printf("  #  ");
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