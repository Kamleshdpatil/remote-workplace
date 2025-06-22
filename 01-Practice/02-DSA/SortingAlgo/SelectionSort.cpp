// CPP Program to demonstrate the use of copy constructor 
#include <iostream> 
#include <stdio.h> 
#include<algorithm>

using namespace std; 

void SelectionSort(int*, int); 

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
    
    cout<<"\nCalling Selection Sort:---"<<endl;
    SelectionSort(Arr, size);

    cout<<"\nOutput: ";
    for(int i = 0; i < size; i++)
    {
        cout<<Arr[i]<<" ";
    }

    delete Arr;
    Arr = NULL;
	return 0; 
}

void SelectionSort(int* brr, int size)
{
    if(!(size > 1))
        return;
    int min = 0;
    for(int i = 0; i< size; i++)
    {
        min = i;
        for(int j = i; j < size; j++)
        {
            // 1. Find minimun 
            if(brr[j] < brr[min]) 
                min = j;
            // 2. Swap with min index
        }
        
        if(min != i)
            swap(brr[i], brr[min]);
        
        cout<<"runs\n";
    }

    // Time :  O(N^2)
    // Space: O(N)
} 
