// ClassTemplate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

template<class myType>
class myClass {
    myType standerd, stdunetCount;

public:
    myClass(myType first, myType second)
    {
        standerd = first;
        stdunetCount = second;
    }
    myType getMax();
    /*myType getMax()
    {
        return(standerd > stdunetCount ? standerd : stdunetCount);
    }*/
};

template<class myType>
myType myClass<myType>::getMax()
{
    myType retVal;
    retVal = standerd > stdunetCount ? standerd : stdunetCount;
    return(retVal);
}

int main()
{
    myClass<int> myObj(112, 120);
    std::cout<< "Result: " << myObj.getMax();

    return(0);
}
