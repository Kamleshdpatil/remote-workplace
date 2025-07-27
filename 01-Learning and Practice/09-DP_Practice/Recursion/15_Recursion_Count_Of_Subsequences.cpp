#include<iostream>
#include<vector>

using namespace std;
int fun(int index, int* arr, int s, int sum, int n)
{
    void Display(vector<int>&);
    if(index == n)
    {
        if(sum == s)
            return 1;
        else
            return 0;
    }

    // Take or pick the particular index into the subsequence
    
    s = s + arr[index];
    int l = fun(index+1, arr, s, sum, n);

    s = s - arr[index];

    // Not pick, or not take condition, this element is not added to your sub sebsequences.
    int r = fun(index+1, arr, s, sum, n);

    return r + l;
}

int main(void)
{
    int arr[] = {1, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 2;
    cout<<"Number of subsequences: "<<fun(0, arr, 0, sum, n);
    return(0);
}
