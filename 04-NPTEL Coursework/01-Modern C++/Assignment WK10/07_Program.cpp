#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void process(int &v)
{
    if (v < 0)
        throw v;
    ++v;
}

void func(vector<int> &iVec) noexcept(noexcept(process(iVec[0])))
{
    for (int &v : iVec)
    {
        process(v);
    }
}

int main()
{
    vector<int> iVec{1, 2, -1, 2};

    try
    {
        func(iVec);
    }
    catch (int i)
    {
    }

    for (int v : iVec)
    {
        cout << v << " ";
    }

    return 0;
}
