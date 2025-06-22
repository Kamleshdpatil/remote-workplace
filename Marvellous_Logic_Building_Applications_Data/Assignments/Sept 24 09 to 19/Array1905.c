#include<stdio.h>
#include<stdlib.h>


void Digits(int Arr[], int iLength)
{
	int iCnt=0, iSum=0, iDigit=0;
	for(iCnt=0; iCnt<iLength; iCnt++)
	{
		iSum=0;
		while(Arr[iCnt] != 0)
		{
		 	iDigit=Arr[iCnt] % 10;
		 	iSum=iSum+iDigit;
		 	Arr[iCnt]=Arr[iCnt]/10;
	 	}
	 	printf("%d\t",iSum);
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
	
	printf("Enter elements: \n");
	for(iCnt=0; iCnt<iSize;iCnt++)
	{
		scanf("%d",&p[iCnt]);
	}
	Digits(p,iSize);
	free(p);
	
	return 0;
}
