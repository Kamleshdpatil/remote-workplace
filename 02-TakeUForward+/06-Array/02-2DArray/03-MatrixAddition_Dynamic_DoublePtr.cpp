#include<iostream>

using namespace std;

int main()
{
    int rows = 3;
    int cols = 3;
    
    // Step 1: Allocation of array pointers (Rows)
    int* arr = new int[rows * cols];

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            arr[i * cols +j] = (i * cols + j) + 1;
        }
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout<<arr[i * cols +j]<<" ";
        }
        cout<<"\n";
    }

    // Clean up memory
    delete[] arr;

    return(0);
}
