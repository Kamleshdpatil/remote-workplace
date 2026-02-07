#include <iostream>
#include <winsock.h> // Need to add wsock32.lib while linking the program
#include "../logger/logger.h"

using namespace std;

// Macros
#define PORT 9909

// Global variables
struct sockaddr_in srv;
struct fd_set fr, fw, fe; // To Read, Write, exceptions/error logs
            // fd_set is is having:- 
            // 1) u_int fd_count- number of file descriptors which we are going to set in this structure
            // 2) SOCKET fd_array[FD_SETSIZE] - at here we are going to set our socket(s) - It can contain 64 Sockets
int nMaxFd;
int nSocket;
int nArrClient[5];

Logger& logger = Logger::getLoggerInstance("server_log.log");

void ProcessNewMessage(int nClientSocket)
{
    logger.log(INFO_, string("Inside the start of ") + __func__);
    // cout <<endl<<"Processing the new message for client socket: "<<nClientSocket<< endl;

    char buff[256 + 1] = { 0, };
    int nRet = recv(nClientSocket, buff, 256, 0);
    if(nRet < 0)
    {
        cout <<endl<<"Something wrong happened at client socket: "<<nClientSocket<< endl;
        logger.log(ERROR_, string("Something wrong happened at client socket: %d", nClientSocket));
        closesocket(nClientSocket);
        cout <<endl<<"Client terminated:-> "<<nClientSocket<< endl<< endl;
        logger.log(INFO_, string("Client terminated:-> ", nClientSocket));
        for(int nIndex = 0; nIndex < 5; nIndex++)
        {
            if(nArrClient[nIndex] == nClientSocket)
            {
                nArrClient[nIndex] = 0;
                break;
            }
        }
    }
    else{
        cout <<endl<<"New message recieved from Client is: "<<buff;
        // // Send response to client
        char send_buff[256 + 1] = { 0, };
        cout<<endl<< "Send your message to Client: ";
        fgets(send_buff, 256, stdin);
        send(nClientSocket, send_buff, 256, 0);
        // send(nClientSocket, "Pocessed your request !!", 23, 0);
        cout<<endl<<"*************************************************************"<<endl;
    }
    logger.log(INFO_, string("Inside the end of ") + __func__);
}

void ProcessTheNewRequest()
{
    int nLen = sizeof(struct sockaddr);

    logger.log(INFO_, string("Inside the start of ") + __func__);

    int nClientSocket = accept(nSocket, NULL, &nLen);
    if (nClientSocket > 0)
    {
        // Put it into the client list
        for (int nIndex = 0; nIndex < 5; nIndex++)
        {
            if (nArrClient[nIndex] == 0)
            {
                nArrClient[nIndex] = nClientSocket;
                send(nClientSocket, "Got the connection done Successfully.", 37, 0);
                cout<< endl << "New client connected with Socket ID: " << nClientSocket << endl;
                return;
            }
        }
        cout<< endl<< endl << "No space for a new connection" << endl<< endl;
        logger.log(ERROR_, string("No space for a new connection"));
        closesocket(nClientSocket);
    }
    logger.log(INFO_, string("Inside the end of ") + __func__);
}

