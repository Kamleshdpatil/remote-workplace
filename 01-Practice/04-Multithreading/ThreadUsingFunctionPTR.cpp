#include<iostream>
#include<thread>

using namespace std;

void DisplayElements(int endelement)
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


typedef void (*FPTR)(int);
// void 

int main(void)
{
    // Using typedef
    // Way 1.
    FPTR FP1 = DisplayElements;
    //thread theadObj(FP1, 20);

    // Way 2.
    FPTR FP2 = &DisplayElements;
    //thread theadObj(FP2, 20);
    
    // Using Function name as a pointer
    thread theadObj(DisplayElements, 20);
    if(theadObj.joinable())
    {
        theadObj.join();
    }

    return(0);
}
