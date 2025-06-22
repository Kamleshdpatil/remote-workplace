#include<iostream>
#include<thread>

using namespace std;

class Base
{
    public:
    static void DisplayElements(int endelement)
    {
        int startElement = 0;
        for(int i = startElement +1; i <= endelement; i++)
        {
            cout<<i<<" ";
            if(i % 10 == 0)
            {
                cout<<endl;
            }
        }
    }
};

int main(void)
{
    // Without '&'
    thread theadObj(Base::DisplayElements, 10);
    if(theadObj.joinable())
    {
        theadObj.join();
    }
    
    cout<<endl;

    // With '&'
    thread theadObj2(&Base::DisplayElements, 10);
    if(theadObj2.joinable())
    {
        theadObj2.join();
    }

    return(0);
}
