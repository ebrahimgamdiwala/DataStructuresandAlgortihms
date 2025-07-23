#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Check if it's safe to place a queen at board[row][col]
// Time complexity: O(n)
bool isSafe(vector<string>& board, int row, int col, int n) {
    // Check horizontal (row)
    for (int j = 0; j < n; j++) {
        if (board[row][j] == 'Q') return false;
    }

    // Check vertical (column)
    for (int i = 0; i < n; i++) {
        if (board[i][col] == 'Q') return false;
    }

    // Check left diagonal (↖)
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }

    // Check right diagonal (↗)
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }

    return true;
}

// Recursive backtracking function to solve N-Queens
// Time complexity: O(n!) in the worst case
void nQueens(vector<string>& board, int row, int n, vector<vector<string>>& ans) {
    if (row == n) {
        ans.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            nQueens(board, row + 1, n, ans);
            board[row][col] = '.';
        }
    }
}

// Solves the N-Queens problem and returns all solutions
// Time complexity: O(n!) overall
vector<vector<string>> solveNQueens(int n) {
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;
    nQueens(board, 0, n, ans);
    return ans;
}

int main() {
    int n = 4; // Change this to run for different board sizes
    vector<vector<string>> solutions = solveNQueens(n);

    cout << "Total Solutions for N = " << n << ": " << solutions.size() << "\n\n";
    for (const auto& solution : solutions) {
        for (const string& row : solution) {
            cout << row << "\n";
        }
        cout << "\n";
    }

    return 0;
}
