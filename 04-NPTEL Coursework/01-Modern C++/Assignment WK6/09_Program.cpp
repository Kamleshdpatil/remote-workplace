#include <iostream>
using namespace std;

class A
{
public:
    virtual void print() { cout << "A "; }
};

class B : public A
{
public:
    void print() { cout << "B "; }
};

class C : public B
{
public:
    void print() { cout << "C "; }
};

int main()
{
    A *cb = new B;
    cb->print();

    return 0;
}
