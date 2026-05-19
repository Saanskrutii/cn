#include <iostream>
using namespace std;

int main() {

    int frames, windowSize;

    cout << "Enter number of frames: ";
    cin >> frames;

    cout << "Enter window size: ";
    cin >> windowSize;

    int lostFrame = 3;

    for(int i = 1; i <= frames; i++) {

        cout << "\nSending Frame " << i;

        if(i == lostFrame) {

            cout << "\nError in Frame " << i;
            cout << "\nRetransmitting from Frame " << i << endl;

            for(int j = i; j < i + windowSize && j <= frames; j++) {
                cout << "Resending Frame " << j << endl;
            }

            i = i + windowSize - 1;
        }
    }

    cout << "\nAll Frames Transmitted";

    return 0;
}