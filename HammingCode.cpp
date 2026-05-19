#include <iostream>
using namespace std;

int main() {

    int h[7];
    int p1, p2, p4;
    int error;

    cout << "Enter 7 bits:\n";

    for(int i = 0; i < 7; i++) {
        cin >> h[i];
    }

    p1 = h[0] ^ h[2] ^ h[4] ^ h[6];
    p2 = h[1] ^ h[2] ^ h[5] ^ h[6];
    p4 = h[3] ^ h[4] ^ h[5] ^ h[6];

    error = p4 * 4 + p2 * 2 + p1;

    if(error == 0) {
        cout << "No Error Detected";
    }
    else {

        cout << "Error at Position: " << error;

        h[error - 1] = h[error - 1] ^ 1;

        cout << "\nCorrected Code: ";

        for(int i = 0; i < 7; i++) {
            cout << h[i] << " ";
        }
    }

    return 0;
}