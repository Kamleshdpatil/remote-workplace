#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    char cArr[] = {'w', 'o', 'r', 'l', 'd'};
    int l = sizeof(cArr) / sizeof(*cArr);

    vector<char> cVec(l);
    // copy(&cArr[0], &cArr[l], cVec.begin());
    // copy(cArr, cArr + l, cVec.begin());
    copy(cArr.begin(), cArr.end(), cVec);
    for (vector<char>::iterator it = cVec.begin(); it != cVec.end(); ++it)
    {
        cout << *it;
    }

    return 0;
}
