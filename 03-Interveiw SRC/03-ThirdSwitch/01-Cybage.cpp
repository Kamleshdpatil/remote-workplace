// Online C++ compiler to run C++ program online
#include <iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

using namespace std;
// 2's table 2, 4, 6, 8...

// two threads

mutex mtx;
bool isThread1Turn = true;
condition_variable cvar;

int counter = 1;

void printTwoTable()
{
    while(true)
    {
        std::unique_lock<mutex> lock(mtx);
        cvar.wait(lock, []{return isThread1Turn;});
        
        if(isThread1Turn){
            cout<<"Thread 1: ";
        }else{
            cout<<"Thread 2: ";
        }
        cout<<counter * 2<<" "<<endl;
        
        isThread1Turn = !(isThread1Turn);
        counter++;
        cvar.notify_all();
    }
}

int main() {
    
    thread t1(printTwoTable);
    thread t2(printTwoTable);
    
    if(t1.joinable())
        t1.join();
        
    if(t2.joinable())
        t2.join();
    

    return 0;
}