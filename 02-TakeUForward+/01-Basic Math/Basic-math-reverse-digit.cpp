#include<iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long int iRet = 0, temp = x;
        while(temp != 0)
        {
           iRet = (iRet * 10) + (temp % 10); 
           temp /= 10;
        }
        return((iRet < INT32_MIN || iRet > INT32_MAX) ? 0 : iRet);
    }
};

int main(void)
{
    int num = 534236469;
    cout<<"Original number: "<<num<<endl;
    Solution obj = Solution();
    int iRet = obj.reverse(num);
    cout<<"Reversed number: "<<iRet<<endl;

    return(0);
}
