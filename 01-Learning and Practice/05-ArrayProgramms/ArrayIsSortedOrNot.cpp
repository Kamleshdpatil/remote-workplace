#include<vector>
#include<iostream>

using namespace std;

bool isArraySorted(int n, vector<int>& a)
{
    for(int i = 1; i < n; i++)
    {
        if(a[i] >= a[i-1])
            continue;
        else
            return false;
    }
    return true;
}

int main()
{
    vector<int> a = {2, 1, 2, 2, 3, 4, 5};
    vector<int> a1 = {1,2, 21, 3, 4, 5};

    bool bRet = isArraySorted(a.size(), a);

    if(bRet)
        cout<<"Sorted!";
    else    
        cout<<"Not sorted!";

    cout<<endl;
    cout<<endl;
    bRet = isArraySorted(a1.size(), a1);

    if(bRet)
        cout<<"Sorted!";
    else    
        cout<<"Not sorted!";
    return(0);
}