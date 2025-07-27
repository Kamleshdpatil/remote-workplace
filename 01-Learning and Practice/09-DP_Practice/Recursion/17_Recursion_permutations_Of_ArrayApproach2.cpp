#include<iostream>
#include<vector>

using namespace std;

void recurPermute(int index, vector<int>& nums, vector<vector<int>>& ans)
{
    if(index == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for(int i = index; i<nums.size(); i++)
    {
        swap(nums[index], nums[i]);

        recurPermute(index+1, nums, ans);
        
        swap(nums[index], nums[i]);
    }
}

int main(void)
{
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans;

    recurPermute(0, nums, ans);

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
