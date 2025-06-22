#include<iostream>
#include<algorithm>

using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void bubble_sort(int arr[], int len)
{
    bool swapped = false;
    for(int i = 0; i < len-1; i++){
        swapped = false;
        for(int j = 0; j < len-1; j++){
            if(arr[j] > arr[j+1]){
                if(arr[j+1] != arr[j]){
                    cout<<"Swapping: "<<arr[j+1]<<" and "<<arr[j]<<endl;
                    swap(arr[j+1], arr[j]);
                    swapped = true;     
                }
            }
        }
        if(!swapped){
            cout<<"Already sorted!!"<<endl;
            break;
        }
    }
}
int main()
{
    // int arr[]={22, 24, 57, 12, 10, 57, 58, 24, 22};
    // int arr[]={64, 25, 12, 22, 11};
    int arr[]={5, 10, 11, 12, 23, 9, 3};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout<<"Before sorting: ";
    for(int i = 0; i < len; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    bubble_sort(arr, len); // Sort the array
    cout<<endl;
    cout<<"After sorting: ";
    for(int i = 0; i < len; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return(0);
}