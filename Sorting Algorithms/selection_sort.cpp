#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (v[j] < v[min_idx])
                min_idx = j;
        swap(v[i], v[min_idx]);
    }
}

int main() {
    vector<int> v = {164, 235, 152, 222, 111};
    selectionSort(v);

    cout << "Selection Sort: ";
    for (int num : v) cout << num << " ";
    cout << endl;

    return 0;
}
