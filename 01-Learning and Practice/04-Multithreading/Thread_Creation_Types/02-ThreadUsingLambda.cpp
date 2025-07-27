#include<iostream>
#include<thread>

using namespace std;

// Lambda function
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

// Lambda function for sum of given number
auto sumOfGivenNumber = [](int n){
    int sum = 0;
    cout<<endl<<"Sum of given numbers: ";
    for(int i = 1; i <= n; i++){
        sum += i;
        cout<<sum<<" ";
    }
    return sum;
};

int main(void)
{
    thread theadObj(DisplayElements, 20);
    if(theadObj.joinable())
    {
        theadObj.join();
    }

    thread threadSum(sumOfGivenNumber, 10);
    if(threadSum.joinable()){
        threadSum.join();
    }

    cout<<endl;
    // Create a Thread from Lambda function
    std::thread threadObj1([]() {
        for(int i = 0; i < 5; ++i) {
            std::cout << "Display Thread Executing" << std::endl;
        }
    });

     // Wait for the thread to finish
    threadObj1.join();

    std::terminate();
    return(0);
}
