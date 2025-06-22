#include <iostream>
using namespace std;

class myClass
{
    static int s;

public:
    myClass(int _s) : s(_s) {}
    void incr() { s = s + 10; }
    void print() { cout << s; }
};

int main(void)
{

    // cout<<"Hello World!"<<endl;
    return (0);
}
