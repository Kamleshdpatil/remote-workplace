/*
    Need to protect a complex object?               --> Use std::mutex.
    Need to signal data is ready?                   --> Use std::condition_variable.
    Need a simple counter?                          --> Use std::atomic.
    Need to limit access to a pool of connections?  --> Use std::semaphore.
    Lots of readers, few writers?                   --> Use std::shared_mutex.
*/


#include<iostream>
#include<thread>
#include<chrono>
#include<mutex>

using namespace std;

thread_local int counter = 0;

void increment()
{
    cout<<"increment() thread PID: "<<this_thread::get_id()<<endl;
    for(int i = 0; i < 100; i++){
        cout<<counter+1<<" ";
        counter++;
    }
    cout<<endl;
    cout<<"The END"<<endl;
}

void printStars(int count)
{
    cout<<"printStars PID: "<<this_thread::get_id()<<endl;
    this_thread::sleep_for(chrono::milliseconds(2000));
    for(int i = 0; i < count; i++)
    {
        cout<<"* ";
    }
    cout<<endl;
}

int main()
{
    cout<<"Main PID: "<<this_thread::get_id()<<endl;
    // thread t1(printStars, 10);
    // if(t1.joinable())
    //     t1.join();

    thread t2(increment);
    // if(t2.joinable())
    //     t2.join();

    cout<<endl<<"Another thread"<<endl;

    thread t3(increment);
    // if(t3.joinable())
    //     t3.join();

    t2.join();
    t3.join();

    return(0);
}

