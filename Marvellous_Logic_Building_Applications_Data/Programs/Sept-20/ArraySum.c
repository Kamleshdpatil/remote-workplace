#include<stdio.h>
int Addition(int *Brr)
{
	int iCnt=0, iSum=0;
	for(iCnt=0; iCnt<5; iCnt++){
		iSum +=Brr[iCnt];
	}	
	return iSum;
}
int main()
{
	int Arr[5];
	int aRet=0, iCnt=0;
	
	printf("Enter Number: \n");
	for(iCnt=0; iCnt<5; iCnt++)
	{
		scanf("%d", &Arr[iCnt]);
	}
	aRet=Addition(Arr);
	printf("Addition is : %d\n", aRet);
	
	return 0;
}    