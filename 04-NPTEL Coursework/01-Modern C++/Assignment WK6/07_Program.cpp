#include <iostream>
using namespace std;

class A
{
public:
    int a = 5;
};

class B : public A
{
public:
    int b = 5;
};

class C : public B
{
public:
    double c = 3.14;
};

int main()
{
    A *p;
    B t1;
    C t2;
    p = (A *)&t1;
    cout << p->a << " ";

    p = (A *)&t2;
    cout << p->a << " ";

    return 0;
}
