#include<stdio.h>
#include<stdbool.h>
typedef unsigned int UINT;


bool CheckBit(UINT iNo)
{
	UINT iMask= 0x00000840, iResult=0; // 0000 0000 0000 0000 0000 0000 0000 0000
	                                   //   0   0     0    0    0    8   4     0
	                                   //   0x00000840                
	
	iResult= iNo & iMask;
	if(iResult == iMask)
	{
		return true;	
	}
	else
	{
		return false;	
	}	
}

int main()
{
	UINT iValue=0;
	bool bRet=false;
	
	printf("Enter Number ");
	scanf("%d",&iValue);
	
	bRet=CheckBit(iValue);
	
	if(bRet==true)
	{
		printf("7th & 12th bit is ON\n");
	}
	else{
		printf("7th & 12th bit is OFF\n");
	}
	
	return 0;
	
}