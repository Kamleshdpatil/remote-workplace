#include<stdio.h>
#include<stdlib.h>


void Display(int Arr[], int iLength, int iStart, int iEnd)
{
	int iCnt=0, iRet=0;
	for(iCnt; iCnt<iLength; iCnt++)
	{
		if(Arr[iCnt]>=iStart && Arr[iCnt]<=iEnd)
		{
			printf("%d\t",Arr[iCnt]);
		}
	}
}

int main()
{
	int iSize=0,iCnt=0, iStart=0, iEnd=0;
	int *p=NULL;
	int iRet=0;
	
	printf("Enter Array size: ");
	scanf("%d", &iSize);
	p=(int *)malloc(iSize * sizeof(int));
	if(p==NULL)
	{
		printf("Unable to allocate memory");
		return -1;
	}
	printf("Enter Start range: ");
	scanf("%d", &iStart);
	printf("Enter End range: ");
	scanf("%d", &iEnd);
	
	printf("Enter elements: \n");
	for(iCnt=0; iCnt<iSize;iCnt++)
	{
		scanf("%d",&p[iCnt]);
	}
	printf("Result \n");
	Display(p,iSize,iStart, iEnd);
	
	free(p);
	
	return 0;
}
