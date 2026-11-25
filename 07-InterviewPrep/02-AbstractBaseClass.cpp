/*
    Abstract Base Class (ABC)
    Definition: A class that has at least one pure virtual function (virtual void func() = 0;). You cannot instantiate an object of an ABC.
    Purpose: Used to provide a common base with shared logic and state for a family of related classes ("Is-A" relationship).
    State: Can contain data members (variables) and non-virtual or regular virtual functions with implementations.
    Constructors: Can have constructors to initialize the base class state, which are called by derived class constructors.
    Inheritance: Used for code reuse—derived classes inherit the implementation of the base class.

    Interface (Pure Abstract Class)
    Definition: In C++, an interface is a class where all functions are pure virtual, and there are no data members.
    Purpose: Defines a strict contract or behavior that derived classes must fulfill ("Can-Do" relationship). It tells the world what a class does, not how.
    State: Strictly stateless. It should not have variables (except perhaps static constants).
    Destructor: Must have a virtual ~ClassName() = default; to ensure proper cleanup of derived objects when deleted via an interface pointer.
    Inheritance: Used for decoupling—different systems can interact with objects through the interface without knowing their internal details.
*/

#include<iostream>

using namespace std;

// Interface
class Vehicle{
    public:
    virtual void start() = 0;
    virtual ~Vehicle() = default;
};

class Zeep : virtual public Vehicle{
    public:
    void start() override {
        cout<<"Zeep Started"<<endl;
    }
    void print(){
        cout<<"Inside Zeep::print()"<<endl;
    }
};

class Car : virtual public Vehicle{
    public:
    void start() override {
        cout<<"Car Started"<<endl;
    }
    void print(){
        cout<<"Inside Car::print()"<<endl;
    }
};

class FourWheeler : public Zeep, public Car{
    public:
    void start() override {
        cout<<"Four wheeler Started"<<endl;
    }
    void print(){
        cout<<"Inside FourWheeler::print()"<<endl;
    }
};

// Abstract base class
class Animal{
    public:
    int num;
    explicit Animal(int i) : num(i){}

    static void print(int i){
        // num = i; // a nonstatic member reference must be relative to a specific object
        cout<<"Inside print: "<<i<<endl;
    }

    virtual void eat() = 0;
    virtual void sound() = 0;
    void walk(){
        cout<<"Walking style"<<endl;
    }

    virtual ~Animal() = default;
};

// Derived class 
class Dog : public Animal{
    public:
    Dog(int i) : Animal(i){}

    void eat(){
        cout<<"Num: "<<num<<endl;
        cout<<"Eat: Pedigry"<<endl;
    }

    void sound(){
        cout<<"Sound: Bark"<<endl;
    }
};

int main()
{
    // Animal* aPtr = new Dog(11);
    // aPtr->eat();
    
    // aPtr->print(10);
    // aPtr->walk();

    Vehicle* obj = new FourWheeler();
    obj->start();

    FourWheeler obj2;
    FourWheeler& obj1 = obj2;
    obj2.start();

    // cout<<sizeof(obj)<<endl;
    cout<<sizeof(obj2)<<endl;

    return 0;
}
