#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

bool isPalimdrome(char *str)
{
    size_t n = strlen(str);;
    for(int i = 0; i< n/2; i++)
    {
        if(str[i] != str[n-i-1])
        {
            return false;
        }
    }
    return true;
}

bool isPalimdromeRecursion(char *str, int i, int n)
{
    if(i > n/2)
        return true;

    if(str[i] != str[n-i-1])
        return false;

    return isPalimdromeRecursion(str, i+1, n);
}

int main(void)
{
    char *str = "MAKLDQLKAM";
    size_t n = strlen(str);;
    //for(int i = 0; i<n; i++) cin>>arr[i];
    //bool bRet = isPalimdrome(str);
    bool bRet = isPalimdromeRecursion(str, 0, n);
    cout<<endl;
    if(bRet == true)
    {
        cout<<"palimdrome"<<endl;
    }
    else{
        cout<<"Not palimdrome"<<endl;
    }
    return(0);
}


