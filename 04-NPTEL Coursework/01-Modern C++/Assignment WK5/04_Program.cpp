#include <iostream>
using namespace std;

class A
{
public:
    int a;
    A(int x) : a(x) { cout << "a: " << a << endl; }
};

class B : public A
{
    int b;

public:
    B(int x, int y) : b(y), A(x) { cout << "b: " << b << endl; }
};

int main()
{
    B t1(1, 2);
    A t2(5);

    cout << t1.a << " ";
    cout << t2.a << " ";

    return 0;
}
