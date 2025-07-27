#include<mutex>
#include<string>
#include<iostream>
#include"logger.hpp"
using namespace std;

Logger* Logger::logger = nullptr;
int Logger::counter = 0;
static std::mutex mtx;

Logger::Logger()
{   counter++;
    cout<<"Instnace cretaed. No. of Instance: "<<counter<<endl;
}

Logger* Logger::getInstance(){
    if(logger == nullptr){
        mtx.lock();
        if(logger == nullptr){
            logger = new Logger();
        }
        mtx.unlock();
    }
    return logger;
}

void Logger::log(const std::string& msg)
{
    cout<<msg<< " Adress of calling object: "<<this<<endl<<endl;
}
