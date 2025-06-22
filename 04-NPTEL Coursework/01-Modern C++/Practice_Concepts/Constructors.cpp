#include <iostream>

using namespace std;

class Number
{
    int n;

public:
    Number()
    {
        cout << "defualt cctor" << endl;
        cout << 0 << " " << endl;
    }
    Number(int i) : n(i)
    {
        cout << "parameterized cctor" << endl;
        cout << n << " " << endl;
    }
    Number(const Number &num) : n(0)
    {
        n = num.n;
        cout << "Copy cctor" << endl;
        cout << n << " " << endl;
    }
};

int main()
{
    int i = 1;

    Number n(11); // Line 2
    Number n1(n); // Line 1
    // Number *n2 = new Number(i++);
    // Number *n3;
    // new Number(i++);

    cout << "OK" << endl;
    return 0;
}
