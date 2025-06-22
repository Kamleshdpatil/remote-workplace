#include <iostream>
using namespace std;

class B
{
    int x;

public:
    B(int _x) : x(_x) {}
    int fun() { return x; }
};

class D : public B
{
    int y;

public:
    D(int _x, int _y) : B(_x), y(_y) {} // correct
    // D(int _x, int _y) : y(_y), B(_x) {} // also correct
    void fun() { cout << B::fun() << y; }
};

int main()
{
    D *b2 = new D(1, 0);
    b2->fun();
    return 0;
}
