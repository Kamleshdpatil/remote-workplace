#include <iostream>
using namespace std;

class Employee
{
    string name;

public:
    Employee(string _name = "unknown") : name(_name) {}
    void update(string na) const
    {
        // (const_cast<Employee *>(this))->name = na;
        ((Employee *)(this))->name = na;
    }
    void showInfo() const
    {
        cout << "Name: " << name;
    }
};

int main()
{
    const Employee e("Sam");
    e.update("Sameer");
    e.showInfo();

    return 0;
}
