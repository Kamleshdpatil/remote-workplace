#include <iostream>
#include <fstream>
#include <mutex>

#ifndef LOGGER_H // Header guard start
#define LOGGER_H

using namespace std;

enum LogLevel
{
    DEBUG_,
    INFO_,
    WARNING_,
    ERROR_,
    CRITICAL_
};

class Logger
{
    ofstream logFile;               // File stream for the log file
    string levelToString(LogLevel) const; // Converts log level to a string output
    mutable mutex mtx; // mutex for synchronizing log access

    Logger(const string &fileName)
    {
        logFile.open(fileName, ios::out | ios::trunc); // Open in truncate mode to clear previous logs
        if (!logFile.is_open()) {
            cout << endl << "Error in opening log file." << endl;
        } else {
            logFile << "===== Log Started =====" << endl;
        }
    }

    public:

    // Delete copy and copy assignment operator constructors
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    // Delete move and move assignment operator constructors
    Logger(Logger&&) = delete;
    Logger& operator=(Logger&&) = delete;

    // Singleton Accessor (thread-safe since C++11 guarantees static local init)
    static Logger& getLoggerInstance(const string& filename = "logs.log")
    {
        static Logger instance(filename);
        return instance;
    }

    void log(LogLevel, const string &);

    ~Logger() { 
        cout << endl << "===== Log Ended =====" << endl;
        logFile.close(); 
    }
};

#endif