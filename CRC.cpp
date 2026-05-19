#include <iostream>
using namespace std;

string xorOperation(string a, string b) {

    string result = "";

    for(int i = 1; i < b.length(); i++) {

        if(a[i] == b[i])
            result += '0';
        else
            result += '1';
    }

    return result;
}

string divide(string data, string divisor) {

    int pick = divisor.length();

    string temp = data.substr(0, pick);

    while(pick < data.length()) {

        if(temp[0] == '1')
            temp = xorOperation(divisor, temp) + data[pick];
        else
            temp = xorOperation(string(divisor.length(), '0'), temp) + data[pick];

        pick++;
    }

    if(temp[0] == '1')
        temp = xorOperation(divisor, temp);
    else
        temp = xorOperation(string(divisor.length(), '0'), temp);

    return temp;
}

int main() {

    string data, divisor;

    cout << "Enter Data: ";
    cin >> data;

    cout << "Enter Divisor: ";
    cin >> divisor;

    string appended = data + string(divisor.length()-1, '0');

    string remainder = divide(appended, divisor);

    string transmitted = data + remainder;

    cout << "\nCRC Bits: " << remainder;
    cout << "\nTransmitted Data: " << transmitted;

    return 0;
}