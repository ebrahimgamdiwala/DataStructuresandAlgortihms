#include <iostream>
#include <string>
using namespace std;

string defangIPaddr(string address) {
    string ans = "";
    for (int i = 0; i < address.length(); i++) {
        char ch = address[i];
        if (ch == '.') {
            ans += "[.]";
        } else {
            ans += ch;
        }
    }
    return ans;
}

int main() {
    string ip = "192.168.0.1";
    string result = defangIPaddr(ip);
    cout << result << endl;
    return 0;
}
