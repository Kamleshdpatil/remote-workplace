#include<iostream>

using namespace std;

void Display(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout << endl;
}

void quick_sort(int arr[], int left, int right)
{
    if(left >= right) 
        return;
    
    int pivot = arr[left];
    int yellow = left + 1;

    for(int green = left + 1; green <= right; green++)
    {
        if(arr[green] <= pivot)
        {
            swap(arr[yellow], arr[green]);
            yellow++;
        }
    }
    int pivotIndex = yellow - 1;
    swap(arr[left], arr[pivotIndex]);

    // Recursive calls on left and right partitions
    quick_sort(arr, left, pivotIndex - 1); // before pivot
    quick_sort(arr, pivotIndex + 1, right); // After pivot
}


int main()
{
    // int arr[]={74, 32, 89, 55, 21, 64};
    int arr[]={43, 32, 22, 78, 63, 57, 91, 13, 10};

    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Before Sort: ";
    Display(arr, size);

    quick_sort(arr, 0, size-1);

    cout<<"After Sort: ";
    Display(arr, size);

    return(0);
}
