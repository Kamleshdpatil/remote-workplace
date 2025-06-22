#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findMax(vector<int> &nums)
    {
        int max = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > max)
            {
                max = nums[i];
            }
        }
        return max;
    }

    int sumOfNNatural(int n)
    {
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += i;
        }
        return sum;
    }

    int sumOfArrayElements(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        return sum;
    }

    int missingNumber(vector<int> &nums)
    {
        int missingNum = 0, max = findMax(nums);
        cout << "Max number: " << max << endl;

        int sumOfMaxNumber = sumOfNNatural(max);
        cout << "Sum of Max number: " << sumOfMaxNumber << endl;

        int sumOfArr = sumOfArrayElements(nums);
        cout << "Sum of All Array elements: " << sumOfArr << endl;

        missingNum = (sumOfMaxNumber - sumOfArr);

        return missingNum;
    }
};

int main()
{
    Solution obj;
    cout << "Finding missing number..." << endl;
    vector<int> arr = {0, 2, 3, 1, 4};
    // vector<int> arr = {0, 1, 2, 4, 5, 6};
    cout << "Missing number: " << obj.missingNumber(arr);

    return 0;
}