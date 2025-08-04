#include <iostream>
using namespace std;

int main() {
    int x = 5, y = 10, z = 200;
    int* p = &x;
    
    cout<<"P: "<<*p<<endl;
    p = &y;
    cout<<"P: "<<*p<<endl;
    p = &z;
    
    int& r = x;
    cout<<"R: "<<r<<endl;
    
    r = y;
    cout<<"R: "<<r<<endl;

    r = *p;
    cout<<"R: "<<r<<endl;
    
    return 0;
}