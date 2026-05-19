#include <iostream>
#include <cmath>

using namespace std;

// Function to print IP Address
void printIP(unsigned int ip) {

    cout << ((ip >> 24) & 255) << ".";
    cout << ((ip >> 16) & 255) << ".";
    cout << ((ip >> 8) & 255) << ".";
    cout << (ip & 255);
}

int main() {

    unsigned int a, b, c, d;
    int cidr;

    cout << "Enter IP Address (Example: 192.168.1.10): ";
    scanf("%u.%u.%u.%u", &a, &b, &c, &d);

    cout << "Enter CIDR value: ";
    cin >> cidr;

    // Convert IP into single number
    unsigned int ip =
        (a << 24) |
        (b << 16) |
        (c << 8)  |
        d;

    // Create subnet mask
    unsigned int mask = ~0 << (32 - cidr);

    // Find network address
    unsigned int network = ip & mask;

    // Find broadcast address
    unsigned int broadcast = network | (~mask);

    // Total hosts
    int totalHosts = pow(2, (32 - cidr));

    // Usable hosts
    int usableHosts = totalHosts - 2;

    // First and Last usable IP
    unsigned int firstIP = network + 1;
    unsigned int lastIP = broadcast - 1;

    cout << "\n----- RESULTS -----\n";

    cout << "Network Address: ";
    printIP(network);

    cout << "\nBroadcast Address: ";
    printIP(broadcast);

    cout << "\nTotal Hosts: " << totalHosts;

    cout << "\nUsable Hosts: " << usableHosts;

    cout << "\nFirst Usable IP: ";
    printIP(firstIP);

    cout << "\nLast Usable IP: ";
    printIP(lastIP);

    cout << endl;

    return 0;
}