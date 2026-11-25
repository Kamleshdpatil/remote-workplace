//
// find is palimdrome of given string

#include<iostream>
#include<algorithm>

using namespace std;

int fibbonacci(int n)
{ 
    int first = 0;
    int last = 0;
    if(n <= 1)
        return n;
    first = fibbonacci(n-1);
    last = fibbonacci(n-2);
    return  first + last; 
}

int PrintFibbonacci(int n)
{ 
    if(n == 0)
    {
        return n;
    }
    else if(n == 1)
    {
        return n;
    }
    else
    {
        return PrintFibbonacci(n-1) + PrintFibbonacci(n-2);
    }
}

int main(void)
{
    //cout<<fibbonacci(11);
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cout<<PrintFibbonacci(i)<<" ";
    }
        
    return(0);
}

// O(N) Time complexity
// O(N) Space complexitys