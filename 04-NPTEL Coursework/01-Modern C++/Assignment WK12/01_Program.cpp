#include <iostream>
#include <thread>
#include <list>
using namespace std;

struct Product
{
    list<int> &iLst;
    int *result;
    Product(list<int> &il, int *res) : iLst{il}, result{res} {}
    void operator()()
    {
        for (auto &i : iLst)
        {
            *result *= i;
            i = 0;
        }
    }
};

void print(list<int> iLst)
{
    for (auto i : iLst)
        cout << i << " ";
}

int main()
{
    list<int> il{10, 20, 30};
    int res = 1;

    std::thread t{std::bind(Product, std::ref(il), &res)};

    t.join();
    print(il);

    cout << res;

    return 0;
}
