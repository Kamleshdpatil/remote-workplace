#include<stdio.h>

int MultDigit(int);

int main()
{
	int iValue=0, iRet=0;
	printf("Enter Number: ");
	scanf("%d", &iValue);
	
	iRet=MultDigit(iValue);
	printf("Multiplication of digits is: %d",iRet);
	
	return 0;	
}

int MultDigit(int iNo)
{
	int iMult=1, iDigit=0;
	if(iNo<0){
		iNo=-iNo;
	}
	while(iNo!=0){
	iDigit=iNo % 10;
	if(iDigit==0){
		iDigit=1;
	}
	iMult=iMult * iDigit; 
	iNo=iNo/10;
	}
	return iMult;
}