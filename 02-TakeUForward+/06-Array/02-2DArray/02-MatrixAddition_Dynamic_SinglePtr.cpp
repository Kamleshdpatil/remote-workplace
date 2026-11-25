#include<iostream>

using namespace std;

int main()
{
    int rows = 3;
    int cols = 3;
    
    // Step 1: Allocation of array pointers (Rows)
    int** arr = new int*[rows];

    // Step 2: Allocation for each row (Columns)
    for(int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            arr[i][j] = (i * cols + j) + 1;
        }
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }


    // Clean up memory
    for(int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    return(0);
}
