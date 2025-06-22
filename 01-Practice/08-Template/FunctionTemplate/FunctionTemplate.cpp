// FunctionTemplate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class uniquePtr {
    int* iptr;
};

template <typename myType>
myType GetMax(myType a, myType b)
{
    return(a > b ? a : b);
}

template <class newType, class prakash>
prakash GetMin(newType a, prakash b)
{
    return(a > b ? b : a);
}

int main()
{
    int id = GetMax<int>(12, 10);
    float fd = GetMax<float>(12.98, 10.8756);
    double dd = GetMax<double>(12.121211, 10.12222);

    std::cout << "Int Result: " << id << std::endl;
    std::cout << "Float Result: " << fd << std::endl;
    std::cout << "Double Result: " << dd << std::endl;


    std::cout << "\n\nNext Flow \n\n" << std::endl;

    int i = GetMin<int, float>(12, 10.98);
    float f = GetMin(12.98, 10.8756);
    double d = GetMin(12.121211, 10.12222);

    std::cout << "Int Result: " << i << std::endl;
    std::cout << "Float Result: " << f << std::endl;
    std::cout << "Double Result: " << d << std::endl;

}
