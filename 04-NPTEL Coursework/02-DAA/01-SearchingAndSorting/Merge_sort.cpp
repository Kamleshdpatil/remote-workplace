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

void merge(int arr[], int left, int mid, int right)
{
    int n = right - left + 1;
    int *brr = new int[n];
    int l = left;
    int r = mid + 1;
    int i = 0;

    while (l <= mid && r <= right)
    {
        if(arr[l] < arr[r])
        {
            brr[i] = arr[l];
            i++;
            l++;
        }else{
            brr[i] = arr[r];
            i++;
            r++;
        }
    }
    while (l <= mid)
    {
        brr[i] = arr[l];
        i++;
        l++;
    }
    while (r <= right)
    {
        brr[i] = arr[r];
        i++;
        r++;
    }

    for (i = 0; i < n; ++i)
        arr[left + i] = brr[i];
    delete [] brr;
}

void merge_sort(int arr[], int left, int right)
{
    if(left >= right)
        return;
    else
    {
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        // Merge two arrays
        merge(arr, left, mid, right);
    }
}


int main()
{
    // int arr[]={74, 32, 89, 55, 21, 64};
    int arr[]={43, 32, 22, 78, 63, 57, 91, 13, 10};

    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Before Sort: ";
    Display(arr, size);

    merge_sort(arr, 0, size-1);

    cout<<"After Sort: ";
    Display(arr, size);

    return(0);
}
