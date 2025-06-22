#include<stdio.h>
#include<stdlib.h>
void Display(int Arr[], int iLength)
{
	int iCnt=0,iRet=0;
	for(iCnt=0; iCnt<iLength; iCnt++)
	{
		if(Arr[iCnt] % 5==0)
		{
			printf("Output: %d\t", Arr[iCnt]);
		}
	}
	
}

int main()
{
	int iSize=0,iCnt=0;
	int *p=NULL;
	
	printf("Enter Array size: ");
	scanf("%d", &iSize);
	p=(int *)malloc(iSize * sizeof(int));
	if(p==NULL)
	{
		printf("Unable to allocate memory");
		return -1;
	}
	printf("Enter elements: ");
	for(iCnt=0; iCnt<iSize;iCnt++)
	{
		scanf("%d",&p[iCnt]);
	}
	Display(p,iSize);
	
	free(p);
	
	return 0;
}
