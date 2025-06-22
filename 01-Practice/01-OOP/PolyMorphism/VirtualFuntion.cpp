#include<iostream>
using namespace std;

class Base
{
    int emplyeeId;
    public:
    Base()
    {
        cout<<"\nBase() constructor called."<<endl;
    }

    virtual void print()
    {
        cout<<"\nprint() inside Base() class"<<endl;
    }

    void SetId(int id)
    {
        cout<<"\nBase::SetId() called with id: "<<id<<endl;
        emplyeeId = id;
    }

    void Display()
    {
        cout<<"\nBase::Employee ID: "<<emplyeeId<<endl;
    }

    virtual ~Base(){}
};

class Derived: virtual public Base
{
    int emplyeeId;

    public:
    Derived()
    {
        cout<<"\nDerived() constructor called."<<endl;
    }
    Derived(int id) : emplyeeId{id} {}
    
    static void print()
    {
        cout<<"\nprint() inside Derived() class"<<endl;
    }

    virtual int GetId()
    {
        return emplyeeId;
    }

    void SetId(int id)
    {
        cout<<"\nDerived::SetId() called with id: "<<id<<endl;
        emplyeeId = id;
    }

    void Display()
    {
        cout<<"\nDerived::Employee ID: "<<emplyeeId<<endl;
    }
    virtual ~Derived(){}
};

class Child : public Derived
{
    int emplyeeId;
    public:
    Child()
    {}
    Child(int i)
    {
        emplyeeId = i;
    }
    // void SetId(int id)
    // {
    //     cout<<"\nChild::SetId() called with id: "<<id<<endl;
    //     emplyeeId = id;
    // }

    void print()
    {
        cout<<"\nprint() inside Child() class"<<endl;
    }

    void Display(){ cout<<"\nChild::Employee ID: "<<emplyeeId<<endl; }
};

int main(void)
{
    Child cObj(312);
    //cObj.SetId(44444);
    //cObj.emplyeeId = 1011142;


    Derived* cptr = &cObj;
    //cptr = &cObj;

    cptr->SetId(44444);
    cptr->Display();
    cptr->print();
    
    return(0);
}
