#include <iostream>
 
class A
{
public:
    A(int a =50): data(a)
    {std::cout<<"In A constructor\n"<<std::endl;}
    int getData()
    {
        return data;
    }
    ~A()
    {std::cout<<"In A destructor\n"<<std::endl;}
private:
    int data;
};
 
class B
{
public:
    B(const int size = 4) // why this is cont?
    {
        std::cout<<"In B constructor\n"<<std::endl;
        this->size = size;

        std::cout<<"\nConst size: "<<size<<std::endl;
        std::cout<<"\nthis size: "<<this->size<<std::endl;


        ptr = new A[size];  //A ptr[3] = [a1, a2, a3];
        std::cout<<"After new A[size]\n"<<std::endl;
        
    }
    void setA(int i, A** a1) // i -> position
    {
        if (i < size)  //i < 3
        {
            *a1 = &ptr[i];
        }
    }
    ~B()
    {
        std::cout<<"In B destructor\n"<<std::endl;
        delete[]ptr;
    }
private:
    A* ptr;
    int size;
};
 

void test1(A** a)
{
    B b1(6);
    b1.setA(0, &*a);
}
 
int main()
{
    std::cout<<"Start Main\n"<<std::endl;

    A *a1 = nullptr;
    test1(&a1);
    std::cout << a1->getData();

    std::cout<<"\n\nEnd Main\n"<<std::endl;
    return 0;
}