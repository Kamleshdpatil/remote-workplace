//7521

//no=no/10
//digit=no%10
//7521/10=752
//752/10=75
//75/10=7

//digit=7

//no=0 (7/10)
#include<stdio.h>
 
 void Display(int);
 
 int main(){
 	int iValue=0;
 	printf("Enter Number: ");
 	scanf("%d",&iValue);
 	
 	Display(iValue);
 	
 	return 0;
 }
 
 void Display(int iNo)
 {
 	int iCnt =0;
 	int iDigit=0;
 	
 	while(iNo != 0){
 		iDigit= iNo%10;
	 	printf("iDigit is : %d\n",iDigit);
	 	iNo=iNo/10;
	 	//printf("iNo is: %d\n", iNo);
	 	iCnt++;
	 }
	 printf("Total iCnt is : %d",iCnt);
 }


