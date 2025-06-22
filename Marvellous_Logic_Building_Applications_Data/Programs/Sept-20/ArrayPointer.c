#include <stdio.h>
#include <stdlib.h>
int Addition(int *Brr, int iSize)
{
	int iCnt = 0, iSum = 0;
	for (iCnt = 0; iCnt <= iSize; iCnt++)
	{
		iSum = iSum + (*Brr);
		Brr++;
	}
	return iSum;
}
int main()
{
	int *Arr = NULL;
	int aRet = 0, iCnt = 0, iLength;
	printf("Enter Array Size: ");
	scanf("%d", &iLength);

	Arr = (int *)malloc(sizeof(int) * iLength);

	printf("Enter %d Elements: \n", iLength);
	for (iCnt = 0; iCnt < iLength; iCnt++)
	{
		scanf("%d", &Arr[iCnt]);
	}

	aRet = Addition(Arr, iLength);
	printf("Addition is : %d\n", aRet);

	free(Arr);
	return 0;
}