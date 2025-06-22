#include<stdio.h>

#define TRUE 1
#define FALSE 0

typedef int BOOL;
BOOL ChckZero(int);

int main()
{
	int iValue=0, bRet=FALSE;
	printf("Enter Number: ");
	scanf("%d", &iValue);
	
	bRet=ChckZero(iValue);
	if(bRet==TRUE){
		printf("It Contains Zero\n");
	} else{
		printf("There is no Zero\n");
	}
	return 0;	
}

BOOL ChckZero(int iNo){
	int iDigit=0;
	
	while(iNo!=0){
		iDigit=iNo%10;
		//printf("%d\n",iDigit);
		if(iDigit==0){
			return 1;
		}
		 iNo=iNo/10;
		 //printf("%d\n",iNo);
	}
	if(iDigit!=0)
		{
			return 0;
		}
	
}