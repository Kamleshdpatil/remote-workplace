#include<iostream>
#include<stdbool.h>
using namespace std;

int findFibbonacci(int num)
{
    int a =0, b = 1, c = 0, i = 0;

    if(num == 0)
    {
        return(a);
    }

    for(i = 2; i <= num; i++)
    {
        c = a + b;
        a = b;
        b  = c;
    }
    return b;
}

int main(void)
{
    int num = 0;
    cout<<"Enter number:- "<<endl;
    cin>>num;

    int bRet = findFibbonacci(num);
    cout<<bRet<<" is Fibbonacci"<<endl;
    
    return(0);
}
