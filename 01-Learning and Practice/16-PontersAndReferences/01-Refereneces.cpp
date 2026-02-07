#include <iostream>
using namespace std;

int main() {
    int x = 5, y = 10, z = 200;
    int* p = &x;
    
    cout<<"&x: "<<&x<<endl;
    cout<<"&y: "<<&y<<endl;
    cout<<"&z: "<<&z<<endl;

    // cout<<"P: "<<*p<<" before &y p: "<<p<<endl;
    // p = &y;
    // cout<<"P: "<<*p<<" before &z p: "<<p<<endl;
    // p = &z;
    // cout<<"P: "<<*p<<" after &z p: "<<p<<endl<<endl;

    int& r = x;
    cout<<"R: "<<r<<" &r: "<<&r<<endl; // created alias by x
    cout<<"X: "<<x<<" &x: "<<&x<<endl;
    
    r = y;
    cout<<"R: "<<r<<" &r: "<<&r<<endl; // changed value only
    cout<<"Y: "<<y<<" &y: "<<&y<<endl;
    cout<<"X: "<<x<<" &x: "<<&x<<endl; // changed value of x

    r = *p;
    cout<<"R: "<<r<<" &r: "<<&r<<endl;
    
    return 0;
}