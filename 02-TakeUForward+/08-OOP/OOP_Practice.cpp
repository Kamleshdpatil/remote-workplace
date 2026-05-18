// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Base { //abstract class
    // private member variable
    // long a;
    //int *ptr;
    //int x;
    //char a;

public:
    Base(int X)
    {
        //cout <<"calling base class constructor"<<endl;
    }

    Base()
    {
        //cout <<"inside base"<<endl;
    }
    // pure virtual function
    // virtual void fun() = 0;
    // virtual void sun()
    // {
    //     int yy;
    //     cout<<"inside sun"<<endl;
    // }
    virtual ~Base()
    {
        cout<<endl<<"inside base destructor";
    }
    // getter function to access x
    virtual int getX() { return 10; }
    int getY() { return 100; }
};
class Derived : public Base {
    // private member variable
    //int y;

public:
    Derived(int x) : Base(x)
    {
        //cout <<endl<<"inside parametrised Derived 2"<<endl;
    }
    Derived()
    {
        //cout <<"inside default Derived 2"<<endl;

    }
    virtual ~Derived()
    {
        //cout <<"inside default Derived 2"<<endl;

    }

    int getX() { return 20; }
    int getY() { return 200; }

    // implementation of the pure virtual function
    void fun() { cout << "fun() called r2"; }
};

struct My{};

int main() {
    // Base base;
    /// Derived derived;
    // cout << "Sizeof base: "<<sizeof(base)<<endl;
    // cout << "Sizeof derived: "<<sizeof(derived)<<endl;
    // cout << "Sizeof myStruct: "<<sizeof(My)<<endl;

    Base* bObj = new Derived();
    bObj->getY(); //
    
    delete bObj;
    
    Derived* dObj = new Derived();
    delete dObj;
    
    return 0;
}
