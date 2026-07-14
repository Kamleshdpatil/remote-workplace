#include<iostream>

using namespace std;

bool isArraySorted(int* arr, int size)
{
    for(int i = 1; i < size; i++)
    {
        if(arr[i] < arr[i-1])
            return false;
    }
    return true;
}

int main()
{
    // int iArr[] = {10, 30, 1, 3, 5, 7, 9, 50, 70, 90, 100};
    int iArr[] = {10, 30, 50, 70, 90, 100};

    bool bRet = isArraySorted(iArr, sizeof(iArr)/sizeof(int));
    if(bRet)
        cout<<"Sorted !!"<<endl;
    else
        cout<<"Not Sorted !!"<<endl;

    return(0);
}
