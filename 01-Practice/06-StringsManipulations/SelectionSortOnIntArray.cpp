#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

template<typename MyType>
void Swap(MyType*, MyType*);

template<typename MyType>
void selection_sort(MyType *brr, int size) // find min and swap to left
{
    for(int i = 0; i<= size-2; i++)
    {
        int minimum = i;
        for(int j = i; j <= size-1; j++)
        {
            if(brr[j] < brr[minimum])
                minimum = j;
        }
        Swap(&brr[minimum], &brr[i]);
    }
}

template<typename MyType>
void bubble_sort(MyType *brr, int size) // find max and do adjustant swapping to right
{
    for(int i = size-1; i>=1; i--)
    {
        for(int j = 0; j <= i-1; j++)
        {
            if(brr[j] > brr[j+1])
                Swap(&brr[j], &brr[j+1]);
        }
    }
}

template<typename MyType>
void insertion_sort(MyType *brr, int size) // adjustant swapping
{
    int j = 0;
    printf("\n");
    for(int i = 0; i<=size-1; i++)
    {
        j = i;
        while (j>0 && brr[j-1]>brr[j])
        {
            Swap(&brr[j], &brr[j-1]);
            
            j--;
        }
    }
}

template<typename MyType>
void Swap(MyType *i1, MyType *i2)
{
    MyType temp = *i1;
    *i1 = *i2;
    *i2 = temp;
}

int main()
{
 
    // Get the array of names to be sorted
    int arr1[]= {12, 11, 13, 5, 6};
    float arr2[]= { 12.0f, 10.12f, 2.4f, 25.0f, 11.23f, 23.21f, 56.0f, 21.2f };
 
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int i;
 
    // Print the given names
    printf("Given array is\n");
    for (i = 0; i < n; i++)
        printf("%d: %d\t", i, arr1[i]);
 
    // Sort the given integer array.
    //sort(arr1, n);
    //selection_sort<float>(arr2, n);
    insertion_sort<int>(arr1, n);
 
    // Print the sorted names
    // printf("\nSorted array is\n");
    // for (i = 0; i < n; i++)
    //     printf("%d: %d\t", i, arr1[i]);
 
    return 0;
}