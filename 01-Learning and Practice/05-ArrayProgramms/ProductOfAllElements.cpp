/*
    How do you find all pairs of an 
    integer array whose sum is equal to a given number?
*/

#include<iostream>
#include<stdlib.h>
#include<vector>

using namespace std;

void CreateProductOfArray(int *arr, int n, int *prodArray)
{
    void DisplayArray(int*, int);
    int mult = 1;

    prodArray = new int(n);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[j] != arr[i])
            {
                mult = mult * arr[j];
            }else
                continue;
        }
        prodArray[i] = mult;
        mult = 1;
    }

    int n1 = sizeof(prodArray) / sizeof(prodArray[0]);
    cout<<"\nprodArray"<<endl;
    DisplayArray(prodArray, n);

    if(prodArray)
    {
        delete[] prodArray;
    }
}

void recurCreateProductOfArray(int index, int *arr, int n)
{
    
}

int main(void)
{
    void DisplayArray(int*, int);

    int arr[] = {10, 3, 5, 6, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int prodArray[] = {0};

    DisplayArray(arr, n);
    CreateProductOfArray(arr, n, prodArray);

    return(0);
}

void DisplayArray(int* arr, int size)
{
    cout<<endl;
    for(auto itr = 0; itr < size; itr++)
    {
        cout<<arr[itr]<<" ";
    }
    cout<<endl;
}
