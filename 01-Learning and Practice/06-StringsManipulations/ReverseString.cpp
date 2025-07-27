#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

void ReverseCString(char* str, int size)
{
    for(int i = 0; i < size/2; i++)
    {
        swap(str[i], str[size-i-1]);
    }
    for(int i = 0; i < size; i++)
    {
        cout<<str[i]<< " ";
    }
    cout<<endl;
}

void ReverseString(string& str, int size)
{
    for(int i = 0; i < size/2; i++)
    {
        swap(str[i], str[size-i-1]);
    }
    for(int i = 0; i < size; i++)
    {
        cout<<str[i]<< " ";
    }
    cout<<endl;
}

bool isPalimdromeCString(char* str, int size){
    string temp = str;
    ReverseCString(str, size);
    if(temp == str){
        return true;
    }
    return false;
}

bool isPalimdromeString(string& str, int size){
    string temp = str;
    ReverseString(str, size);
    if(temp == str){
        return true;
    }
    return false;
}

int main(void)
{
    char str[] = "Kamlesh";
    // string str1 = "Kamlesh hselmaK";
    string str1 = "hselmaK";
    int n = strlen(str); //3

    // cout<<"strlen: "<<strlen(str)<<endl;
    // cout<<"length: "<<str1.length()<<endl;
    // cout<<"Sizeof "<<sizeof(str)/sizeof(str[0])<<endl;

    cout<<"C style String: ";
    ReverseCString(str, n);

    cout<<"C++ String: ";
    ReverseString(str1, str1.length());

    str1 = "ABCDCBA";
    
    bool bRet = isPalimdromeString(str1, str1.length());
    if(bRet){
        cout<<"Palimdrome"<<endl;
    }else{
        cout<<"Not Palimdrome"<<endl;
    }

    char str2[] = "ABCDCBA";

    bool Ret = isPalimdromeCString(str2, strlen(str2));
    if(Ret){
        cout<<"Palimdrome"<<endl;
    }else{
        cout<<"Not Palimdrome"<<endl;
    }
}