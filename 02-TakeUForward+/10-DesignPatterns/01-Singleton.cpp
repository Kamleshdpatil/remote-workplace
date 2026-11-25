/*
    The singleton pattern ensure that the class only one instace throughout the applications lifecycle
    and provides a gloabal access point to the instance.
*/

#include<iostream>
#include<mutex>

using namespace std;

class DatabaseConnection
{
    static DatabaseConnection* connection;
    static mutex mtx;

    DatabaseConnection() {}

    public:
    // Delete copy constructor and copy assignment operator constructor
    DatabaseConnection(const DatabaseConnection& obj) = delete;
    DatabaseConnection& operator=(const DatabaseConnection& obj) = delete;

    // Delete move constructor and move assignment operator constructor
    DatabaseConnection(DatabaseConnection&& obj) = delete;
    DatabaseConnection&& operator=(DatabaseConnection&& obj) = delete;

    // // Method to create single connection handle - Thread safe by mutex
    // static DatabaseConnection* getDatabaseHandle(){
    //     if(connection == nullptr)
    //     {
    //         lock_guard<mutex> lock(mtx);
    //         if(connection == nullptr)
    //             connection = new DatabaseConnection();
    //     }
    //     return connection;
    // }

    // Meyer's singleton implementation - Thread safe by local static instance
    static DatabaseConnection* getDatabaseHandle() {
        // This is initialized only once in a thread-safe manner by the compiler
        static DatabaseConnection instance; 
        return &instance;
    }

    void log(string msg)
    {
        cout<<msg<<endl;
    }
};

// Initilize the static member
DatabaseConnection* DatabaseConnection::connection = nullptr;
mutex DatabaseConnection::mtx;

int main()
{
    DatabaseConnection* connection1 = DatabaseConnection::getDatabaseHandle();
    cout<<connection1<<endl;

    return(0);
}
