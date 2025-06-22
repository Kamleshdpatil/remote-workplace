#include<stdio.h>

void DisplayTable(int);

int main()
{
	int iValue=0;
	
	printf("Enter Number: "); //28
	scanf("%d",&iValue);
	DisplayTable(iValue);
	
	return 0;
}

void DisplayTable(int iNo){
	int iTab=0, iCnt=0;
	if(iNo<0){iNo=-iNo;}
	if(iNo==0){return ;}
	iTab=iNo;
	for(iCnt=1; iCnt<=10; iCnt++){
		iNo=iTab * iCnt;
		printf("%d\n",iNo);
	}
}