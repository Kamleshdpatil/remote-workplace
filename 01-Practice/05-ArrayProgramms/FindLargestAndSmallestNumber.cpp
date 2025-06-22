#include<iostream>
#include<stdlib.h>

using namespace std;

int PrintLargestNumber(int *arr, int n)
{
    cout<<"\nPrintLargestNumber "<<endl;
    int max = 0; //
    for(int i = 0; i < n; i++)
    {
        max = arr[i];                 // 1
        for(int j = 0; j < n; j++)    // j = 1, 
        {
            if(arr[j] > max)          // arr[0] = 92, > 1 yes
            {
                max = arr[j];
            }
        }
    }
    return(max);
}

int recurPrintLargestNumber(int index, int *arr, int n)
{
    cout<<"\nrecurPrintLargestNumber "<<endl;
    int max = arr[index];
    for(int j = 0; j < n; j++)
    {
        if(arr[j] > max)
        {
            max = arr[j];
        }
    }
    return(max);
    return(recurPrintLargestNumber(index+1, arr, n));
}

int PrintSmallestNumber(int *arr, int n)
{
    cout<<"\nPrintSmallestNumber "<<endl;
    int min = 0; //
    for(int i = 0; i < n; i++)
    {
        min = arr[i];                 // 1
        for(int j = 0; j < n; j++)    // j = 1, 
        {
            if(arr[j] < min)          // arr[0] = 92, > 1 yes
            {
                min = arr[j];
            }
        }
    }
    return(min);
}

int recurPrintSmallestNumber(int index, int *arr, int n)
{
    cout<<"\nrecurPrintSmallestNumber "<<endl;
    int min = arr[index];
    for(int j = 0; j < n; j++)
    {
        if(arr[j] < min)
        {
            min = arr[j];
        }
    }
    return(min);
    return(recurPrintSmallestNumber(index+1, arr, n));
}

void DisplayArray(int* arr, int size)
{
    for(auto itr = 0; itr < size; itr++)
    {
        cout<<arr[itr]<<" ";
    }
    cout<<endl;
}
int main(void)
{
    int arr[] = {100, 99, 92, 33, 45, 93, 10, 5};

    int n = sizeof(arr) / sizeof(arr[0]);
    DisplayArray(arr, n);
    cout<<"Largest Number: "<<PrintLargestNumber(arr, n);
    //recurPrintLargestNumber(0, arr, n);
    cout<<"Largest Number: "<<recurPrintLargestNumber(0, arr, n);
    cout<<endl;
    cout<<"Smallest Number: "<<PrintSmallestNumber(arr, n);
    //recurPrintLargestNumber(0, arr, n);
    cout<<"Smallest Number: "<<recurPrintSmallestNumber(0, arr, n);
    return(0);
}
