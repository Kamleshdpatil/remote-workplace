#include<iostream>
#include<string>
#include<stack>

using namespace std;

//  Reverse String using Two Pointers
void reverseStringTwoPointers(string& str, int size)
{
    int i = 0, j = size - 1; 
    for(i = 0; i < size/2; i++, j--)
    {
        swap(str[i], str[j]);
    }
}

//  Reverse String using Reverse traversal
string reverseStringBackTraversal(string& str, int size)
{
    string output;
    for(int i = size-1; i >= 0; i--)
    {
        output+=str[i];
    }
    return output;
}

//  Reverse String Recursion Utility
void reverseStringRecFun(string& str, int left, int right)
{
    if(left >= right)
        return;
    swap(str[left], str[right]);

    reverseStringRecFun(str, ++left, --right);
}

//  Reverse String using Recursion
string reverseStringUsingRecursion(string& str, int size)
{
    reverseStringRecFun(str, 0, size-1);
    return str;
}

//  Reverse String Recursion Utility
void reverseStringUsingStack(string& str, int size)
{
    stack<char> charStack;
    for(int i = 0; i < size; i++)
    {
        charStack.push(str[i]);
    }
    static int itr = 0;
    while(!charStack.empty()){
        str[itr] = charStack.top();
        charStack.pop();
        itr++;
    }
}

int main()
{
    string str = "hselmaK";
    // string str = "AbbA";
    cout<<"The original string is: "<< str<<endl;

    // reverseStringTwoPointers(str, str.length());
    // cout<<"After Reverse: "<< str<<endl;
    
    // string output = reverseStringBackTraversal(str, str.length());
    // cout<<"After Reverse: "<<output<<endl;
    
    // string output = reverseStringUsingRecursion(str, str.length());
    // cout<<"After Reverse: "<<output<<endl;
    
    reverseStringUsingStack(str, str.length());
    cout<<"After Reverse: "<< str<<endl;

    return(0);
}

