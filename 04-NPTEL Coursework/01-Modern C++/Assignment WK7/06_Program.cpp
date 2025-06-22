#include <iostream>
#include <typeinfo>
using namespace std;

class Base
{
public:
    virtual ~Base() {}
};

class Derived : public Base
{
};

int main()
{
    Base b;
    Derived d;

    Derived *dp = &d;
    Base *bp = dp;
    Derived *dpp = (Derived *)dp;

    cout << (typeid(dp).name() == typeid(bp).name());    // 0
    cout << (typeid(*dp).name() == typeid(*bp).name());  // 1
    cout << (typeid(bp).name() == typeid(dpp).name());   // 0
    cout << (typeid(*bp).name() == typeid(*dpp).name()); // 1

    return 0;
}
