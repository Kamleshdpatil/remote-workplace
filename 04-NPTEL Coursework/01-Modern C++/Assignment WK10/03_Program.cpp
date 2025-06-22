#include <iostream>
using namespace std;

class CustList
{
public:
    CustList(initializer_list<double> dList)
    {
        cout << "ctor-1" << " ";
    }
    CustList(initializer_list<int> dList)
    {
        cout << "ctor-2" << " ";
    }
    CustList(double d1, double d2, double d3)
    {
        cout << "ctor-3" << " ";
    }
};

int main()
{
    CustList c1{3.1, 4.5, 6.5};

    CustList c2(3.1, 4.5, 6.5);

    CustList c3{3.1f, 4.5f, 6.5};

    // CustList c4{3, 4.5, 6};

    return 0;
}
