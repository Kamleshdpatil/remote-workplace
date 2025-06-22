#include<stdio.h>
#include<conio.h>

void Pattern(int iRow, int iCol)
{
	int i=0, j=0;
	for(i=1; i<=iRow; i++)
	{
		for(j=iCol; j>=1; j--)
		{
			if(j==i)
				{
					printf("#\t");
				}else
				{
					printf("*\t");
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