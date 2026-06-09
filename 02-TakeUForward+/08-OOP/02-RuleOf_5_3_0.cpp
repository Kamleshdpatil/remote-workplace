#include<iostream>
#include<vector>

using namespace std;

// Rule of three: 
// Definition: If your class manages a resource manually (like a raw pointer), 
// and you need to define a Destructor, Copy Constructor and a Copy Assignment Operator.

class RuleOfThree{
    int* data;

    public:
        RuleOfThree() : data(new int(0)){}

        // 1. Destructor
        ~RuleOfThree(){delete data;}

        // 2. Copy constructor (Deep Copy)
        RuleOfThree(const RuleOfThree& obj) : data(new int(*obj.data)){}

        // 3. Copy assignment (Deep Copy)
        RuleOfThree& operator=(const RuleOfThree& obj){
            if(this == &obj)
                return *this;
            *data = *obj.data;
            return *this;
        }
};

// Rule of Five: 
// Definition: With the introduction of C++11 (Move Semantics), the Rule of Three expanded. 
// To ensure maximum efficiency, if you define the first three, you should also define 
// the Move Constructor and Move Assignment Operator.

class RuleOfFive{
    int* data;

    public:
        RuleOfFive() : data(new int(0)){}

        // 1. Destructor
        ~RuleOfFive(){delete data;}

        // 2. Copy constructor (Deep Copy)
        RuleOfFive(const RuleOfFive& obj) : data(new int(*obj.data)){}

        // 3. Copy assignment (Deep Copy)
        RuleOfFive& operator=(const RuleOfFive& obj){
            if(this == &obj)
                return *this;
            *data = *obj.data;
            return *this;
        }

        // 4. Move contructor
        RuleOfFive(RuleOfFive&& obj) : data(obj.data){
            obj.data = nullptr;
        }

        // 5. Move assignment contructor
        RuleOfFive& operator=(RuleOfFive&& obj) {
            if(this == &obj)
                return *this;
            data = (obj.data);
            obj.data = nullptr;
            return *this;
        }
};

// Rule of Zero
// Definition: Try to design your classes so that you don't have to define any of these five functions.
// The Logic: Instead of managing raw pointers yourself, use components that already handle 
// their own memory (like std::vector, std::string, or std::unique_ptr). 
// If your class only contains "smart" members, the compiler-generated defaults will work perfectly.

class RuleOfZero
{
    std::string name;
    std::vector<int> score;
    // No destructor, copy, or move functions needed!
    // The compiler generates perfect versions for us.
};

int main()
{
    
    return(0);
}
