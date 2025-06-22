#include<iostream>

using namespace std;

template<class T>
T ReverseNumber(T num)
{
    T rem = 0;
    T ret = 0;
    while (num > 0)
    {
        rem = num % 10;
        ret = (ret * 10) + rem;
        num = num / 10;
    }
    return(ret);
}

template<class T>
T ConvertZeroToGivenInteger(T num, int replace)
{
    if(num == 0)
        return(replace);

    T ret = 0;
    T digit = 0;
    while (num > 0)
    {
        digit = num % 10;
        if(digit == 0)
            digit = replace;
        ret = (ret * 10) + digit;
        num = num / 10;
    }
    return(ReverseNumber(ret));
}

int main(void)
{
    int num = 10101101;
    int replace = 0;
    cin>>replace;
    int ret = ConvertZeroToGivenInteger(num, replace);
    cout<<"Actual value: "<<num<<endl;
    cout<<"\nConverted value: "<<ret<<endl;
    return(0);
}
