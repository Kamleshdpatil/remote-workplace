#include<stdio.h>

void Pattern(int iRow, int iCol)
{
	int i=0, j=0;
	
	for(j=1; j<=iCol; ++j)
	{
		for(i=1; i<=iCol; i++)
		{
			printf(" %d ",j);
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