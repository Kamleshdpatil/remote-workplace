#include <iostream>
using namespace std;

class A
{
public:
    void print() { cout << "A "; }
};

class B : public A
{
public:
    // void print() { cout << "A "; }
    // using A::print;
    void print(double d) { cout << "B "; }
};

int main()
{
    B t1;
    t1.print();
    t1.print(9.81);
    return 0;
}
