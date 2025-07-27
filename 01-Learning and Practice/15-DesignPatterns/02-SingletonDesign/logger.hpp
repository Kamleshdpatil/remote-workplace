#ifndef LOGGER_HPP
#define LOGGER_HPP
#include<string>

class Logger{
    
    Logger();
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    public:
    static int counter;
    static Logger* logger;
    static Logger* getInstance();
    void log(const std::string& msg);
};

#endif