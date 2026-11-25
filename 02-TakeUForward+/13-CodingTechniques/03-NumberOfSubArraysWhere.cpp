#include<iostream>
#include<vector>

using namespace std;

// Two pointer - Sliding window
int numberOfSubArray_SumEqualTo_K(vector<int>& nums, int k)
{
    int n = nums.size();
    int left = 0, right = 0;
    int count = 0;
    int sum = 0;

    while(right < n)
    {
        sum += nums[right];
        while(left <= right && sum > k){
            sum -= nums[left++];
        }
        if(sum == k)
        {
            count++;
        }
        right++;
    }

    return count;
}


int main()
{
    vector<int> vecNums = {-1, 2, 3, 3, 4, 2, 6, 1, 2,2,8, 5, 1, 6};
    int k = 12;

    int iAns = numberOfSubArray_SumEqualTo_K(vecNums, k);
    cout<<"Answer: "<<iAns<<"\n";

    return(0);
}
