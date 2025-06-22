/*
    How do you find all pairs of an 
    integer array whose sum is equal to a given number?
*/

#include<iostream>
#include<stdlib.h>

using namespace std;

void FindMultipleDuplicateNumbers(int *arr, int n)
{
    int pickNumCount = 0;
    int pickNum = 0;

    for(int i = 0; i < n; i++)
    {
        pickNum = arr[i];
        cout<<"\npickNum: "<<pickNum<<"\n"<<endl;
        for(int j = 0; j < n; j++)
        {
            if(pickNum == arr[j])
            {
                pickNumCount++;
                //cout<<arr[i]<<"\t"<<"Count : "<<pickNumCount;
            }
        }
        cout<<"Count : "<<pickNumCount;
        cout<<"\n--------------------------------------------------"<<endl;
        pickNumCount = 0;
    }
}

void recurFindMultipleDuplicateNumbers(int index, int *arr, int n)
{
    
}

int main(void)
{
    void DisplayArray(int*, int);

    //int arr[] = {1, 98, -5, 5, 50, 3, 4, 8, 99, 98, 59, 3, 75, 25, 41, 1, 98, -5, 5, 50, 3, 4, 8, 99, 98, 59, 3, 75, 25, 41};
    int arr[] = {1, 2, 3, 3, 2, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    DisplayArray(arr, n);
    FindMultipleDuplicateNumbers(arr, n);

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
