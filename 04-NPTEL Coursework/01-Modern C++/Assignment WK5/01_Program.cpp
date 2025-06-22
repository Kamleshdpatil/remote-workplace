#include <iostream>
using namespace std;

class myClass1
{
    int x1;
    double x2;

public:
    void func() { cout << "fun" << endl; }
};

class myClass2 : public myClass1
{
    double d1;
};

int myClass1::x1 = 0;

int main()
{

    myClass2 d;
    cout << sizeof(d);

    return 0;
}
