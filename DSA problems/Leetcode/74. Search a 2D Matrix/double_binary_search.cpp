#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchInRow(vector<vector<int>>& matrix, int target, int row) {
        int start = 0, end = matrix[0].size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int startRow = 0, endRow = m - 1;
        while (startRow <= endRow) {
            int midRow = startRow + (endRow - startRow) / 2;
            if (target >= matrix[midRow][0] && target <= matrix[midRow][n - 1]) {
                return searchInRow(matrix, target, midRow);
            } else if (target > matrix[midRow][n - 1]) {
                startRow = midRow + 1;
            } else {
                endRow = midRow - 1;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> matrix1 = {{1, 3}};
    int target1 = 3;
    cout << "Test 1: " << (sol.searchMatrix(matrix1, target1) ? "true" : "false") << endl;
    
    vector<vector<int>> matrix2 = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    int target2 = 5;
    cout << "Test 2: " << (sol.searchMatrix(matrix2, target2) ? "true" : "false") << endl;
    
    vector<vector<int>> matrix3 = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    int target3 = 13;
    cout << "Test 3: " << (sol.searchMatrix(matrix3, target3) ? "true" : "false") << endl;
    
    return 0;
}