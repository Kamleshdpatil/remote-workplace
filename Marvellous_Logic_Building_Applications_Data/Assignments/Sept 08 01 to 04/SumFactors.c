#include<stdio.h>

int MultiFactor(int iNo){
	int iCnt=1,iSum=0;
	for(iCnt; iCnt<iNo; iCnt++){
		if(iNo % iCnt !=0)
			iSum=iSum+iCnt;
	}
	return iSum;
}

int main(){
	int iValue=0, bRet=0;
	printf("Enter Number: ");
	scanf("%d",&iValue);
	
	bRet=MultiFactor(iValue);
	printf("Sum of %d\'s Factors is %d",iValue,bRet);
	return 0;
}