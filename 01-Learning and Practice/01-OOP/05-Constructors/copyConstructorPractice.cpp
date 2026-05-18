// Online C++ compiler to run C++ program online
#include <iostream>
#include <memory>
using namespace std;

class Base {
    int* ptr;
    int data;
    public:
    //Base() = default;
    Base(int val) : data(val){
        ptr = new int[val];
        for(int i = 0; i < data; i++){
            ptr[i] = i+1;
        }
        cout<<endl<<"Data insertion is done"<<endl;
    }
    
    Base(Base& obj) {
        cout<<endl<<"Inside Shallow copy"<<endl;
        data = obj.data;
        ptr = obj.ptr;
    }
    
    // Base(const Base& obj) : data(obj.data){
    //     cout<<endl<<"Inside Deep copy"<<endl;
    //     delete []ptr;
    //     ptr = new int[obj.data];
    //     for(int i = 0; i < obj.data; i++){
    //         ptr[i] = i+1;
    //     }
    // }
    
    void printData() {
        cout<<endl<<"Printing data: ";
        for(int i = 0; i < data; i++){
            cout<<ptr[i]<<" ";
        }
    }
    virtual void func() {
        std::cout << "Inside Base::func()"<<endl;
    }
};
class Derived : public Base {
    public:
    void func() {
        std::cout << "Inside Derived::func()"<<endl;
    }
    void gun() {
        std::cout << "Inside Derived::gun()"<<endl;
    }
};


int main() {
    // Write C++ code here
    Base* b_ptr1 = new Base(5);
    Base* b_ptr2 = b_ptr1;
    // b_ptr1->printData();
    b_ptr2->printData();
    
    
    // Base* b_ptr = new Base();
    // Base* b_ptr = new Derived();
    // Derived* d_ptr = dynamic_cast<Derived*>(b_ptr); // d_ptr will be nullptr
    // // Derived* d_ptr = static_cast<Derived*>(b_ptr); // d_ptr will be nullptr
    // if(d_ptr)
    //     std::cout << "d_ptr is not NULL"<<endl;
    // else
    //     std::cout << "d_ptr is NULL"<<endl;
    // d_ptr->func();
    // d_ptr->gun();
    
    // Base* b_ptr = new Derived();
    // unique_ptr<Base> ud_ptr = make_unique<Derived>();
    // unique_ptr<Base> u_ptr = move(ud_ptr);
    
    // b_ptr = move(u_ptr);
    // if (!b_ptr)
    //     std::cout << "b_ptr is now null\n";
    return 0;
}





