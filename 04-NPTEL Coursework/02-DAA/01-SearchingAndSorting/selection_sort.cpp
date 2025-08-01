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

void Selection_sort(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        int minIndex = i;
        for(int j = i+1; j < size; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        if(i != minIndex)
            swap(arr[minIndex], arr[i]);
    }
}

int main()
{
    int arr[]={74, 32, 89, 55, 21, 64};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Before Sort: ";
    Display(arr, size);

    Selection_sort(arr, size);

    cout<<"After Sort: ";
    Display(arr, size);



    return(0);
}
