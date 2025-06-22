#include<stdio.h>

void DisplayFactors(int);

int main()
{
	int iNo;
	printf("Enter number: ");
	scanf("%d", &iNo);
	DisplayFactors(iNo);
	
	return 0;
}

void DisplayFactors(int iValue){
	int iCnt=0;
	if(iValue<0){
		iValue=-iValue;
	}
	for(iCnt=1; iCnt<iValue; iCnt++){
		if((iValue % iCnt) ==0){
			if(iCnt %2 ==0) // only even factors
				printf("%d\t", iCnt);
		}
	}
}
