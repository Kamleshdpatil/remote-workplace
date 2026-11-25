//
// Print numbers 1 to N

#include<iostream>

using namespace std;

void print(int i, int N)
{
    if(i > N)
        return;
    cout<<i<<endl;
    print(i+1, N);
}

int main(void)
{
    print(1, 10);
    return(0);
}

// O(N) Time complexity
// O(N) Space complexity