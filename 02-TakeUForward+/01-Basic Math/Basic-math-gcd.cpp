#include<iostream>
using namespace std;

class Solution {
public:
    int reverse(int X) {
        long int iRet = 0, temp = X;
        while(temp != 0)
        {
           iRet = (iRet * 10) + (temp % 10); 
           temp /= 10;
        }
        return((iRet < INT32_MIN || iRet > INT32_MAX) ? 0 : iRet);
    }

    int findGCD(int A, int B) {
        int lcm = 1, gcd = 1, itr = 1;
        int min = (A > B && B < A ? B : A);
        int max = (A < B && B > A ? B : A);
        while(itr <= min){
            //cout<<"itr: "<<itr<<endl;
            //cout<<"gcd: "<<gcd<<endl;
            if((max % itr) == 0 && (min % itr) == 0){
                gcd = itr;
            }
            itr++;
        }
        return(gcd);
    }

    int multiPliedNumber(int n, int mult){
	int iRet = 1;
	for(int i = 0; i < mult; i++)
	{
		iRet = iRet * n;
	}
	return iRet;
}

    bool checkArmstrong(int n){
	//Write your code here
	int temp = n;
	int sum = 0;
	while(temp != 0){
		int num = temp % 10;
        cout<<"Num: "<<num<<endl;
		temp = temp / 10;
		sum = sum + (num * num * num);
        cout<<"Sum: "<<sum<<endl;
	}
	if(sum == n){
		return(true);
	}else{
		return(false);
	}
}
};

int main(void)
{
    Solution obj = Solution();
    //int num = 534236469;
    //cout<<"Original number: "<<num<<endl;
    //int iRet = obj.reverse(num);
    //cout<<"Reversed number: "<<iRet<<endl;
    // int N1 = 20, N2 = 40;
    // cout<<"GCD : "<<obj.findGCD(N1, N2);

    //cout<<"Attach: "<<obj.multiPliedNumber(10, 4);

    bool bRet = obj.checkArmstrong(1634);
    if(bRet){
        cout<<"It is Armstrong Number"<<endl;
    }else{
        cout<<"It's Not Armstrong Number"<<endl;
    }

    return(0);
}
