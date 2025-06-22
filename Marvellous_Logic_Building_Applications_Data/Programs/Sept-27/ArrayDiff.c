

#include<stdio.h>
#include<stdlib.h>

 int Minimum(int Brr[], int iSize)
 {
 	int i=0,iDiff=0, iMin=Brr[0], iMax=Brr[0];
	float fResult=0.0f; 	
	
	for(i=0;i<iSize; i++)
	{
		if(Brr[i] < iMin)
		{
			iMin=Brr[i];	
		}
		if(Brr[i] > iMax)
		{
			iMax=Brr[i];	
		}	
	}
	iDiff =iMax-iMin;
	return iDiff;
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
	iRet= Minimum(ptr,iLength);
	printf("\n Difference between Max & Min is: %d\n", iRet);
	
 	free(ptr);
 	return 0;
 } 