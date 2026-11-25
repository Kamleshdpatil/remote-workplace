//
// Print numbers 1 to N

#include<iostream>

using namespace std;

void print(int i, int N)
{
    if(i > N)
        return;
    print(i+1, N);
    cout<<i<<endl;
}

int main(void)
{
    int count = 0;
    cout<<"Enter Number: ";
    cin>>count;
    print(1, count);
    return(0);
}

// O(N) Time complexity
// O(N) Space complexity