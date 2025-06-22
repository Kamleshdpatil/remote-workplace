#include<conio.h>
#include<stdio.h>

int Sum(int);

int main(){
	int iValue=0, iRet=0;
	printf("Enter Number: ");
	scanf("%d",&iValue);
	iRet=Sum(iValue);
	printf("\n Addition is: %d",iRet);
	return 0;	
}

int Sum(int iNo)
{
	int iSum=0, iCnt=0;
	for(iCnt=1; iCnt<=iNo; iCnt++)
		iSum += iCnt;
	return iSum;
}