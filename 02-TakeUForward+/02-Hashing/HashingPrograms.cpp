#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int mostFrequentSmallElement(vector<int>& nums)
{
    int mostFreq = -1;
    int element = -1;

    //// Option: 1  ////
    // unordered_map<int, int> hash;

    // for(int num : nums)
    // {
    //     hash[num]++;
    // }

    // for(auto it : hash)
    // {
    //     if(it.second > mostFreq){
    //         mostFreq = it.second;
    //         element = it.first;
    //     }else if (it.second == mostFreq && element > it.first){
    //         element = it.first;
    //     }
    // }

    //// Option: 2  ////
    int max = nums[0];
    for(int num : nums)
    {
        if(num > max)
            max = num;
    }

    int* hash = new int[max+1]();
    for(int num : nums)
    {
        hash[num]++;
    }

    for(int num : nums)
    {
        hash[num]++;
        if(hash[num] > mostFreq){
            mostFreq = hash[num];
            element = num;
        }else if(hash[num] == mostFreq && element > num){
            element = num;
        }
    }
    delete[] hash;

    return element;
}

int mostFrequentBigElement(vector<int>& nums)
{
    int mostFreq = -1;
    int element = -1;

    //// Option: 1  ////
    // unordered_map<int, int> hash;

    // for(int num : nums)
    // {
    //     hash[num]++;
    // }

    // for(auto it : hash)
    // {
    //     if(it.second > mostFreq){
    //         mostFreq = it.second;
    //         element = it.first;
    //     }else if (it.second == mostFreq && element < it.first){
    //         element = it.first;
    //     }
    // }

    //// Option: 2  ////
    int max = nums[0];
    for(int num : nums)
    {
        if(num > max)
            max = num;
    }

    int* hash = new int[max+1]();
    for(int num : nums)
    {
        hash[num]++;
    }

    for(int num : nums)
    {
        hash[num]++;
        if(hash[num] > mostFreq){
            mostFreq = hash[num];
            element = num;
        }else if(hash[num] == mostFreq && element < num){
            element = num;
        }
    }
    delete[] hash;

    return element;
}

int secondHighestOccuringElement(vector<int>& nums)
{
    int secMostFreq = -1;
    int mostFreq = -1;
    int element = -1;
    unordered_map<int, int> hash;

    for(int num : nums)
    {
        hash[num]++;
    }

    // Most frequent element
    for(auto it : hash)
    {
        if(it.second > mostFreq){
            mostFreq = it.second;
        }
    }
    // Second Most frequent element
    for(auto it : hash)
    {
        if(it.second > secMostFreq && it.second < mostFreq ){
            secMostFreq = it.second;
            element = it.first;
        }
    }

    return element;
}

int sumOfHighestAndLowestFreq(vector<int>& nums)
{
    int highFreq = 0;
    int lowFreq = 0;
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
    // Lowest freq
    for(auto it : hash)
    {
        if(it.second < lowFreq){
            lowFreq = it.second;
        }
    }
    return (highFreq + lowFreq);
}

int main()
{
    int result = 0;
    // vector<int> nums = {1,5,5,6,5,6,3,3,3, 2, 4, 5, 2, 8, 7};
    // vector<int> nums = {1, 2, 2, 3, 3, 3};
    vector<int> nums = {1, 2, 4, 4, 7, 7, 1, 2};

    // result = mostFrequentSmallElement(nums);
    // cout<<"Result of most Frequent small Element: "<<result<<endl;

    // result = mostFrequentBigElement(nums);
    // cout<<"Result of most Frequent big Element: "<<result<<endl;

    // result = secondHighestOccuringElement(nums);
    // cout<<"Result of second Highest Occuring Element: "<<result<<endl;

    result = sumOfHighestAndLowestFreq(nums);
    cout<<"Result of sum of Highest and lowest Frequency: "<<result<<endl;

    return 0;
}