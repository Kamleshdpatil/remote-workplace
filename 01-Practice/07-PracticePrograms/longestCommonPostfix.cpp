#include<iostream>
using namespace std;

string longestCommonPostfix(string arr[], int n)
{
    string res = arr[0]; //geeksforgeeks
    int len = res.length();  //13

    for(int i = 1; i<n; i++)
    {
        int k = 1;
        while(arr[i].find(res) != 0)
        {
            res = res.substr(k, len);
            cout<<"Iteration: "<<k<<" String is: "<<res<<endl;
            k++;
        }

        if(res.empty())
        {
            return "-1";
        }
    }
    
    cout<<"Result: "<<res<<endl;

    return res;
}

int main(void)
{
    string input[] = { "geeksforgeeks", "geeks", "geek", "geezer" };
    string output[] = { "amlee", "billee", "klee", "mlee" };

    int len = sizeof(output) / sizeof(output[0]);

    cout<<"The longest common postfix is: "<<longestCommonPostfix(output, len);

    return(0);
}
