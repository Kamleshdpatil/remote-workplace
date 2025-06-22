#include<iostream>
#include<algorithm>

using namespace std;

bool hasArrayTwoCandidates(int* A, int arr_size, int Sum)
{
    sort(A, A + arr_size);
    int l = 0, r = arr_size-1;
    for(int i = 0; i< arr_size; i++)
    {
        if(A[l] + A[r] > Sum)
            r--;
        else
            l++;
        if(A[l] + A[r] == Sum)
            return true;
    }
    return false;
}

int main()
{
    int A[] = { 1, 4, 45, 6, 10, -8 };
    int n = 16;
    int arr_size = sizeof(A) / sizeof(A[0]);
 
    // Function calling
    if (hasArrayTwoCandidates(A, arr_size, n))
        cout << "Yes";
    else
        cout << "No";
 
    return 0;
}