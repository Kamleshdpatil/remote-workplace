#include<stdio.h>
#include<stdlib.h>


int checkDiff(int Arr[], int iLength)
{
	int iCnt=0, iRet=0, iBig=0 ,iSmall=Arr[0];
	for(iCnt; iCnt<iLength; iCnt++)
	{
		if(Arr[iCnt]< iSmall)
		{
			iSmall=Arr[iCnt];
		}
		if(Arr[iCnt] > iBig)
		{
			iBig=Arr[iCnt];
		}
	}
	iRet=iBig-iSmall;
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
	printf("Result \n");
	iRet=checkDiff(p,iSize);
	printf("Diffrenece between small and largest is: %d",iRet);
	free(p);
	
	return 0;
}
