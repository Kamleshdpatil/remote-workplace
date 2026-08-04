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
int itemsCount = 10;

void producer(int val)
{
    while(itemsCount){
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [](){return (!isProduced && sharedQueue.size() <= itemsCount);});

        sharedQueue.push(val * itemsCount);
        cout<<"Produced: "<<(val * itemsCount)<<"\n";
        itemsCount--;
        isProduced = !isProduced;
        lock.unlock();
        cv.notify_one();
    }
}

void consumer()
{
    while(true){
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [](){return (isProduced && sharedQueue.size() > 0);});

        int item = sharedQueue.front();
        sharedQueue.pop();
        cout<<"Consumed: "<<item<<"\n\n";
        isProduced = !isProduced;
        lock.unlock();
        cv.notify_one();
    }
}

int main()
{
    thread t1(producer, 100);
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