#include<iostream>
#include<stdlib.h>

using namespace std;

void PrintDuplicateNumber(int *arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
                cout<<arr[i]<<" ";
            }
        }
    }
}

void recurPrintDuplicateNumber(int index, int *arr, int n)
{
    if(index>n)
    {
        return;
    }
    for(int j = index+1; j < n; j++)
    {
        if(arr[index] == arr[j])
            cout<<arr[index]<<" ";
    }

    recurPrintDuplicateNumber(index+1, arr, n);
}

int main(void)
{
    int arr1[] = {1, 2, 3, 4 ,3};
    //int arr1[] = {1, 2, 2, 32, 4, 5, 10, 6, 7, 8, 9, 10, 32};

    int n = sizeof(arr1) / sizeof(arr1[0]);


    for(int i = 0; i < n; i++)
    {
        cout<<arr1[i]<<" ";
    }

    
    cout<<"\n\nDuplicate numbers using PrintDuplicateNumber: ";
    PrintDuplicateNumber(arr1, n);
    cout<<"\n\nDuplicate numbers uisng recurPrintDuplicateNumber: ";
    recurPrintDuplicateNumber(0, arr1, n);
    return(0);
}
