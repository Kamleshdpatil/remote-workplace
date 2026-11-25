#include<iostream>
#include<vector>

using namespace std;

template<typename T>
void print(vector<T>& arr)
{
    for(auto ele : arr)
    {
        cout<<ele<<" ";
    }
    cout<<endl;
}

int main(void)
{
    vector<int> numArray = {10, 20, 30, 40};
    print(numArray);

    vector<char> charArray = {'K', 'A', 'M', 'L', 'E', 'S', 'H'};
    print(charArray);

    return(0);
}
