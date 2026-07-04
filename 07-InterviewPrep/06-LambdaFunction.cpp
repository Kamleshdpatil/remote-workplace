#include<iostream>
using namespace std;

int main()
{
    auto isEven = [](int num) {
        return num % 2 == 0;
    };

    auto result = [](int num, int num1) {
        return num + num1;
    };

    if(isEven(10))
    {
        cout<<"Even !!"<<endl;
    }else
        cout<<"Odd !!"<<endl;

    cout<<result(10, 12)<<endl;

    return(0);
}
