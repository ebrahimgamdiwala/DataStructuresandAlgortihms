#include <iostream>
#include <vector>
using namespace std;

void reverseString(vector<char>& s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        swap(s[left++], s[right--]);
    }
}

int main() {
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    reverseString(s);
    for (char c : s) {
        cout << c;
    }
    cout << endl;
    return 0;
}
