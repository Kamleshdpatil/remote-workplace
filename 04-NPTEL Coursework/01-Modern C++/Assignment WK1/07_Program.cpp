#include<iostream>
#include<string>

using namespace std;

int main(void)
{
    string str1 = "Modern ";
    string str2 = "C++";

    //str1 += str2;

    str1.append(str2);

    cout<<str1;
    
    return(0);
}
