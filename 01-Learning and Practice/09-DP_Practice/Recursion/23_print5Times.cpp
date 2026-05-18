//
// Print N times Name

#include<iostream>

using namespace std;

void print(int i)
{
    if(i <= 0)
        return;
    cout<<"Kamlesh"<<endl;
    print(i-1);
}

int main(void)
{
    print(5);
    return(0);
}

// O(N) Time complexity
// O(N) Space complexity