#include <iostream>
#include <winsock2.h>

using namespace std;

#pragma comment(lib,"ws2_32.lib")

int main() {

    WSADATA wsa;
    SOCKET sock;

    sockaddr_in server;

    char serverReply[100];

    // Start Winsock
    WSAStartup(MAKEWORD(2,2), &wsa);

    // Create Socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    // Configure Server
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect
    connect(sock,
            (sockaddr*)&server,
            sizeof(server));

    // Send Message
    char message[] = "Hello Server";

    send(sock, message, sizeof(message), 0);

    // Receive Reply
    recv(sock, serverReply, sizeof(serverReply), 0);

    cout << "Server Reply: " << serverReply;

    // Close
    closesocket(sock);

    WSACleanup();

    return 0;
}