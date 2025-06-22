#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

string convertDecimalToBinary(int num)
{
    string binary;
    while(num > 0){
        if(num % 2 == 1){
            binary = binary + "1";
        }else{
            binary = binary + "0";
        }
        num = num / 2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

int convertBinaryToDecimal(string binary)
{
    int num = 0, len = binary.length(), p2 = 1;
    for(int i = len-1; i >= 0; i--){
        if(binary[i] == '1'){
            num = num + p2;
        }
        p2 = p2 * 2;
    }
    return num;
}

int main()
{
    string str = convertDecimalToBinary(13);
    cout<<"Binary: "<<str<<endl;
    cout<<"Decimal: "<<convertBinaryToDecimal(str)<<endl;
    return 0;
}
