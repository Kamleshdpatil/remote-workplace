#include<iostream>
#include<vector>

using namespace std;

void print(vector<int>& nums)
{
    for(auto num : nums)
    {
        cout<<num<<" ";
    }
    cout<<endl;
}

int main(void)
{
    vector<int> arr = {10, 20, 30, 40};
    cout<<"Printing source array: ";
    print(arr);

    return(0);
}
