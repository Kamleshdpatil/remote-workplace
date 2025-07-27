#include<iostream>
#include<thread>
#include"logger.hpp"

using namespace std;

void getLogger1(){
    Logger* logger1 = Logger::getInstance();
    // Logger* logger2 = Logger::getInstance();
    // logger1 = logger2;
    // logger2->log("Log from logger1::2");

    logger1->log("Log from logger1");
}
void getLogger2(){
    Logger* logger2 = Logger::getInstance();
    logger2->log("Log from logger2");
}

int main()
{
    thread t1(getLogger1);
    thread t2(getLogger2);

    t1.join();
    t2.join();
    
    // if(t1.joinable()){
    //     t1.join();
    // }
    // if(t2.joinable()){
    //     t2.join();
    // }
    
    return(0);
}