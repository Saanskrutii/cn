#include <iostream>
using namespace std;

int main() {

    int frames, lostFrame;

    cout << "Enter number of frames: ";
    cin >> frames;

    cout << "Enter frame number to lose: ";
    cin >> lostFrame;

    for(int i = 1; i <= frames; i++) {

        cout << "\nSending Frame " << i;

        if(i == lostFrame) {

            cout << "\nFrame Lost!";
            cout << "\nNo Acknowledgement";
            cout << "\nResending Frame " << i;
        }

        cout << "\nAcknowledgement Received for Frame " << i << endl;
    }

    cout << "\nAll Frames Sent Successfully";

    return 0;
}