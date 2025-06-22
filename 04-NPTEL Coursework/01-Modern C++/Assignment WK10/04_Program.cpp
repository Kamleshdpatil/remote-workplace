#include <iostream>
using namespace std;

class ComplexNum
{
public:
    constexpr ComplexNum(int _r = 0, int _i = 0) : r(_r), i(_i) {}

private:
    int r, i;
};

int randGen()
{
    return 10;
}

constexpr int numGen(int i, int j)
{
    return i + j;
}

int main()
{
    constexpr ComplexNum c1(10, 20); // Line 1
    constexpr int i = 10, j = 20;

    constexpr ComplexNum c2(i, j); // Line 2

    constexpr ComplexNum c3(randGen(), randGen()); // Line 3

    // constexpr ComplexNum c4(numGen(i, j), numGen(i, j)); // Line 4

    return 0;
}
