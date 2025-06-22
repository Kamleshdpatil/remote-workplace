#include<stdio.h>

int CountDiff(int);

int main()
{
	int iValue=0, iRet=0;
	printf("Enter Number: ");
	scanf("%d", &iValue);
	
	iRet=CountDiff(iValue);
	printf("Count of Diffrence between even and odd is: %d",iRet);
	
	return 0;	
}

int CountDiff(int iNo)
{
	int iCnt=0, iDigit=0,iEven=0, iOdd=0, iDiff=0;
	while(iNo!=0){
	iDigit=iNo % 10;
	if(iDigit%2==0){
		iEven=iEven+iDigit;
	}
	if(iDigit%2!=0){
		iOdd=iOdd+iDigit;
	}
	iNo=iNo/10;
	}
	iDiff=iEven-iOdd;
	return iDiff;
}