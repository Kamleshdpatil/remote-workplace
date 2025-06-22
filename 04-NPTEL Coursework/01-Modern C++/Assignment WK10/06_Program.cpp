#include <iostream>
using namespace std;

long double operator"" _KB(long double mem)
{
    return 1024 * mem;
}

long double operator"" _B(long double mem)
{
    return mem;
}

int main()
{
    long double size = 10.0_KB + 2.0_B;
    cout << "Size (in bytes): " << size;

    return 0;
}
