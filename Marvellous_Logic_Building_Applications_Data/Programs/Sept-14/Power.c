#include<stdio.h>

int Power(int, int);

int main()
{
	int iBase=0, iPower=0;
	int iPow=0;
	
	printf("Enter Base: "); 
	scanf("%d",&iBase);
	printf("Enter Power: "); 
	scanf("%d",&iPower);
	iPow=Power(iBase,iPower);
	printf("Result is: %d",iPow);
	return 0;
}

int Power(int x, int y){
	int iRet=1, iCnt=0;
	if(x<0){x=-x;}
	if(y<0){y=-y;}
	
	for(iCnt=1; iCnt<=y;iCnt++){
		iRet=iRet * x;
	}
	return iRet;
}