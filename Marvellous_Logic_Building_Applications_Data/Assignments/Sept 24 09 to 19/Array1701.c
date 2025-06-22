#include<stdio.h>
#include<stdlib.h>
int CheckEven(int Arr[], int iLength)
{
	int iCnt=0,iRet=0,evens=0;
	for(iCnt=0; iCnt<iLength; iCnt++)
	{
		if(Arr[iCnt] % 2==0)
		{
			evens++;
		}
	}
	return evens;
}

int main()
{
	int iSize=0,iCnt=0, iRet=0;
	int *p=NULL;
	
	printf("Enter Array size: ");
	scanf("%d", &iSize);
	p=(int *)malloc(iSize * sizeof(int));
	if(p==NULL)
	{
		printf("Unable to allocate memory");
		return -1;
	}
	printf("Enter elements: \n");
	for(iCnt=0; iCnt<iSize;iCnt++)
	{
		scanf("%d",&p[iCnt]);
	}
	iRet=CheckEven(p,iSize);
	printf("Count of Even number is: %d",iRet);
	free(p);
	
	return 0;
}
