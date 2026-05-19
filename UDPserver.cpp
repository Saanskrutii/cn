#include <iostream>
#include <winsock2.h>

using namespace std;

#pragma comment(lib,"ws2_32.lib")

int main() {

    WSADATA wsa;

    SOCKET serverSocket;

    sockaddr_in server, client;

    char buffer[100];

    int clientLen = sizeof(client);

    WSAStartup(MAKEWORD(2,2), &wsa);

    // Create UDP Socket
    serverSocket = socket(AF_INET, SOCK_DGRAM, 0);

    // Configure
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = INADDR_ANY;

    // Bind
    bind(serverSocket,
         (sockaddr*)&server,
         sizeof(server));

    cout << "UDP Server Waiting...\n";

    // Receive
    recvfrom(serverSocket,
             buffer,
             sizeof(buffer),
             0,
             (sockaddr*)&client,
             &clientLen);

    cout << "Client Message: " << buffer << endl;

    // Reply
    char reply[] = "Hello UDP Client";

    sendto(serverSocket,
           reply,
           sizeof(reply),
           0,
           (sockaddr*)&client,
           clientLen);

    closesocket(serverSocket);

    WSACleanup();

    return 0;
}