// ClassTemplate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

template<class myType>
class myClass {
    myType a, b;

public:
    myClass(myType first, myType second)
    {
        a = first;
        b = second;
    }
    myType getMax();
    /*myType getMax()
    {
        return(a > b ? a : b);
    }*/
};

template<class myType>
myType myClass<myType>::getMax()
{
    myType retVal;
    retVal = a > b ? a : b;
    return(retVal);
}

int main()
{
    myClass<int> myObj(112, 120);
    std::cout<< "Result: " << myObj.getMax();

    return(0);
}
