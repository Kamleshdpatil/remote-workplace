#include<iostream>
#include<stdbool.h>

using namespace std;

bool checkPalimdrome(int num)
{
    int reverese = 0;
    int temp = num;

    while (temp != 0)
    {
        reverese = (reverese * 10) + (temp % 10);
        cout<<"reverese: "<<reverese<<endl;
        temp = temp/10;
        cout<<"temp: "<<temp<<endl;
    }
    if(reverese == num)
    {
        return true;
    }
    return false;
    
}

int main(void)
{
    int num = 7007;
    //int num = 70001007;
    bool bRet= checkPalimdrome(num);
    if(bRet)
    {
        cout<<"\nYes, "<<num<<" is palimdrome number"<<endl;
    }
    else{
        cout<<"\nOops, "<<num<<" is not palimdrome number"<<endl;
    }
    return(0);
}
