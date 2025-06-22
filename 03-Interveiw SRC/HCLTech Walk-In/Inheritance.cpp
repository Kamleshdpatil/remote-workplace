#include<iostream>
using namespace std;

class Base{
    public:
    virtual void fun(){
        cout<<"Inside Base"<<endl;
    }
    void display(){
        cout<<"Inside Base::display"<<endl;
    }
};

class Derived: public Base{
    public:
    void fun(){
        cout<<"Inside Derived"<<endl;
    }
     void display(){
        cout<<"Inside Derived::display"<<endl;
    }
};

int main(){
    Base b1;
    // b1.fun(); way 1
    
    Derived d1;
    // d1.Base::fun(); // Way 2
    
    Base *pB = new Derived();
    // pB->fun(); // Way 3
    
    // (pB)->Base::fun(); // Way 4
    
    Base b2(d1);
    //b2.fun(); //way 5

    Base b3 = d1;
    // b3.fun(); //way 6
    //b3.fun();

    Base *b4 = &d1;
    //b4->fun(); //way 7

    Base& b5 = d1;
    //b5.Base::fun(); //way 8
    
    // Way 3 and way 4 perform runtime type checking in case of Base is hvaing virtual fun().

    //casting
    // Derived *dPtr = new Derived();
    
    // bPtr = dPtr; // 
    // bPtr->fun();
    
    Base *bPtr = new Base();
    Derived *basePtr = static_cast<Derived*>(bPtr);
    if(basePtr)
    {
        basePtr->display();
    }

    return 0;
}