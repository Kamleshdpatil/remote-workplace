#include<stdio.h>

int CountCapital(char *str)
{
	int CntCap=0, CntSmall=0, iFreq=0;
	char *temp= str;
	while(*str !='\0')
	{
		if((*str >='A') && (*str<='Z'))
		{
			CntCap++;
		} str++;
	}
	while(*temp !='\0')
	{
		if((*temp >='a') && (*temp<='z'))
		{
			CntSmall++;
		} temp++;
	}
	
	iFreq=CntSmall - CntCap;
	
	return iFreq;
}

int main()
{
	char arr[20];
	int iRet=0;
	
	printf("Enter String: ");
	scanf("%[^'\n']s",arr);
	
	iRet=CountCapital(arr);
	
	printf("Frequency of small and capital characters is: %d", iRet);
	
	return 0;
}