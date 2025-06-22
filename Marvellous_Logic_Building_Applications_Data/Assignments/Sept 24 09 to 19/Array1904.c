#include<stdio.h>
#include<stdlib.h>


void Digits(int Arr[], int iLength)
{
	int iCnt=0, iTemp=0, count=0;
	for(iCnt=0; iCnt<iLength; iCnt++)
	{
		iTemp=Arr[iCnt];
		count=0;
		while(Arr[iCnt] != 0)
		{
		 	Arr[iCnt]=Arr[iCnt]/10; 
		 	++count; 
	 	}
		if(count==3)
		 {
			printf("%d\t",iTemp);
		 }
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
