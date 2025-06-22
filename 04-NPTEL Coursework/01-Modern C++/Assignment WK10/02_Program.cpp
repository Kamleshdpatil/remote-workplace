#include <iostream>
using namespace std;

struct Oper1
{
    int i;
    Oper1(int _i) : i(_i) {}
    int &operator()()
    {
        cout << "1 ";
        return i;
    }
};

struct Oper2
{
    int i;
    Oper2(int _i) : i(_i) {}
    int &operator()()
    {
        cout << "2 ";
        return i;
    }
};

template <typename U>
// decltype(auto) foobar(U &op)
// auto &foobar(U &op)
auto foobar(U &op) -> decltype(op())
{
    return op();
}

int main()
{
    Oper1 o1{10};
    Oper2 o2{10};

    foobar(o1) = 10;
    foobar(o2);

    return 0;
}
