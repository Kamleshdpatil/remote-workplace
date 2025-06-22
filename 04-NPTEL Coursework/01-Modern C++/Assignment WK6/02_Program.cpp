#include <iostream>
using namespace std;

class A
{
public:
    virtual void fun() { cout << "class1" << endl; }
};
class B : public A
{
public:
    void fun() { cout << "class2" << endl; }
};

int main()
{
    B t1;
    A *t2 = new B();
    A *t3 = &t1;
    t2->fun();
    t3->fun();

    return 0;
}
