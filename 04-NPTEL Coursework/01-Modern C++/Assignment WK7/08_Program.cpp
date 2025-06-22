#include <iostream>
#include <typeinfo>
using namespace std;

class A
{
public:
    virtual ~A()
    {
    }
};

class B : public A
{
};

class C : public A
{
};

int main()
{
    A objA;
    B objB;

    A *pA = static_cast<A *>(&objB); // up-cast
    pA == NULL ? cout << "cast-1 invalid: " : cout << "cast-1 valid: ";

    B *pB = static_cast<B *>(pA);
    pB == NULL ? cout << "cast-2 invalid: " : cout << "cast-2 valid: ";

    C *pC = dynamic_cast<C *>(new A);
    pC == NULL ? cout << "cast-3 invalid: " : cout << "cast-3 valid: ";

    pC = dynamic_cast<C *>(&objB);
    pC == NULL ? cout << "cast-3 invalid: " : cout << "cast-3 valid: ";

    return 0;
}
