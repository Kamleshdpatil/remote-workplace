#include<iostream>
#include<vector>

using namespace std;
static int i = 0;
void fun(int index, int* arr, int s, int sum, vector<int>& vecInt , int n)
{
    void Display(vector<int>&);
    if(index == n)
    {
        i++;
        if(sum == s)
        {
            Display(vecInt);
        }
        return;
    }

    // Take or pick the particular index into the subsequence
    
    vecInt.push_back(arr[index]);
    s = s + arr[index];
    fun(index+1, arr, s, sum, vecInt, n);

    vecInt.pop_back();
    s = s - arr[index];

    fun(index+1, arr, s, sum, vecInt, n);

    // Not pick, or not take condition, this element is not added to your sub sebsequences.
}

void Display(vector<int>& vecInt)
{
    for(auto itr:vecInt)
    {
        cout<<itr<<" ";
    }
    if(vecInt.size() == 0)
    {
        cout<<"{}";
    }
    cout<<endl;
}

int main(void)
{
    int arr[] = {0, 1, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 2;
    vector<int> vecInt;

    fun(0, arr, 0, sum, vecInt, n);
    cout<<"\nCout: "<<i;
    return(0);
}
