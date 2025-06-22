#include<stdio.h>
#include<stdlib.h>

int Check(int Arr[], int iLength)
{
	int iCnt=0, iRet=0;
	for(iCnt; iCnt<iLength; iCnt++)
	{
		if(Arr[iCnt]==11)
		{
			iRet++;
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
	iRet=Check(p,iSize);
	printf("Frequency of 11 is: %d",iRet);
	
	free(p);
	
	return 0;
}
