// count average of elements from array
#include <stdio.h>
#include <stdlib.h>

int Avg(int Brr[], int iSize)
{
	int iSum = 0, i = 0;
	float fResult = 0.0f;

	for (i = 0; i < iSize; i++)
	{
		iSum = iSum + Brr[i];
	}
	fResult = (float)iSum / (float)iSize; // explicite typecasting
	return (float)fResult;
}

int main()
{
	int iLength = 0, i = 0;
	int *ptr = NULL;
	float fRet = 0.0f;

	printf("Enter Number of Elements: ");
	scanf("%d", &iLength);

	ptr = (int *)malloc(sizeof(int) * iLength);
	printf("Enter %d Elements: \n", iLength);
	for (i = 0; i < iLength; i++)
	{
		scanf("%d", &ptr[i]);
	}
	printf("Entered Data is: \n");
	for (i = 0; i < iLength; i++)
	{
		printf("%d\t", ptr[i]);
	}
	fRet = Avg(ptr, iLength);
	printf("\nAverage is : %f\n", fRet);

	free(ptr);
	return 0;
}