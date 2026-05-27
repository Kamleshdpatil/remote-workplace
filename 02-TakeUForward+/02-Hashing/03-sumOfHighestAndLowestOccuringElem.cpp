#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int sumHighestAndLowestFrequency(vector<int>& nums) {
        int highFreq = INT_MIN;
    int lowFreq = INT_MAX;
    unordered_map<int, int> hash;

    for(int num : nums)
    {
        hash[num]++;
    }

    // Highest freq
    for(auto it : hash)
    {
        if(it.second > highFreq){
            highFreq = it.second;
        }
    }
    // Highest freq
    for(auto it : hash)
    {
        if(it.second < lowFreq){
            lowFreq = it.second;
        }
    }
    return (highFreq + lowFreq);
    }
};

// Optimal force aproach
int highestOccuringElement(int* nums, int size)
{
    int mostOccEle = -1;
    int maxCnt = 0;
    
    unordered_map<int, int> hashMap;
    for(int i = 0; i < size; i++)
    {
        hashMap[nums[i]]++;
        if(hashMap[nums[i]] > maxCnt)
        {
            maxCnt = hashMap[nums[i]];
            mostOccEle = nums[i];
        }else if(hashMap[nums[i]] == maxCnt && nums[i] < mostOccEle)
        {
            mostOccEle = nums[i];
        }
    }
    return mostOccEle;
}

// Optimal force aproach
int lowestOccuringElement(int* nums, int size)
{
    int lowestEle = -1;
    int minCnt = __INT_MAX__;
    
    unordered_map<int, int> hashMap;
    for(int i = 0; i < size; i++)
    {
        hashMap[nums[i]]++;
    }

    for(auto it : hashMap)
    {
        if(it.second < minCnt){
            minCnt = it.second;
            lowestEle = it.first;
        }else if(it.second == minCnt && it.first < lowestEle)
            lowestEle = it.first;
    }
    return lowestEle;
}

int main()
{ 
    int nums[] = {4, 4, 5, 5, 6, 7};

    int size = sizeof(nums)/sizeof(nums[0]);

    int highestEle = highestOccuringElement(nums, size);
    cout<<"Highest Occuring element: "<<highestEle<<endl;

    int lowestEle = lowestOccuringElement(nums, size);
    cout<<"Lowest Occuring element: "<<lowestEle<<endl;

    cout<<"Sum of lowest & highest occuring element from given array: "<<(highestEle+lowestEle)<<endl;

    return(0);
}
