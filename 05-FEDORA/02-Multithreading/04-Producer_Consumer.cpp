#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<queue>

using namespace std;

// Global Variables
queue<int> buffer;
mutex mtx;
condition_variable cv;
int production_quantity = 5; // Decide

void producer()
{
    for(int i = 1; i <= production_quantity; i++)
    {
        this_thread::sleep_for(chrono::milliseconds(500));
        {
            lock_guard<mutex> lock(mtx);
            buffer.push(i);
            cout<<"Produced: "<< i << "\n";
        }
        cv.notify_one(); // Wake up one waiting consumer
    }
}

void consumer()
{
    while(true)
    {
        unique_lock<mutex> lock(mtx);
        // wait() unlocks the mutex and sleeps. 
        // When notified, it re-locks and checks the condition.
        cv.wait(lock, []{ return !buffer.empty(); });

        int data = buffer.front();
        buffer.pop();
        cout<<"Consumed: "<< data << "\n";
        if(data == production_quantity) break;
    }
}

int main()
{
    thread t1(producer);
    thread t2(consumer);

    if(t1.joinable())
        t1.join();
    
    if(t2.joinable())
        t2.join();

    return(0);
}
