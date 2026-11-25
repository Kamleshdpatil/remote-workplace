#include<iostream>

using namespace std;

void sumAndShow(int* Arr, int* Brr, int* Sum, int& rows, int& cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            Sum[i * cols + j] = Arr[i * cols + j] + Brr[i * cols + j];
        }
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout<<Sum[i * cols + j]<<" ";
        }
        cout<<"\n";
    }
}

template<size_t ROWS, size_t COLS>
void sumAndShowTemplate(int (&Arr)[ROWS][COLS], int (&Brr)[ROWS][COLS], int (&Sum)[ROWS][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            Sum[i][j] = Arr[i][j] + Brr[i][j];
        }
    }

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            cout<<Sum[i][j]<<" ";
        }
        cout<<"\n";
    }

}

int main()
{
    constexpr int rows = 3;
    constexpr int cols = 3;
    
    int Arr[rows][cols] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int Brr[rows][cols] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    int Sum[rows][cols];

    // for(int i = 0; i < rows; i++)
    // {
    //     for(int j = 0; j < cols; j++)
    //     {
    //         Sum[i][j] = Arr[i][j] + Brr[i][j];
    //     }
    // }

    // for(int i = 0; i < rows; i++)
    // {
    //     for(int j = 0; j < cols; j++)
    //     {
    //         cout<<Sum[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    // Calling function with flattened array type
    // sumAndShow((int*)Arr, (int*)Brr, (int*)Sum, rows, cols);
    sumAndShowTemplate(Arr, Brr, Sum);

    return(0);
}
