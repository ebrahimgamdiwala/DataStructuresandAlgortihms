#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
}

int main() {
    vector<int> v = {64, 25, 12, 22, 11};
    bubbleSort(v);

    cout << "Bubble Sort: ";
    for (int num : v) cout << num << " ";
    cout << endl;

    return 0;
}
