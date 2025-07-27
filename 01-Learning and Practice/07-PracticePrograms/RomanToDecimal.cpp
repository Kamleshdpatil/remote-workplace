#include<iostream>

using namespace std;

int value(char c)
{
    if(c == 'I')
        return 1;
    if(c == 'V')
        return 5;
    if(c == 'X')
        return 10;
    if(c == 'L')
        return 50;
    if(c == 'C')
        return 100;
    if(c == 'D')
        return 500;
    if(c == 'M')
        return 1000;
    return -1;
}

int romanTodecimal(string& str)
{
    //Initialize result
    int res = 0;
    int len = str.length();
    //traverse input string
    for(int i = 0; i < len; i++)
    {
        //Get value of symbol s[i] -- one by one
        int s1 = value(str[i]);

        if(i + 1 < len)
        {
            int s2 = value(str[i+1]);

            if(s1>=s2)
            {
                res += s1;
            }
            else{
                res = res + s2 - s1;
                i++;
            }
        }
        else
        {
            res = res + s1;
        }
    }
    return res;
}

int main(void)
{
    string str = "MCMIV";
    cout<<"Integer from of roman numeral is: "<<romanTodecimal(str)<<endl;

    return(0);
}
