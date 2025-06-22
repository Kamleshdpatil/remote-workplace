#include<stdio.h>

void Pattern(int iRow, int iCol)
{
	int i=0, j=0, num=1;
	
	for(j=iRow; j>=1; --j)
	{
		for(i=1; i<=iCol; i++)
		{
			printf("  %2d  ",num);
			num++;
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