#include<iostream>
#include<thread>

using namespace std;

class Base
{
    public:
    void DisplayElements(long endelement)
    {
        long startElement = 0;
        for(long i = startElement +1; i <= endelement; i++)
        {
            cout<<i<<" ";
            if(i % 10 == 0)
            {
                cout<<endl;
            }
        }
    }
};

void thread_function(int num)
{
    for (int i = 0; i < num; i++)
    {
        std::cout << "thread function Executing" << std::endl;
    }
}

int main(void)
{
    Base b;
    thread theadObj(&Base::DisplayElements, &b, 200);
    if(theadObj.joinable())
    {
        theadObj.join();
    }

    cout<<endl;
    cout<<endl;

    thread thread1(thread_function, 10);
    if(thread1.joinable())
    {
        thread1.join();
    }

    return(0);
}
