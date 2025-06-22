#include <iostream>
#include <list>
#include <numeric>
#include <functional>

using namespace std;

double compute(list<int> &li)
{
    double result = accumulate(li.begin(), li.end(), 0.5, multiplies<double>());
    return result;
}

int main()
{
    int arr[] = {10, 20, 30, 40};
    list<int> li(arr, arr + sizeof(arr) / sizeof(*arr));
    cout << compute(li) << endl;
    return 0;
}
