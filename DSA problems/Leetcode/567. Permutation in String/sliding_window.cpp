#include <iostream>
#include <string>

using namespace std;

bool isFreqSame(int freq[], int windowFreq[]) {
    for (int i = 0; i < 26; i++) {
        if (freq[i] != windowFreq[i]) {
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2) {
    int freq[26] = {0};
    for (int i = 0; i < s1.length(); i++) {
        freq[s1[i] - 'a']++;
    }
    int windowSize = s1.length();
    for (int i = 0; i <= s2.length() - windowSize; i++) {
        int windowFreq[26] = {0};
        for (int j = 0; j < windowSize; j++) {
            windowFreq[s2[i + j] - 'a']++;
        }
        if (isFreqSame(freq, windowFreq)) {
            return true;
        }
    }
    return false;
}

int main() {
    string s1 = "ab";
    string s2 = "eidbaooo";
    bool result = checkInclusion(s1, s2);
    cout << (result ? "true" : "false") << endl;
    return 0;
}
