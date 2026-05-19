#include <iostream>
#include <winsock2.h>

using namespace std;

#pragma comment(lib,"ws2_32.lib")

int main() {

    WSADATA wsa;
    SOCKET serverSocket, clientSocket;

    sockaddr_in server, client;

    char message[100];

    // Start Winsock
    WSAStartup(MAKEWORD(2,2), &wsa);

    // Create Socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    // Configure Server
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = INADDR_ANY;

    // Bind
    bind(serverSocket, (sockaddr*)&server, sizeof(server));

    // Listen
    listen(serverSocket, 1);

    cout << "Server Waiting...\n";

    int c = sizeof(sockaddr_in);

    // Accept Client
    clientSocket = accept(serverSocket,
                          (sockaddr*)&client,
                          &c);

    // Receive Message
    recv(clientSocket, message, sizeof(message), 0);

    cout << "Client Message: " << message << endl;

    // Send Reply
    char reply[] = "Hello Client";

    send(clientSocket, reply, sizeof(reply), 0);

    // Close
    closesocket(serverSocket);
    closesocket(clientSocket);

    WSACleanup();

    return 0;
}