#include <iostream>
#include <fstream>

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
    string levelToString(LogLevel); // Converts log level to a string output

public:
    Logger(const string &fileName)
    {
        logFile.open(fileName, ios::out | ios::trunc); // Open in truncate mode to clear previous logs
        if (!logFile.is_open()) {
            cout << endl << "Error in opening log file." << endl;
        } else {
            logFile << "===== Log Started =====" << endl;
        }
    }

    void log(LogLevel, const string &);

    ~Logger() { 
        cout << endl << "===== Log Ended =====" << endl;
        logFile.close(); 
    }
};

#endif