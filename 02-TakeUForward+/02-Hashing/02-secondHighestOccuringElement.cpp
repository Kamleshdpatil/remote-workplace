#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// Optimal force aproach
int secondHighestOccuringElement(int* nums, int size)
{
    int highEle = -1;
    int secHighEle = -1;
    int maxCnt = 0;
    int secMaxCnt = 0;
    
    unordered_map<int, int> hashMap;
    for(int i = 0; i < size; i++)
    {
        hashMap[nums[i]]++;
        if(hashMap[nums[i]] > maxCnt)
        {
            maxCnt = hashMap[nums[i]];
            highEle = nums[i];
        }else if(hashMap[nums[i]] == maxCnt && nums[i] < highEle)
        {
            highEle = nums[i];
        }
    }

    for(auto it : hashMap)
    {
        int cnt = it.second;
        int ele = it.first;

        if(cnt > secMaxCnt && cnt < maxCnt)
        {
            secMaxCnt = cnt;
            secHighEle = ele;
        }else if(cnt == secMaxCnt && cnt < maxCnt)
        {
            secHighEle = min(ele, secHighEle);
        }
    }
    
    return secHighEle;
}

int main()
{
    // int nums[] = {1, 2, 3, 3, 3, 2};
    int nums[] = {4, 4, 5, 5, 6, 7};

    int size = sizeof(nums)/sizeof(nums[0]);

    int result = secondHighestOccuringElement(nums, size);
    cout<<"Second Highest Occuring element: "<<result<<endl;
    return(0);
}

