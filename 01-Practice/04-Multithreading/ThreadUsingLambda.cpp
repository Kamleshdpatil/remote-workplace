#include<iostream>
#include<thread>

using namespace std;

auto DisplayElements = [](int endelement)
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
};

int main(void)
{
    thread theadObj(DisplayElements, 20);
    if(theadObj.joinable())
    {
        theadObj.join();
    }


    // Create a Thread from Lambda function
    std::thread threadObj1([]() {
        for(int i = 0; i < 5; ++i) {
            std::cout << "Display Thread Executing" << std::endl;
        }
    });

     // Wait for the thread to finish
    threadObj1.join();

    return(0);
}
