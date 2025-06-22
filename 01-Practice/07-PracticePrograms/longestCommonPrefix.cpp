#include<iostream>
using namespace std;

string longestCommonPrefix(string arr[], int n)
{
    string res = arr[0]; //geeksforgeeks
    int len = res.length();  //13

    for(int i = 0; i<n; i++)
    {
        while(arr[i].find(res) != 0)
        {
            res = res.substr(0, len - 1);
            len--;
        }

        if(res.empty())
        {
            return "-1";
        }
    }

    return res; //
}

int main(void)
{
    string input[] = { "geeksforgeeks", "geeks", "geek", "geezer" };
    string output[] = { "kamgoulee", "kambillee", "kamgolee", "kamlee" };

    int len = sizeof(output) / sizeof(output[0]);

    cout<<"The longest common prefix is: "<<longestCommonPrefix(output, len);

    return(0);
}
