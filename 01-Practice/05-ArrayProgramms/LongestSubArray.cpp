#include<vector>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;

int LengthOfLongestSubArray(vector<int> &arr, int n, int k)
{
    int sum = 0;
    int longest = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            sum = sum + arr[j];
            if(sum == k)
            {
                longest = max(longest, j-i+1);
            }
        }
        sum = 0;
    }
    return(longest);
}


int LengthOfLongestSubArrayOptimal(vector<int> &arr, int n, int k)
{
    // Hashing
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;

    for(int i = 0; i < n; i++)
    {
        sum +=arr[i];
        if(sum == k)
            maxLen = max(maxLen, i+1);
        long long rem = sum - k;
        if(preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        preSumMap[sum] = i;
    }
    return(maxLen);
}

int LengthOfLongestSubArrayTwoPointerSolution(vector<int> &arr, int n, int k)
{
    int left = 0;
    int right = 0;
    long long sum = arr[0];
    int maxLen = 0;

    while (right < n)
    {
        while (left <= right && sum > k)
        {
            sum -=arr[left];
            left++;
        }
        if(sum == k)
        {
            maxLen = max(maxLen, right-left + 1);
        }
        
        right++;
        if(right <n)
            sum += arr[right];
    }
    return(maxLen);
}

int main(void)
{
    int k = 6;
    vector<int> vrr = {1, 1, 0,2, 1, 1, 2, 3, 0, 1, 1, 4, 2, 3};
    cout<<LengthOfLongestSubArray(vrr, vrr.size(), k);
    cout<<endl;
    cout<<LengthOfLongestSubArrayOptimal(vrr, vrr.size(), k);
    cout<<endl;
    cout<<LengthOfLongestSubArrayTwoPointerSolution(vrr, vrr.size(), k);

    return(0);
}