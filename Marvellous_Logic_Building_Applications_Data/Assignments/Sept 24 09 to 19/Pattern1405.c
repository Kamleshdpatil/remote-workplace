#include<stdio.h>
#include<conio.h>

void Pattern(int iRow, int iCol)
{
	int i=0, j=0, k=1;
	for(i=1; i<=iRow; i++)
	{
		for(j=2; j<=i; j++){
			printf("\t");
		}
		for(j=2; j<=iCol+1; j++){
			printf("%d\t",k);
		}
		iCol--;
		
		printf("\n");
		k++;
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