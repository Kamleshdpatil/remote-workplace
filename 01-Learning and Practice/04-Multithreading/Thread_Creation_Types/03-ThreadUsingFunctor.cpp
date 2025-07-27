#include<iostream>
#include<thread>

using namespace std;

class DisplayElements
{
    public:
    void fun(){cout<<endl<<"Inside fun";}
    void operator()(int endelement)
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
        cout<<endl;
        std::cout<<"Inside Thread :: ID  = "<<std::this_thread::get_id()<<std::endl;
    }
};

int main(void)
{
    // thread theadObj(DisplayElements(), 20);
    // if(theadObj.joinable())
    // {
    //     cout<<"Inside theadObj"<<endl;
    //     theadObj.join();
    // }


    //thread t = move(theadObj);
    DisplayElements obj;
    thread t(obj, 10);
    
    if(t.joinable())
    {
        cout<<"Inside t"<<endl;
        t.join();
    }

    std::cout << "Number of threads = " <<  std::thread::hardware_concurrency() << std::endl;

    return(0);
}
