#include<iostream>
#include<stdio.h>

using namespace std;

void f(int i, int *fPtr, int n)
{
    if(i >= n/2)
        return;

    swap(*(fPtr+i), *(fPtr + (n-i-1)));
    
    f(i+1, fPtr+i, n);
}

int main(void)
{
    int n=5;
    int arr[5] = {10, 20, 50, 40, 60};
    //for(int i = 0; i<n; i++) cin>>arr[i];
    f(0, arr, n);
    cout<<endl;
    for(int i = 0; i<n; i++) cout<<arr[i]<<" ";
    return(0);
}
