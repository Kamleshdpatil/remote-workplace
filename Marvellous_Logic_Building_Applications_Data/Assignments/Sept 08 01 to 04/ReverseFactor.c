#include<stdio.h>

void MultiFactor(int iNo){
	int iCnt=1;
	for(iCnt=iNo-1; iCnt>0; iCnt--){
		if(iNo % iCnt==0){
			printf(" %d ",iCnt);
		}
	}
}

int main(){
	int iValue=0;
	printf("Enter Number: ");
	scanf("%d",&iValue);
	
	MultiFactor(iValue);
	
	return 0;
}