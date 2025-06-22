#include<stdio.h>
 
 int CountEven(int);
 
 int main(){
 	int iValue=0,iRet=0;
 	printf("Enter Number: ");
 	scanf("%d",&iValue);
 	
 	iRet=CountEven(iValue);
 	printf("Total iCnt is : %d",iRet);
 	return 0;
 }
 
 int CountEven(int iNo)
 {
 	int iCnt =0;
 	int iDigit=0;
 	if(iNo<0)
	 { iNo=-iNo;}
	if(iNo==0)
	 { return 1; }
 	
 	while(iNo > 0)
	 {
 		iDigit= iNo%10;
 		if((iDigit%2)==0)
		 {
		 	iCnt++; //iCnt will count only even digit
		 }
		iNo=iNo/10;
	 }
	 return iCnt;
 }