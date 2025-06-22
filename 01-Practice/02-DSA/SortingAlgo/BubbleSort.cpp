// CPP Program to demonstrate the use of copy constructor 
#include <iostream> 
#include <stdio.h> 
#include<algorithm>

using namespace std; 

void BubbleSort(int*, int); 
void BubbleSortOptimal(int*, int); 

// Driver code 
int main() 
{ 
    int* Arr = NULL;
    int size =0;
    cout<<"Enter the size of an array: ";
    cin>> size;

    Arr = new int(size);

    cout<<"\nEnter "<<size<<" array elements: ";
    for(int i = 0; i < size; i++)
    {
        cin>>Arr[i];
    }
    
    cout<<"\nCalling Bubble Sort:---"<<endl;
    //BubbleSort(Arr, size);
    BubbleSortOptimal(Arr, size);

    cout<<"\nOutput: ";
    for(int i = 0; i < size; i++)
    {
        cout<<Arr[i]<<" ";
    }

    delete Arr;
    Arr = NULL;
	return 0; 
}

void BubbleSort(int* brr, int size)
{
    if(!(size > 1))
        return;
    for(int i = size - 1; i > 0; i--)
    {
        for(int j =0; j < i; j++)
        {
            if(brr[j] > brr[j+1])
                swap(brr[j], brr[j+1]);
        }
        cout<<"runs\n";
    }

    // Time: O(N^2)
} 

void BubbleSortOptimal(int* brr, int size)
{
    if(!(size > 1))
        return;
    for(int i = size - 1; i > 0; i--)
    {
        int swapped = 0;
        for(int j =0; j < i; j++)
        {
            if(brr[j] > brr[j+1])
            {
                swap(brr[j], brr[j+1]);
                swapped = 1;
            }
        }
        if(swapped == 0)
            break;
        cout<<"runs\n";
    }

    // Time: O(N^2)
} 

