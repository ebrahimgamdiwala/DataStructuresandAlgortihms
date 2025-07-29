#include <iostream>
#include <vector>
using namespace std;

//Time Complexity : O(8^(n^2)) This is because we are making 8 different choices for n^2 cells
//Space Complexity : O(n^2) This is because of the recursion call stack

bool isValid(vector<vector<int>>& grid, int r, int c, int n, int expVal) {
    if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != expVal) {
        return false;
    }
    if (expVal == n * n - 1) {
        return true;
    }

    // 8 possible moves of Knight
    bool ans1 = isValid(grid, r - 2, c + 1, n, expVal + 1);
    bool ans2 = isValid(grid, r - 1, c + 2, n, expVal + 1);
    bool ans3 = isValid(grid, r + 1, c + 2, n, expVal + 1);
    bool ans4 = isValid(grid, r + 2, c + 1, n, expVal + 1);
    bool ans5 = isValid(grid, r + 2, c - 1, n, expVal + 1);
    bool ans6 = isValid(grid, r + 1, c - 2, n, expVal + 1);
    bool ans7 = isValid(grid, r - 1, c - 2, n, expVal + 1);
    bool ans8 = isValid(grid, r - 2, c - 1, n, expVal + 1);

    return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
}

bool checkValidGrid(vector<vector<int>>& grid) {
    return isValid(grid, 0, 0, grid.size(), 0);
}

int main() {
    // A valid knight's tour on a 5x5 grid (starting at grid[0][0] = 0)
    vector<vector<int>> grid = {
        {0, 11, 16, 5, 20},
        {17, 4, 19, 10, 15},
        {12, 1, 8, 21, 6},
        {3, 18, 23, 14, 9},
        {24, 13, 2, 7, 22}
    };

    if (checkValidGrid(grid)) {
        cout << "Valid Knight's Tour" << endl;
    } else {
        cout << "Invalid Knight's Tour" << endl;
    }

    return 0;
}
