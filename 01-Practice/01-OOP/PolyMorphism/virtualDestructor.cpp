#include<iostream>
using namespace std;

class Base{
    public:
    Base(){
        cout<<"Inside Base cCtor"<<endl;
    }
    virtual void fun(){
        cout<<"Inside Base fun()"<<endl;
    }
    virtual ~Base(){
        cout<<"Inside Base dCtor"<<endl;
    }
};

class Derived : public Base{
    public:
    Derived(){
        cout<<"Inside Derived cCtor"<<endl;
    }
    void fun(){
        cout<<"Inside Derived fun()"<<endl;
    }
    ~Derived(){
        cout<<"Inside Derived dCtor"<<endl;
    }
};

int main(){
    // Base *bObj = new Derived();
    // //Derived *dObj = new Derived();

    // bObj->fun();
    // //dObj->fun();

    // delete bObj;
    // // delete dObj;

    // Derived dObject;
    // // dObject.fun();
    // Base &bObject = dObject;
    // bObject.fun();
    
    return 0;
}
