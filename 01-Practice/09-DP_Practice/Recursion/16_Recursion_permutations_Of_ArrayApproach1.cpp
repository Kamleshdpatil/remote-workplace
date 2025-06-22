#include<iostream>
#include<vector>

using namespace std;

void recurPermute(vector<int>& ds, vector<int>& nums, vector<vector<int>>& ans, int* freq)
{
    if(ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }
    for(int i = 0; i<nums.size(); i++)
    {
        if(!freq[i])
        {
            ds.push_back(nums[i]);
            freq[i] = 1;
            recurPermute(ds, nums, ans, freq);

            freq[i] = 0;
            ds.pop_back();
        }
    }
}

int main(void)
{
    vector<int> nums = {1,2,3,4};
    vector<vector<int>> ans;
    vector<int> ds;
    int freq[3] = {0};

    recurPermute(ds, nums, ans, freq);

    for(int j = 0; j < ans.size(); j++)
    {
        for(int i = 0; i<ans[j].size(); i++)
        {
            cout<<ans[j][i]<<" ";
        }
        cout<<endl;
    }
    return(0);
}
