//
// Reverse array using recursion(Functional way)

#include<iostream>
#include<algorithm>

using namespace std;

void ReverseArray(int* arr, int l, int r)
{
    if(l >= r)
    {
        return;
    }
    swap(arr[l], arr[r]);
    ReverseArray(arr, l+1, r-1);
}

void ReverseArrayEx(int* arr, int n, int i)
{
    if(i >= n/2)
    {
        return;
    }
    swap(arr[i], arr[n-i-1]);
    ReverseArrayEx(arr, n, i+1);
}

int main(void)
{
    int Arr[] = {10, 20, 5, 40, 15, 11};
    int size = 0;

    size = sizeof(Arr)/sizeof(Arr[0]);
    ReverseArrayEx(Arr, size, 0);

    for(int i = 0; i < size; i++)
    {
        cout<<Arr[i]<<" ";
    }

    return(0);
}

// O(N) Time complexity
// O(N) Space complexitys