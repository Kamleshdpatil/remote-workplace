#include<iostream>
#include<thread>
#include<chrono>
#include<mutex>

using namespace std;

int counter = 0;

mutex mtx;

void increment()
{
    cout<<"increment() thread PID: "<<this_thread::get_id()<<endl;
    for(int i = 0; i < 100; i++){

        lock_guard<mutex> lock(mtx); // RAII -- handle unlcoking automatically

        cout<<counter+1<<" ";
        counter++;
        // mtx.unlock();
    }
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

