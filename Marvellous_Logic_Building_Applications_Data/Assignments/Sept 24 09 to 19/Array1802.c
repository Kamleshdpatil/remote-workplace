#include<stdio.h>
#include<stdlib.h>


int Check(int Arr[], int iLength, int iFind)
{
	int iCnt=0, iRet=0;
	for(iCnt; iCnt<iLength; iCnt++)
	{
		if(iFind==Arr[iCnt])
		{
			iRet=iCnt;
			break;
		}
	}
	return iRet;
}

int main()
{
	int iSize=0,iCnt=0, iFind=0;
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
	printf("Enter find num: ");
	scanf("%d", &iFind);
	
	printf("Enter elements: \n");
	for(iCnt=0; iCnt<iSize;iCnt++)
	{
		scanf("%d",&p[iCnt]);
	}
	iRet=Check(p,iSize,iFind);
	printf("Index of %d in Array is: %d",iFind,iRet);
	
	free(p);
	
	return 0;
}
