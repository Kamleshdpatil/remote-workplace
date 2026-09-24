#include<stdio.h>
#include<stdlib.h>

#define MAX1 5
#define MAX2 10

int main()
{
    int iPlanes;    // -4
    int iRows;      // -8
    int iColumns;   // -12
    int iCounter1;  // -16
    int iCounter2;  // -20
    int iCounter3;  // -24
    int arr[MAX1][MAX2][MAX2];

    printf("Enter value of planes, rows & columns(< %d, %d, %d):\t", MAX1, MAX2, MAX2);
    scanf("%d%d%d", &iPlanes, &iRows, &iColumns);

    for(iCounter1 = 0; iCounter1 < iPlanes; iCounter1++)
    {
        for(iCounter2 = 0; iCounter2 < iRows; iCounter2++)
        {
            for(iCounter3 = 0; iCounter3 < iColumns; iCounter3++)
            {
                printf("Enter [%d][%d][%d] value:\t", iCounter1, iCounter2, iCounter3);
                scanf("%d", &arr[iCounter1][iCounter2][iCounter3]);
            }
        }
        
    }

    printf("Entered elements are: \n");

    for(iCounter1 = 0; iCounter1 < iPlanes; iCounter1++)
    {
        for(iCounter2 = 0; iCounter2 < iRows; iCounter2++)
        {
            for(iCounter3 = 0; iCounter3 < iColumns; iCounter3++)
            {
                printf("[%d][%d][%d] value is:\t%d\n", iCounter1, iCounter2, iCounter3, arr[iCounter1][iCounter2][iCounter3]);
            }
        }
        
    }

    exit(0);
}