int main(void)
{
    // Local variables
    int nRet = 0;
    cout <<endl<<"---------!!!  Server Program Started Running  !!!---------"<< endl;
    logger.log(INFO_, string("---------!!!  Server Program Started Running  !!!---------"));
    
    // Initilize the WSA variables - Windows Socket API's
    WSADATA wsData;
    if (WSAStartup(MAKEWORD(2, 2), &wsData) < 0)
    {
        cout << "WSA Failed to initilize!"<< endl;
        logger.log(ERROR_, string("WSA Failed to initilize!"));
        WSACleanup();
        exit(EXIT_FAILURE);
    }
    
    // Initilize the socket
    nSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); // AF_INET -> for inter network, SOCK_STREAM -> connection oriented socket
    if (nSocket < 0)
    {
        cout << "The socket not opened!"<< endl;
        logger.log(ERROR_, string("The socket not opened!"));
        WSACleanup();
        exit(EXIT_FAILURE);
    }

    // Initilize the environment for sockaddr structure
    srv.sin_family = AF_INET;
    srv.sin_port = htons(PORT);
    srv.sin_addr.s_addr = INADDR_ANY; // inet_addr("127.0.0.1"); <-- can be used instead
    memset(&(srv.sin_zero), 0, 8);

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    // About the Blocking vs Non-Blocking sockets - By defualt all sockets are blocking sockets
    /*
    // optval = 0 means blocking and != 0 means non blocking
    // FIONBIO - set/clear non-blocking i/o
    u_long optval = 1;
    nRet = ioctlsocket(nSocket, FIONBIO, &optval); // Help a socket to set a socket blocking or non-blocking.
    if (nRet != 0)
    {
        cout << "ioctlsocket call failed !!"<< endl;
        // WSACleanup();
        // exit(EXIT_FAILURE);
    }
    */
   ///////////////////////////////////////////////////////////////////////////////////////////////////////////

    // setsockopt call
    int nOptVal = 0;
    int nOptLen = sizeof(nOptVal);
    nRet = setsockopt(nSocket, SOL_SOCKET, SO_REUSEADDR, (const char*)&nOptVal, nOptLen);
    if (nRet != 0)
    {
        cout << "Fail to set socket options!"<< endl;
        logger.log(ERROR_, string("Fail to set socket options!"));
        WSACleanup();
        exit(EXIT_FAILURE);
    }
    
    // Bind the socket to the local port. Excluding: (0 - 256)
    nRet = bind(nSocket, (sockaddr *)&srv, sizeof(sockaddr));
    if (nRet < 0)
    {
        cout << "Fail to bind the Local port!"<< endl;
        logger.log(ERROR_, string("Fail to bind the Local port!"));
        WSACleanup();
        exit(EXIT_FAILURE);
    }
    
    // Listen the request from client (queues the requests)
    nRet = listen(nSocket, 5); // 5(Backlog) --> ? Which tells you how many rquests can be there in a active queue.
    if (nRet < 0)
    {
        cout << "Fail to start listen to the Local port!"<< endl;
        logger.log(ERROR_, string("Fail to start listen to the Local port!"));
        WSACleanup();
        exit(EXIT_FAILURE);
    }

    nMaxFd = nSocket;     // + 1 for select() system call to store in struct of fd
    nMaxFd = nSocket;
    for (int i = 0; i < 5; i++) {
        if (nArrClient[i] > nMaxFd) {
            nMaxFd = nArrClient[i];
        }
    }
    
    while (1)
    {
        FD_ZERO(&fr); // Clear FD
        FD_ZERO(&fw);
        FD_ZERO(&fe);
    
        FD_SET(nSocket, &fr); // Must to Set FD before select system call
        FD_SET(nSocket, &fe);

        for (int i = 0; i < 5; i++) {
            if (nArrClient[i] > 0) {
                FD_SET(nArrClient[i], &fr);
                FD_SET(nArrClient[i], &fe);
                if (nArrClient[i] > nMaxFd) {
                    nMaxFd = nArrClient[i];
                }
            }
        }

        struct timeval timeValue; // To wait how much time to see any of the fd is ready
        timeValue.tv_sec = 3;
        timeValue.tv_usec = 50;

        // Keep waiting for new requests and proceed as per the request
        nRet = select(nMaxFd + 1, &fr, &fw, &fe, &timeValue); // To wait for all these socket descreptors
        if (nRet > 0)
        {
            // When someone connects or communicates with a message over a dedicated connection
            // Process the request..
            if(FD_ISSET(nSocket, &fe))
            {
                cout<<"There is an exception. Just get away from here.."<<endl;
            }
            if(FD_ISSET(nSocket, &fw))
            {
                cout<<"Ready to write something.."<<endl;
            }
            if(FD_ISSET(nSocket, &fr))
            {
                //cout<<"Ready to read something new came up.."<<endl;
                // Accept the connection
                ProcessTheNewRequest();
            }
            // break;
            // Also check if existing clients sent data
            for (int nIndex = 0; nIndex < 5; nIndex++)
            {
                if (nArrClient[nIndex] > 0 && FD_ISSET(nArrClient[nIndex], &fr))
                {
                    ProcessNewMessage(nArrClient[nIndex]);  // Handle client message
                }
            }
        }
        else if (nRet == 0)
        {
            // No connection or any communication request made or you can say that none of the socket descriptors are ready.
            //cout << "Nothing on port: " << PORT << endl;
        }
        else{
            cout<< endl <<"Server started to listen...."<< endl;
        }
        cout << "Waiting for client request... " << endl;
    }

    // Exit the program
    cout<< endl <<"---------!!!  Server Program Stopped  !!!---------"<< endl;
    logger.log(INFO_, string("---------!!!  Server Program Stopped  !!!---------"));
    WSACleanup(); // To does all necessary resource deallocation for the task.
    return 0;
}