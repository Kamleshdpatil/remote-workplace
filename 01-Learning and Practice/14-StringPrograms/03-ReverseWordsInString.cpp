#include<iostream>
#include<string>
#include<map>
#include<stack>
#include<vector>
#include<functional>

using namespace std;

//  Reverse String using Two Pointers
string reverseWordsInStringUsingStack(string& str, int size)
{
    stack<string> strStack;
    string word;
    string output;
    int offset = 0;
    for(int i = 0; i <= size; i++)
    {
        if(str[i] == '.' || str[i] == ' ' || i == size){
            word = str.substr(offset, i - offset); // substr(start, length), not (start, end).
            offset = i+1;
            strStack.push(word);
        }
    }

    while (!strStack.empty())
    {
        output+= strStack.top();
        strStack.pop();
        if(!strStack.empty())
            output+=' ';
    }
    return output;
}

//  Reverse String using String Vector
string reverseWordsInStringUsingVector(string& str, int size)
{
    vector<string> strVector;
    string word;
    string output;
    int offset = 0;
    for(int i = 0; i <= size; i++)
    {
        if(str[i] == '.' || str[i] == ' ' || i == size){
            word = str.substr(offset, i - offset); // substr(start, length), not (start, end).
            offset = i+1;
            strVector.push_back(word);
        }
    }

    for(int i = strVector.size()-1; i >= 0; i--)
    {
        output+= strVector[i];
        output+=' ';
    }
    return output;
}

//  Sort String by word length
string sortWordsInStringByLength(string& str, int size)
{
    multimap<int, string, std::greater<int>> map;
    string word;
    string output;
    int offset = 0;
    for(int i = 0; i <= size; i++)
    {
        if(str[i] == '.' || str[i] == ' ' || i == size){
            word = str.substr(offset, i - offset); // substr(start, length), not (start, end).
            offset = i+1;
            map.insert({word.length(), word});
        }
    }

    for(auto it : map){
        output += it.second;
        output += ' ';
    }

    return output;
}

int main()
{
    string str = "i.like.this.program.very.much";
    // string str = "I am Sachin";
    cout<<"The original string is: "<< str<<endl;

    // string output = reverseWordsInStringUsingStack(str, str.length());
    // cout<<"Output: "<< output<<endl;

    // string output = reverseWordsInStringUsingVector(str, str.length());
    // cout<<"Output: "<< output<<endl;

    string output = sortWordsInStringByLength(str, str.length());
    cout<<"Output: "<< output<<endl;

    return(0);
}

