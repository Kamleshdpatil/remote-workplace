#include<iostream>
#include<vector>

using namespace std;

void print(vector<int>& nums)
{
    for(int num : nums)
    {
        cout<<num<<" ";
    }
    cout<<endl;
}

int main(void)
{
    vector<int> source = {10, 20, 30, 40};
    print(source);

    return(0);
}
