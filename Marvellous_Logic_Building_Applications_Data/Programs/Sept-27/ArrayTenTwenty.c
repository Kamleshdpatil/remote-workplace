//count ten to twenty

#include<stdio.h>
#include<stdlib.h>

 int CountTen(int Brr[], int iSize)
 {
 	int iCnt=0, i=0, iSum=0;
	float fResult=0.0f; 	
	
	for(i=0;i<iSize; i++)
	{
		if((Brr[i] >10) && (Brr[i] <20)
		{
			iCnt++;
		}
	}
	return iCnt;
 }
 
 int main()
 {
 	int iLength=0, i=0;
 	int *ptr =NULL;
 	int iRet=0;
 	
 	printf("Enter Number of Elements: ");
 	scanf("%d", &iLength);
 	
 	ptr= (int *)malloc(sizeof(int) *iLength);
 	printf("Enter %d Elements: \n", iLength);
 	for(i=0; i< iLength; i++)
 	{
 		scanf("%d", &ptr[i]);
	}
	printf("Entered Data is: \n");
	for(i=0; i< iLength; i++)
 	{
 		printf("%d\t", ptr[i]);
	}
	iRet= CountTen(ptr,iLength);
	printf("\n Count of greater than ten is: %d\n", iRet);
	
 	free(ptr);
 	return 0;
 }