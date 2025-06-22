// Online C++ compiler to run C++ program online
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int add(int a = 100) { return a; }
int add(int a = 100, int b = 100) { return a + b; }
int add(int a = 100, double b = 100.0) { return a + b; }
int add(int a = 100, int b = 100, int c = 100) { return a + b + c; }

#define DOUBLE(x) (2 * x)

inline int TRIPLE(int x) { return 3 * x; }

int &incr(int &i)
{
    cout << "i : " << i << endl;
    return ++i;
}

#define C1 10 + 1
const int C2 = 10 + 1;

int main()
{
    // Write C++ code here
    // int r = add(10, 20);
    // cout<<"R: "<<r<<endl;
    // cout<<"DOUBLE: "<<DOUBLE(10 + 10)<< " ";
    // cout<<"TRIPLE: "<<TRIPLE(10 + 10)<<endl;

    // int x = 10, y = 20;
    // int& z = incr(x);
    // cout<<x<<" "<<z<<" "<<endl;

    // incr(x) = y;
    // cout<<"x "<<x<<endl;
    // cout<<"y "<<y<<endl;
    // cout<<x<<" "<<z<<" "<<endl;

    // int n1, n2;
    // cout<<C1<<" "<<C2<<" "<<endl;

    // n1 = C1 * 100 * C2;
    // n2 = C2 * 100 * C1;
    // cout<<n1<<" "<<n2<<" "<<endl;

    // cout<<"Main: 1110 11001"<<endl;

    // int i = 10;
    // int& r = i;
    // r += i += ++r;
    // // cout<< "r +=i  " << ( r +=i )<<endl;
    // // cout<< "i: "<<i << " r: "<<r<<endl;
    // // cout<< "i += ++r  " <<( i += ++r) <<endl;

    // cout<< i << " "<<r;

    // const char c = 'X';
    // // const char* cp = &c;
    // // cout<<*cp++<<endl;
    // char const* cp = &c;
    // cout<<*cp--<<endl;

    cout << "Malloc" << endl;
    int *ip = (int *)malloc(sizeof(int) * 5);
    for (int i = 1; i <= 5; i++)
    {
        ip[i] = i * 10;
        // cout<<ip[i]<< " ";
    }

    for (int i = 1; i <= 5; i++)
    {
        // ip[i] = i * 10;
        cout << ip[i] << " ";
    }

    cout << endl;
    cout << "New" << endl;
    cout << endl;
    int *ipp = new int[5];
    for (int i = 1; i <= 5; i++)
    {
        ipp[i] = i * 10;
        // cout<<ip[i]<< " ";
    }

    for (int i = 1; i <= 5; i++)
    {
        // ip[i] = i * 10;
        cout << ipp[i] << " ";
    }

    cout << endl;
    cout << "Operator New: " << endl;
    cout << endl;
    int *ippp = (int *)operator new(sizeof(int) * 5);
    for (int i = 1; i <= 5; i++)
    {
        ippp[i] = i * 10;
        // cout<<ip[i]<< " ";
    }

    for (int i = 1; i <= 5; i++)
    {
        // ip[i] = i * 10;
        cout << ippp[i] << " ";
    }

    return 0;
}
