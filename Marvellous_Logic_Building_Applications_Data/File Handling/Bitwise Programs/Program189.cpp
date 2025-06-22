#include<iostream>

using namespace std;
typedef unsigned int UINT;

/* 
op1    op2   &      |       ^
 1      0    0      1       1
 0      1    0      1       1
 1      1    1      1       0
 0      0    0      0       0
 */
 
  // iNo   0000 0000 1110 0100 1111 0100 1011 1010
  // iPos   6
  // iRet  0000 0000 1110 0100 1111 0100 1001 1010
  
  int ToggleBit(int iNo)
  {
  	int i=0, iCnt=0, iResult=0;
  	int iMask = 0x00000001;
  	
  	for(i=1; i< 32; i++)
  	{
  		iResult = iNo & iMask;
  		
  		if(iResult !=0)
  		{
  			iCnt++;
		}
		iMask = iMask <<1;
		//
	}
	return iCnt;
  }
  
int main()
{
	int iValue=0, i=0, iRet=0;
	
	cout<<"Enter Number: ";
	cin>>iValue;
	
	iRet=ToggleBit(iValue,i);
	cout<<"Number of bit which are ON: "<<iRet<<"\n";
	
	return 0;
}