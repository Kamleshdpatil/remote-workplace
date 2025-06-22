#include <iostream>
using namespace std;

int var = 0;

namespace name
{
    int var = 2;
}

int main(void)
{
    using namespace name;
    cout << ::var << " " << var << " " << name::var;

    return (0);
}
