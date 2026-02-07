#include <iostream>

using namespace std;

template <typename T>
class UniquePtr
{
private:
    T *ptr;

public:
    // Constructor
    explicit UniquePtr(T* p = nullptr) : ptr(p){}

    // Destructor
    ~UniquePtr()
    {
        delete ptr;
    };

    // Delete Copy Constructor
    UniquePtr(const UniquePtr&) = delete;
    
    // Delete Copy Assignment Constructor
    UniquePtr& operator=(const UniquePtr&) = delete;
    
    // Move Constructor
    UniquePtr(UniquePtr&& other) noexcept : ptr(other.ptr){
        other.ptr = nullptr;
    }
    
    // Move Assignement Constructor
    UniquePtr& operator=(UniquePtr&& other) noexcept {
        if(this != &other){
            delete ptr;

            ptr = other.ptr;
            other.ptr = nullptr;
        }

        return(*this);
    }

    // Dereference operator
    T& operator*() const{
        return *ptr;
    }
    
    // Arrow operator
    T* operator->() const{
        return ptr;
    }

    // Get the raw pointer
    T* get() const{
        return ptr;
    }
    
    // Get the raw pointer
    T* release() {
        T* temp = ptr;
        ptr = nullptr;

        return temp;
    }

    // Replace the managed pointer
    void reset(T* p=nullptr){
        delete ptr;
        ptr = p;
    }
};

// Example usage
class Test{
    public:
    void sayHello(){
        std::cout<<"Hello from test"<<endl;
    }
};

int main()
{
    UniquePtr<Test> up1(new Test());
    up1->sayHello();
    
    UniquePtr<Test> up2 = move(up1);
    if(!up2.get()){
        cout<<"Up1 is now empty !"<<endl;
    }

    
    up2.release();
    
    up2->sayHello();
}

