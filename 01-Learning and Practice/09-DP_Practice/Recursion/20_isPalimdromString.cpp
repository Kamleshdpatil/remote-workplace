//
// find is palimdrome of given string

#include<iostream>
#include<algorithm>

using namespace std;

void isPlaimdromeString(char* str, int l, int r)
{
    cout<<"l : "<<str[l]<<endl;
    cout<<"r : "<<str[r]<<endl;
    if(l > r)
    {
        cout<<"This is palimdrome string"<<endl;
        return;
    }
    if(str[l] != str[r])
    {
        cout<<"This is not palimdrome string"<<endl;
        return;
    }
    isPlaimdromeString(str, l+1, r-1);
}

int main(void)
{
    char str[] = "KAKAAAKAK";
    string str1 = "KAKAAAKAK";
    //int length = sizeof(str)/sizeof(str[0]);
    int length = strlen(str);
    cout<<"Length is: "<<length<<endl;
    int size = str1.length();
    cout<<"size is: "<<size<<endl;
    isPlaimdromeString(str, 0, length-1);

    return(0);
}

// O(N) Time complexity
// O(N) Space complexitys