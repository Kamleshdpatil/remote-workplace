#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int i = 10;

void test(int &&rv)
{
    // Traffic
}

int getVal()
{
    return i;
}

int &getRef()
{
    return i;
}

int main()
{
    test(i);

    test(i + 10);
    test(getVal());

    // test(getRef());

    return 0;
}
