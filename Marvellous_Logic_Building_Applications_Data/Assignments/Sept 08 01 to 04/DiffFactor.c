#include<STDIO.H>

int MultiFactor(int iNo){
	int iCnt=1,iSum=0,iFact=0;
	for(iCnt; iCnt<iNo; iCnt++){
		if(iNo % iCnt ==0)
			iFact=iFact+iCnt;
		else if(iNo % iCnt !=0)
			iSum=iSum+iCnt;
	}
	iSum=iFact-iSum;
	return iSum;
}

int main(){
	int iValue=0, bRet=0;
	printf("Enter Number: ");
	scanf("%d",&iValue);
	
	bRet=MultiFactor(iValue);
	printf("Difference betweentwo factors is %d",bRet);
	return 0;
}