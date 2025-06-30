#include <iostream>
#include <winsock.h> // Need to add wsock32.lib while linking the program
using namespace std;

// Macros
#define PORT 9909

// Global variables
struct sockaddr_in srv;
struct fd_set fr, fw, fe; // To Read, Write, exceptions/error logs
// fd_set is is having:- 1) u_int fd_count- number of file descriptors which we are going to set in this structure
// 2) SOCKET fd_array[FD_SETSIZE] - at here we are going to set our socket(s) - It can contain 64 Sockets
int nMaxFd = 0;

int main(void)
{
    // Local variables
    int nRet = 0;

    // Initilize the WSA variables - Windows Socket API's
    WSADATA wsData;
    if (WSAStartup(MAKEWORD(2, 2), &wsData) < 0)
    {
        cout << endl << "WSA Failed to initilize!";
        WSACleanup();
        exit(EXIT_FAILURE);
    }
    else
    {
        cout << endl << "The WSA initilize successfully!!";
    }
    cout << endl;

    // Initilize the socket
    int nSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); // AF_INET -> for inter network, SOCK_STREAM -> connection oriented socket
    if (nSocket < 0)
    {
        cout << endl << "The socket not opened!";
        WSACleanup();
        exit(EXIT_FAILURE);
    }
    else
    {
        cout << endl << "The socket opened successfully: " << nSocket;
    }
    cout << endl;

    // Initilize the environment for sockaddr structure
    srv.sin_family = AF_INET;
    srv.sin_port = htons(PORT);
    srv.sin_addr.s_addr = INADDR_ANY; // inet_addr("127.0.0.1"); <-- can be used instead
    memset(&(srv.sin_zero), 0, 8);

    // // About the Blocking vs Non-Blocking sockets - By defualt all sockets are blocking sockets
    // // optval = 0 means blocking and != 0 means non blocking
    // // FIONBIO - set/clear non-blocking i/o
    // u_long optval = 1;
    // nRet = ioctlsocket(nSocket, FIONBIO, &optval); // Help a socket to set a socket blocking or non-blocking.
    // if (nRet != 0)
    // {
    //     cout << endl << "ioctlsocket call failed !!";
    //     // WSACleanup();
    //     // exit(EXIT_FAILURE);
    // }
    // else
    // {
    //     cout << endl << "ioctlsocket call passed !!";
    // }
    // cout << endl;
    
    // Bind the socket to the local port. Excluding: (0 - 256)
    nRet = bind(nSocket, (sockaddr *)&srv, sizeof(sockaddr));
    if (nRet < 0)
    {
        cout << endl << "Fail to bind the Local port!";
        WSACleanup();
        exit(EXIT_FAILURE);
    }
    else
    {
        cout << endl << "Successfully bind to Local port!!";
    }
    cout << endl;

    // Listen the request from client (queues the requests)
    nRet = listen(nSocket, 5); // 5(Backlog) --> ? Which tells you how many rquests can be there in a active queue.
    if (nRet < 0)
    {
        cout << endl << "Fail to start listen to the Local port!";
        WSACleanup();
        exit(EXIT_FAILURE);
    }
    else
    {
        cout << endl;
        cout << endl << "Started listening to local port ...";
    }
    cout << endl;

    nMaxFd = nSocket + 1;     // + 1 for select() system call to store in struct of fd
    struct timeval timeValue; // To wait how much time to see any of the fd is ready
    timeValue.tv_sec = 1;
    timeValue.tv_usec = 0;

    
    while (1)
    {
        FD_ZERO(&fr); // Clear FD
        FD_ZERO(&fe);
    
        FD_SET(nSocket, &fr); // Must to Set FD before select system call
        FD_SET(nSocket, &fe);
        cout << endl << "Before select call: " << fr.fd_count << endl;

        // Keep waiting for new requests and proceed as per the request
        nRet = select(nMaxFd, &fr, &fw, &fe, &timeValue); // To wait foer all these socket descreptors
        if (nRet > 0)
        {
            // When someone connects or communicates with a message over a dedicated connection
            cout << endl << "Someone connected to this fd..";
        }
        else if (nRet == 0)
        {
            // No connection or any communication request made or you can say that none of the socket descriptors are ready.
            cout << endl << "Nothing on port: " << PORT;
        }
        else
        {
            cout << endl << "select() is failed.";
            WSACleanup();
            exit(EXIT_FAILURE);
        }
        cout << endl;
        cout << endl<< "After select call: " << fr.fd_count << endl;
    }

    // Exit the program
    WSACleanup(); // To does all necessary resource deallocation for the task.
    return 0;
}