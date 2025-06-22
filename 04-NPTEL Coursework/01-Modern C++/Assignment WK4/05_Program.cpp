#include <iostream>
using namespace std;

int x = 10;

namespace e
{
    namespace e1
    {
        int x = 15;
    }
    int x = 5;
}

int main(void)
{
    using e::e1::x;

    cout << x;

    return (0);
}
