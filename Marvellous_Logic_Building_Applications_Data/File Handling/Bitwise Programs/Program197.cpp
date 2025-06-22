#include<iostream>
using namespace std;
typedef unsigned int UINT;

  UINT ToggleRange(UINT iNo, int iStart, int iEnd)
  {
  	return (iNo ^((0xFFFFFFFFFF << (iStart-1)) & (0xFFFFFFFF >> (32- iEnd))));
  }
  
int main()
{
	UINT iValue=0, iRet=0, i,j;
	
	cout<<"Enter Number: ";
	cin>>iValue;
	cout<<"Enter Starting Position: ";
	cin>>i;
	cout<<"Enter Ending Position: ";
	cin>>j;
	
	iRet=ToggleRange(iValue,i,j);
	cout<<"Updated number is: "<<iRet<<"\n";
	
	return 0;
}