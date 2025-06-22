#include<iostream>

using namespace std;

char findNonRepeating(string str) {
    // Write your code here.
    char ch = str[0];
    int iCout = 0;
    for(int i = 0; i < str.length(); i++)
    {
        ch = str[i];
        cout<<"ch: "<<ch<<endl;
        for(int j = i; j < str.length(); j++)
        {
          cout<<"str[j]: "<<str[j]<<endl;
          if (ch != str[j]) 
          {
            ch = str[j];
            iCout++;
          }
        }
    }
    if(iCout > 0)
    {
        return ch;
    }
    return ch;
}
/*5
bbabcbcb
babaabea
cbbd
bebeeed
abcd
*/

int main(void)
{

    string str = "bbabcbcb";
    cout<<findNonRepeating(str);
}
