#include<iostream>

using namespace std;

// int sumOfArray(int arr[], int size)
// {
//     int result = 0;
//     for(int i = 0; i < size; i++)
//     {
//         result = result + arr[i];
//     }
//     return result;
// }

int sumOfArray(int* arr, int size)
{
    int result = 0;
    for(int i = 0; i < size; i++)
    {
        result = result + arr[i];
    }
    return result;
}

int main()
{
    // int iArr[] = {10, 30, 50, 70, 90};

    // cout<<"Sum of Array: "<<sumOfArray(iArr, sizeof(iArr)/sizeof(int));

    cout<<"Enter the size of Array: ";
    int size = 0;
    cin>>size;
    cout<<endl;

    int* pArr = new int[size];

    cout<<"Enter numbers and add space: ";
    for(int i = 0; i < size; i++)
    {
        cin>>pArr[i];
    }

    cout<<"Sum of Array: "<<sumOfArray(pArr, size);

    delete[] pArr;
    return(0);
}
