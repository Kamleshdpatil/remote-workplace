#include<stdio.h>
#include<stdlib.h>


int Product(int Arr[], int iLength)
{
	int iCnt=0, iRet=1;
	for(iCnt; iCnt<iLength; iCnt++)
	{
		if(Arr[iCnt]%2==1)
		{
			iRet=iRet * Arr[iCnt];
		}
	}
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
	iRet=Product(p,iSize);
	printf("Product of odd elements: %d",iRet);
	free(p);
	
	return 0;
}
