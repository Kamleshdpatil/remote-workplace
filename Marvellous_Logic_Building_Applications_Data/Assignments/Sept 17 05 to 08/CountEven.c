#include<stdio.h>

int CountTwo(int);

int main()
{
	int iValue=0, iRet=0;
	printf("Enter Number: ");
	scanf("%d", &iValue);
	
	iRet=CountTwo(iValue);
	printf("Count of Even digits is: %d",iRet);
	
	return 0;	
}

int CountTwo(int iNo)
{
	int iCnt=0, iDigit=0;
	while(iNo!=0){
	iDigit=iNo % 10;
	if(iDigit%2==0){
		iCnt+=1;
	}
	iNo=iNo/10;
	}
	return iCnt;
}