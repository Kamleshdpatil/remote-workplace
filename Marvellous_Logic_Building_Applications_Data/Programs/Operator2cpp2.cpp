#include<iostream>
using namespace std;

int main()
{
    int i = 10, j = 10;
    int x,y;
    
    x = i--;    // Post increment
    
    y = --j;    // Pre  incremenrt
    
    cout<<x<<"\n";      // 10
    cout<<y<<"\n";      // 9
    
    cout<<i<<"\n";      // 9
    cout<<j<<"\n";      // 9
    
    
    return 0;
}
