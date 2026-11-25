#include <iostream>
#include<memory>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

template<typename T>
class uniquePtr{
    T* mPtr = nullptr;
    public:
        // default Constructor
        uniquePtr() = default;
        
        // param Constructor
        explicit uniquePtr(T* ptr) : mPtr(ptr){}
        
        // delete -- copy Constructor
        uniquePtr(const uniquePtr&) = delete;
        uniquePtr& operator=(const uniquePtr&) = delete;
    
        // move Constructor
        uniquePtr(uniquePtr&& obj) noexcept : mPtr(obj.mPtr)
        {
            obj.mPtr = nullptr;
        }
        
        // move Assignment operator
        uniquePtr& operator=(uniquePtr&& obj) noexcept
        {
            if(this != &obj)
            {
                delete mPtr;
                mPtr = obj.mPtr;
                obj.mPtr = nullptr;
            }
            return *this;
        }
        
        // destructor
        ~uniquePtr(){ 
            if(mPtr)
                delete mPtr;
        }
        
        // -> pointer operator
        T* operator->() const noexcept { return mPtr;}
        
        // * dereferance operator
        T& operator*() const { return *mPtr;}
        
        // get method
        T* get() const noexcept { return mPtr; }
        
        // reset method
        void reset(T* ptr = nullptr)
        {
            T* old_ptr = mPtr;
            mPtr = ptr;
            if(old_ptr){
                delete old_ptr;
            }
        }
        
        // release method
        T* release() noexcept {
            T* old_ptr = mPtr;
            mPtr = nullptr;
            return old_ptr;
        }
};

class Base{
    std::vector<int> vec;
    public:
    Base() = default;
    Base(vector<int>& nums) : vec(std::move(nums)){
        
    }
    void print()
    {
        for(int& num : vec)
        {
            cout<<num<<" ";
        }
        cout<<"\n";
    }
    
    virtual ~Base() = default;
};

int main()
{
    // uniquePtr<int> ptr = uniquePtr<int>();
    // std::cout<<ptr.get()<<endl;
    // *ptr = 500;
    // cout<<*ptr;
    
    vector<int> nums = {10, 20, 50, 60};
    
    
    uniquePtr<Base> bPtr1(new Base(nums));
    
    //uniquePtr<Base> bPtr2(bPtr1);
    
    uniquePtr<Base> bPtr = std::move(bPtr1);
    
    bPtr->print();
    
    return 0;
}