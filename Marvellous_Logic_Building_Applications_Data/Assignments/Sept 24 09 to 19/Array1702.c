#include<stdio.h>
#include<stdlib.h>
int CheckDiff(int Arr[], int iLength)
{
	int iCnt=0,iRet=0,evens=0, odds=0;
	for(iCnt=0; iCnt<iLength; iCnt++)
	{
		if(Arr[iCnt] % 2==0)
		{
			evens++;
		}
		if(Arr[iCnt] % 2==1)
		{
			odds++;
		}
	}
	iRet=evens-odds;
	return iRet;
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
	iRet=CheckDiff(p,iSize);
	printf("Difference of frequency between Even & Odd numbers is: %d",iRet);
	free(p);
	
	return 0;
}
