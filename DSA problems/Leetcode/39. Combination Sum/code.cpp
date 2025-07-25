#include <iostream>
#include <vector>
#include <set>

using namespace std;

set<vector<int>> s;

void getAllCombinations(vector<int>& arr, int idx, int target, vector<vector<int>>& ans, vector<int>& combin) {
    if (idx == arr.size() || target < 0) {
        return;
    }
    if (target == 0) {
        if (s.find(combin) == s.end()) {
            ans.push_back(combin);
            s.insert(combin);
        }
    }
    combin.push_back(arr[idx]);
    getAllCombinations(arr, idx + 1, target - arr[idx], ans, combin);
    getAllCombinations(arr, idx, target - arr[idx], ans, combin);
    combin.pop_back();
    getAllCombinations(arr, idx + 1, target, ans, combin);
}

vector<vector<int>> combinationSum(vector<int>& arr, int target) {
    vector<vector<int>> ans;
    vector<int> combin;
    getAllCombinations(arr, 0, target, ans, combin);
    return ans;
}

int main() {
    vector<int> arr = {2, 3, 5};
    int target = 8;
    vector<vector<int>> result = combinationSum(arr, target);

    for (const auto& comb : result) {
        for (int num : comb) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
