//
// Print numbers 1 to N

#include<iostream>

using namespace std;

void print(int i, int N)
{
    if(i < 1)
        return;
    cout<<i<<endl;
    print(i-1, N);
}

int main(void)
{
    int count = 0;
    cout<<"Enter Number: ";
    cin>>count;
    print(count, count);
    return(0);
}

// O(N) Time complexity
// O(N) Space complexity