#include <iostream>
using namespace std;
class myClass
{
    static int X;
    static int Y;

public:
    static void print()
    {
        cout << X << " " << Y;
    }
    void setX(int a)
    {
        X = a;
    }
    void setY(int a)
    {
        Y = a;
    }
};

int myClass::X = 10;
int myClass::Y = 10;

int main(void)
{
    myClass t1, t2;
    t1.setX(4);
    t2.setY(5);

    myClass::print();

    return (0);
}
