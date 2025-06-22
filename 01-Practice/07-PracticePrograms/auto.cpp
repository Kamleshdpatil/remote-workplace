#include<iostream>

using namespace std;

auto& sum(int i, int k)
{
    int sum = i + k;

    return sum; 
}

int main(void)
{
    int& ret = sum(10, 10);

    cout<<ret<<endl;
}
