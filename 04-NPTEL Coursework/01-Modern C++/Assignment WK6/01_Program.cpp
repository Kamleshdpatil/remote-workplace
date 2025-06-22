#include <iostream>
using namespace std;

class classA
{
public:
    void fun1() { cout << "1"; }
    virtual void fun2() { cout << "3"; }
};
class classB : public classA
{
public:
    void fun1() { cout << "2"; }
    void fun2() { cout << "4"; }
};

int main()
{
    classA *t = new classB;
    t->fun1();
    t->fun2();

    return 0;
}
