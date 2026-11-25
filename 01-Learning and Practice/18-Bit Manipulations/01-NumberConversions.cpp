#include<iostream>
#include<cmath>

using namespace std;

unsigned long int decimalToBinaryConversion(int decNum)
{
    unsigned long int ans = 0;
    int power = 1;
    int rem = 0;
    while(decNum > 0)
    {
        rem = decNum % 2;
        decNum = decNum / 2;
        ans = ans + (rem * power);
        power = power * 10;
    }

    return ans;
}

int binaryToDecimalConversion(unsigned long int binNum)
{
    int ans = 0;
    int power = 1;
    int digit = 0;
    while(binNum > 0)
    {
        digit = binNum % 10;
        binNum = binNum / 10;
        // ans = ans + (digit * (pow(2, power++)));
        ans = ans + (digit * power);
        power = power*2;
    }

    return ans;
}

int main()
{
    ///////// DEC TO BIN ////////////////
    // int num = 0;
    // unsigned long int ans = 0;
    // while(true){
    //     cout<<"Enter a Numer to convert DEC to BIN: ";
    //     cin>>num;
    //     if(num == 0)
    //         return(0);
    //     ans = decimalToBinaryConversion(num);
    //     cout<<"Answer: "<<ans<<endl; 
    // }

    ///////// BIN TO DEC ////////////////
    // unsigned long int num = 0;
    // int ans = 0;
    // while(true){
    //     cout<<"Enter a Numer to convert BIN to DEC: ";
    //     cin>>num;
    //     if(num == 0)
    //         return(0);
    //     ans = binaryToDecimalConversion(num);
    //     cout<<"Answer: "<<ans<<endl; 
    // }

    // cout<<"(4 & 7): "<<(4 & 7)<<endl;
    // cout<<"(4 & 8): "<<(4 & 8)<<endl;
    // cout<<"(4 | 7): "<<(4 | 7)<<endl;
    // cout<<"(4 | 8): "<<(4 | 8)<<endl;
    // cout<<"(4 ^ 7): "<<(4 ^ 7)<<endl;
    // cout<<"(4 ^ 8): "<<(4 ^ 8)<<endl;
    // cout<<endl;
    // cout<<"(4 << 1): "<<(4 << 1)<<endl;
    // cout<<"(5 << 2): "<<(5 << 2)<<endl;
    // cout<<"(11 << 3): "<<(11 << 3)<<endl;
    // cout<<endl;
    // cout<<"(4 >> 1): "<<(4 >> 1)<<endl;
    // cout<<"(5 >> 2): "<<(5 >> 2)<<endl;
    // cout<<"(11 >> 3): "<<(11 >> 3)<<endl;
    // cout<<"(8 >> 2): "<<(11 >> 2)<<endl;

    cout<<endl;
    cout<<"(6 & 10)): "<<(6 & 10)<<endl;
    cout<<"(6 | 10)): "<<(6 | 10)<<endl;
    cout<<"(6 ^ 10)): "<<(6 ^ 10)<<endl;
    cout<<"(10 << 2): "<<(10 << 2)<<endl;
    cout<<"(10 >> 1): "<<(10 >> 1)<<endl;
    return(0);
}
