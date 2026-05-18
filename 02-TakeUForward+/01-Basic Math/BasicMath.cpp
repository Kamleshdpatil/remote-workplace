#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool isArmstrong(int n) {
        cout<<"Inside isArmstrong()"<<endl;
        int count = 0, temp = n, iRet = 0, iRev = 0;
        while(temp > 0){
            temp /= 10;
            count++;
        }
        temp = n;
        cout<<"Count is: "<<count<<endl;
        while(temp > 0){
            int digit = temp % 10;
            iRev = digit + (iRev *10);
            temp = temp / 10;
        }
        cout<<"Reverse is: "<<iRev<<endl;
        while(iRev > 0){
            int digit = iRev % 10;
            iRet = iRet + (pow(digit, count));
            iRev = iRev / 10;
        }
        if(iRet == n){
            return true;
        }else{
            return false;
        }
    }

    bool isPerfect(int n) {
        int temp = n-1, iSum = 0;
        while(temp > 0){
            if(n % temp == 0){
                iSum = iSum + temp;
            }
            temp--;
        }
        cout<<"iSum: "<<iSum<<endl;
        if(iSum == n){
            return true;
        }else{
            return false;
        }
    }

    vector<int> getDivisorsArrayOfGivenNumber(int n){
        int temp = n, count = 0;
        vector<int> vec;
        while(temp > 1){
            if(n % temp == 0){
                vec.push_back(temp);
                //cout<<temp<<" ";
            }
            temp--;
        }
        //cout<<endl;
        //sort(vec.begin(), vec.end());
        //cout<<"Size is: "<<vec.size()<<endl;
        return(vec);
    }

    int GCD(int n1,int n2) {
        int iRet = 0;
        int size = (int)min(n1, n2);
        for(int i = 1; i <= size; i++){
            if((n1 % i == 0) && (n2 % i == 0)){
                iRet = i;
            }
        }
        return(iRet);
    }

    int LCM(int n1,int n2) {
        vector<int> iRet = {};
        vector<int> n1Vec, n2Vec;
        n1Vec = getDivisorsArrayOfGivenNumber(n1);
        n2Vec = getDivisorsArrayOfGivenNumber(n2);
        //int size = min(n1Vec.size(), n2Vec.size());
        // for(int i = 0; i < size; i++){
        //     for(auto it : n2Vec){
        //         if(n1Vec[i] % it == 0){
        //             iRet.push_back(n1Vec[i]);
        //         }
        //     }
        //     for(auto it : n1Vec){
        //         if(n2Vec[i] % it == 0){
        //             iRet.push_back(n2Vec[i]);
        //         }
        //     }
        // }
        
        int size = min(n1Vec.size(), n2Vec.size());
        if(size > 1){
            for(int k = 0; k < size; k++){
                return(n1Vec[k] * n2Vec[k]);
            }
        }else{
            return(iRet[0]);
        }
    }

    int mostFrequentElement(vector<int>& nums) {
        if (nums.empty()) 
            return -1;
        if (nums.size() == 1) 
            return nums[0];

        unordered_map<int, int> freqMap;
        int largest = nums[0], count=0;

        for(int num : nums){ 
            freqMap[num]++;

            if(freqMap[num] > count || (freqMap[num] == count && num < largest))
            {
                largest = num;
                count = freqMap[num];
            }
        }
        return largest;
    }

    // int secondMostFrequentElement(vector<int>& nums) {
    //     if (nums.empty()) 
    //         return -1;
    //     if (nums.size() == 1) 
    //         return nums[0];

    //     int size = pow(10, 4) + 1;
    //     int visitedArr[size] = {0};
    //     int ele1Freq = 0, ele2Freq = 0;
    //     int ele1 = -1, ele2 = -1, count = 0;

    //     for(int i = 0; i < nums.size(); i++){
    //         if(visitedArr[nums[i]] == 0){
    //             visitedArr[nums[i]] = 1;
    //             for(int j = 0; j < nums.size(); j++){
    //                 if(nums[j] == nums[i]){
    //                     count++;
    //                 }
    //             }
    //             if(count > ele1Freq){
    //                 ele2 = ele1;
    //                 ele2Freq = ele1Freq;

    //                 ele1 = nums[i];
    //                 ele1Freq = count;
    //             }else if(count > ele2Freq){
    //                 ele2 = nums[i];
    //                 ele2Freq = count;
    //             }else if(count == ele1Freq && nums[i] < ele1){
    //                 ele1 = nums[i];
    //             }else if(count == ele2Freq && nums[i] < ele2){
    //                 ele2 = nums[i];
    //             }
    //         }
    //     }
        
    //     return ele2;
    // }

    int secondMostFrequentElement(vector<int>& nums) {
        if (nums.empty()) 
            return -1;
        if (nums.size() == 1) 
            return nums[0];

        unordered_map<int, int> freqMap;
        int largestNum = nums[0], count=0;
        int largeCount = 0;
        int secondLargest = nums[0];

        for(int num : nums){ 
            freqMap[num]++;
            count = freqMap[num];

            cout<<" num "<<num<<" count: "<<count<<endl;

            if(count > largeCount){
                largeCount = count;
                secondLargest = largestNum;
                largestNum = num;
            }else if(count < largeCount && num > largestNum && num < secondLargest){
                secondLargest = num;
                //break;
            }

        }
        return secondLargest;
    }

    // int mostFrequentElement(vector<int>& nums) {
    //     int maxi = 0, ele = -1, maxCnt = 0;
    //     int size = nums.size(); 
    //     int count = 0;

    //     int visitedArr[10001] = {0};

    //     for(int i = 0; i < size; i++){
    //         count = 0;
            
    //         if(visitedArr[nums[i]] == 0){
    //             visitedArr[nums[i]] = 1;

    //             for(int j = 0; j < size; j++){
    //                 if(nums[i] == nums[j]){
    //                     count++;
    //                 }
    //             }
    //             if(count > maxCnt){
    //                 maxCnt = count;
    //                 ele = nums[i];
    //             }else if(count == maxCnt && nums[i] < ele){
    //                 ele = nums[i];
    //             }
    //         }
    //     }
    //     return ele;
    // }


    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0, maxCnt = 0; 
        int num = nums[0];
        for(int i = 0; i < nums.size(); i++){
            if(num == nums[i]){
                count++;
                num++;
            }else if(num < nums[i]){
                num = nums[i] + 1;
                count=1;
            }else{
                continue;
            }

            if(count > maxCnt){maxCnt=count;}
        }
        return maxCnt;
    }

    int longestSubarray(vector<int> &nums, int k){
        sort(nums.begin(), nums.end());
        int count = 0, maxCnt = 0; 
        int sum = nums[0];
        for(int i = 0; i < nums.size(); i++){
            if(sum == k){
                break;
            }else if(sum < k){
                sum = sum + nums[i];
                count++;
            }
            else if(sum + nums[i] != k){
                sum = nums[i];
                count = 0;
            }

            if(count > maxCnt){maxCnt=count;}
        }
        return maxCnt;
    }

};

