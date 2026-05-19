#include <iostream>
#include <winsock2.h>

using namespace std;

#pragma comment(lib,"ws2_32.lib")

int main() {

    WSADATA wsa;

    SOCKET sock;

    sockaddr_in server;

    char reply[100];

    int serverLen = sizeof(server);

    WSAStartup(MAKEWORD(2,2), &wsa);

    // Create UDP Socket
    sock = socket(AF_INET, SOCK_DGRAM, 0);

    // Configure Server
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Send Message
    char message[] = "Hello UDP Server";

    sendto(sock,
           message,
           sizeof(message),
           0,
           (sockaddr*)&server,
           serverLen);

    // Receive Reply
    recvfrom(sock,
             reply,
             sizeof(reply),
             0,
             (sockaddr*)&server,
             &serverLen);

    cout << "Server Reply: " << reply;

    closesocket(sock);

    WSACleanup();

    return 0;
}