#include <iostream>
using namespace std;

class base
{
protected:
    int n1;

public:
    base(int x) : n1(x) {}
    void f1() { cout << ++n1 << endl; }
};

class derived : public base
{
public:
    derived(int x) : base(x) {}
    void f1(int a) { cout << ++n1 << endl; }
};

int main()
{
    derived d(10);
    d.base::f1();

    return 0;
}
