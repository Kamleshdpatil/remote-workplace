//
// Print numbers 1 to N

#include<iostream>

using namespace std;

int print(int N)
{
    if(N == 0)
        return 0;
    
    return N + print(N-1);
}

int factorial(int N)
{
    if(N == 0)
        return 1;
    
    return N * factorial(N-1);
}

int main(void)
{
    int N = 0;
    cout<<"Enter Number: ";
    cin>>N;
    //cout<<print(N);
    cout<<factorial(N);
    return(0);
}

// O(N) Time complexity
// O(N) Space complexitys