#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define TRUE 1
#define FALSE 0

bool Check(int Arr[], int iLength, int iFind)
{
	int iCnt=0;
	for(iCnt; iCnt<iLength; iCnt++)
	{
		if(Arr[iCnt]==iFind)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	int iSize=0,iCnt=0, iFind=0;
	int *p=NULL;
	bool bRet=false;
	
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
	bRet=Check(p,iSize,iFind);
	
	if(bRet==true)
	{printf("%d is present",iFind);}
	else
	{printf("%d is absent",iFind);}
	
	free(p);
	
	return 0;
}
