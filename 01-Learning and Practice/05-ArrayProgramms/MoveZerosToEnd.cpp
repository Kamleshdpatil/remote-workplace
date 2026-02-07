#include<iostream>
#include<vector>

using namespace std;

void Display(vector<int>& nums){
    int pos = 0;
    cout<<endl<<"Display Array: ";
    for(int i = 0; i < nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

void moveZerosToEnd(vector<int>& nums){
    int pos = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] != 0){
            nums[pos++] = nums[i];
        }
    }

    while(pos < nums.size())
    {
        nums[pos++] = 0;
    }
}

int main()
{
    vector<int> vecInt = {1, 0, 22, 32, 0, 45, 0, 12, 0, 11};
    Display(vecInt);
    moveZerosToEnd(vecInt);
    Display(vecInt);
    return 0;
}
