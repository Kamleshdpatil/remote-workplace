#include<stdio.h>
#include<stdbool.h>
 
 bool ChkPalindrom(int);
 
 int main()
 {
 	int iValue=0;
	bool bRet=false;
	 
 	printf("Enter Number: ");
 	scanf("%d",&iValue);
 	
 	bRet=ChkPalindrom(iValue);
 	if(bRet==true)
	 {
 		printf("Number is Palindrome");
 	 } else{
 	 	printf("Number is not Palindrome ");
	  }
 	 
 	return 0;
 }
 
 bool ChkPalindrom(int iNo)
 {
 	int iCnt =0, iRev=0, iDigit=0;
 	int iTemp=iNo;
 	
 	while(iNo != 0)
	 {
 		iDigit= iNo%10;
 		iRev =(iRev * 10) + iDigit;
	 	iNo=iNo/10;
	 }
	 if(iRev == iTemp)
		 {
		 	return true;
		 } 
	 else
		 {
		 	return false;
		 }
 }


