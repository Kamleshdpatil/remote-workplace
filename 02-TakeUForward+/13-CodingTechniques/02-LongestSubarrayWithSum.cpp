#include<iostream>
#include<vector>

using namespace std;

// Genrate all possible arrays
int brute_findMaximumLenOfSubArraySum(vector<int>& nums, int k)
{
    int n = nums.size()-1;
    int left = 0, right = k-1;
    int maxLen = 0;

    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = i; j < n; j++)
        {
            sum += nums[j];
            if(sum <= k)
                maxLen = max(maxLen, j-i+1);
            else if(sum > k)
                break;
        }
    }

    return maxLen;
}

// Two pointer - Sliding window
int better_findMaximumLenOfSubArraySum(vector<int>& nums, int k)
{
    int n = nums.size()-1;
    int left = 0, right = 0;
    int maxLen = 0;
    int sum = 0;

    while(right < n)
    {
        sum += nums[right];
        while(sum > k){
            sum -= nums[left++];
        }
        if(sum <= k)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
    }

    return maxLen;
}

// Two pointer - Sliding window
int optimal_findMaximumLenOfSubArraySum(vector<int>& nums, int k)
{
    int n = nums.size()-1;
    int left = 0, right = 0;
    int maxLen = 0;
    int sum = 0;

    while(right < n)
    {
        sum += nums[right];
        if(sum > k){ // changed loop to if. Instead shrinking less than the max len we can shrink by only one index at a time
            sum -= nums[left++];
        }
        if(sum <= k)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
    }

    return maxLen;
}

int main()
{
    vector<int> vecNums = {2, 5, 1, 10, 5, 10};
    int k = 20;

    // int iAns = brute_findMaximumLenOfSubArraySum(vecNums, 4);
    // int iAns = better_findMaximumLenOfSubArraySum(vecNums, k);
    int iAns = optimal_findMaximumLenOfSubArraySum(vecNums, k);

    cout<<"Answer: "<<iAns<<"\n";

    return(0);
}
