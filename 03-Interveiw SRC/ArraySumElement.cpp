#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


// Array - we need to find two values from that array which are the sume of given target.

int main(void)
{
    int arr[] = {10, 20, 30, 40, 50};
    int target = 70;
    int l = 0;
    int r = sizeof(arr)/sizeof(arr[0]) - 1;

    while (l < r) {
        if (arr[l] + arr[r] == target)
        {
            cout<<arr[l]<<" and "<<arr[r]<<endl;
            r--;
            //continue;
        }
        else if (arr[l] + arr[r] < target)
            l++;
        else // A[l] + A[r] > target
            r--;
    }
    
    // O(N2) )(N)
    
    return(0);
}