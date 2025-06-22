#include <iostream>
using namespace std;

class base
{
public:
    void print() { cout << "C" << " "; }
};

class derived : public base
{
public:
    void print() { cout << "C++" << " "; }
};

int main()
{
    base *a1 = new base();
    base *b1 = new derived();

    a1->print();
    b1->print();

    return 0;
}
