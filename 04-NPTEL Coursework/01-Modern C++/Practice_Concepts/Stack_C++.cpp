#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int main()
{
    char str[10] = "ABCDE";
    stack<char> st;
    for (int i = 0; i < strlen(str); i++)
    {
        st.push(str[i]);
    }
    cout << "Reversed String: ";
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }

    return 0;
}
