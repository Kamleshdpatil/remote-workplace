#include<iostream>

using namespace std;

int findDuplicate(int *Arr, int n)
{
    int i = 0, j = 0;
    bool isDuplicate = false;

    for(i =0; i<n; i++)
    {
        int k = Arr[i]; //0
        for(j = i+1; j<n; j++)
        {
            if(k == Arr[j])
            {
                isDuplicate = true;
                return k;
            }
        }
    }

    if(isDuplicate == false)
    {
        return(-1);
    }
}

int main(void)
{
    //int Arr[] = { 0, 50, 10, 40,50, 14, 10, 60, 11, 1, 10};
    //int Arr[] = { 1, 2, 3, 4, 4 };
    int Arr[] = { 1, 2, 3, 4, 2 };
    int n = sizeof(Arr)/sizeof(Arr[0]);

    int iRet = findDuplicate(Arr, n);
    cout<<"This is duplicate no.: "<<iRet<<endl;
    return(0);
}
