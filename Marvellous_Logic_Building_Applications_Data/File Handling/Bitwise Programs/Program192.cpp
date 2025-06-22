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
 
  int ToggleBit(int iNo, int iPos1, int iPos2)
  {
  	int i=0, iCnt=0, iResult=0;
  	int iMask1 = 0x00000001;
  	int iMask2=0x00000001, iMask=0;
  	
	iMask1=iMask1<<(iPos1-1);
	iMask2=iMask2<<(iPos2-1);
	
	iMask = iMask1 | iMask2; 
	iResult = iNo ^ iMask;
	
  	return iResult;
  }
  
int main()
{
	int iValue=0, i=0, j=0, iRet=0;
	
	cout<<"Enter Number: ";
	cin>>iValue;
	cout<<"Enter first Position of bit: ";
	cin>>i;
	cout<<"Enter second Position of bit: ";
	cin>>j;
	
	iRet=ToggleBit(iValue,i,j);
	cout<<"Updated number is: "<<iRet<<"\n";
	
	return 0;
}