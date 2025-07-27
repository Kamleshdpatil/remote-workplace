#include<iostream>
#include<stdlib.h>

using namespace std;

void markRow(int (*arr)[4], int i, int rows)
{
    for(int j = 0; j < rows; j++)
    {
        if(i != 0)
        {
            if(arr[i][j] != 0)
                arr[i][j] = -1;
        }
    }
}

void markColumns(int (*arr)[4], int j, int columns)
{
    for(int i = 0; i < columns; i++)
    {
        if(j != 0)
        {
        if(arr[i][j] != 0)
            arr[i][j] = -1;
        }
    }
}

void SetMatrixZeros(int (*arr)[4], int rows, int columns)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            if(arr[i][j] == 0)
            {
                markRow(arr, i, rows);
                markColumns(arr, j, columns);
            }
        }
        cout<<endl;
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            if(arr[i][j] == -1)
            {
                arr[i][j] = 0;
            }
        }
        cout<<endl;
    }
}

void Display(int (*arr)[4], int rows, int columns)
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout<<arr[i][j]<<"   ";
        }
        cout<<endl;
    }
}

void SetMatrixZerosOptimal(int (*arr)[4], int rows, int columns)
{
    int col[4] = {0};
    int row[4] = {0};

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            if(arr[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            if(row[i] || col[j])
            {
                arr[i][j] = 0;
            }
        }
    }
}

int main(void)
{
    int arr[4][4] = {1, 1, 1, 1, 1, 0, 0, 1,1, 1, 0, 1, 1, 1, 1, 1};

    int rows = sizeof(arr) / sizeof(arr[0]);
    int columns = sizeof(arr[0]) / sizeof(arr[0][0]);

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    SetMatrixZerosOptimal(arr, rows, columns);
    Display(arr, rows, columns);

    return(0);
}
