#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

 int CheckNumber(int Brr[], int iSize, int iNo)
 {
 	int i=0;
 	//    1       2      3
 	for(i=0; i < iSize; i++)
 	{
 		if(Brr[i] ==iNo) //4
 		{ break;}
		if(i==iSize)
		{
			return -1;
		} else
		{
			return i;
		}
	 }
	 return i;
 }
 
 int main()
 {
 	int iLength=0, iValue=0, i=0;
 	int *ptr =NULL, iRet=0;
 	
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
	iRet= CheckNumber(ptr,iLength,iValue);
	if(iRet == -1)
	{
		printf("Number is not there..!!");
	}
	else
	{
		printf("Number index: %d",iRet);
	}
 	free(ptr);
 	return 0;
 } 