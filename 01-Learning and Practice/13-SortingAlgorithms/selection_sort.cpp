#include<iostream>
#include<algorithm>

using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void selection_sort(int arr[], int len)
{
    for(int i = 0; i < len-1; i++){
        int minIdx = i;
        for(int j = i+1; j < len; j++){
            if(arr[j] < arr[minIdx]){
                minIdx = j;
            }
        }
        if(arr[minIdx] != arr[i]){
            cout<<"Swapping: "<<arr[minIdx]<<" and "<<arr[i]<<endl;
            swap(arr[minIdx], arr[i]);        
        }
    }
}
int main()
{
    int arr[]={22, 24, 57, 12, 10, 57, 58, 24, 22};
    // int arr[]={64, 25, 12, 22, 11};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout<<"Before sorting: ";
    for(int i = 0; i < len; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
    selection_sort(arr, len);
    cout<<"After sorting: ";
    for(int i = 0; i < len; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return(0);
}