#include<iostream>
#include<stdlib.h>
using namespace std;

int StrCapR(char *str)
{
	static int iCnt=0;
	
	if(*str != '\0')
	{
		if((*str>='A')&&(*str<='Z'))
		{
			iCnt++;
		}
		str++;
		StrCapR(str);
	}
	return iCnt;
}

int StrSmallR(char *str)
{
	static int iCnt=0;
	
	if(*str != '\0')
	{
		if((*str>='a')&&(*str<='z'))
		{
			iCnt++;
		}
		str++;
		StrSmallR(str);
	}
	return iCnt;
}

int StrNumR(char *str)
{
	static int iCnt=0;
	
	if(*str != '\0')
	{
		if((*str>='0')&&(*str<='9'))
		{
			iCnt++;
		}
		str++;
		StrNumR(str);
	}
	return iCnt;
}

int main()
{
	char Arr[20];
	int iRet=0, iSet=0, iNum=0;	
	cout<<"Enter string\n";
	scanf("%[^'\n']s",Arr);
	
	iRet= StrCapR(Arr);
	
	cout<<"Capital character count of string is: "<<iRet<<"\n";
	
	iSet= StrSmallR(Arr);
	
	cout<<"Small character count of string is: "<<iSet<<"\n";
	
	iNum= StrNumR(Arr);
	
	cout<<"Number count of string is: "<<iNum<<"\n";
	return 0;
}