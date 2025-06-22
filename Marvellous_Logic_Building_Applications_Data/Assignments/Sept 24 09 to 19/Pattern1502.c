#include<stdio.h>
#include<conio.h>

void Pattern(int iRow, int iCol)
{
	int i=0, j=0,k=0;
	for(i=1; i<=iRow; i++)
	{
		k=iCol;
		for(j=iCol; j>=1; j--)
		{
			iCol=k;
			if(j==i)
				{
					printf("#\t");
				}else
				{
					printf("*\t");
				}
				k--;
		}
//		for(j=iCol-1; j>=1; j--)
//		{
//			printf("#\t");
//		}
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