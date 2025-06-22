#include <iostream>
using namespace std;

class myClass1
{
    int x;

public:
    myClass1(int a) : x(a) {}
    void fun() { cout << x << endl; }
};

class myClass2 : public myClass1
{
    int y;

public:
    myClass2(int a, int b) : myClass1(a), y(b) {}
    void fun() { cout << y << endl; }
};

int main()
{

    myClass2 m(1, 2);
    m.myClass1::fun();
    return 0;
}
