#include <iostream>
using namespace std;

int main() {

    string data;
    int count = 0;
    int choice;

    cout << "Enter binary data: ";
    cin >> data;

    // Count number of 1s
    for(int i = 0; i < data.length(); i++) {
        if(data[i] == '1') {
            count++;
        }
    }

    cout << "\n1. Even Parity";
    cout << "\n2. Odd Parity";
    cout << "\nEnter choice: ";
    cin >> choice;

    if(choice == 1) {

        if(count % 2 == 0) {
            cout << "\nParity Bit = 0";
            cout << "\nFinal Data = " << data << "0";
        }
        else {
            cout << "\nParity Bit = 1";
            cout << "\nFinal Data = " << data << "1";
        }
    }

    else if(choice == 2) {

        if(count % 2 == 0) {
            cout << "\nParity Bit = 1";
            cout << "\nFinal Data = " << data << "1";
        }
        else {
            cout << "\nParity Bit = 0";
            cout << "\nFinal Data = " << data << "0";
        }
    }

    else {
        cout << "Invalid Choice";
    }

    return 0;
}