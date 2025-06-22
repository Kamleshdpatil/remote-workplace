#include <iostream>
using namespace std;

namespace name
{
    class Student
    {
        int roll;

    public:
        Student(int x) : roll(x) {}
        void print() const
        {
            cout << roll << endl;
        }
    };
}

int main(void)
{
    name::Student s(5);
    s.print();
    return (0);
}
