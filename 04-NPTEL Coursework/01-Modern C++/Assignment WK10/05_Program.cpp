#include <iostream>
using namespace std;

void update(char *str) {}

template <typename F, typename P>
void caller(F func, P s)
{
    func(s);
}

int main()
{
    char s[2] = "0";
    char *p = &s[1];

    // caller(update, p); // Line 1

    caller(update, nullptr); // Line 4

    return 0;
}
