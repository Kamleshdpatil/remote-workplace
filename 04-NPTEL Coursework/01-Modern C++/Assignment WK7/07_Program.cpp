#include <iostream>
#include <typeinfo>
using namespace std;

class Base
{
public:
    virtual void f()
    {
        cout << "Base ";
    }
};

class Derived : public Base
{
public:
    virtual void f()
    {
        cout << "Derived ";
    }
};

int main()
{
    Base obb;
    Derived obd;

    try
    {
        Base &ra1 = static_cast<Base &>(obd);
        ra1.f(); // Derived

        Base &ra2 = dynamic_cast<Base &>(obd); // up-cast
        ra2.f();                               // Derived

        Derived &rb1 = static_cast<Derived &>(obb); // down-cast
        rb1.f();                                    // Base

        Derived &rb2 = dynamic_cast<Derived &>(obb); // down-cast
        rb2.f();                                     // Bad-cast
    }
    catch (exception &e)
    {
        cout << e.what();
    }

    return 0;
}
