#include<iostream>
#include<stdio.h>

using namespace std;

template <typename genType>
genType getMax(genType i, genType j)
{
    return(i>j?i:j);
}

template<class myType>
myType getMin(myType i, myType j)
{
    return(i<j?i:j);
}

template<class cType, typename tType>
void compareTypeAndPrint(cType c, tType t)
{
    if(c == t)
    {
        cout<<"\nsame";
    }else{
        cout<<"\nDiffrent!!";
    }
}

int main(void)
{
    int i = getMax<int>(20, 14.0f);
    int f = getMax<float>(10.25, 14.74f);

    std::cout<<"\n i= "<<i<<std::endl;
    std::cout<<"\n f= "<<f<<std::endl;

    compareTypeAndPrint<int, float>(11, 25.0f);
    compareTypeAndPrint<int, int>(100, 25);

    return(0);
}
