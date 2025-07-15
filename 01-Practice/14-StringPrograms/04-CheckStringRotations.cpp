#include<iostream>
#include<string>

using namespace std;

//  Check string rotations using two loops
bool checkStringRotations(string& str1, string& str2)
{
    bool isRotateFound = false;
    string temp = str1;
    int size = str1.length();
    for(int i = 0; i < size; i++){
        // cout<<"Inside for i: "<<i<<endl;
        
        char ch = temp[i];
        for(int j = 0; j < size; j++){
            str1[j] = str1[j+1];
        }
        str1[size-1] = ch;
        
        // cout<<"After rotation str1: "<<str1<<endl;

        if(str1 == str2){
            isRotateFound = true;
            break;
        }
    }

    return isRotateFound;
}

//  Check string rotations Optimal Approach
bool checkStringRotationsOptimal(string& str1, string& str2)
{
    return (str1.length() == str2.length() && (str1 + str1).find(str2) != string::npos);
}

int main()
{
    string str1 = "abcd";
    string str2 = "cdab";

    // string str1 = "abcd";
    // string str2 = "acbd";

    // string str1 = "aab";
    // string str2 = "aba";
    
    // if(checkStringRotations(str1, str2)){
    //     cout<<"Rotation found"<<endl;
    // }else{
    //     cout<<"Rotation not found"<<endl;
    // }

    if(checkStringRotationsOptimal(str1, str2)){
        cout<<"Rotation found"<<endl;
    }else{
        cout<<"Rotation not found"<<endl;
    }

    return(0);
}

