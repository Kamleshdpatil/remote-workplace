#include <iostream>

using namespace std;

int main()
{
    int m = 4;
    const int n = 5;
    const int *p = &n;
    const int *const ptr = &n;

    p = &m;
    p = &n;
    *p = 6;
    // ptr = &n;

    cout << "OK" << endl;
    return 0;
}
