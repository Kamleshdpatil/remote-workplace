#include<stdio.h>

void Pattern(int iRow, int iCol)
{
	int i=0, j=0;
	
	for(j=1; j<=iRow; j++)
	{
		for(i=iCol; i>=1;i--){
			printf("%d ",i);
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