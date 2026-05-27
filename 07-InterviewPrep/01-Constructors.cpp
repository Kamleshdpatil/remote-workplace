/*
    - If you define ANY constructor → compiler does NOT generate default constructor.
    - const members MUST be initialized using initializer list.
    - Reference members MUST be initialized using initializer list.
    - Objects without default constructor MUST use initializer list.
    - Initialization order depends on member declaration order, NOT initializer list order.
    - Copy constructor must take reference  to avoid recursive object creation.
    - Constructor cannot be:
                        virtual ❌
                        static ❌
                        const ❌
    - Never call virtual functions inside constructor.
    - Move constructor transfers ownership instead of copying.

*/

#include<iostream>

using namespace std;

class Employee{
    int emp_id;
    //const int seat_number; // must be initilize using initilizer list
    //string& address; // must be initilize using initilizer list
    string designation = "_NA_";

    int *salary = nullptr;
    public:
    // Default Constructor
    Employee() = default;

    // Parameterized Constructor
    Employee(int x) : emp_id(x) {
        cout<<"Inside Parameterized Constructor with one param"<<endl;
    }
    
    Employee(int x, string str, int sal) : emp_id(x), designation(str) {
        cout<<"Inside Parameterized Constructor with two param"<<endl;
        salary = new int(sal);
    }

    // // Copy Constructor - Shallow Copy
    // Employee(const Employee& obj) : emp_id(obj.emp_id), designation(obj.designation), salary(obj.salary) {
    //     cout<<"Inside Conpy Constructor - Shallow Copy"<<endl;
    // }
        
    // Copy Constructor - Deep Copy
    Employee(const Employee& obj) : emp_id(obj.emp_id), designation(obj.designation){
        cout<<"Inside Conpy Constructor - Deep Copy"<<endl;
        this->salary = new int();
        if(this->salary != nullptr)
            *(this->salary) = *(obj.salary);
    }

    // Copy Assignment Operator - Deep Copy
    Employee& operator=(const Employee& obj) {
        cout<<"Inside Copy Assignment Operator - Deep Copy"<<endl;
        if(this == &obj)
            return *this;
        emp_id = obj.emp_id;
        designation = obj.designation;

        this->salary = new int();
        if(this->salary != nullptr)
            *(this->salary) = *(obj.salary);
        return *this;
    }

    // Move Constructor
    Employee(Employee&& obj) : emp_id(obj.emp_id), designation(obj.designation){
        cout<<"Inside Move Constructor"<<endl;
        
        this->salary = obj.salary;
        obj.salary = nullptr;
    }


    void show()
    {
        cout<<"This address: "<<this<<endl;
        cout<<"Employee details: "<<endl;
        cout<<"EMP ID: "<<emp_id<<"\nDesignation: "<<designation<<endl;
        if(salary != nullptr)
            cout<<"Salary: "<<*salary<<endl;
        cout<<endl;
    }

    void updateSalary(int upgrade){
        if(salary != nullptr)
            *salary = upgrade;
    }
};

class Base
{
    public:
    int bNum;

    Base()
    {
        cout << "Base\n";
    }
    Base(int num) : bNum(num)
    {
        cout << "Parameterised Base\n";
    }
    virtual void show(){
        cout<<"Num: "<<bNum<<endl;
    }
};

class Derived : public Base
{
    public:
    int dNum;

    Derived() : Base(10), dNum(10)
    {
        cout << "Derived\n";
    }
    void show(){
        cout<<"b Num: "<<bNum<<endl;
        cout<<"d Num: "<<dNum<<endl;
    }
};

int main()
{
    // Employee t;
    // t.show();
    // cout<<endl;

    // Employee t2(4402);
    // t2.show();
    // cout<<endl;
    
    // Employee t3(4402, "Developer", 18000);
    // t3.show();
    // cout<<endl;
    
    // Employee t4(t3);
    // Employee t5 = move(t3);
    // // t5 = t3;
    // t5.show();
    // t3.show();
    
    // t4.show();
    // t4.updateSalary(21000);
    // cout<<endl;
    // cout<<"After salary upgradation: "<<endl;
    // t4.show();
    
    // cout<<endl;

    // cout<<"t3: objest's show()"<<endl;
    // t3.show();

    Derived d;
    d.show();
    return 0;
}
