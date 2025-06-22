#include <iostream>
using namespace std;

class base
{
    int a;

public:
    base(int i) : a(i) { cout << "base ctor called" << endl; }
    virtual void test(base *)
    {
        cout << "** base test called" << endl;
        cout << a << endl;
    }
};
class derived : public base
{
    int b;

public:
    derived(int i = 0, int j = 0) : base(i), b(j)
    {
        cout << "derived ctor called" << endl;
    }
    void test(derived *)
    {
        cout << "** derived test called" << endl;
        cout << b << endl;
    }
};

int main()
{
    base *t1 = new derived(5, 9);
    t1->test(new derived);
    return 0;
}
