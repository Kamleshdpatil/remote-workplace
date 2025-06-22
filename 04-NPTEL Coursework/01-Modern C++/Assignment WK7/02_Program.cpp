#include <iostream>
using namespace std;

int incr(int *ptr)
{
    return ++(*ptr);
}

int main()
{
    int x = 5;
    const int *ptr = &x;
    x = incr(const_cast<int *>(ptr));
    cout << x;
    return 0;
}
