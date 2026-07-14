#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main(void)
{
    vector<int> arr = {4, 5, 1, 2, 3, 4};
    int factor = 10;

    cout<<endl;

    // 1. While sorting
    sort(arr.begin(), arr.end(), [](int a, int b){return a > b;});

    // . While iterating
    for_each(arr.begin(), arr.end(), [factor](int n){
        cout<<n * factor<<" ";
    });

    cout<<endl;



    return(0);
}
