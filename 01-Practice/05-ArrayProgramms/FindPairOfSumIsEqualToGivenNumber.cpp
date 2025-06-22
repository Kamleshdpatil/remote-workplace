/*
    How do you find all pairs of an 
    integer array whose sum is equal to a given number?
*/

#include<iostream>
#include<stdlib.h>

using namespace std;

void FindPairOfSumNumber(int *arr, int n, const int Sum)
{
    int pickNum = 0;

    for(int i = 0; i < n; i++)
    {
        pickNum = arr[i];
        for(int j = i + 1; j < n; j++)
        {
            if(pickNum + arr[j] == Sum)
            {
                cout<<"pickNum: "<<pickNum<<" + "<<arr[j] << " = "<<pickNum + arr[j];
                cout<<endl;
            }
        }
    }
}

void recurFindPairOfSumNumber(int index, int *arr, int n, const int Sum)
{
    int pickNum = arr[index];
    if(index < n)
    {
        for(int j = index + 1; j < n; j++)
        {
            if(pickNum + arr[j] == Sum)
            {
                cout<<"pickNum: "<<pickNum<<" + "<<arr[j] << " = "<<pickNum + arr[j];
                cout<<endl;
                //return;
            }
        }
    }
    else
        return;
    
    recurFindPairOfSumNumber(index+1, arr, n, Sum);
}

int main(void)
{
    void DisplayArray(int*, int);

    int arr[] = {1, 2, -5, 5, 50, 3, 4, 8, 99, 98, 59, 75, 25, 41};
    int n = sizeof(arr) / sizeof(arr[0]);
    int Sum = 0;

    cout<<"Enter Number for sum: ";
    cin>>Sum;

    DisplayArray(arr, n);
    FindPairOfSumNumber(arr, n, Sum);

    recurFindPairOfSumNumber(0, arr, n, Sum);

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
