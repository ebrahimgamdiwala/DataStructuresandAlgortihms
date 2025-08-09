#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> previousSmallerElement(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n);
    stack<int> s;

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && s.top() >= arr[i]) {
            s.pop();
        }
        if (s.empty()) {
            result[i] = -1;
        } else {
            result[i] = s.top();
        }
        s.push(arr[i]);
    }

    return result;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> result = previousSmallerElement(arr);

    cout << "Previous smaller elements are: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}