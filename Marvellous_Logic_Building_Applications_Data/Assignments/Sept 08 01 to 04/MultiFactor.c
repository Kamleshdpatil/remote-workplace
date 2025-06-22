#include<stdio.h>

int MultiFactor(int iNo){
	int iCnt=0, iFact=1;
	for(iCnt=1; iCnt<iNo; iCnt++){
		if(iNo % iCnt==0){
			printf(" %d * ",iCnt);
			iFact=iFact*iCnt;
		}
	}
	return iFact;
}

int main(){
	int iValue=0;
	int bRet=0;
	printf("Enter Number: ");
	scanf("%d",&iValue);
	
	bRet=MultiFactor(iValue);
	
	printf("\nMultiplication of %d number factors is %d",iValue,bRet);
	return 0;
}