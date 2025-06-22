#include<stdio.h>
#include<conio.h>

void Pattern(int iRow, int iCol)
{
	int i=0, j=0;
	for(i=1; i<=iRow; i++)
	{
		for(j=iCol; j>=1; j--)
		{
			if(j==1)
			{
				printf("*\t");
			}
			else if(i==1)
			{
				printf("*\t");
			}
			else if(j==iCol)
			{
				printf("*\t");
			}
			else if(i==iRow)
			{
				printf("*\t");
			}
			else if(i==j)
			{
				printf("*\t");
			}
			else
			{
				printf(" \t");
			}
			
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