#include<iostream>
#include<utility>

template<typename T>
class SharedPtr{
    private:
    T* ptr;
    size_t* ref_count;

    public:
    // Constructor
    explicit SharedPtr(T* p = nullptr) : ptr(p), ref_count(new size_t(p ? 1 : 0)) {}

    // Copy constructor
    SharedPtr(const SharedPtr& other) : ptr(other.ptr), ref_count(other.ref_count){
        if(ptr){
            ++(*ref_count);
        }
    }
    
    // Copy Assignment operator constructor
    SharedPtr& operator=(const SharedPtr& other){
        if(this != &other){
            release();
            ptr = other.ptr;
            ref_count = other.ref_count;

            if(ptr)
                ++(*ref_count);
        }
        return *this;
    }

    // Move constructor
    SharedPtr(SharedPtr&& other) noexcept : ptr(other.ptr), ref_count(other.ref_count){
        other.ptr = nullptr;
        other.ref_count = nullptr;
    }

    // Move Assignment operator constructor
    SharedPtr& operator=(SharedPtr&& other) noexcept{
        if(this != &other){
            release();
            ptr = other.ptr;
            ref_count = other.ref_count;

            other.ptr = nullptr;
            other.ref_count = nullptr;
        }
        return *this;
    }

    // Destructor
    ~SharedPtr() {
        release();
    }

    // Dereference operator
    T& operator*() const {
        return *ptr;
    }

    // Arrow operator
    T* operator->() const {
        return ptr;
    }

    // Get raw pointer
    T* get() const {
        return ptr;
    }

    // Get reference count
    size_t use_count() const {
        return ref_count ? *ref_count : 0;
    }

    private:
    void release() {
        if (ref_count) {
            --(*ref_count);
            if (*ref_count == 0) {
                delete ptr;
                delete ref_count;
            }
        }
        ptr = nullptr;
        ref_count = nullptr;
    }
};

int main() {
    SharedPtr<int> sp1(new int(42));
    std::cout << "sp1 count: " << sp1.use_count() << "\n"; // 1
    {
        SharedPtr<int> sp2 = sp1; // Copy constructor
        std::cout << "sp1 count: " << sp1.use_count() << "\n"; // 2
        std::cout << "sp2 count: " << sp2.use_count() << "\n"; // 2

        SharedPtr<int> sp3 = std::move(sp2); // Move constructor
        std::cout << "sp1 count: " << sp1.use_count() << "\n"; // 2
        std::cout << "sp3 count: " << sp3.use_count() << "\n"; // 2
    } // sp3 goes out of scope

    std::cout << "sp1 count: " << sp1.use_count() << "\n"; // 1

    return 0;
}
