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

void Insert(int arr[], int start)
{
    int nextPos = start;
        while(nextPos > 0 && (arr[nextPos] < arr[nextPos - 1])){
            swap(arr[nextPos], arr[nextPos-1]);
            nextPos = nextPos - 1;
        }
}

void Insertion_sort(int arr[], int size)
{
    for(int i = 1; i < size; i++)
    {
        Insert(arr, i);
    }
}

void Insertion_sort_recursive(int arr[], int start, int size)
{
    if(start >= size-1)
        return;
    Insert(arr, start);
    return Insertion_sort_recursive(arr, start+1, size);
}

int main()
{
    int arr[]={74, 32, 89, 55, 21, 64};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Before Sort: ";
    Display(arr, size);

    // Insertion_sort(arr, size);
    Insertion_sort_recursive(arr, 0, size);

    cout<<"After Sort: ";
    Display(arr, size);

    return(0);
}
