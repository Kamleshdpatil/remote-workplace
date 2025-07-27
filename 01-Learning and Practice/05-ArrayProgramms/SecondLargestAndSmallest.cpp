#include<vector>
#include<iostream>

using namespace std;
    
vector<int> getSecondOrderElements(int n, vector<int> a) {
    // Write your code here.
    int largest = a[0];
    int secondLargest = -1;
    int smallest = a[0];
    int secondSmallest = -1;
    for(int i = 0; i < n; i++)  // to find largest and smallest.
    {
        if(a[i] > largest)
        {
            largest = a[i];
        }
        if(a[i] < smallest)
        {
            smallest = a[i];
        }
    }
    // largest = 5
    // smallest = 1
    secondSmallest = largest;
    for (int i = 0; i < n; i++) // to find second largest and second smallest.
    {   //1, 2, 3
        if(a[i] != largest && a[i] > secondLargest)
        {
            secondLargest = a[i];
        }

        if(a[i] != smallest && a[i] < secondSmallest)
        {
            secondSmallest = a[i];
        }
    }
    
    return {secondLargest, secondSmallest};
}


vector<int> getSecondOrderElementsOptimal(int n, vector<int>& a) 
{
    // Write your code here.
    int largest = a[0];
    int secondLargest = -1;
    int smallest = a[0];
    int secondSmallest = INT_MAX;
    for(int i = 0; i < a.size(); i++)  // to find largest and smallest.
    {
        if(a[i] > largest)
        {
            secondLargest = largest;
            largest = a[i];
        }
        else if(a[i] < largest && a[i] > secondLargest)
        {
            secondLargest = a[i];
        }

        if(a[i] < smallest)
        {
            secondLargest = smallest;
            smallest = a[i];
        }
        else if(a[i]>smallest && a[i]<secondSmallest)
        {
            secondSmallest = a[i];
        }
    }

    return {secondLargest, secondSmallest};
}


int main()
{
    vector<int> res;
    vector<int> a = {1,2,3,4,5, 7, 7, 5};

    res = getSecondOrderElementsOptimal(a.size(), a);

    for(int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<" ";
    }
    return(0);
}