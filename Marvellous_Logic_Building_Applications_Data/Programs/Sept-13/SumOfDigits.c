#include<stdio.h>
 
 int Display(int);
 
 int main()
 {
 	int iValue=0;
 	int bRet=0, iCnt=0;
 	printf("Enter Number: ");
 	scanf("%d",&iValue);
 	
 	iCnt=Display(iValue);
 	//printf("Total sum of all digits is: %d",bRet);
 	printf("Total Count of all digits is: %d",iCnt);
 	
 	return 0;
 }
 
 int Display(int iNo)
 {
 	int iCnt =0,iSum=0;
 	int iDigit=0;
 	if(iNo==0){
 		return 1;
	 }
 	if(iNo<0){
 		iNo=-iNo;
	 }
 	
 	while(iNo != 0){
 		iDigit= iNo%10;
	 	//printf("iDigit is : %d\n",iDigit);
	 	iNo=iNo/10;
	 	//printf("iNo is: %d\n", iNo);
	 	iSum=iSum + iDigit;
	 	//printf("Total sum of all digits is: %d",iSum);
	 	iCnt++;
	 	
	 }
	 return iCnt; //Return value
 }


