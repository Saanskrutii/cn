#include <iostream>
using namespace std;

int main() {

    int frames, lostFrame;

    cout << "Enter number of frames: ";
    cin >> frames;

    cout << "Enter lost frame number: ";
    cin >> lostFrame;

    for(int i = 1; i <= frames; i++) {

        if(i == lostFrame) {

            cout << "\nFrame " << i << " Lost";
            cout << "\nRetransmitting Frame " << i << endl;
        }

        else {
            cout << "\nFrame " << i << " Sent Successfully";
        }
    }

    cout << "\nTransmission Completed";

    return 0;
}
