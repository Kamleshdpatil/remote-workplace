#include <iostream>
#include <functional>
using namespace std;

int print(int n1, int n2, int n3, const int &n4)
{
    return (n1 - (n2 + n3 + n4));
}

int main()
{
    using namespace std::placeholders;
    int val = 10;
    auto f = std::bind(print, _2, val _1, std::cref(val));
    val = -10;
    cout << f(100, 20, -100);

    return 0;
}
