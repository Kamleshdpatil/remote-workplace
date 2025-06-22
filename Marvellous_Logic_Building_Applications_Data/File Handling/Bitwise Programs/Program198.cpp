#include<iostream>
using namespace std;
typedef unsigned int UINT;

  UINT DispalyByte(UINT iNo)
  {
  	UINT Byte1 = iNo & 0x000000FF;
  	UINT Byte2 = iNo & 0x0000FF00;
  	
  	
  }
  
int main()
{
	UINT iValue=0, iRet=0, i,j;
	
	cout<<"Enter Number: ";
	cin>>iValue;
	ToggleRange(iValue);
	
	return 0;
}