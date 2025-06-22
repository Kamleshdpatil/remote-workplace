#include<iostream>

using namespace std;

class Marvellous
{
	public:
	int Add(int iValue1, int iValue2)
	{
		int iSum=0;
		iSum=iValue1 + iValue2;
		return iSum;
	}
};

int main()
{
	int iNo1=0, iNo2=0, iRet=0;
	Marvellous mobj;
	cout<<"Enter first number: ";
	cin>>iNo1;
	cout<<"Enter first number: ";
	cin>>iNo2;
	
	iRet=mobj.Add(iNo1, iNo2);
	
	cout<<"Addition is: "<<iRet;
	
	return 0;
}
