#include<iostream>
using namespace std;

int main(void)
{
    // Not valid/ undefined behaviour
    const int a1 = 10;
    const int* b1 = &a1;

    int* d1 = const_cast<int*>(b1);

    *d1 = 15;

    cout<<a1<<endl;
    cout<<*d1<<endl;

    cout<<endl;

    // Valid code
    int a2 = 20;
    const int* b2 = &a2;

    int* d2 = const_cast<int*>(b2);
    *d2 = 30;
    cout<<a2<<endl;
    cout<<*d2<<endl;

    return(0);
}
