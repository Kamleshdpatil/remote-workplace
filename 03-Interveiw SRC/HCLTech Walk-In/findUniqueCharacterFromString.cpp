// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include<unordered_map>

using namespace std;

// void findFirstUniqueElement(string str)
// {
//     int size = str.length(), count = 0;
//     for(int i = 0; i < size; i++){
//         char ch = str[i];
//         for(int j = 0; j < size; j++){
//             if(ch == str[j])
//             {
//                 count++;
//             }
//         }
//         if(count == 1){
//             cout<<ch<<endl;
//             return;
//         }
//         count = 0;
//     }
//     cout<<"None"<<endl;
//     return;
// }

void findFirstUniqueElement(string str)
{
    int size = str.length();
    unordered_map<char, int> hash;

    for(int i = 0; i < size; i++){
        hash[str[i]]++;
    }
    for(auto it : hash){
        if(it.second == 1){
            cout<<it.first<<endl;
            return;
        }
    }

    cout<<"None"<<endl;
    return;
}

int main() {
    // Write C++ code here
    string st = "SKKWWQQISS";
    findFirstUniqueElement(st);
    //cout<<str<<endl;

    return 0;
}