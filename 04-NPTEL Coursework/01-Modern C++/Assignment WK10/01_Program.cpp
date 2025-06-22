#include <iostream>
using namespace std;

int main()
{
    char n = 'A';
    char &rn = n;

    auto &t = rn;
    // decltype(rn) t = rn;

    ++t;

    cout << n << " " << rn << " " << t << endl;

    return 0;
}
