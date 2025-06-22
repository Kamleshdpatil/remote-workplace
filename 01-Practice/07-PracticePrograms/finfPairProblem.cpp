#include<iostream>

using namespace std;

int countFindPairOfSum(int arr[], int n, int target);

int main(void)
{
    int arr[] = {1, 4, 7, 6, 8, 7, 1, 5, 3, 1, 7, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 0;

    cout<<"Enter target number: "<<endl;
    cin>>target;

    int count = countFindPairOfSum(arr, size, target);
    if(count > 0)
    {
        cout<<"\ncount of pairs: "<<count<<endl;
    }

    return(0);
}

int countFindPairOfSum(int arr[], int size, int target)
{
    int i, j;
    int count=0;
    for(i=0; i<size-1; i++)
    {
        for(j = i+1; j<size; j++)
        {
            if((arr[i] + arr[j]) == target)
            {
                cout<<"\nPair of array element which having sum "<<target<<" :"<<arr[i]<<" and "<<arr[j]<<endl;
                count++;
            }
        }
    }

    if(count== 0)
    {
        cout<<"Does not match any pair"<<endl;
    }
    return count;
}

