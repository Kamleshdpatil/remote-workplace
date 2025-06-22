#include <iostream>
using namespace std;

class constTest
{
    const int x;

public:
    constTest(int _x) : x(_x) {}

    void set(int a) const
    {
        x = a;
    }

    void print() const
    {
        cout << x << endl;
    }
};

int main(void)
{
    const constTest m(5);
    m.set(10);
    m.print();
    return (0);
}
