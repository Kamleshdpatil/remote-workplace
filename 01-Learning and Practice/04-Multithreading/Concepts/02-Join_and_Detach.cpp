// JOIN() Notes:-->
// 1) Once a thread is started we wait for this thread to finish by calling join() function on thread object.
// 2) Double join() will result into program termination.
// 3) If needed we should check thread is joinable before joining to avoid double join(). (Using joinable() function)


// Detach() Notes:-->
// 1) This is used to detach newly created thread from the parent thread.
// 2) Always check before detaching a thread that it is joinable otherwise we may end up double detaching and 
//    double detach() will result into program termination.
// 3) If we have detached thread and main function is returning then the detached thread execution is suspended


// Notes:-->
// Either join() or detach() should be called on thread object, otherwise during thread object's destructor it will
// terminate the program Becuase inside destructor it checks it thread is still joinable? If yes then terminates the program.

#include<iostream>
#include<chrono>
#include<thread>

using namespace std;

void run(int count){
    while (count-- > 0)
    {
        cout<<endl<<"Kamlesh";
    }
    cout<<endl;
    std::this_thread::sleep_for(chrono::seconds(3));
}

int main(){
    thread t1(run, 10);
    cout<<"Main()"<<endl;
    std::this_thread::sleep_for(chrono::seconds(5));
    cout<<"calling join()"<<endl;
    
    t1.join();
    cout<<"After join join()"<<endl;

    cout<<endl<<"Main() after join()"<<endl;

    return(0);
}
