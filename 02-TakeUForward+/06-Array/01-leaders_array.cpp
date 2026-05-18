#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:

    bool isRestMembersAreSmaller(vector<int>& nums, int num, int index){
        for(int i = index; i < nums.size(); i++){
            if(num <= nums[i]){
                return false;
            }
        }
        return true;
    }

    vector<int> leaders(vector<int>& nums) {
        vector<int> result;
        for(int i = 0; i < nums.size()-1; i++){
            if(isRestMembersAreSmaller(nums, nums[i], i+1)){
                result.push_back(nums[i]);
            }
        }
        result.push_back(nums.back());
        return result;
    }
};

int main()
{
    Solution obj;
    // vector<int> nums = {198,393,946,655,978,781,472,239,639,738,705,8,355,457,69,152,37,74,390,659,238,132,122,739,687,992,699,258,684,903,556,903,330,321,413,600,197,696,512,671,429,644,908,952,714,608,178,346,182,77,134,956,313,582,160,217,291,907,924,151,541,850,271,533,705,258,716,835,307,426};
    vector<int> nums = {737,344,561,65,885,18,131,27,335,90,267,336,375,157,548,698,273,342,275,107,561,930,747,383,486,92,242,758,782,594,86,688,978,824,964,497,524,659,114,880,958,280,195,235,341,838,403,573,686,922,388,403,864,722,688,443,714,259,399,93,590,150,652,958,854,289,123,539,782,547,494,132,306,626,761,369,913,480,602};
    vector<int> result = obj.leaders(nums); 
    cout<<endl;
    for(auto it: result){
        cout<<it<<" ";
    }

    return 0;
}