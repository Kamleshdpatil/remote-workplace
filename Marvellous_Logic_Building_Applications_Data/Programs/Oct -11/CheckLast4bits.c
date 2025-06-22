#include<stdio.h>
#include<stdbool.h>
typedef unsigned int UINT;


bool CheckBit(UINT iNo)
{
	UINT iMask= 0x0000000F, iResult=0; // 0000 0000 0000 0000 0000 0000 0000 1111
	                                   //   0   0     0    0    0    0    0    F  
	                                   //   0x0000000F                
	
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
		printf("Last four bits is ON\n");
	}
	else{
		printf("Last four bits bit is OFF\n");
	}
	
	return 0;
	
}