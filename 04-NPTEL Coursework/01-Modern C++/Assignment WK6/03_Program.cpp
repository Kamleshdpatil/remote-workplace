#include <iostream>
using namespace std;

int x = 0;

class Base
{
public:
    Base() { x = x + 3; }
    ~Base() { x = x - 5; }
};
class Derived : public Base
{
public:
    Derived() { x = x + 7; }
    ~Derived() { x = x - 1; }
};

void fun()
{
    Derived t;
    Base *t1 = new Derived();
    cout << x << " ";
    delete t1;
}

int main()
{
    fun();
    cout << x;

    return 0;
}
