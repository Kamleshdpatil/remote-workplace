#include<iostream>
#include<stdbool.h>
using namespace std;

bool isArmstrongNumber(int num)
{
    int temp = num;
    int p = 0;

    while (num>0)
    {
        int rem = num % 10;
        cout<<"Rem "<<rem<<endl;
        p = (p) + (rem * rem * rem);
        num = num / 10;
    }

    if(p == temp)
    {
        return true;
    }else
    {
        return false;
    }
    
}

int main(void)
{
    int num = 0;
    cout<<"Enter number:- "<<endl;
    cin>>num;

    bool bRet = isArmstrongNumber(num);
    if(bRet == true)
    {
        cout<<num<<" is Armstrong number"<<endl;
    }else
    {
        cout<<num<<" is not Armstrong number"<<endl;
    }

    return(0);
}
