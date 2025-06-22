#include<stdio.h>
#include<stdlib.h>
int Diffrence(int Arr[], int iLength)
{
	int iCnt=0,iRet=0, iOdd=0, iEven=0,iSumE=0,iSumO=0;
	for(iCnt=0; iCnt<iLength; iCnt++)
	{
		if(Arr[iCnt] % 2==0)
		{
			iEven=Arr[iCnt];
			iSumE=iSumE+iEven;
		}else
		{
			iOdd=Arr[iCnt];
			iSumO=iSumO+Arr[iCnt];
		}
	}
	iRet=iSumE-iSumO;
	return iRet;
}

int main()
{
	int iSize=0, iRet=0, iCnt=0;
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
	printf("Print elements: ");
	for(iCnt=0; iCnt<iSize;iCnt++)
	{
		printf("%d\t",p[iCnt]);
	}
	iRet=Diffrence(p,iSize);
	printf("\nResult is %d",iRet);
	free(p);
	
	return 0;
}
