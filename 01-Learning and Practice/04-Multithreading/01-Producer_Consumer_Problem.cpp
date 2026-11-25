#include<iostream>
#include<queue>
#include<mutex>
#include<thread>
#include<condition_variable>

using namespace std;

queue<int> sharedQueue;
condition_variable cv;
mutex mtx;
bool isProduced = false;
const int itemsCount = 10;
int counter = 0;
bool done = false; // Flag to signal consumer shutdown

void producer()
{
    while(true){
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [](){return (!isProduced && sharedQueue.size() <= itemsCount);});

        if(counter >= itemsCount)
        {
            done = true;
            cv.notify_all();
            break;
        }

        isProduced = true;
        counter++;
        
        cout<<"Produced: "<<counter * 100<<"\n";
        sharedQueue.push(counter * 100);
        
        cv.notify_all();
    }
}

void consumer()
{
    while(true){
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [](){return (isProduced == true && sharedQueue.size() > 0) || done;});

        if(sharedQueue.empty() && done)
        {
            break;
        }
        
        int item = sharedQueue.front();
        sharedQueue.pop();
        cout<<"Consumed: "<<item<<"\n\n";
        isProduced = false;

        cv.notify_all();
    }
}

int main()
{
    thread t1(producer);
    thread t2(consumer);

    if(t1.joinable())
    {
        t1.join();
    }

    if(t2.joinable())
    {
        t2.join();
    }

    return(0);
}