#include <iostream>
using namespace std;

class base
{
public:
    base() { cout << "base()::ctor called" << endl; }
    static void func() { cout << "C++" << endl; }
};

class derived : public base
{
public:
    derived()
    {
        (new base)->func();
        cout << "derived()::ctor called" << endl;
    }
};

int main()
{
    derived t1;

    return 0;
}
