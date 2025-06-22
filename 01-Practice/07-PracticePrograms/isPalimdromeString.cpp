#include<iostream>
#include<stdbool.h>

using namespace std;

bool checkPalimdrome(string num)
{
    string reverese = num;
    reverse(reverese.begin(), reverese.end());
    if(reverese == num)
    {
        return true;
    }
    return false; 
}

bool isPalimdrome(string num)
{
    int len = num.length();
    for(int i=0; i<len-1; i++)
    {
        if(num[i] != num[len - i-1])
        {
            return false;
        }
    }

    return true;
}

void print(string s)
{
    cout<<"Start||";
    for(int i = 0; i < s.length(); i++)
    {
        cout<<s[i];
    }
    cout<<"||End"<<endl;
}   

int main(void)
{
    //string num = "7007";
    string num = "707010707";
    //bool bRet= checkPalimdrome(num);
    // bool bRet= isPalimdrome(num);
    // if(bRet)
    // {
    //     cout<<"\nYes, "<<num<<" is palimdrome string"<<endl;
    // }
    // else{
    //     cout<<"\nOops, "<<num<<" is not palimdrome string"<<endl;
    // }

    print(num);

    return(0);
}
