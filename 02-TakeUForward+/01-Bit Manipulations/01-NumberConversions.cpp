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

    unsigned long int num = 0;
    int ans = 0;
    while(true){
        cout<<"Enter a Numer to convert BIN to DEC: ";
        cin>>num;
        if(num == 0)
            return(0);
        ans = binaryToDecimalConversion(num);
        cout<<"Answer: "<<ans<<endl; 
    }

    return(0);
}
