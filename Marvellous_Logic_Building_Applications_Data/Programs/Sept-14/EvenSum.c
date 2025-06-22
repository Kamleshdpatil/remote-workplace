#include<stdio.h>
 
 int EvenSum(int);
 
 int main(){
 	int iValue=0,iRet=0,iSum=0;
 	printf("Enter Number: ");
 	scanf("%d",&iValue);
 	
 	iSum=EvenSum(iValue);
 	printf("Addition of Even Digits is : %d",iSum);
 	return 0;
 }
 
 int EvenSum(int iNo)
 {
 	int iDigit=0, iSum=0;
 	if(iNo<0)
	 { iNo=-iNo;}
 	
 	while(iNo > 0)
	 {
 		iDigit= iNo%10;
 		if((iDigit %2 ) ==0 )
		 {
		 	iSum=iSum+iDigit;
		 }
		 iNo=iNo/10;
		 
	 }
	 return iSum;
 }