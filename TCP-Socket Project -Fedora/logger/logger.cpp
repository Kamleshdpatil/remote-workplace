#include<iostream>
#include<fstream>
#include<sstream>
#include<ctime>
#include"logger.h"

using namespace std;

void Logger::log(LogLevel level, const string& message) {
    lock_guard<mutex> lock(mtx); // ensures only one thread logs at a time

    // Get current timestamp
    time_t now = time(0);
    tm* timeinfo = localtime(&now);
    char timestamp[30];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);

    // Create log entry
    ostringstream logEntry;
    logEntry<<"["<<timestamp<<"] "<<Logger::levelToString(level)
    <<": "<<message<<endl;

    // Output to console
    // cout<<logEntry.str();

    // Output to log file
    if(logFile.is_open()){
        logFile<<logEntry.str();
        logFile.flush(); // Ensure immidiate write to file
    }
}
string Logger::levelToString(LogLevel level) const{
    switch (level)
    {
    case DEBUG_:
        return "DEBUG";
    case INFO_:
        return "INFO";
    case WARNING_:
        return "WARNING";
    case ERROR_:
        return "ERROR";
    case CRITICAL_:
        return "CRITICAL";
    default:
        return "UNKNOWN";
    }
}