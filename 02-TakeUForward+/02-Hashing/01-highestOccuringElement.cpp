#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// // Brute force aproach
// int highestOccuringElement(int* nums, int size)
// {
//     int mostOccEle = -1;
//     int maxCnt = 0;
//     int maxi = nums[0];
//     for(int i = 1; i < size; i++)
//     {
//         if(nums[i] > maxi)
//             maxi = nums[i];
//     }
//     vector<int> visited(maxi+1, 0);
//     for(int i = 0; i < size; i++)
//     {
//         int cnt = 0;
//         if(visited[nums[i]] == 0)
//         {
//             for(int j = i; j < size; j++)
//             {
//                 if(nums[i] == nums[j])
//                     cnt++;
//             }
//             if(cnt > maxCnt){
//                 maxCnt = cnt;
//                 mostOccEle = nums[i];
//             }else if(cnt == maxCnt && nums[i] < mostOccEle)
//                 mostOccEle = nums[i];
//             visited[nums[i]] = 1;
//         }else
//             continue;
//     }
//     return mostOccEle;
// }

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

int main()
{
    // int nums[] = {1, 2, 3, 3, 3, 2};
    int nums[] = {1, 2, 3, 3, 3, 2, 5, 4, 4, 5, 2};

    int size = sizeof(nums)/sizeof(nums[0]);

    int result = highestOccuringElement(nums, size);
    cout<<"Highest Occuring element: "<<result<<endl;
    return(0);
}
