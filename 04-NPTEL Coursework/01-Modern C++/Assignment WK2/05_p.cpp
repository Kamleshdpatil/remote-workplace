#include <iostream>
#include <malloc.h>
#include <string.h>
#include <cstring>
using namespace std;
class Test
{
    char *s;

public:
    Test(char *s) : s(strcpy(new char[strlen(s) + 1], s)) {} // LINE-1
    ~Test() { delete[] s; }                                  // LINE-2
    Test &operator=(const Test &m)
    { // LINE-3
        free(s);
        s = strdup(m.s);
        return *this;
    }
    void update(char *x)
    {
        // s = s + " " + x;
        // LINE-4
        s = strcat(s, " ");
        s = strcat(s, x);
    }
    void print()
    {
        cout << s << endl;
    }
};
int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    Test *m1 = new Test(&str1[0]);
    Test *m2 = m1;
    m2->update(&str2[0]);
    m2->print();
    delete (m1);
    return 0;
}
