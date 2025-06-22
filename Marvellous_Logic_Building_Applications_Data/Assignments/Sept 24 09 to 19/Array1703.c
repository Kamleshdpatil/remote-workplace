#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define TRUE 1
#define FALSE 0

bool Check(int Arr[], int iLength)
{
	int iCnt=0;
	for(iCnt; iCnt<iLength; iCnt++)
	{
		if(Arr[iCnt]==11)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	int iSize=0,iCnt=0;
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
	printf("Enter elements: \n");
	for(iCnt=0; iCnt<iSize;iCnt++)
	{
		scanf("%d",&p[iCnt]);
	}
	bRet=Check(p,iSize);
	
	if(bRet==true)
	{printf("11 is present");}
	else
	{printf("11 is absent");}
	
	free(p);
	
	return 0;
}
