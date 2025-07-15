#include <iostream>
#include <stdio.h>
using namespace std;

#define NUM_ROWS 5
#define NUM_COLUMNS 3

#define NUM_DEPTH 2

int main(void)
{
    int Array_2D[NUM_ROWS][NUM_COLUMNS] = {
        {1, 2, 3},
        {2, 3, 4},
        {3, 4, 5},
        {4, 5, 6},
        {2, 3, 4}};
    int Array_1D_For_2D[NUM_ROWS * NUM_COLUMNS];

    // In-line Initilization
    int Array_3D[NUM_ROWS][NUM_COLUMNS][NUM_DEPTH] = {
        {{9, 18}, {27, 36}, {45, 54}},
        {{8, 16}, {24, 32}, {40, 48}},
        {{7, 14}, {21, 28}, {35, 42}},
        {{6, 12}, {18, 21}, {30, 36}},
        {{5, 10}, {15, 20}, {25, 30}}};

    int Array_1D_For_3D[NUM_ROWS * NUM_COLUMNS * NUM_DEPTH];

    /*
    // *** Display of 2D Array ***
    printf("\n*** Display of 2D Array ***\n");
    printf("Two-Dimensional (2D) Array of Integers: \n\n");
    for(int i = 0; i < NUM_ROWS; i++)
    {
        printf("***** Row %d ****\n", (i + 1));
        for(int j = 0; j < NUM_COLUMNS; j++)
        {
            printf("iArray_2D[%d][%d] = %d\n", i, j, Array_2D[i][j]);
        }
        printf("\n\n");
    }

    for(int i = 0; i < NUM_ROWS; i++)
    {
        for(int j = 0; j < NUM_COLUMNS; j++)
        {
            //cout<<"(i * NUM_COLUMNS ) +j: "<<(i * NUM_COLUMNS ) +j<<endl;
            Array_1D_For_2D[(i * NUM_COLUMNS ) +j] = Array_2D[i][j];
        }
    }

    printf("One-Dimensional (1D) Array of Integers: \n\n");
    for(int i = 0; i < (NUM_ROWS * NUM_COLUMNS); i++)
    {
        printf("Array_1D_For_3D[%d]= %d\n", i, Array_1D_For_2D[i]);
    }
    printf("\n\n"); */

    for (int i = 0; i < NUM_ROWS; i++)
    {
        for (int j = 0; j < NUM_COLUMNS; j++)
        {
            for (int k = 0; k < NUM_DEPTH; k++)
            {
                // cout << "(i * NUM_COLUMNS * NUM_DEPTH) " << (i * NUM_COLUMNS * NUM_DEPTH) << endl;
                // cout << "(j * NUM_DEPTH) + k: " << (j * NUM_DEPTH) + k << endl;

                // cout << "(i * NUM_COLUMNS * NUM_DEPTH)+ (j * NUM_DEPTH) + k: " << (i * NUM_COLUMNS * NUM_DEPTH) + (j * NUM_DEPTH) + k << endl;

                Array_1D_For_3D[(i * NUM_COLUMNS * NUM_DEPTH) + (j * NUM_DEPTH) + k] = Array_3D[i][j][k];
            }
        }
    }

    // ***** DISPLAY 1D ARRAY *****
    printf("\n\n");
    printf("Element In The 1D Array: \n");
    for (int i = 0; i < (NUM_ROWS * NUM_COLUMNS * NUM_DEPTH); i++)
    {
        printf("Array_1D_For_3D[%d] = %d\n", i, Array_1D_For_3D[i]);
    }

    return (0);
}
