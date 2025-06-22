#include <iostream>
using namespace std;

class A
{
public:
    A() { cout << "A "; }
    ~A() { cout << "~A "; }
};

class B : public A
{
public:
    B() { cout << "B "; }
    ~B() { cout << "~B "; }
};
class C : public B
{
    B b;

public:
    C() { cout << "C "; }
    ~C() { cout << "~C "; }
};

int main()
{
    C obj;

    return 0;
}
