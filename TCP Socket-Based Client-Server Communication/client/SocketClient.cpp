#include <iostream>
#include <winsock.h> // Need to add wsock32.lib while linking the program
using namespace std;

// Macros
#define PORT 9909

// Global variables
int nClientSocket;
struct sockaddr_in srv;

int main(void)
{
    cout <<endl<<"---------!!!  Client Program Started Running  !!!---------"<< endl;

    // Local variables
    int nRet = 0;

    // Initilize the WSA variables - Windows Socket API's
    WSADATA wsData;
    if (WSAStartup(MAKEWORD(2, 2), &wsData) < 0)
    {
        cout << "WSA Failed to initilize..!!"<< endl;
        WSACleanup();
        exit(EXIT_FAILURE);
    }

    // Initilize the socket
    nClientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); // AF_INET -> for inter network, SOCK_STREAM -> connection oriented socket
    if (nClientSocket < 0)
    {
        cout << "The socket not opened!"<< endl;
        WSACleanup();
        exit(EXIT_FAILURE);
    }

    // Initilize the environment for sockaddr structure
    srv.sin_family = AF_INET;
    srv.sin_port = htons(PORT);
    srv.sin_addr.s_addr = inet_addr("127.0.0.1"); // Use INADDR_ANY for server side sockaddr structure
    memset(&(srv.sin_zero), 0, 8);

    // Connect the socket to the server port. Excluding: (0 - 256)
    nRet = connect(nClientSocket, (struct sockaddr *)&srv, sizeof(srv));
    if (nRet < 0)
    {
        cout << "Fail to connect to Server !!"<< endl;
        WSACleanup();
        exit(EXIT_FAILURE);
    }else{
        cout<<endl << "Connected to Server..."<< endl;
        char buff[256 + 1] = { 0, };
        // recv(nClientSocket, buff, 256, 0);
        int nBytes = recv(nClientSocket, buff, 256, 0);
        if (nBytes > 0) {
            buff[nBytes] = '\0';   // null-terminate at actual length
            cout << endl<< "Server response: " << buff << endl;
        } else {
            cout << endl<< "No welcome message received from server." << endl;
        }
        while (1)
        {
            cout<<endl<< "Send your message to Server: ";
            fgets(buff, 256, stdin);

            // Send user message
            send(nClientSocket, buff, strlen(buff), 0);

            // Wait for server reply
            memset(&buff, 0, 256); // null-terminate the received data
            int nRet = recv(nClientSocket, buff, 256, 0);
            if (nRet > 0) {
                cout<<endl<< "Server reply: " << buff;
            } else if (nRet == 0) {
                cout<<endl<< "Server closed the connection."<<endl;
                break;
            } else {
                cout<<endl<< "Error receiving data from server."<<endl;
                break;
            }
            cout<<endl<<"*************************************************************"<<endl;
        }
    }

    // Exit the program
    cout<< endl <<"---------!!!  Client Program Stopped  !!!---------"<< endl;
    WSACleanup(); // To does all necessary resource deallocation for the task.
    return 0;
}