class Solution1 {
public:
    int secondMostFrequentElement1(vector<int>& nums) {
        if (nums.empty()) return -1;  // Handle edge case: empty array
        
        int maxi = nums[0];
        
        // Find the maximum element in the array to size the hash array
        for (int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
        }

        // Frequency array to count occurrences of each element
        int *hash = new int[maxi + 1]{0};

        // Count the frequency of each element in nums
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
        }

        // Variables to track the most frequent and second most frequent elements
        int ele1 = -1, ele2 = -1;
        int ele1Freq = 0, ele2Freq = 0;

        // Traverse the hash array and find the most and second most frequent elements
        for (int i = 0; i <= maxi; i++) {
            int count = hash[i];
            if (count == 0) continue;  // Skip elements not present in the array

            // Update the most frequent element
            if (count > ele1Freq) {
                ele2 = ele1;
                ele2Freq = ele1Freq;

                ele1 = i;
                ele1Freq = count;
            }
            // Handle tie for most frequent element (choose the smallest element)
            else if (count == ele1Freq && i > ele1) {
                ele2 = ele1;
                ele2Freq = ele1Freq;

                ele1 = i;
            }
            // Update the second most frequent element
            else if (count > ele2Freq) {
                ele2 = i;
                ele2Freq = count;
            }
            // Handle tie for second most frequent element (choose the smallest element)
            else if (count == ele2Freq && i > ele2) {
                ele2 = i;
            }
        }

        // If there is no second most frequent element, return -1
        return ele2Freq > 0 ? ele2 : -1;
    }
};



int main(void){
    Solution *obj = new Solution();
    Solution1 *obj1 = new Solution1();
    bool iRet = false;
    //iRet = obj->isArmstrong(153);
    // iRet = obj->isPerfect(28);
    // if(iRet){
    //     cout<<"Perfect"<<endl;
    // }else{
    //     cout<<"Not Perfect"<<endl;
    // }

    //cout<<"LCM: "<<obj->LCM(4, 6);

    // vector<int> vec = obj->getDivisorsArrayOfGivenNumber(4);
    // for(auto i : vec){
    //     cout<<i<<" ";
    // }

    //cout<<"GCD: "<<obj->GCD(6, 4);

    // vector<int> vec = {100, -6, 5, 3, -13, 13, 30};

    // cout<<"GCD: "<<obj->mostFrequentElement(vec);

    vector<int> vec = {6, 5, 4, 4, 5, 5, 6, 7};
    cout<<"Second highest: "<<obj1->secondMostFrequentElement1(vec);
    
    // vector<int> vec = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    // //vector<int> vec = {100, 4, 200, 1, 3, 2};
    // cout<<"Longest Consucutive: "<<obj->longestConsecutive(vec);

    // vector<int> vec = {-3, 2, 1};
    // int k = 6;

    // vector<int> vec = {100, 5, 2, 7, 1, 200};
    // int k = 15;
    // cout<<"Longest subarray size: "<<obj->longestSubarray(vec, k);



    return(0);
}
