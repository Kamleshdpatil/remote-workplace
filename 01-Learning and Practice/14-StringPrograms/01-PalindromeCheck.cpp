#include<iostream>
#include<string>

using namespace std;

bool isStringPalindrome(string& str, int size)
{
    int i = 0, j = size - 1; 
    for(i = 0; i < size; i++, j--)
    {
        if(str[i] != str[j]){
            return false;
        }
    }
    return true;
}

bool isPalindromeString(string& str, int left, int right)
{
    if(left >= right)
        return true;
    
    if(str[left] != str[right])
        return false;

    return isPalindromeString(str, ++left, --right);
}

bool isPalindrome(string& str, int size)
{
    int right = size-1, left = 0;
    return isPalindromeString(str, left, right);
}

int main()
{
    // string str = "hselmaK";
    string str = "AbbA";
    cout<<"The original string is: "<< str<<endl;

    // Check palindrome using two pointers
    // bool bRet = isStringPalindrome(str, str.length());
    // if(bRet){
    //     cout<<str<<" is Palindrome";
    // }else{
    //     cout<<str<<" is not Palindrome";
    // }

    // Check palindrome using Recursion
    bool bRet = isPalindrome(str, str.length());
    if(bRet){
        cout<<str<<" is Palindrome";
    }else{
        cout<<str<<" is not Palindrome";
    }
    return(0);
}

