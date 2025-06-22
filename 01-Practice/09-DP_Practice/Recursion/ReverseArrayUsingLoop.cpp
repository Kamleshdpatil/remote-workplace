#include<stdio.h>
#include<iostream>

using namespace std;

int main(void)
{
    void DisplayReverse(int*, int);
    void Swap(int*, int*);

    int Arr[] = {11, 2, 3, 4 , 2, 12, 25};

    int size = sizeof(Arr)/sizeof(Arr[0]);

    DisplayReverse(Arr, size);

    return(0);
}

void DisplayReverse(int *Brr, int size)
{
    void Swap(int*, int*);
    int *fPtr = &Brr[0];
    int *lPtr = &Brr[size-1];

    for(int i = 0; i<size/2; i++, ++fPtr, --lPtr)
    {
        if(fPtr != lPtr)
            Swap(fPtr, lPtr);
    }
    
    for(int i = 0; i< size; i++)
    {
        printf("%d\t", Brr[i]);
    }
}

void Swap(int *el1, int *el2)
{
    int temp = *el1;
    *el1 = *el2;
    *el2 = temp;
}
