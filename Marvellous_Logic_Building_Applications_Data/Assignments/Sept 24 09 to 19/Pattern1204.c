#include<stdio.h>
#include<conio.h>

void Pattern(int iRow, int iCol)
{
	int i=0, j=0;
	for(i=1; i<=iRow; i++) //outer
	{
		for(j=1; j<=iCol; j++) //inner
		{
			if(i==1){
			printf("  %2*  ");
			}
			else if(i==iRow)
			{
				printf("  %2*  ");
			}
			else if(j==1){
				printf("  %2*  ");
			}
			else if(j==iCol){
				printf("  %2*  ");
			}else
				printf("  %2@  ");
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