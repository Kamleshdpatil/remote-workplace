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
    cout <<endl<<"---------!!  Client Program Started Running  !!---------"<< endl;

    // Local variables
    int nRet = 0;

    // Initilize the WSA variables - Windows Socket API's
    WSADATA wsData;
    if (WSAStartup(MAKEWORD(2, 2), &wsData) < 0)
    {
        cout << "WSA Failed to initilize!"<< endl;
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
    srv.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(&(srv.sin_zero), 0, 8);


    // Connect the socket to the server port. Excluding: (0 - 256)
    nRet = connect(nClientSocket, (struct sockaddr *)&srv, sizeof(srv));
    if (nRet < 0)
    {
        cout << "Fail to connect to server !!"<< endl;
        WSACleanup();
        exit(EXIT_FAILURE);
    }else{
        cout << "Connected to server !!"<< endl;
        char buff[256 + 1] = { 0, };
        recv(nClientSocket, buff, 256, 0);
        cout<<endl<<"press any key to see the message recieved from the server: ";
        getchar();
        cout<<endl<<buff;
        cout<<endl<<"Send your message to server: ";
        while (1)
        {
            fgets(buff, 256, stdin);
            send(nClientSocket, buff, 256, 0);
            cout<<endl<<"press any key to see the message recieved from the server: ";
            getchar();
            recv(nClientSocket, buff, 256, 0);
            cout<<endl<<buff<<"Now send next message: "<<endl;
        }
    }

    // Exit the program
    cout<< endl <<"---------!!  Client Program Stopped  !!---------"<< endl;
    WSACleanup(); // To does all necessary resource deallocation for the task.
    return 0;
}