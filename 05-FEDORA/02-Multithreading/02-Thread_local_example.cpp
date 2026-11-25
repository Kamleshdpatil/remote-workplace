#include<iostream>
#include<thread>

using namespace std;

class ThreadLogger{
    public:
    ThreadLogger(){
        cout<<"Logger created for Thread: "<<this_thread::get_id()<<"\n"; 
    }

    void log(string msg)
    {
        cout<<"[Thread "<< this_thread::get_id()<< "]: "<<msg<<"\n";
    }
};

void executeTask(){
    static thread_local ThreadLogger logger;

    logger.log("Doing some work...");
}

int main()
{   
    thread t1(executeTask);
    thread t2(executeTask);

    t1.join();
    t2.join();

    return(0);
}

