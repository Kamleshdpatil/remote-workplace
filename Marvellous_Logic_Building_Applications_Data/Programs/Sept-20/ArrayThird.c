#include<stdio.h>

int Addition(int *Brr, int iSize)
{
	int iCnt=0, iSum=0;
	for(iCnt=0; iCnt<iSize; iCnt++){
		iSum =iSum + (*Brr);
		Brr++;
	}	
	return iSum;
}
int main()
{
	int aRet=0, iCnt=0, n=0;
	
	printf("Enter Array Size: ");
	scanf("%d",&n);
	int Arr[n];
	
	printf("Enter %d Numbers: \n", n);
	for(iCnt=0; iCnt<n; iCnt++)
	{
		scanf("%d", &Arr[iCnt]);
	}
	aRet=Addition(Arr,n);
	printf("Addition is : %d\n", aRet);
	
	return 0;
}    