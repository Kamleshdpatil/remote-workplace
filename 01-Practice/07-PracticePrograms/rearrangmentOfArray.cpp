#include<iostream>

using namespace std;

int SortArray(int *Arr, int n)
{
    int k = 0;
    for(int i = 0 ; i<n; i++)
    {
        if(Arr[i] == 0)
        {
            Arr[k] = 0;
            k++;
        }
    }

    for(int i = k; i<n; i++)
    {
        Arr[i] = 1;
    }
    return(n-k);
}

int main(void)
{
    int Arr[] = { 0, 0, 1, 0, 1, 1, 0, 1, 0, 0 , 1, 1};
    int n = sizeof(Arr)/sizeof(Arr[0]);

    int iOneCount = SortArray(Arr, n);
    cout<<"\nCount of 1 is: "<<iOneCount<<"\n\n"<<endl;

    //Print array elements after sorting
    for(int i=0; i< n; i++)
    {
        printf("|%d| ", Arr[i]);
    }

    return (0);
}
