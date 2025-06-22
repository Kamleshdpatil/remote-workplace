#include<iostream>
#include<stdlib.h>

using namespace std;

void PrintMissingNumber(int *arr, int n)
{
    for(int i = 0; i<n-1; i++)
    {
        if((arr[i] + 1) != arr[i+1])
        {
            cout<<"\n\nMissing Number: "<<arr[i]+1<<endl;
            break;
            return;
        }
    }
}

void recurPrintMissingNumber(int index, int *arr, int n)
{
    if((arr[index] + 1) != arr[index+1])
    {
        cout<<"\n\nMissing Number: "<<arr[index]+1<<endl;
        return;
    }
    recurPrintMissingNumber(index+1, arr, n);
}

int main(void)
{
    int arr[100]={0};

    int arr1[] = {2, 3, 4, 5, 6, 8, 9, 10};

    int n = sizeof(arr1) / sizeof(arr1[0]);

    for(int i = 0; i <= 90; i++)
    {
        arr[i] = i+1;
    }

    for(int i = 92; i < 100; i++)
    {
        arr[i] = i+1;
    }

    // for(int i = 0; i < 100; i++)
    // {
    //     if(i+1 != 92)
    //     {
    //      cout<<arr[i]<<" ";
    //     }
    // }
    // PrintMissingNumber(arr, 100);
    // PrintMissingNumber(arr1, n);
    recurPrintMissingNumber(0, arr1, n);
    return(0);
}
