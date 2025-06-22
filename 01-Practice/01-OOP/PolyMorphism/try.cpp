
// C++ program for function overriding
#include <iostream>
using namespace std;
  
class base {
public:
    base(){cout<<"\n\n base() constructor\n"<<endl;}
    virtual ~base(){cout<<"\n\n base() destructor\n"<<endl;}
    virtual void print()
    {
        cout << "print base class" << endl;
    }
  
    void show() { cout << "show base class" << endl; }
};
  
class derived : public base {
public:
    // print () is already virtual function in
    // derived class, we could also declared as
    // virtual void print () explicitly
    derived(){cout<<"\n derived() constructor\n"<<endl;}
    ~derived(){cout<<"\n derived() destructor\n"<<endl;}
    void print() { cout << "\nprint derived class" << endl; }
  
    void show() { cout << "\nshow derived class" << endl; }
};
  
// Driver code
int main()
{
    base* bptr = new base();
    derived d;
    bptr = &d;
  
    // Virtual function, binded at
    // runtime (Runtime polymorphism)
    bptr->print();
  
    // Non-virtual function, binded
    // at compile time
    bptr->show();

    delete bptr;
  
    return 0;
}
