#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

 bool CheckNumber(int Brr[], int iSize, int iNo)
 {
 	int i=0;
 	bool bAns=false;
 	for(i=0; i < iSize; i++)
 	{
 		if(Brr[i] ==iNo)
 		{
 			bAns=true;
 			break;
		 }
	 }
	 return bAns;
 }
 
 int main()
 {
 	int iLength=0, iValue=0, i=0;
 	int *ptr =NULL;
 	bool bRet=false;
 	
 	printf("Enter Number of Elements: ");
 	scanf("%d", &iLength);
 	
 	ptr= (int *)malloc(sizeof(int) *iLength);
 	printf("Enter %d Elements: \n", iLength);
 	for(i=0; i< iLength; i++)
 	{
 		scanf("%d", &ptr[i]);
	}
	printf("Enter number for find:  ");
	scanf("%d", &iValue);
	int k=0;
	for(k=1;i<=iLength; k++)
	{
		bRet= CheckNumber(ptr,iLength,iValue);
	}
	
	if(bRet==true)
	{
		printf("Number is there..!!");
	}
	else{
		printf("Number is not there..!!");
	}
 	free(ptr);
 	return 0;
 } 