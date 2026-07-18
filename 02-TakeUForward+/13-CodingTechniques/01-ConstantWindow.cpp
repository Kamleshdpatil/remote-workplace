#include<iostream>
#include<vector>

using namespace std;

int findMaximumSumOfK(vector<int>& nums, int k)
{
    int left = 0, right = k-1;
    int sum = 0;
    int maxSum = 0;
    int n = nums.size()-1;

    for(int i = 0; i < k; i++)
    {
        sum += nums[i];
    }

    while(right < n)
    {
        sum = sum - nums[left];
        left++;
        right++;
        sum = sum + nums[right];
        maxSum = max(sum, maxSum);
    }

    return max(sum, maxSum);
}

int main()
{
    vector<int> vecNums = {-1, 2, 3, 3, -1, 4, 5, -1};
    int k = 4;

    int iAns = findMaximumSumOfK(vecNums, k);
    cout<<"Answer: "<<iAns<<"\n";

    return(0);
}
